#进阶1：基础查询
/*
语法：
select 查询列表
from 表名;

特点：
1.查询列表可以是：表中的字段、常量指、表达式、函数
2.查询的结果是一个虚拟的表格
*/

USE myemployees;

#1.查询表中的单个字段
SELECT last_name FROM employees;

#2.查询表中的多个字段
SELECT last_name,salary,email FROM employees;

#3.查询表中的所有字段
SELECT 
  `employee_id`,
  `first_name`,
  `last_name`,
  `email`,
  `phone_number`,
  `job_id`,
  `salary`,
  `commission_pct`,
  `manager_id`,
  `department_id`,
  `hiredate` 
FROM
  employees ;
  
SELECT * FROM employees;

#4.查询常量值
SELECT 100;
SELECT 'john';

#5.查询表达式
SELECT 100%98;

#6.查询函数
SELECT VERSION();

#7.起别名
#方法一
SELECT 100%98 AS 结果;
SELECT last_name AS 姓,first_name AS 名 FROM employees;
#方法二
SELECT last_name 姓,first_name 名 FROM employees;

#8.去重

#案例：查询员工表中涉及到的所有的部门编号
SELECT DISTINCT department_id FROM employees;

#9.+号的作用
/*
mysql中的+号只有一个功能：运算符
select 100+90;两个操作数都为数值型，则做加法运算
select '123'+90;只要其中一方为字符型，试图将字符型数值转换为数值型
			如果转换成功，则继续做加法运算
select 'john'+90;	如果转换失败，则将字符型数值转换为0
select null+10;	 只要其中一方为null，则结果肯定为null
*/

SELECT CONCAT('a','b','c') AS 结果;

#案例：查询员工名和姓连接成一个字段，并显示为姓名
SELECT CONCAT(last_name,' ',first_name) AS 姓名 FROM employees;




#exercise
#1下面的语句是否可以执行成功   答：可以
SELECT last_name , job_id , salary AS sal
FROM employees;

#2下面的语句是否可以执行成功   答：可以
SELECT * FROM employees;

#3
SELECT employee_id,last_name,salary*12 "ANNUAL SALARY" FROM employees;

#4显示表 departments 的结构，并查询其中的全部数据
DESC departments;
SELECT * FROM departments;

#5显示出表 employees 中的全部 job_id（不能重复）
SELECT DISTINCT job_id FROM employees;

#6显示出表 employees 的全部列，各个列之间用逗号连接，列头显示成 OUT_PUT
SELECT 
  IFNULL(commission_pct, 0) 奖金率,
  commission_pct  
FROM
  employees ;

SELECT 
  CONCAT(
    `employee_id`,
    ',',
    `first_name`,
    ',',
    `last_name`,
    ',',
    `email`,
    ',',
    `phone_number`,
    ',',
    `job_id`,
    ',',
    `salary`,
    ',',
    IFNULL(`commission_pct`,0),
    ',',
    IFNULL(`manager_id`,0),
    ',',
    IFNULL(`department_id`,0),
    ',',
    `hiredate`
  ) AS OUT_PUT 
FROM
  employees ;

