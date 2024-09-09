#进阶6：连接查询
/*
含义：又称多表查询，当查询的字段来自于多个表时，就会用到连接查询
笛卡尔乘积现象：表1有m行，表2有n行，结果=m*n行

发生原因：没有有效的连接条件
如何避免：添加有效的连接条件

分类：
	按年代分类：
	sql92标准：仅仅支持内连接
	sql99标准（推荐）：支持内连接+外连接（左外和右外）+交叉连接
	
	按功能分类：
		内连接：
			等值连接
			非等值连接
			自连接
		外连接：
			左外连接
			右外连接
			全外连接
		交叉连接
*/

SELECT * FROM beauty;
SELECT * FROM boys;

SELECT NAME,boyName FROM boys,beauty
WHERE beauty.boyfriend_id=boys.id;

#一、sql92连接
#1.等值连接
/*
①多表等值连接的结果为多表的交集部分
②n表连接，至少需要n-1个连接条件
③多表的顺序没有要求
④一般需要为表起别名
⑤可以搭配前面介绍的所有子句使用，比如排序、分组、筛选
*/

#案例1：查询女神名和对应的男神名
SELECT NAME,boyName
FROM boys,beauty
WHERE beauty.boyfriend_id=boys.id;

#案例2：查询员工名和对应的部门名
SELECT CONCAT(first_name,' ',last_name) 姓名,department_name 部门名
FROM employees,departments
WHERE employees.department_id=departments.department_id;

#1.1为表起别名
/*
①提高语句简洁度
②区分多个重名的字段
注意：如果为表起别名，则查询的字段就不能使用原来的表名去限定
*/
#查询员工名、工种号、工种名
SELECT last_name,e.`job_id`,job_title
FROM employees e,jobs j
WHERE e.`job_id`=j.`job_id`;

#1.2两个表的顺序可以调换
#查询员工名、工种号、工种名
SELECT last_name,e.`job_id`,job_title
FROM jobs j,employees e
WHERE e.`job_id`=j.`job_id`;

#1.3可以加筛选
#案例1：查询有奖金的员工名、部门名
SELECT last_name,department_name,commission_pct
FROM employees e,departments d
WHERE e.`department_id`=d.`department_id` AND e.`commission_pct` IS NOT NULL;

#案例2：查询城市名中第二个字符为o的对应的部门名和城市名
SELECT department_name,city
FROM departments d,locations l
WHERE city LIKE '_o%' AND d.`location_id`=l.`location_id`;

#1.4可以加分组
#案例1：查询每个城市的部门个数
SELECT COUNT(*) 个数,city
FROM departments d,locations l
WHERE d.`location_id`=l.`location_id`
GROUP BY l.`city`;

#案例2：查询有奖金的每个部门的部门名和部门的领导编号和该部门的最低工资
SELECT department_name,d.`manager_id`,MIN(salary)
FROM employees e,departments d
WHERE e.`department_id`=d.`department_id` AND e.`commission_pct` IS NOT NULL
GROUP BY department_name;

#1.5可以加排序
#案例：查询每个工种的工种名和员工的个数，并且按员工个数降序
SELECT job_title,COUNT(*)
FROM employees e,jobs j
WHERE e.`job_id`=j.`job_id`
GROUP BY job_title
ORDER BY COUNT(*) DESC;

#1.6多表连接
#案例：查询员工名、部门名和所在的城市
SELECT last_name,department_name,city
FROM employees e,departments d,locations l
WHERE e.`department_id`=d.`department_id`
AND d.`location_id`=l.`location_id`
AND city LIKE 's%'
ORDER BY department_name DESC;


#2.非等值连接
#案例1：查询员工的工资和工资级别
SELECT salary,grade_level
FROM employees e,job_grades j
WHERE salary BETWEEN j.`lowest_sal` AND j.`highest_sal`
AND grade_level='A';

SELECT * FROM job_grades;
#创建员工等级表 from employees
CREATE TABLE job_grades
(grade_level VARCHAR(3),
 lowest_sal  INT,
 highest_sal INT);

INSERT INTO job_grades
VALUES ('A', 1000, 2999);

INSERT INTO job_grades
VALUES ('B', 3000, 5999);

INSERT INTO job_grades
VALUES('C', 6000, 9999);

INSERT INTO job_grades
VALUES('D', 10000, 14999);

INSERT INTO job_grades
VALUES('E', 15000, 24999);

INSERT INTO job_grades
VALUES('F', 25000, 40000);


#3.自连接
#自己连接自己，例如employees中通过manager_id再找到表中的领导的名字
#案例：查询员工名和上级的名称
SELECT e.`employee_id` 员工编号,e.`last_name` 员工姓名,m.`employee_id` 领导编号,m.`last_name` 领导姓名
FROM employees e,employees m
WHERE e.`manager_id`=m.`employee_id`;



#exercise1
#1.显示员工表的最大工资，工资平均值
SELECT MAX(salary),AVG(salary)
FROM employees;

#2.查询员工表的employee_id，job_id，last_name，按department_id降序，salary升序
SELECT employee_id,job_id,last_name,department_id,salary
FROM employees
ORDER BY department_id DESC,salary ASC;

#3.查询员工表的job_id中包换a和e的，并且a在e的前面
SELECT job_id
FROM employees
WHERE job_id LIKE '%a%e%';

#4.
SELECT s.name,g.name,r.score
FROM student s,grade g,result r
WHERE s.id=r.studentNo AND s.gradeId=g.id;

#5.显示当前日期，以及去前后空格，截取子字符串的函数
SELECT NOW();


SELECT * FROM departments;
#exercise2 连接查询
#1.显示所有员工的姓名，部门号和部门名称。
SELECT last_name,e.`department_id`,department_name
FROM employees e,departments d
WHERE e.`department_id`=d.`department_id`;

#2.查询 90 号部门员工的 job_id 和 90 号部门的 location_id
SELECT e.`job_id`,d.`location_id`
FROM employees e,departments d
WHERE d.`department_id`=e.`department_id`
AND e.`department_id`=90;

#3.选择所有有奖金的员工的last_name , department_name , location_id , city
SELECT last_name,department_name,d.location_id,city
FROM employees e,departments d,locations l
WHERE commission_pct IS NOT NULL
AND e.`department_id`=d.`department_id`
AND d.`location_id`=l.`location_id`;

#4.选择city在Toronto工作的员工的last_name , job_id , department_id , department_name
SELECT last_name,e.job_id,e.department_id,department_name
FROM employees e,departments d,locations l
WHERE city='Toronto'
AND e.`department_id`=d.`department_id`
AND l.`location_id`=d.`location_id`;

#5.查询每个工种、每个部门的部门名、工种名和最低工资
SELECT job_title,department_name,MIN(salary)
FROM employees e,jobs j,departments d
WHERE e.`department_id`=d.`department_id`
AND e.`job_id`=j.`job_id`
GROUP BY job_title,department_name;

#6.查询每个国家下的部门个数大于 2 的国家编号
SELECT country_id,COUNT(*) 部门个数
FROM locations l,departments d
WHERE d.`location_id`=l.`location_id`
GROUP BY country_id
HAVING COUNT(*)>2;

#7.选择指定员工的姓名，员工号，以及他的管理者的姓名和员工号，结果类似于下面的格式
#employees Emp# manager Mgr#
#kochhar   101   king    100
SELECT e.last_name employees,e.employee_id "Emp#",m.`last_name` manager,m.`employee_id` "Mgr#"
FROM employees e,employees m
WHERE e.`manager_id`=m.`employee_id`;