#（1）初始化变量
answer='y'
#（2）条件判断
while answer=='y':
    print('---------------欢迎使用10086查询功能-------------------')
    print('1.查询当前余额')
    print('2.查询当前剩余流量')
    print('3.查询当前剩余的通话时长')
    print('0.退出系统')
    op=input('请输入您要执行的操作：')
    if op=='1':
        print('当前余额为：180.2元')
    elif op=='2':
        print('当前剩余流量为：4GB')
    elif op=='3':
        print('当前剩余的通话时长为：300分钟')
    elif op=='0':
        print('程序退出，谢谢您的使用')
        break
    else:
        print('输入操作数无效，请重新输入')
    #（4）改变变量
    answer=input('还继续操作吗？(y/n)')
else:
    print('程序退出，谢谢您的使用')

