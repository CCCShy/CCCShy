s=0
i=1     #（1）初始化变量
while i<11:
    s+=i
    if s>20:
        print('累加和大于20的当前数为：',i)
        break
    i+=1

print('--------------------------------------')
i=0     #（1）初始化变量
while i<3:
    name=input('请输入用户名：')
    password=input('请输入密码：')
    if name=='syl' and password=='888888':
        print('正在登录，请稍后...')
        break
    else:
        if i<2:
            print('用户名或密码不正确，您还有',2-i,'次机会')
    i+=1
else:
    print('三次机会已用完，账号已锁定')