#存储过程和函数
/*
存储过程和函数：类似于java中的方法
好处：
1.提高代码的重用性
2.简化操作
*/

#存储过程
/*
含义：一组预先编译好的SQL语句的集合，理解成批处理语句
1.提高代码的重用性
2.简化操作
3.减少了编译次数并且减少了和数据服务器的连接次数。提高了效率
*/

#一、创建语法
CREATE PROCEDURE 存储过程名(参数列表)
BEGIN
	存储过程体（一组合法的SQL语句）
END

/*注意：
1.参数列表包含三部分：参数模式 参数名 参数类型
例如：in stuname varchar(20)
参数模式：
	in：该参数可以作为输入，也就是该参数需要调用方传入值
	out：该参数可以作为输出，也就是该参数可以作为返回值
	inout：该参数既可以作为输入又可以作为输出也就是该参数既需要传入值，又可以返回值

2.如果存储过程体仅仅有一句话，begin end可以省略
存储过程体中的每条SQL语句的结尾要求必须加分号。
存储过程的结尾可以使用delimiter重新设置
语法：
delimiter 结束标记
案例：
delimiter $
*/

#二、调用语法
CALL 存储过程名(实参列表);
#1.空参列表
#案例：插入到admin表中五条记录
SELECT * FROM admin;
DELIMITER $
CREATE PROCEDURE myp1()
BEGIN
	INSERT INTO admin(username,`password`)
	VALUES('john','0000'),('lily','1111'),('jack','1111'),('rose','1111'),('peter','1111');
END $
#调用
CALL myp1()$
SELECT * FROM admin$
DELETE FROM admin WHERE id>2;

#2.创建带in模式参数的存储过程
#案例1：创建存储过程实现 根据女神名，查询对应的男神信息
DELIMITER $ 	#设置结束标志
CREATE PROCEDURE myp2(IN beautyName VARCHAR(20))
BEGIN
	SELECT bo.*
	FROM boys bo
	RIGHT JOIN beauty b ON b.boyfriend_id=bo.id
	WHERE b.name=beautyName;
END$
#调用
CALL myp2('柳岩')$
SET NAMES utf8;#更改字符集
SELECT * FROM boys;

#案例2：创建存储过程，实现用户是否登录成功
DELIMITER $ 
CREATE PROCEDURE myp3(IN username VARCHAR(20),IN `password` VARCHAR(20))
BEGIN
	DECLARE result INT DEFAULT 0;	#声明局部变量并初始化
	SELECT COUNT(*) INTO result	#给result赋值
	FROM admin
	WHERE admin.`username`=username
	AND admin.`password`=`password`;
	
	SELECT IF(result>0,'成功','失败') 登录状态;	#使用局部变量判断
END$
#调用
CALL myp3('john',8888)$
SELECT * FROM admin;


#3.创建带out模式的存储过程
#案例1：根据女神名，返回对应的男神名
CREATE PROCEDURE myp4(IN beautyName VARCHAR(20),OUT boyName VARCHAR(20))
BEGIN
	SELECT bo.boyName INTO boyName
	FROM beauty b
	LEFT JOIN boys bo ON b.boyfriend_id=bo.id
	WHERE b.name=beautyName;
END$
#调用
SET @bName$
CALL myp4('苍老师',@bName)$
SELECT @bName

#案例2：根据女神名，返回对应的男神名和男神魅力值
CREATE PROCEDURE myp5(IN beautyName VARCHAR(20),OUT boyName VARCHAR(20),OUT userCP INT)
BEGIN
	SELECT bo.boyName,bo.userCP INTO boyName,userCP
	FROM beauty b
	LEFT JOIN boys bo ON b.boyfriend_id=bo.id
	WHERE b.name=beautyName;
END$
#调用
CALL mvp5('苍老师',@bName,@CP)$
SELECT @bName,@CP;


#4.创建带inout模式参数的存储过程
#案例1：传入a和b两个值，最终a和b都翻倍并返回
CREATE PROCEDURE myp6(INOUT a INT,INOUT b INT)
BEGIN
	SET a=a*2;
	SET b=b*2;
END$
#调用
SET @m=10;
SET @n=20;
CALL myp6(@m,@n)
SELECT @m,@n;


#三、删除存储过程
/*
语法：
drop procedure 存储过程名;	#一次只能删除一个
*/
DROP PROCEDURE ex5;

#四、查看存储过程的信息
SHOW CREATE PROCEDURE ex2;





#exercise
#1.创建存储过程或函数实现传入用户名和密码，插入到 admin 表中
CREATE PROCEDURE ex1(IN uname VARCHAR(20),IN pw VARCHAR(20))
BEGIN
	INSERT INTO admin(username,PASSWORD) VALUES(uname,pw);
END$
CALL ex1('sun','1234')$
SELECT * FROM admin;

#2.创建存储过程或函数实现传入女神编号，返回女神名称和女神电话
CREATE PROCEDURE ex2(IN beautyId INT,OUT beautyName VARCHAR(50),OUT beautyPhone VARCHAR(11))
BEGIN
	SELECT NAME,phone INTO beautyName,beautyPhone
	FROM beauty
	WHERE id=beautyId;
END$
CALL ex2(1,@bn,@bp);
SELECT @bn,@bp;

#3.创建存储存储过程或函数实现传入两个女神生日，返回大小
CREATE PROCEDURE ex3(IN date1 DATETIME,IN date2 DATETIME,OUT result INT)
BEGIN
	SELECT DATEDIFF(date1,date2) INTO result;
END$
CALL ex3('2000-01-31','2000-05-26',@result)$
SELECT @result;

#4.创建存储过程或函数实现传入一个日期，格式化成 xx 年 xx 月 xx 日并返回
CREATE PROCEDURE ex4(IN dt DATE,OUT dtt VARCHAR(20))
BEGIN
	SELECT DATE_FORMAT(dt,'%Y年%m月%d日') INTO dtt;
END$
CALL ex4(NOW(),@dt)$
SELECT @dt$


#5.创建存储过程或函数实现传入女神名称，返回：女神 and 男神 格式的字符串
#如 传入 ：小昭
#返回： 小昭 and 张无忌
DROP PROCEDURE ex5;
DELIMITER $
CREATE PROCEDURE ex5(IN beautyName VARCHAR(20),OUT naname VARCHAR(20))
BEGIN
	SELECT CONCAT(beautyName,' and ',IFNULL(bo.boyName,'null')) INTO naname
	FROM beauty b
	LEFT JOIN boys bo ON b.boyfriend_id=bo.id
	WHERE b.name=beautyName;
END$
CALL ex5('天天',@naname);
SELECT @naname;

#6.创建存储过程或函数，根据传入的条目数和起始索引，查询 beauty 表的记录
CREATE PROCEDURE ex6(IN orig INT,IN num INT)
BEGIN
	SELECT *
	FROM beauty
	LIMIT orig,num;
END$
CALL ex6(1,1)$