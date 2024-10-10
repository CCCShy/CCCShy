try:
    num1 = eval(input("请输入一个整数："))
    num2 = eval(input('请输入另一个整数：'))
    result = num1 / num2
    print('结果:{0:.2f}'.format(result))
except ZeroDivisionError:
    print('除数不能为0')
except NameError:
    print('不能将字符串转成整数')
except BaseException:
    print('未知异常')