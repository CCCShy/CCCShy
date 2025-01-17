#流程控制结构
/*
顺序结构：程序从上往下依次执行
分支结构：程序从两条或多条路径中选择一条去执行
循环结构：程序在满足一定条件基础上，重复执行一段代码
*/

#一、分支结构
#1.if函数
/*
功能：实现简单的双分支
语法：
select if(表达式1,表达式2,表达式3)
执行顺序：
如果顺序表达式1成立，则if函数返回表达式2的值，否则返回表达式3的值

应用：任何地方
*/

#2.case结构
/*
情况1：类似于java中的switch语句，一般用于实现等值判断
语法：
	case 变量|表达式|字段
	when 要判断的值 then 返回的值1或语句1;
	when 要判断的值 then 返回的值1或语句2;
	...
	else 要返回的值n或语句n;
	end case;
	
情况2：类似于java中的多重if语句，一般用于实现区间判断
语法：
	case 变量|表达式|字段
	when 要判断的条件1 then 返回的值1或语句1;
	when 要判断的条件2 then 返回的值2或语句2;
	...
	else 要返回的值n或语句n;
	end case;
	
特点：
可以作为表达式，嵌套在其他语句中使用，可以放在任何地方，begin end中或begin end外面
可以作为独立的语句去使用，只能放在begin end中

如果when中的值满足或条件成立，则执行对应的then后面的语句，并且结束case
如果不满足，则执行else中的语句或值
else可以省略，如果else省略了，并且所有when条件都不满足，则返回null
*/

#案例：创建函数，实现传入成绩，如果成绩>90,返回A，如果成绩>80,返回B，如果成绩>60,返回C，否则返回D
DELIMITER $
CREATE PROCEDURE test1(IN score INT)
BEGIN
	CASE
	WHEN score>=90 AND score<=100 THEN SELECT 'A';
	WHEN score>=80 THEN SELECT 'B';
	WHEN score>=60 THEN SELECT 'C';
	ELSE SELECT 'D';
	END CASE;
END$
CALL test1(40)$


#3.if结构
/*
功能：实现多重分支
语法：
if 条件1 then 语句1;
elseif 条件2 then 语句2;
...
【else 语句n;】
end if;
应用场合：在begin end中
*/
#案例：实现传入成绩，如果成绩>90,返回A，如果成绩>80,返回B，如果成绩>60,返回C，否则返回D
CREATE FUNCTION test2(score INT) RETURNS CHAR
BEGIN
	IF socre>=90 AND score<=100 THEN RETURN 'A';
	ELSEIF score>=80 THEN RETURN 'B';
	ELSEIF score>=60 THEN RETURN 'C';
	ELSE RETURN 'D';
	END IF;
END$



#二、循环结构
/*
分类：
while、loop、repeat
循环控制：
iterate类似于continue，继续，结束本次循环，继续下一次
leave类似于break，跳出，结束当前所在的循环
*/

#1.while
/*
语法：
【标签:】while 循环条件 do
	循环体
end while【标签】;
联想：
while(循环条件){
	循环体;
}
*/

#2.loop
/*
【标签:】loop
	循环体;
end loop【标签】;
可以用来模拟简单的死循环
*/

#3.repeat
/*
语法：
【标签:】repeat
	循环体;
until 结束循环的条件
end repeat【标签】;
*/

#1.没有添加循环控制语句
#案例：批量插入，根据次数插入到admin表中多条记录
DELIMITER $
CREATE PROCEDURE while1(IN insertCount INT)
BEGIN
	DECLARE i INT DEFAULT 1;
	a:WHILE i<=insertCount DO
		INSERT INTO admin(username,`password`) VALUES(CONCAT('sun',i),'123');
		SET i=i+1;
	END WHILE a;
END$
CALL while1(100)$
DELETE FROM admin WHERE id>=3;
SELECT * FROM admin;
ALTER TABLE admin AUTO_INCREMENT=3;

#2.添加leave语句
#案例：批量插入，根据次数插入到admin表中多条记录，如果次数>20则停止
DELIMITER $
CREATE PROCEDURE while2(IN insertCount INT)
BEGIN
	DECLARE i INT DEFAULT 1;
	a:WHILE i<=insertCount DO
		INSERT INTO admin(username,`password`) VALUES(CONCAT('sun',i),'123');
		IF i>=20 THEN LEAVE a;
		END IF;
		SET i=i+1;
	END WHILE a;
END$
CALL while2(100)$

#3.添加iterate语句
#案例：批量插入，根据次数插入到admin表中多条记录，只插入偶数次
CREATE PROCEDURE while3(IN insertCount INT)
BEGIN
	DECLARE i INT DEFAULT 0;
	a:WHILE i<=insertCount DO
		SET i=i+1;
		IF i%2=1 THEN ITERATE a;
		END IF;
		INSERT INTO admin(username,`password`) VALUES(CONCAT('sun',i),'123');
	END WHILE a;
END$
CALL while3(100)$





#exercise
/*
已知表 stringcontent
其中字段：
id 自增长
content varchar(20)
向该表插入指定个数的，随机的字符串,个数<=20
*/
DROP TABLE IF EXISTS stringcontent;
CREATE TABLE stringcontent(
	id INT PRIMARY KEY AUTO_INCREMENT,
	content VARCHAR(20)
);
DELIMITER $
CREATE PROCEDURE rand_str_insert(IN insertCount INT)
BEGIN
	DECLARE str VARCHAR(26) DEFAULT 'abcdefghijklmnopqrstuvwxyz';
	DECLARE i INT DEFAULT 1;#定义循环变量i，表示插入次数
	DECLARE startIndex INT DEFAULT 1;#代表起始索引
	DECLARE len INT DEFAULT 1;#代表截取的字符串长度
	WHILE i<=insertCount DO
		SET startIndex=FLOOR(RAND()*26+1);#产生一个随机数，代表起始索引
		SET len=FLOOR((21-startIndex)*RAND()+1);#产生一个随机数，代表截取长度
		INSERT INTO stringcontent(content) VALUES(SUBSTR(str,startIndex,len));
		SET i=i+1;#循环变量更新
	END WHILE;
END$
CALL rand_str_insert(5)$
SELECT * FROM stringcontent;
DROP PROCEDURE rand_str_insert;