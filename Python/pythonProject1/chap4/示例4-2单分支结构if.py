number=eval(input("请输入6位中奖号码:"))
if(number==987654):
    print('恭喜您中奖了！')
if(number!=987654):
    print('很遗憾，您未中本期大奖')
print('---------以上if判断的表达式，是通过比较运算符计算出来的，结果是布尔类型----------')

n=98    #赋值操作
if n%2: #98%2的余数是0，0的布尔值是False，非0的布尔值是True
    print(n,'是奇数')  #由于98%2的余数是0，所以该代码不执行
if not n%2:          #98%2的余数是0，0的布尔值是False，not False的结果为True
    print(n,'是偶数')
print('---------判断一个字符串是否为空字符串------------')
x=input('请输入一个字符串：')
if x:   #在Python一切皆对象，每个对象都有一个布尔值，而非空字符串的布尔值为True，空字符串的布尔值为False
    print('x是一个非空字符串')
if not x:   #空字符串的布尔值是False，取反，not False的结果为True
    print('x是一个空字符串')
print('----------表达式也可以是一个单纯的布尔型变量----------')
flag=eval(input('请输入一个布尔类型的值：True or False'))
if flag:
    print('Flag的值为True')
if not flag:
    print('Flag的值为False')

print('---------使用if语句时，如果语句块中只有一句代码，可以奖语句块直接写在冒号的后面----------')
a=10
b=5
if a>b:max=a    #语句块只有一句，赋最大值
print('a和b的最大值为：',max)