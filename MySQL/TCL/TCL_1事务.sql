#TCL
/*
Transaction Control Language：事务控制语言

事务：
一个或一组sql语句组成一个执行单元，这个执行单元要么全部执行，要么全部不执行。

案例：转账
张三 1000
李四 1000
update 表 set 张三的余额=500 where name='张三';
意外中断
update 表 set 李四的余额=1500 where name='李四';

事务的特性：
ACID
原子性：一个事务不可再分割，要么都执行，要么都不执行
一致性：一个事务执行会使数据从一个一致状态切换到另外一个一致状态
隔离性：一个事务的执行不受其他事务的干扰
持久性：一个事务一旦提交，则会永久的改变数据库的数据

事务的创建
隐式事务：事务没有明显的开启和结束的标记
比如：insert、update、delete语句

显式事务：事务具有明显的开启和结束标记
前提：必须先设置自动提交功能为禁用
设置自动提交功能禁用：
set autocommit=0;(仅一次有效)

事务的隔离级别：
read uncommitted：出现脏读、不可重复读、幻读
read committed：避免脏读，出现不可重复读、幻读
repeatable read：避免脏读、不可重复读，出现幻读
serializable：避免脏读、不可重复读、幻读
mysql中默认第三个隔离级别：repeatbale read
oracle中默认第二个隔离级别：read committed
查看隔离级别：
select @@tx_isolation;
设置隔离级别：
set session|global transaction isolation level 隔离级别;


步骤1：开启事务
set autocommit=0;
start transaction;可选的
步骤2：编写事务中的sql语句（select、insert、update、delete，DDL语言没有事务之说）
语句1;
语句2;
...
步骤3：结束事务
commit;提交事务
rollback;回滚事务


savepoint 节点名;设置保存点
*/

#查看存储引擎
SHOW ENGINES;
#查看自动提交事务开关
SHOW VARIABLES LIKE 'autocommit';

#演示事务的使用步骤
#创建表
DROP TABLE IF EXISTS account;
CREATE TABLE account(
	id INT PRIMARY KEY AUTO_INCREMENT,
	username VARCHAR(20),
	balance DOUBLE
);

INSERT INTO account(username,balance) VALUES('张三',1000),('李四',1000);
#开启事务
SET autocommit=0;
START TRANSACTION;
#编写一组事务的语句
UPDATE account SET balance=1000 WHERE username='张三';
UPDATE account SET balance=1000 WHERE username='李四';
#结束事务
ROLLBACK;

SELECT * FROM account;

#2.delete和truncate在事务使用时的区别
#演示delete
SET autocommit=0;
START TRANSACTION;
DELETE FROM account;
ROLLBACK;
#演示truncate  不能回滚
SET autocommit=0;
START TRANSACTION;
TRUNCATE TABLE account;
ROLLBACK;

#3.savepoint的使用
SET autocommit=0;
START TRANSACTION;
DELETE FROM account WHERE id=1;
SAVEPOINT a;#设置保存点
DELETE FROM account WHERE id=2;
ROLLBACK TO a; #回滚到保存点




#exercise
#1.创建一个表，里面有 id 为主键，stuname 唯一键，seat 座位号，要求将 id 设置成自增
CREATE TABLE transaction_1(
	id INT PRIMARY KEY AUTO_INCREMENT,
	stuname VARCHAR(20) UNIQUE,
	seat INT
);

#2.要求用事务的方式插入 3 行数据
SET autocommit=0;
START TRANSACTION;
INSERT INTO transaction_1(stuname,seat) VALUES('sun',1),('han',2),('hai',3);
COMMIT;
SELECT * FROM transaction_1;
TRUNCATE TABLE transaction_1;

#3.要求用事务的方式删除数据，并回滚
SET autocommit=0;
START TRANSACTION;
DELETE FROM transaction_1;
ROLLBACK;