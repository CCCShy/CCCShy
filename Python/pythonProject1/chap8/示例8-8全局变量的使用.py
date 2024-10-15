a=100   #全局变量

def calc(c,d):
    return  a+c+d
print(a)
print(calc(10,20))
print('-'*40)

def calc2(x,y):
    a=200
    return a+x+y

print(calc2(10,20))
print(a)

def calc3(x,y):
    global s    #s是在函数中定义的变量，但是使用了global关键字声明，这个变量s变成了全局变量
    s=300       #声明和赋值必须分开执行
    return s+x+y
print(calc3(10,20))
print(s)