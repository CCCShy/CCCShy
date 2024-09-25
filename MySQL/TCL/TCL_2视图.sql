#视图
/*
含义：虚拟表，和普通表一样使用
mysql5.1版本出现的新特性，是通过表动态生成的数据

比如：舞蹈班和普通班级对比
	创建关键字           是否实际占用物理空间	使用
视图	create view		只保存了sql逻辑		增删改查，一般不能增删改
表	create table		保存实际数据		增删改查
*/

#案例：查询姓张的学生名和专业名
SELECT stuname,majorname
FROM stuinfo s
INNER JOIN major m
ON s.`id`=m.`id`
WHERE s.`stuName` LIKE '张%';

CREATE VIEW v1
AS
SELECT stuname,majorname
FROM stuinfo s
INNER JOIN major m
ON s.`id`=m.`id`;

SELECT * FROM v1 WHERE stuName LIKE '张%';


#一、创建视图
/*
语法：
create view 视图
as
查询语句;
*/
USE myemployees;
#1.查询邮箱中包含a字符的员工名、部门名和工种信息
#①创建
CREATE VIEW myv1
AS
SELECT last_name,department_name,job_title
FROM employees e
JOIN departments d ON e.department_id  = d.department_id
JOIN jobs j ON j.job_id  = e.job_id;
#②使用
SELECT * FROM myv1 WHERE last_name LIKE '%a%';

#自己的
CREATE VIEW v2
AS
SELECT last_name,department_name,j.*,email
FROM employees e
LEFT JOIN departments d ON e.`department_id`=d.`department_id`
LEFT JOIN jobs j ON e.`job_id`=j.`job_id`;
SELECT * FROM v2 WHERE email LIKE '%a%';

#2.查询各部门的平均工资级别
#①创建视图查看每个部门的平均工资
CREATE VIEW myv2
AS
SELECT AVG(salary) ag,department_id
FROM employees
GROUP BY department_id;
#②使用
SELECT myv2.`ag`,g.grade_level
FROM myv2
JOIN job_grades g
ON myv2.`ag` BETWEEN g.`lowest_sal` AND g.`highest_sal`;

#自己的
CREATE VIEW v3
AS
SELECT d.*,AVG(salary) s
FROM employees e
INNER JOIN departments d
ON d.`department_id`=e.`department_id`
GROUP BY e.department_id;

SELECT v3.*,j.`grade_level`
FROM v3
INNER JOIN job_grades j
ON s BETWEEN j.`lowest_sal` AND j.`highest_sal`;

#3.查询平均工资最低的部门信息
SELECT * FROM myv2 ORDER BY ag LIMIT 1;

#自己的
SELECT * FROM v3 WHERE s=(
	SELECT MIN(s)
	FROM v3);
SELECT * FROM v3 ORDER BY s LIMIT 1;

#4.查询平均工资最低的部门名和工资
CREATE VIEW myv3
AS
SELECT * FROM myv2 ORDER BY ag LIMIT 1;
SELECT d.*,m.ag
FROM myv3 m
JOIN departments d
ON m.`department_id`=d.`department_id`;


#自己的
SELECT department_name,s FROM v3 WHERE s=(SELECT MIN(s) FROM v3);




#二、视图的修改
#方式一：
/*
create or replace view
as
查询语句;
*/
SELECT * FROM v3;
CREATE OR REPLACE VIEW v3
AS
SELECT AVG(salary),job_id
FROM employees
GROUP BY job_id;

#方式二：
/*
语法：
alter view 视图名
as
查询语句;
*/
ALTER VIEW v3
AS
SELECT d.*,AVG(salary) s
FROM employees e
INNER JOIN departments d
ON d.`department_id`=e.`department_id`
GROUP BY e.department_id;


#三、删除视图
/*
语法：
drop view 视图名,视图名,...;
*/
DROP VIEW v2,v3;


#四、查看视图
DESC v3;
SHOW CREATE VIEW v3;




#五、视图的更新
CREATE OR REPLACE VIEW myv1
AS
SELECT last_name,email,salary*12*(1+IFNULL(commission_pct,0)) 'annual salary'
FROM employees;

CREATE OR REPLACE VIEW myv1
AS
SELECT last_name,email
FROM employees;

SELECT * FROM myv1;
SELECT * FROM employees;
#1.插入
INSERT INTO myv1 VALUES('张飞','zf@qq.com');

#2.修改
UPDATE myv1 SET last_name='张无忌' WHERE last_name='张飞';

#3.删除
DELETE FROM myv1 WHERE last_name='张无忌';

#具备以下特点的视图是不允许更新
/*
①包含以下关键字的sql语句：分组函数、distinct、group by、having、union或者union all
②常量视图
③Select中包含子查询
④join
⑤from一个不能更新的视图
⑥where子句的子查询引用了from子句中的表
*/
#①包含以下关键字的sql语句：分组函数、distinct、group by、having、union或者union all
CREATE OR REPLACE VIEW myv2
AS
SELECT MAX(salary) m,department_id
FROM employees
GROUP BY department_id;
SELECT * FROM myv2;
#更新
UPDATE myv2 SET m=9000 WHERE department_id=10;#不允许更新

#②常量视图
CREATE OR REPLACE VIEW myv2
AS
SELECT 'john' NAME;
SELECT * FROM myv2;
#更新
UPDATE myv2 SET NAME='lucy';#不能更新

#③Select中包含子查询
CREATE OR REPLACE VIEW myv3
AS
SELECT department_id,(SELECT MAX(salary) FROM employees) 最高工资
FROM departments;
#更新
SELECT * FROM myv3;
UPDATE myv3 SET 最高工资=100000;#不能更新

#④join
CREATE OR REPLACE VIEW myv4
AS
SELECT last_name,department_name
FROM employees e
JOIN departments d
ON e.department_id=d.department_id;
#更新
SELECT * FROM myv4;
UPDATE myv4 SET last_name='张飞' WHERE last_name='Whalen';#可以改变值
INSERT INTO myv4 VALUES('陈真','xxxx');#不能更新

#⑤from一个不能更新的视图
CREATE OR REPLACE VIEW myv5
AS
SELECT * FROM myv2;
#更新
SELECT * FROM myv5;
UPDATE myv5 SET NAME='sun';#不能更新

#⑥where子句的子查询引用了from子句中的表
CREATE OR REPLACE VIEW myv6
AS
SELECT last_name,email,salary
FROM employees
WHERE employee_id IN(
	SELECT manager_id
	FROM employees
	WHERE manager_id IS NOT NULL
);
#更新
SELECT * FROM myv6;
UPDATE myv6 SET salary=10000 WHERE last_name='k_ing';











#exercise
#1.创建视图 emp_v1,要求查询电话号码以‘011’开头的员工姓名和工资、邮箱
CREATE VIEW emp_v1
AS
SELECT last_name,salary,email
FROM employees
WHERE phone_number LIKE'011%';
SELECT * FROM emp_v1;

#2.要求将视图 emp_v1 修改为查询电话号码以‘011’开头的并且邮箱中包含 e 字符的员工姓名和邮箱、电话号码
CREATE OR REPLACE VIEW emp_v1
AS
SELECT last_name,email,phone_number
FROM employees
WHERE phone_number LIKE '011%' AND email LIKE '%e%';
SELECT * FROM emp_v1;

#3.向 emp_v1 插入一条记录，是否可以？

#4.修改刚才记录中的电话号码为‘0119’

#5.删除刚才记录

#6.创建视图 emp_v2，要求查询部门的最高工资高于 12000 的部门信息
CREATE VIEW emp_v2
AS
SELECT d.*,MAX(salary) m
FROM employees e
JOIN departments d ON e.department_id=d.department_id
GROUP BY e.department_id
HAVING m>12000;
SELECT * FROM emp_v2;

#7.向 emp_v2 中插入一条记录，是否可以？

#8.删除刚才的 emp_v2 和 emp_v1
DROP VIEW emp_v1,emp_v2;








CREATE TABLE IF NOT EXISTS book(
	bid INT PRIMARY KEY,
	bname VARCHAR(20) UNIQUE NOT NULL,
	price FLOAT DEFAULT 10,
	btypeId INT,
	CONSTRAINT fk_book_bookType FOREIGN KEY(btypeId) REFERENCES bookType(id)
);

CREATE TABLE bookType(
	id INT,
	NAME VARCHAR(20)
);
ALTER TABLE bookType MODIFY COLUMN id INT PRIMARY KEY;
INSERT INTO bookType VALUES(1,'C');

SET autocommit=0;
START TRANSACTION;
INSERT INTO book VALUES(1,'C language',20,1);
COMMIT;

CREATE VIEW v1
AS
SELECT bname,NAME
FROM book b
JOIN bookType t
ON b.btypeId=t.id
WHERE price>100;


CREATE OR REPLACE VIEW v1
AS
SELECT bname,price
FROM book b
JOIN bookType t
ON b.btypeId=t.id
WHERE price BETWEEN 90 AND 120;

DROP VIEW v1;