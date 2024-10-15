def happy_birthday(name,age):
    print('祝'+name+'生日快乐')
    print(str(age)+'生日快乐')

#调用
# happy_birthday('卷老师')   #TypeError: happy_birthday() missing 1 required positional argument: 'age'
# happy_birthday(18,'sun')    #TypeError: can only concatenate str (not "int") to str
happy_birthday('sun',18)