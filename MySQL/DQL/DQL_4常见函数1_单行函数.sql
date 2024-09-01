#进阶4：常见函数:单行函数
/*
概念：类似于Java中的方法、C中的函数，将一组逻辑语句封装在方法（函数）中，对外提供方法名（函数名）
特点：1、隐藏了实现细节；2、提高代码的重用性
调用：select 函数名(实参列表) 【from 表】;
特点：①叫什么（函数名）②干什么（函数功能）
分类：
1、单行函数：如concat、length、ifnull等
	字符函数:length,concat,substr,instr,upper,lower,lpad,rpad,replace,trim
	数学函数:round,ceil,floor,truncate,mod
	日期函数:now,curdate,curtime,year,month,monthname,day,hour,minute,second,str_to_date,date_format
	其他函数（补充）:version,database,user
	流程控制函数（补充）:if,case
	
2、分组函数：功能：做统计使用，又称统计函数、聚合函数、组函数
*/

#一、字符函数 （类似string.h）
#1.length 功能：获取参数值的字节个数
SELECT LENGTH('john');
SELECT LENGTH('数据库');

SHOW VARIABLES LIKE '%char%';

#2.concat 功能：拼接字符串
SELECT CONCAT(last_name,'_',first_name) 姓名 FROM employees;

#3.upper、lower 功能：大小写转换
SELECT LOWER('JOHN');
SELECT UPPER('john');
#案例：将姓变成大写，名变成小写，然后拼接
SELECT CONCAT(UPPER(last_name),' ',LOWER(first_name)) FROM employees;

#4.substr、substring
#注意：索引从1开始
#截取打印从指定索引处后面的所有字符
SELECT SUBSTR('阿珍爱上了阿强',6) out_put;

#截取打印从指定索引处指定字符长度的字符
SELECT SUBSTR('阿珍爱上了阿强',1,2) out_put;

#案例：姓名中首字母大写，其他字符小写然后用_拼接起来，显示出来
SELECT CONCAT(UPPER(SUBSTR(last_name,1,1)),LOWER(SUBSTR(last_name,2)),'_',LOWER(first_name)) 姓名 FROM employees;

#5.instr 功能：返回子串第一次出现的索引，如果找不到返回0
SELECT INSTR('阿珍爱上了阿强','上了') out_put;

#6.trim 功能：去除字符串前后的空格或者指定字符
SELECT LENGTH(TRIM('    123    ')) out_put;

SELECT TRIM('a' FROM 'aaaaaaaaa1a2a3aaaaaa') out_put;

#7.lpad 功能：用指定的字符实现左填充指定长度 当填充长度不够源字符长度时，将源字符按照填充长度打印
SELECT LPAD('123',10,'*') out_put;

#8.rpad 功能：用指定的字符实现右填充指定长度
SELECT RPAD('abc',12,'12') put_put;

#9.replace 功能：使用指定字符替换源字符内所有相同字符段
SELECT REPLACE('阿强阿强阿强阿珍爱上了阿强','阿强','阿龙') out_put;



#二、数学函数

#1.round 功能：四舍五入
SELECT ROUND(-1.55);
SELECT ROUND(1.577,2); #重载第二位代表保留小数点后个数

#2.ceil 功能：向上取整，返回>=该参数的最小整数
SELECT CEIL(1.002);

#3.floor 功能：向下取整，返回<=该参数的最大整数
SELECT FLOOR(4.99);

#4.truncate 功能：截断，截断保留小数点后x位
SELECT TRUNCATE(1.699999,1);

#5.mod 功能：取余
/*
mod(a,b);   a-a/b*b;
mod(-10,-3); -10-(-10)/(-3)*(-3)=-1
*/
SELECT MOD(10,3);
SELECT 10%3;

#三、日期函数
#1.now() 功能：返回当前系统日期+时间
SELECT NOW();

#2.curdate() 功能：返回当前系统日期，不包含时间
SELECT CURDATE();

#3.curtime() 功能：返回当前时间，不包含日期
SELECT CURTIME();

#4.可以获取指定的部分，年、月、日、小时、分钟、秒
SELECT YEAR(NOW()) 年;
SELECT YEAR('2000-05-26') 年;
SELECT YEAR(hiredate) 年 FROM employees;
SELECT MONTH(NOW()) 月;
SELECT MONTHNAME(NOW());

#5.str_to_date 功能：将日期格式的字符转换成指定格式的日期
SELECT STR_TO_DATE('1998-08-30','%Y-%c-%d') OUT_PUT;
#案例：查询入职日期为1992-4-3的员工信息
SELECT * FROM employees WHERE hiredate = '1992-4-3';
SELECT * FROM employees WHERE hiredate = STR_TO_DATE('4-3 1992','%m-%d %Y');

#6.date_format 功能：将日期转换成字符
SELECT DATE_FORMAT(NOW(),'%Y年%m月%d日');
#案例：查询有奖金的员工名和入职日期（xx月/xx日 xx年）
SELECT first_name,DATE_FORMAT(hiredate,'%m月/%d日 %y年') 入职日期 FROM employees WHERE commission_pct IS NOT NULL;



#四、其他函数
SELECT VERSION();
SELECT DATABASE();
SELECT USER();




#五、流程控制函数
#1.if函数 功能：if else效果
SELECT IF(10>5,'大','小') out_put;

SELECT last_name,commission_pct,IF(commission_pct IS NULL,'没奖金','有奖金') 备注 FROM employees;

#2.case函数 功能1：switch case的效果
/*
switch(变量或表达式){
	case 常量1:语句1;break;
	...
	default:语句n;break;
}

mysql中
case 要判断的字段或表达式
when 常量1 then 要显示的值1或语句1;
when 常量2 then 要显示的值2或语句2;
...
else 要显示的值n或语句n;
end
*/

/*案例：查询员工的工资，要求
部门号=30，显示的工资为1.1倍
部门号=40，显示的工资为1.2倍
部门号=50，显示的工资为1.3倍
其他部门，显示的工资为原工资
*/
SELECT salary 原始工资,department_id,
CASE department_id
WHEN 30 THEN 1.1*salary
WHEN 40 THEN 1.2*salary
WHEN 50 THEN 1.3*salary
ELSE salary
END 实际工资 FROM employees;

#case 功能2：类似于多重if
/*
java中：
if(条件1){
	语句1;
}else if(条件2){
	语句2;
}
...
else{
	语句n;
}

mysql中：
case
when 条件1 then 要显示的值1或语句1;
when 条件2 then 要显示的值2或语句2;
...
else 要显示的值n或语句n;
end
*/
#案例：查询员工的工资情况
/*
如果工资>20000，显示A级别
如果工资>15000，显示B级别
如果工资>10000，显示C级别
否则，显示D级别
*/
SELECT salary,
CASE
WHEN salary>20000 THEN 'A'
WHEN salary BETWEEN 15001 AND 20000 THEN 'B'
WHEN salary BETWEEN 10001 AND 15000 THEN 'C'
ELSE 'D' 
END AS 工资级别
FROM employees;

#1.显示系统时间(注：日期+时间)
SELECT NOW();

#2.查询员工号，姓名，工资，以及工资提高百分之 20%后的结果（new salary）
SELECT employee_id,CONCAT(first_name,' ',last_name) 姓名,salary,salary*1.2 "new salary" FROM employees;

#3.将员工的姓名按首字母排序，并写出姓名的长度（length）
SELECT CONCAT(first_name,' ',last_name) 姓名,LENGTH(CONCAT(first_name,' ',last_name)) `length` FROM employees ORDER BY SUBSTR(first_name,1,1);

#4.
SELECT CONCAT(last_name,' earns ',ROUND(salary),' monthly but wansts ',ROUND(salary*3)) AS `Dream Salary` FROM employees;

#5.
SELECT DISTINCT last_name Last_name,job_id Job_id,
CASE job_id
WHEN 'AD_PRES' THEN 'A'
WHEN 'ST_MAN' THEN 'B'
WHEN 'IT_PROG' THEN 'C'
WHEN 'SA_REP' THEN 'D'
WHEN 'ST_CLERK' THEN 'E'
END Grade
FROM employees;