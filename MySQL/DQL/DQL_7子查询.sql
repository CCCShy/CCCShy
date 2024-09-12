#进阶7：子查询
/*
含义：
出现在其他语句中的select语句，称为子查询或内查询
外部的查询语句，称为主查询或外查询

分类：
按子查询出现的位置：
	select后面：
		仅仅支持标量子查询
	from后面：
		支持表子查询
	where或having后面：★
		标量子查询（单行）
		列子查询  （多行）
		行子查询
	exists后面（相关子查询）
		表子查询
按结果集的行列数不同：
	标量子查询（结果集只有一行一列）
	列子查询（结果集只有一列多行）
	行子查询（结果集有一行多列，也可多行多列）
	表子查询（结果集一般为多行多列）
*/

#一、where或having后面
/*1.标量子查询（单行子查询）

2.列子查询（多行子查询）
3.行子查询（多列多行）
特点：
①子查询放在小括号内
②子查询一般放在条件的右侧
③标量子查询，一般搭配着单行操作符使用
> < >= <= <>

列子查询，一般搭配着多行操作符使用
IN、ANY/SOME、ALL

④子查询的执行优先于主查询执行，主查询的条件用到了子查询的结果
*/
USE myemployees;
#1.标量子查询
#案例1：谁的工资比Abel高？
#①查询Abel的工资
SELECT salary
FROM employees
WHERE last_name = 'Abel'

#②查询员工的信息，满足 salary>①结果
SELECT *
FROM employees
WHERE salary>(

	SELECT salary
	FROM employees
	WHERE last_name = 'Abel'

);

SELECT last_name
FROM employees
WHERE salary>(
	SELECT salary
	FROM employees
	WHERE last_name='Abel');


#案例2：返回job_id与141号员工相同，salary比143号员工多的员工 姓名，job_id 和工资
#①查询141号员工的job_id
SELECT job_id
FROM employees
WHERE employee_id=141;
#②查询143号员工的salary
SELECT salary
FROM employees
WHERE employee_id=143;
#③查询员工的姓名，job_id和工资，要求job_id=①，并且salary>②
SELECT last_name,job_id,salary
FROM employees
WHERE job_id=(
	SELECT job_id
	FROM employees
	WHERE employee_id=141)
AND salary>(
	SELECT salary
	FROM employees
	WHERE employee_id=143);

#案例3：返回公司工资最少的员工的last_name,job_id和salary
#①查询工资最少的员工的工资
SELECT MIN(salary)
FROM employees;
#②查询last_name,job_id和salary，要求salary=①
SELECT last_name,job_id,salary
FROM employees
WHERE salary=(
	SELECT MIN(salary)
	FROM employees
);


#案例4：查询最低工资大于50号部门最低工资的部门id和其最低工资
#①查询50号部门的最低工资
SELECT MIN(salary)
FROM employees
WHERE department_id=50;
#②查询每个部门的最低工资
SELECT department_id,MIN(salry)
FROM employees
GROUP BY department_id;
#③筛选②，满足min(salary)>①
SELECT department_id,MIN(salary)
FROM employees
GROUP BY department_id
HAVING MIN(salary)>(
	SELECT MIN(salary)
	FROM employees
	WHERE department_id=50
);

#非法使用标量子查询
#子查询结果不是一行一列


#2.列子查询（多行子查询）
#案例1：返回location_id是1400或1700的部门中的所有员工姓名
#①查询location_id是1400或1700的部门编号
SELECT DISTINCT department_id
FROM departments
WHERE location_id IN(1400,1700);
#②查询员工姓名，要求部门号是①列表中的某一个
SELECT last_name
FROM employees 
WHERE department_id IN (
SELECT department_id
FROM departments
WHERE location_id IN (1400,1700)
);
#或
SELECT last_name
FROM employees 
WHERE department_id = ANY (
SELECT department_id
FROM departments
WHERE location_id IN (1400,1700)
);

#案例2：返回其它工种中比job_id为‘IT_PROG’工种任一工资低的员工的员工号、姓名、job_id 以及salary
#①查询jod_id为‘IT_PROG’工种的任一工资
SELECT DISTINCT salary
FROM employees
WHERE job_id='IT_PROG';
#②查询员工的员工号、姓名、job_id 以及salary，salary<any(①)的任意一个
SELECT employee_id,last_name,job_id,salary
FROM employees
WHERE salary < ANY (
	SELECT DISTINCT salary
	FROM employees
	WHERE job_id='IT_PROG'
)AND job_id<>'IT_PROG';
#或
SELECT employee_id,last_name,job_id,salary
FROM employees
WHERE salary <(
	SELECT  MAX(salary)
	FROM employees
	WHERE job_id='IT_PROG'
)AND job_id<>'IT_PROG';

#案例3：返回其它部门中比job_id为‘IT_PROG’部门所有工资都低的员工的员工号、姓名、job_id 以及salary
#①
SELECT DISTINCT salary
FROM employees
WHERE job_id='IT_PROG';
#②
SELECT employee_id,last_name,job_id,salary
FROM employees
WHERE salary<ALL(
	SELECT DISTINCT salary
	FROM employees
	WHERE job_id='IT_PROG'
);
#或
SELECT employee_id,last_name,job_id,salary
FROM employees
WHERE salary<(
	SELECT MIN(salary)
	FROM employees
	WHERE job_id='IT_PROG'
);


#3.行子查询（结果集一行多列或多行多列）
#案例：查询员工编号最小并且工资最高的员工信息
SELECT *
FROM employees
WHERE employee_id=(
	SELECT MIN(employee_id)
	FROM employees
)
AND salary=(
	SELECT MAX(salary)
	FROM employees
);
#行子查询
SELECT *
FROM employees
WHERE (employee_id,salary)=(
	SELECT MIN(employee_id),MAX(salary)
	FROM employees
);


#二、select后面
#案例1：查询每个部门的员工个数
SELECT d.*,(
	SELECT COUNT(*)
	FROM employees e
	WHERE e.department_id=d.`department_id`
) 个数
FROM departments d;

SELECT department_id,COUNT(*)
FROM employees
GROUP BY department_id;

#案例2：查询员工号=102的部门名
#子查询
SELECT e.*,(
	SELECT department_name
	FROM departments d
	WHERE e.`department_id`=d.`department_id`
) 部门名
FROM employees e
WHERE e.`employee_id`=102;

#SQL99外连接
SELECT d.`department_name`
FROM departments d
LEFT OUTER JOIN employees e
ON d.`department_id`=e.`department_id`
WHERE e.`employee_id`=102;


#三、from后面
/*
将子查询结果充当一张表，要求必须起别名
*/

#案例：查询每个部门的平均工资的工资等级
#①查询每个部门的平均工资
SELECT department_name,ROUND(AVG(salary))
FROM departments d
INNER JOIN employees e
ON d.`department_id`=e.`department_id`
GROUP BY d.`department_id`;
#②连接①的结果集和job_grades表，筛选条件平均工资between lowest_sal and highest_sal
SELECT ag_dep.*,j.`grade_level`
FROM (
	SELECT department_name,ROUND(AVG(salary)) s
	FROM departments d
	INNER JOIN employees e
	ON d.`department_id`=e.`department_id`
	GROUP BY d.`department_id`
) ag_dep
INNER JOIN job_grades j
ON ag_dep.s BETWEEN j.`lowest_sal` AND j.`highest_sal`;



#四、exists后面（相关子查询）
/*
语法：exists（完整的查询语句）
结果：当查询有结果返回1，无结果则返回0
*/
SELECT EXISTS (SELECT employee_id FROM employees WHERE salary=300000);
#案例1：查询有员工的部门名
SELECT department_name
FROM departments d
WHERE EXISTS(SELECT * FROM employees e WHERE d.`department_id`=e.`department_id`); 

#in实现
SELECT department_name
FROM departments d
WHERE department_id IN(
	SELECT department_id
	FROM employees
);

#案例2：查询没有女朋友的男神信息
#in实现
SELECT bo.*
FROM boys bo
WHERE bo.`id` NOT IN(
	SELECT boyfriend_id
	FROM beauty b
);

#exists
SELECT bo.*
FROM boys bo
WHERE NOT EXISTS(
	SELECT boyfriend_id
	FROM beauty b
	WHERE bo.`id`=b.`boyfriend_id`
);


USE myemployees;
#exercise
#1.查询和 Zlotkey 相同部门的员工姓名和工资
SELECT last_name,salary
FROM employees
WHERE department_id=(
	SELECT department_id
	FROM employees
	WHERE last_name='Zlotkey'
);

#2.查询工资比公司平均工资高的员工的员工号，姓名和工资。
SELECT employee_id,last_name,salary
FROM employees
WHERE salary>(
	SELECT AVG(salary)
	FROM employees
);

#3.查询各部门中工资比本部门平均工资高的员工的员工号, 姓名和工资
SELECT employee_id,last_name,salary
FROM employees e
INNER JOIN(	
	SELECT AVG(salary) s,department_id
	FROM employees
	GROUP BY department_id
) e1
ON e.`department_id`=e1.`department_id`
WHERE salary>e1.s;

#4.查询和姓名中包含字母 u 的员工在相同部门的员工的员工号和姓名
SELECT employee_id,last_name,department_id
FROM employees
WHERE department_id IN (
	SELECT DISTINCT department_id
	FROM employees
	WHERE last_name LIKE '%u%'
);

#5.查询在部门的 location_id 为 1700 的部门工作的员工的员工号
SELECT employee_id,department_id
FROM employees e
WHERE e.`department_id` IN (
	SELECT department_id
	FROM departments
	WHERE location_id=1700
	ORDER BY department_id
);

#6.查询管理者是 King 的员工姓名和工资
SELECT last_name,salary,manager_id
FROM employees
WHERE manager_id IN(
	SELECT employee_id
	FROM employees
	WHERE last_name LIKE '%K_ing%'
);

#7.查询工资最高的员工的姓名，要求 first_name 和 last_name 显示为一列，列名为 姓.名
SELECT CONCAT(first_name,'.',last_name) `姓.名`
FROM employees
WHERE salary=(
	SELECT MAX(salary)
	FROM employees
);
#或
SELECT CONCAT(first_name,'.',last_name) `姓.名`
FROM employees
WHERE salary>= ALL(
	SELECT salary
	FROM employees
);