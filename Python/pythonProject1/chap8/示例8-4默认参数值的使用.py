def happy_birthday(name='sun',age=18):
    print('祝'+name+'生日快乐')
    print(str(age)+'生日快乐')

#调用
happy_birthday()    #不用传参
happy_birthday('jun')    #位置传参
happy_birthday(age=20)    #关键字传参
# happy_birthday(19)  #如果使用位置传参，19被传给了name

def fun(a,b=20):        #a作为位置参数，b为默认值参数
    pass
# def fun1(a=20,b):       #报错，语法错误，当位置参数和默认值参数同时存在的时候，位置参数在后会被报错
    pass