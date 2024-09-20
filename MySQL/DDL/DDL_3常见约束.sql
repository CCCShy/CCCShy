#常见约束

/*
含义：一种限制，用于限制表中的数据，为了保证表中的数据的准确和可靠性

分类：六大约束
NOT NULL：非空约束，用于保证该字段的值不能为空。比如姓名，学号等
DEFAULT：默认约束，用于保证该字段有默认值。比如性别
PRIMARY KEY：主键约束，用于保证该字段的值具有唯一性，并且非空。比如学号、员工编号
UNIQUE：唯一约束，用于保证该字段的值具有唯一性，可以为空。比如座位号
CHECK：检查约束（MySQL中不支持）。比如年龄、性别
FOREIGN KEY：外键约束，用于限制两个表的关系，用于保证该字段的值必须来自于主表关联列的值。在从表中添加外键的约束，用于引用主表中某列的值。比如学生表的专业编号，员工表的工种编号

添加约束的时机：
	1.创建表时；
	2.修改表时
约束的添加分类：
	列级约束：
		六大约束语法上都支持，但外键约束没有效果
	表级约束：
		除了非空、默认，其他都支持

主键和唯一的对比：
	保证唯一性   是否允许为空   一个表可以有多少个   是否允许组合
主键	√		×		至多有1个	   √，但不推荐
唯一	√		√		可以有多个	   √，但不推荐
insert into major values(1,'java');
insert into major values(2,'C++');
insert into stuinfo values(1,'john','男',null,19,1);
insert into stuinfo values(2,'lily','女',null,19,2);
select * from major;
select * from stuinfo;

外键：
	1.要求在从表设置外键关系
	2.从表的外键列的类型和主表的关联列类型要求一致或兼容，名称无要求
	3.主表的关联列必须是一个key（一般是主键或唯一键，没有约束会报错）
	4.插入数据时，先插入主表数据，再插入从表；删除数据时，先删除从表，再删除主表
DROP TABLE IF EXISTS major;
CREATE TABLE IF NOT EXISTS stuinfo(
	id INT,
	stuName VARCHAR(20),
	gender CHAR(1),
	seat INT,
	age INT,
	majorID INT,
	PRIMARY KEY(id),#主键
	UNIQUE(seat),#唯一键
	CHECK(gender='男' OR gender='女'),#检查
	FOREIGN KEY(majorid) REFERENCES major(id)#外键
);

CREATE TABLE major(
	id INT primary key,
	majorName VARCHAR(20)
);
*/


CREATE TABLE 表名(
	字段名 字段类型 列级约束,
	字段名 字段类型,
	表级约束

);

#一、创建表时添加约束
#1.添加列级约束
/*
语法：直接在字段名和类型后面追加约束类型即可。只支持：默认、非空、主键、唯一
*/
CREATE DATABASE students;
CREATE TABLE stuinfo(
	id INT PRIMARY KEY,#主键
	stuName VARCHAR(20) NOT NULL,#非空
	gender CHAR(1) CHECK(gender='男' OR gender='女'),#检查约束
	seat INT UNIQUE,#唯一
	age INT DEFAULT 18,#默认约束
	majorID INT REFERENCES major(id)#外键
);

CREATE TABLE major(
	id INT PRIMARY KEY,
	majorName VARCHAR(20)
);

DESC stuinfo;
#查看stuinfo表中所有的索引，包括主键、外键、唯一
SHOW INDEX FROM stuinfo;


#2.添加表级约束
/*
语法：各个字段的最下面
【constraint 约束名】 约束类型(字段名)
*/

DROP TABLE IF EXISTS stuinfo;
CREATE TABLE IF NOT EXISTS stuinfo(
	id INT,
	stuName VARCHAR(20),
	gender CHAR(1),
	seat INT,
	age INT,
	majorID INT,
	CONSTRAINT pk PRIMARY KEY(id),#主键
	CONSTRAINT uq UNIQUE(seat),#唯一键
	CONSTRAINT ck CHECK(gender='男' OR gender='女'),#检查
	CONSTRAINT fk_stuinfo_major FOREIGN KEY(majorid) REFERENCES major(id)#外键
);

SHOW INDEX FROM stuinfo;

DROP TABLE IF EXISTS stuinfo;
CREATE TABLE IF NOT EXISTS stuinfo(
	id INT,
	stuName VARCHAR(20),
	gender CHAR(1),
	seat INT,
	age INT,
	majorID INT,
	PRIMARY KEY(id),#主键
	UNIQUE(seat),#唯一键
	CHECK(gender='男' OR gender='女'),#检查
	FOREIGN KEY(majorid) REFERENCES major(id)#外键
);

SHOW INDEX FROM stuinfo;

#通用的写法：
CREATE TABLE IF NOT EXISTS stuinfo(
	id INT PRIMARY KEY,
	stuname VARCHAR(20) NOT NULL,
	gender CHAR(1),
	age INT DEFAULT 18,
	seat INT UNIQUE,
	majorid INT,
	CONSTRAINT fk_stuinfo_major FOREIGN KEY(majorid) REFERENCES major(id) 
);

#两个列组合为一个主键，组合主键
#效果，组合主键的列内容不能同时一样，可以分别列内容相同
DROP TABLE IF EXISTS stuinfo;
CREATE TABLE IF NOT EXISTS stuinfo(
	id INT,
	stuName VARCHAR(20),
	gender CHAR(1),
	seat INT,
	age INT,
	majorID INT,
	PRIMARY KEY(id,stuName),#主键
	UNIQUE(seat),#唯一键
	CHECK(gender='男' OR gender='女'),#检查
	FOREIGN KEY(majorid) REFERENCES major(id)#外键
);
INSERT INTO stuinfo VALUES(1,'john','男',NULL,19,1);
INSERT INTO stuinfo VALUES(1,'joh','女',NULL,19,2);
SHOW INDEX FROM stuinfo;
TRUNCATE TABLE stuinfo;
SELECT * FROM stuinfo;




#二、修改表时添加约束
/*
1.添加列级约束
alter table 表名 modify column 字段名 字段类型 新约束；
2.添加表级约束
alter table 表名 add 【constraint 约束名】 约束类型(字段名) 【外键的引用】;
*/
DROP TABLE IF EXISTS stuinfo;
CREATE TABLE IF NOT EXISTS stuinfo(
	id INT,
	stuName VARCHAR(20),
	gender CHAR(1),
	seat INT,
	age INT,
	majorID INT
);
SHOW INDEX FROM stuinfo;
DESC stuinfo;
#1.添加非空约束
ALTER TABLE stuinfo MODIFY COLUMN stuname VARCHAR(20) NOT NULL;
#2.添加默认约束
ALTER TABLE stuinfo MODIFY COLUMN age INT DEFAULT 18;
#3.添加主键
#①列级约束
ALTER TABLE stuinfo MODIFY COLUMN id INT PRIMARY KEY;
#②表级约束
ALTER TABLE stuinfo ADD PRIMARY KEY(id);
#4.添加唯一键
#①列级约束
ALTER TABLE stuinfo MODIFY COLUMN seat INT UNIQUE;
#②表级约束
ALTER TABLE stuinfo ADD UNIQUE(seat);
#5.添加外键
ALTER TABLE stuinfo ADD CONSTRAINT fk_stuinfo__major FOREIGN KEY(majorID) REFERENCES major(id);



#三、修改表时删除约束
#1.删除非空约束
ALTER TABLE stuinfo MODIFY COLUMN stuname VARCHAR(20) NULL;
#2.删除默认约束
ALTER TABLE stuinfo MODIFY COLUMN age INT;
#3.删除主键
ALTER TABLE stuinfo MODIFY COLUMN id INT;
ALTER TABLE stuinfo DROP PRIMARY KEY;
#4.删除唯一键
ALTER TABLE stuinfo DROP INDEX seat_2;
SHOW INDEX FROM stuinfo;
#5.删除外键
ALTER TABLE stuinfo DROP FOREIGN KEY fk_stuinfo__major;
ALTER TABLE stuinfo DROP INDEX fk_stuinfo__major;



#exercise
#1.向表 emp2 的 id 列中添加 PRIMARY KEY 约束（my_emp_id_pk）
ALTER TABLE emp5 MODIFY COLUMN employee_id INT PRIMARY KEY;#列级约束，不支持添加名字
ALTER TABLE emp5 ADD CONSTRAINT my_emp_id_pk PRIMARY KEY(employee_id);#表级约束，但是主键添名字也没用

#2.向表 dept2 的 id 列中添加 PRIMARY KEY 约束（my_dept_id_pk）
ALTER TABLE dept2 ADD CONSTRAINT my_dept_id_pk PRIMARY KEY(department_id);

#3.向表 emp2 中添加列 dept_id，并在其中定义 FOREIGN KEY 约束，与之相关联的列是dept2 表中的 id 列。
ALTER TABLE emp5 ADD COLUMN dept_id INT(4);
ALTER TABLE emp5 ADD FOREIGN KEY(dept_id) REFERENCES dept2(department_id);

/*
列级约束：
	位置：列的后面
	支持的约束类型：语法都支持，但外键没效果
	是否可以起约束名：不可以
表级约束：
	位置：所有列的下面
	支持的约束类型：默认和非空不支持，其他支持
	是否可以起约束名：可以（主键没有效果）
*/