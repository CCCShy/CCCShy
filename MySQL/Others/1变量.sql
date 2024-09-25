#变量
/*
系统变量：
	全局变量
	会话变量

自定义变量：
	用户变量
	局部变量
*/

#一、系统变量
/*说明：变量由系统提供，不是用户定义，属于服务器层面
使用的语法：
1.查看所有的系统变量
show global|[session] variables; 全局/会话 若不写则默认查看会话变量

2.查看满足条件的部分系统变量
show global|[session] variables like '%char%';

3.查看指定的某个系统变量的值
select @@global|[session]系统变量名; 若不写则默认查看会话变量

#4.为某个系统变量赋值
方式一：
set global|[session] 系统变量名=值;
方式二：
set @@global|[session].系统变量名=值;

注意：如果是全局级别，则需要加global；如果是会话级别，则需要加session，如果不写则默认session
*/

#1.全局变量
/*
作用域：服务器每次启动将为所有的全局变量赋初始值，针对于所有的会话（连接）有效，但不能跨重启
*/
#①查看所有全局变量
SHOW GLOBAL VARIABLES;
#②查看部分的全局变量
SHOW GLOBAL VARIABLES LIKE '%char%';
#③查看指定某个全局变量
SELECT @@global.autocommit;
SELECT @@tx_isolation;
#④为某个指定的全局变量赋值
SET @@global.autocommit=0;#修改全局变量值跨连接有效

#2.会话变量
/*
作用域：仅仅针对于当前会话（连接）有效
*/
#①查看所有的会话变量
SHOW VARIABLES;
SHOW SESSION VARIABLES;
#②查看部分的会话变量
SHOW VARIABLES LIKE '%char%';
SHOW SESSION VARIABLES LIKE '%char%';
#③查看指定的某个会话变量
SELECT @@tx_isolation;
SELECT @@session.autocommit;
#④为某个会话变量赋值
#方式一：
SET @@session.tx_isolation='read-uncommitted';
SET @@tx_isolation='repeatable-read';
#方式二：
SET SESSION tx_isolation='read-committed';



#二、自定义变量
/*
说明：变量是用户自定义的，不是由系统的
使用步骤：
声明
赋值
使用（查看、比较、运算等）
*/
#1.用户变量
/*
作用域：针对于当前会话（连接）有效，同于会话变量的作用域
应用在任何地方，也就是begin end外面或begin end里面

*/

#①声明并初始化
#赋值的操作符：=或:=
SET @用户变量名=值;
SET @用户变量名:=值;
SELECT @用户变量名:=值;

#②赋值（更新用户变量的值）
#方式一：通过set或select
SET @用户变量名=值;
SET @用户变量名:=值;
SELECT @用户变量名:=值;
#方式二：通过select into
SELECT 字段 INTO @变量名 FROM 表;

#③使用（查看用户变量的值）
SELECT @用户变量名;

#案例：
#声明并初始化
SET @name='john';
SET @name=100;
#赋值
SELECT COUNT(*) INTO @name FROM employees;
#查看
SELECT @name;


#2.局部变量
/*
作用域：仅仅在定义它的begin end中有效
应用在begin end中的第一句话！！
*/
#①声明
DECLARE 变量名 类型;
DECLARE 变量名 类型 DEFAULT 默认值;

#②赋值（更新用户变量的值）
#方式一：通过set或select
SET 局部变量名=值;
SET 局部变量名:=值;
SELECT @局部变量名:=值;
#方式二：通过select into
SELECT 字段 INTO 局部变量名 FROM 表;

#③使用
SELECT 局部变量名;


/*
对比用户变量和局部变量：
		作用域			定义和使用的位置				语法
用户变量	当前会话		会话中的任何地方				必须加@符号，不用限定类型
局部变量	begin end中		只能在begin end中且为第一句话			一般不用加@符号，需要限定类型
*/

#案例：声明两个变量并赋初值，求和并打印
#1.用户变量
SET @a=1;
SET @b=2;
SELECT @a+@b;

#2.局部变量
DECLARE d INT DEFAULT 1;
DECLARE e INT DEFAULT 2;
DECLARE c INT;
SET c=d+e;
SELECT c;






































