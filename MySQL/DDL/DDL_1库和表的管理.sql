#DDL：数据定义语言
/*
库和表的管理
一、库的管理
创建、修改、删除
二、表的管理
创建、修改、删除

创建：create
修改：alter
删除：drop
*/

#一、库的管理
#1.库的创建
/*
语法：
create database [if not exists] 库名;
*/

#案例：创建库books
CREATE DATABASE IF NOT EXISTS books;



#2.库的修改
RENAME DATABASE books TO Books;#修改库名：已废弃，不安全

#可以更改库的字符集
ALTER DATABASE books CHARACTER SET utf8;



#3.库的删除
DROP DATABASE IF EXISTS books;




#二、表的管理
#1.表的创建★
/*
create table 表名(
	列名 列的类型【(长度）约束】,
	列名 列的类型【(长度）约束】,
	列名 列的类型【(长度）约束】,
	...
	列名 列的类型【(长度）约束】
)
*/
SELECT DATABASE();
USE myemployees;
#案例：创建book
CREATE TABLE book(
	id INT,#编号
	bName VARCHAR(20),#书名
	price DOUBLE,#价格
	authorID INT,#作者编号
	publishDate DATETIME#出版日期
);
DESC book;

#案例：创建办author
CREATE TABLE IF NOT EXISTS author(
	id INT,
	authorName VARCHAR(20),
	nation VARCHAR(10)
);
DESC author;



#2.表的修改
/*
①修改列名
②修改列的类型或约束
③添加新列
④删除列
⑤修改表名

alter table 表面 add|drop|modify|change column 列名 【列类型 约束】;
*/
#①修改列名
#其中column可以省略
ALTER TABLE book CHANGE COLUMN publishDate pubDate DATETIME;
DESC book;

#②修改列的类型或约束
ALTER TABLE book MODIFY COLUMN pubdate TIMESTAMP;
DESC book;

#③添加新列
ALTER TABLE author ADD COLUMN annual DOUBLE;
DESC author;

#④删除列
ALTER TABLE author DROP COLUMN annual;

#⑤修改表名
ALTER TABLE author RENAME TO book_author;



#3.表的删除
DROP TABLE IF EXISTS book_author;

SHOW TABLES;

#通用的写法：
DROP DATABASE IF EXISTS 旧库名;
CREATE DATABASE 新库名;

DROP TABLE IF EXISTS 旧表名;
CREATE TABLE 新表名;



#4.表的复制
INSERT INTO author
VALUES (1,'村上春树','日本'),
(2,'莫言','中国'),
(3,'冯唐','中国'),
(4,'金庸','中国');
DESC author;
SELECT * FROM author;

#①仅仅复制表的结构
CREATE TABLE authorCopy LIKE author;
SELECT * FROM authorcopy;

#②复制表的结果+数据
CREATE TABLE copy2
SELECT * FROM author;
SELECT * FROM copy2;

#③只复制部分数据
CREATE TABLE copy3
SELECT id,authorname
FROM author
WHERE nation='中国';
SELECT * FROM copy3;

#④仅仅复制某些字段
CREATE TABLE copy4
SELECT id,authorname
FROM author
WHERE 0;
SELECT * FROM copy4;



#exercise
#1.创建表 dept1
/*
name Null? type
id         int(7)
name       varchar(25)
*/
CREATE DATABASE IF NOT EXISTS exercise;
CREATE TABLE deptl(
	id INT,
	NAME VARCHAR(25)
);
ALTER TABLE deptl MODIFY COLUMN id INT(7);

#2.将表 departments 中的数据插入新表 dept2 中
CREATE TABLE exercise.dept2
SELECT * FROM myemployees.`departments`;
SELECT * FROM departments;

#3.创建表 emp5
/*
name Null? type
id 	   int(7)
First_name Varchar (25)
Last_name  Varchar(25)
Dept_id    int(7)
*/
CREATE TABLE emp5(
	id INT(7),
	first_name VARCHAR(25),
	last_name VARCHAR(25),
	dept_id INT(7)
);
CREATE TABLE exercise.emp5 LIKE myemployees.emp5;
DROP TABLE IF EXISTS myemployees.emp5;

#4.将列 Last_name 的长度增加到 50
ALTER TABLE emp5 MODIFY COLUMN last_name VARCHAR(50);

#5.根据表 employees 创建 employees2
CREATE TABLE exercise.employees2 LIKE myemployees.`employees`;

#6.删除表 emp5
DROP TABLE IF EXISTS exercise.`emp5`;

#7.将表 employees2 重命名为 emp5
ALTER TABLE employees2 RENAME TO emp5;

#8.在表 dept 和 emp5 中添加新列 test_column，并检查所作的操作
ALTER TABLE dept1 ADD COLUMN test_column INT;
ALTER TABLE emp5 ADD COLUMN test_column VARCHAR(25);
DESC dept1;
DESC emp5;

#9.直接删除表 emp5 中的列 dept_id
ALTER TABLE emp5 DROP COLUMN dept_id;