for i in 'hello':
    if i=='o' :
        break
    print(i)
print('-----------------------')
for i in range(3):
    username=input('请输入用户名：')
    password=input('请输入密码：')
    if username=='syl' and password=='888888':
        print('正在登录，请稍后...')
        break
    else:
        if i < 2:
            print('用户名或密码不正确，您还有', 2 - i, '次机会')
else:
    print('三次机会已用完，账号已锁定')