#进阶4：常见函数:分组函数
#二、分组函数
/*
功能：用作统计使用，又称为聚合函数或统计函数或组函数

分类：
sum：求和、avg：平均值、max：最大值、min：最小值、count：计算个数
特点：
1.sum、avg一般用于处理数值型，max、min、count可以处理任何类型
2.以上分组函数均忽略null值
3.可以和distinct搭配实现去重运算
4.count函数的单独介绍
5.和分组函数一同查询的字段要求是group by后的字段

USE myemployees;
SELECT DATABASE();
*/

#1.简单使用
SELECT SUM(salary) FROM employees;
SELECT AVG(salary) FROM employees;
SELECT MAX(salary) FROM employees;
SELECT MIN(salary) FROM employees;
SELECT COUNT(salary) FROM employees;
SELECT SUM(salary) 和,ROUND(AVG(salary),1) 平均值,MAX(salary) 最高,MIN(salary) 最低,COUNT(salary) 个数 FROM employees;

#2.参数支持哪些类型
SELECT SUM(last_name),AVG(last_name) FROM employees;#不报错，但是没有意义
SELECT SUM(hiredate),AVG(hiredate) FROM employees;#不报错，无意义
SELECT MAX(last_name),MIN(last_name) FROM employees;#名字可以进行排序
SELECT MAX(hiredate),MIN(hire_date) FROM employees;#日期可以进行排序
SELECT COUNT(commission_pct) FROM employees;#只计算不为空的值的个数，空的值忽略
SELECT COUNT(last_name) FROM employees;

#3.忽略NULL值
SELECT SUM(commission_pct),AVG(commission_pct),SUM(commission_pct)/35,SUM(commission_pct)/107 FROM employees;#max和avg均忽略null值进行计算
SELECT MAX(commission_pct),MIN(commission_pct) FROM employees;#忽略null

#4.和distinct搭配
SELECT SUM(DISTINCT salary),SUM(salary) FROM employees;
SELECT COUNT(DISTINCT salary),COUNT(salary) FROM employees;

#5.count函数的详细介绍
SELECT COUNT(salary) FROM employees;
SELECT COUNT(*) FROM employees; #统计总行数
SELECT COUNT(1) FROM employees; #相当于给表加了一列常量值，统计的是总行数
/*
MYISAM存储引擎下，count(*)的效率高
INNOB存储引擎下，count(*)和count(1)的效率差不多，比count(字段)要高一些，因为字段要判断是否为NULL
*/

#6.和分组函数一同查询的字段有限制
SELECT AVG(salary),employee_id FROM employees;#表格格式不对

SELECT DISTINCT job_id FROM employees;
#1.查询各 job_id 的员工工资的最大值，最小值，平均值，总和，并按 job_id 升序
CASE(job_id)
WHEN AC_ACCOUNT THEN MAX(salary),MIN(salary),AVG(salary),SUM(salary) 
END
FROM employees;
#2.查询员工最高工资和最低工资的差距（DIFFERENCE）
SELECT MAX(salary)-MIN(salary) DIFFRENCE FROM employees;

#3.查询各个管理者手下员工的最低工资，其中最低工资不能低于 6000，没有管理者的员工不计算在内


#4.查询所有部门的编号，员工数量和工资平均值,并按平均工资降序


#5.选择具有各个 job_id 的员工人数


#查询员工最大入职天数和最小入职天数的差值
SELECT DATEDIFF(MAX(hiredate),MIN(hiredate)) FROM employees;

#查询部门编号为90的员工个数
SELECT COUNT(*) FROM employees WHERE department_id = 90;