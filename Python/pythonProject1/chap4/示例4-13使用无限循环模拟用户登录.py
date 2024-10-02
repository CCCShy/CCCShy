#（1）初始化变量
i=0
#（2）判断i的值
while i<3:
    #（3）语句块
    username=input('用户名：')
    password=input('密码：')
    #登录操作，if...else...
    if username=='admin' and password=='12345678':
        print('系统正在登录中...')
        #需要改变循环变量，目的：退出循环
        i=8
    else:
        if i<2:
            print('用户名或密码不正确，请重试，您还有：',2-i,'次机会')
        i+=1    #（4）改变变量
if i==3:
    print('对不起，三次均输入错误')