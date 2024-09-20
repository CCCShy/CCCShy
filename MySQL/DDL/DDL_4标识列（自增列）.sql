#标识列
/*
又称自增长列
含义：可以不用手动的插入值，系统提供默认的序列值

特点：
1.标识列不一定和主键搭配，但要求是一个key（比如unique）
2.一个表中至多只能用一个自增长列
3.标识列的类型只能是数值型（int，float，double等）
4.标识列可以通过SET auto_increment_increment=1设置步长，也可以通过手动插入设置起始值
*/

#一、创建表时设置标识列
DROP TABLE IF EXISTS tab_identity;
CREATE  TABLE tab_identity(
	id INT,
	NAME DOUBLE UNIQUE,
	seat INT
);
TRUNCATE TABLE tab_identity;
INSERT INTO tab_identity VALUES(NULL,'Sun');
INSERT INTO tab_identity(NAME) VALUES('Han');
SELECT * FROM tab_identity;
DESC tab_identity;
SHOW INDEX FROM tab_identity;

SHOW VARIABLES LIKE '%auto_increment%';
#设置自增步长
SET auto_increment_increment=1;
#如何更改起始值
INSERT INTO tab_identity VALUES(10,'SSun');



#二、修改表时设置标识列
ALTER TABLE tab_identity MODIFY COLUMN id INT PRIMARY KEY AUTO_INCREMENT;



#三、修改表时删除标识列
ALTER TABLE tab_identity MODIFY COLUMN id INT;