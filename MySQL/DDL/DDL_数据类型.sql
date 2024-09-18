#常见的数据类型
/*
数值型：
	整形
	小数：
		定点数
		浮点数
字符型：
	较短的文本：char、varchar
	较长的文本：text、blob()（较长的二进制数据）
日期型
	
*/

#一、整型
/*
分类：
tinyint、smallint、mediumint、int/integer、bigint
1	 2	   3	      4		   8
特点：
①如果不设置无符号还是有符号，默认是有符号，如果想设置无符号，需添加unsigned
②如果插入的数值超出整型范围，会报out of range异常，并且插入临界值
③如果不设置长度，会有默认的长度
长度代表了显示的最大宽度，如果不够会用0在左边填充，但必须搭配zerofill使用，且使用zerofill后默认为无符号整形
*/

#1.如何设置无符号和有符号
CREATE TABLE tab_int(
	t1 INT(7),
	t2 INT(7) UNSIGNED
);
DESC tab_int;
INSERT INTO tab_int VALUES(-123456,-123);
INSERT INTO tab_int VALUES(2147483648,4294967296);
INSERT INTO tab_int VALUES(1,2);
DROP TABLE IF EXISTS tab_int;
SELECT * FROM tab_int;


#二、小数
/*
分类：
1.浮点型
float(M.D)
double(M,D)
2.定点型
dec(M,D)
decimal(M,D)

特点：
①M和D
M：整数部位+小数部位
D：小数部位
如果超过范围，则插入临界值
②M和D都可以省略
如果是decimal，则(M,D)默认为(10,0)
如果是float和double，则会根据插入数值的精度来决定精度
③定点型的精确度较高，如果要求插入数值的精度较高，如货币运算等则考虑使用
*/
#测试M和D
CREATE TABLE tab_float(
	f1 FLOAT,
	f2 DOUBLE,
	f3 DECIMAL
);
DROP TABLE IF EXISTS tab_float;
DESC tab_float;

INSERT INTO tab_float VALUES(123.4523,123.4523,123.4523);
INSERT INTO tab_float VALUES(123.456,123.456,123.456);
INSERT INTO tab_float VALUES(1223.45,1223.45,1223.45);
SELECT * FROM tab_float;

/*原则：
所选择的类型越简单越好，能保存的数值类型越小越好
*/



#三、字符型
/*
较短的文本：
char
varchar

较长的文本：
text
blob(较大的二进制)

其他：
binary和varbinary用于保存较短的二进制
enum用于保存枚举
set用于保存集合

特点：
char：
写法：char(M)
M的意思：最大的字符数，可以省略，默认为1
特点：固定长度的字符
空间的耗费：比较耗费
效率：高

varchar：
写法：varchar(M)
M的意思：最大的字符数，不可以省略
特点：可变长度的字符
空间的耗费：比较节省
效率：低
*/

#enum 枚举
CREATE TABLE tab_char(
	c1 ENUM('a','b','c')
);

INSERT INTO tab_char VALUES('a');
INSERT INTO tab_char VALUES('b');
INSERT INTO tab_char VALUES('c');
INSERT INTO tab_char VALUES('M');
INSERT INTO tab_char VALUES('A');
SELECT * FROM tab_char;

#set 集合
CREATE TABLE tab_set(
	s1 SET('a','b','c','d')
);

INSERT INTO tab_set VALUES('a');
INSERT INTO tab_set VALUES('a,e');
INSERT INTO tab_set VALUES('a,b,c,d');
SELECT * FROM tab_set;


#四、日期型
/*
分类：
date：只保存日期
time：只保存时间
year：只保存年

datetime：保存日期+时间
timestamp：保存日期+时间

特点：
datetime：
	字节：8
	范围：1000-1-1——9999-12-31
	是否受时区影响：不受
timestamp：
	字节：4
	范围：1970——2038
	是否受时区影响：受
*/

CREATE TABLE tab_date (
	t1 DATETIME,
	t2 TIMESTAMP
);

INSERT INTO tab_date VALUES(NOW(),NOW());
SELECT * FROM tab_date;
SHOW VARIABLES LIKE  'time_zone';

SET time_zone='+9:00';