s='3.14+3'
print(s,type(s))
x=eval(s)
print(x,type(x))

#eval函数经常与input()函数一起使用
age=eval(input('请输入您的年龄：'))
print(age,type(age))
height=eval(input('请输入您的身高：'))
print(height,type(height))
hello='北京欢迎你'
print(hello)
print(eval('hello')) #输出了“北京欢迎你”
print(eval(hello)) #NameError: name '北京欢迎你' is not defined