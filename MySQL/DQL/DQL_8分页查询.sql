#进阶8：分页查询
/*
应用场景：当要显示的数据，一页显示不全，需要分页提交sql请求
语法：
	select 查询列表
	from 表
	【join type join 表2
	on 连接条件
	where 筛选条件
	group by 分组字段
	having 分组后的筛选
	order by 排序的字段】
	limit offset,size
	
	offset：要显示条目的起始索引（其实索引从0开始）
	size 要显示的条目个数
特点：
	①limit语句放在查询语句的最后，在执行上和语法上均在最后
	②公式
	要显示的页数page，每页的条目数size
	
	select 查询列表
	from 表
	limit (page-1)*size,size
*/
#案例1：查询前5条员工信息
SELECT * FROM employees LIMIT 0,5;
SELECT * FROM employees LIMIT 5;

#案例2：查询第11条至第25条
SELECT * FROM employees LIMIT 10,15;

#案例3：有奖金的员工信息，并且工资较高的前10名显示出来
SELECT * 
FROM employees
WHERE commission_pct IS NOT NULL
ORDER BY salary DESC
LIMIT 10;
/*
select 查询列表
from 表
连接类型 join 表
on 连接条件
where 筛选条件
group by 分组列表
having 分组后筛选
order by 排序列表
limit 偏移，条目数
*/



#exircise
#1.查询工资最低的员工信息：last_name，salary
SELECT last_name,salary
FROM employees
WHERE salary=(
	SELECT MIN(salary)
	FROM employees
);

#2.查询平均工资最低的部门信息
#方式一：
#①各部门平均工资
SELECT AVG(salary),department_id
FROM employees
GROUP BY department_id;
#②查询①结果上的最低平均工资
SELECT MIN(ag)
FROM (
	SELECT AVG(salary) ag,department_id
	FROM employees
	GROUP BY department_id
) ag_dep;
#③查询哪个部门的平均工资=②
SELECT AVG(salary),department_id
FROM employees
GROUP BY department_id
HAVING AVG(salary)=(
	SELECT MIN(ag)
	FROM (
		SELECT AVG(salary) ag,department_id
		FROM employees
		GROUP BY department_id
	) ag_dep
);
#④查询部门信息
SELECT d.*
FROM departments d
WHERE d.`department_id`=(
SELECT department_id
FROM employees
GROUP BY department_id
HAVING AVG(salary)=(
		SELECT MIN(ag)
		FROM (
			SELECT AVG(salary) ag,department_id
			FROM employees
			GROUP BY department_id
		) ag_dep
	)
);
#方式二：
#①各部门的平均工资
SELECT AVG(salary),department_id
FROM employees
GROUP BY department_id;
#②求出最低平均工资的部门编号
SELECT department_id
FROM employees
GROUP BY department_id
ORDER BY AVG(salary)
LIMIT 1;
#③查询部门信息
SELECT *
FROM departments
WHERE department_id=(
	SELECT department_id
	FROM employees
	GROUP BY department_id
	ORDER BY AVG(salary)
	LIMIT 1
);
#自己的方法
SELECT d.*
FROM departments d
INNER JOIN(
	SELECT AVG(salary) s,department_id
	FROM employees
	GROUP BY department_id) aa
ON d.`department_id`=aa.`department_id`
WHERE aa.s <=ALL(
	SELECT AVG(salary)
	FROM employees
	GROUP BY department_id
);

#3.查询平均工资最低的部门信息和该部门的平均工资
SELECT d.*,aa.s
FROM departments d
INNER JOIN(
	SELECT AVG(salary) s,department_id
	FROM employees
	GROUP BY department_id) aa
ON d.`department_id`=aa.`department_id`
WHERE aa.s <=ALL(
	SELECT AVG(salary)
	FROM employees
	GROUP BY department_id
);

#4.查询平均工资最高的job信息
SELECT *
FROM jobs
WHERE job_id=(
	SELECT job_id
	FROM employees
	GROUP BY job_id
	ORDER BY AVG(salary) DESC
	LIMIT 1
);	
#自己的方法
#①查询所有job的平均工资
SELECT AVG(salary),job_id
FROM employees
GROUP BY job_id;
#②查询工资最高job信息
SELECT j.*
FROM jobs j
INNER JOIN (
	SELECT AVG(salary) s,job_id
	FROM employees
	GROUP BY job_id
	) aa
ON j.`job_id`=aa.`job_id`
WHERE aa.s<=ALL(
	SELECT AVG(salary)
	FROM employees
	GROUP BY job_id
);

#5.查询平均工资高于公司平均水平的部门有哪些
#1.查询公司平均水平
SELECT AVG(salary)
FROM employees;
#2.
SELECT *
FROM departments
WHERE department_id IN(
	SELECT a.department_id
	FROM(
		SELECT AVG(salary) s,department_id
		FROM employees
		GROUP BY department_id) a
	WHERE a.s>(
		SELECT AVG(salary)
		FROM employees
	)
);

#6.查询出公司中所有manager的详细信息
#①查询manager的id
SELECT DISTINCT manager_id
FROM employees;
#②查询manger的详细信息
SELECT *
FROM employees
WHERE employee_id IN(
	SELECT DISTINCT manager_id
	FROM employees
);

#7.各个部门中，最高工资中最低的那个部门的最低工资是多少
#①查询每个部门中最高工资
SELECT MAX(salary),department_id
FROM employees
GROUP BY department_id; 
#②查询①中最低工资的部门
SELECT department_id
FROM (
	SELECT MAX(salary) s,department_id
	FROM employees
	GROUP BY department_id) a
ORDER BY a.s
LIMIT 1;
#③查询②中的部门的最低工资
SELECT MIN(salary)
FROM employees
WHERE department_id=(
SELECT department_id
	FROM (
		SELECT MAX(salary) s,department_id
		FROM employees
		GROUP BY department_id) a
	ORDER BY a.s
	LIMIT 1
);

#8.查询平均工资最高的部门的manager的详细信息：last_name，department_id，email，salary
#①查询每个部门的平均工资
SELECT AVG(salary),department_id
FROM employees
GROUP BY department_id;
#②查询①中平均工资最高的department_id
SELECT department_id
FROM (
	SELECT AVG(salary) s,department_id
	FROM employees
	GROUP BY department_id) a
ORDER BY a.s DESC
LIMIT 1;
#③查询②中部门的manager的信息
SELECT last_name,department_id,email,salary
FROM employees
WHERE employee_id IN(
	SELECT DISTINCT manager_id
	FROM employees
	WHERE department_id=(
		SELECT department_id
		FROM (
			SELECT AVG(salary) s,department_id
			FROM employees
			GROUP BY department_id) a
		ORDER BY a.s DESC
		LIMIT 1
	)
);