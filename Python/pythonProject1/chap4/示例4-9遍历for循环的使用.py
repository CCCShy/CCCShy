#遍历字符串：
for i in 'hello':
    print(i)
#rang()函数，Python中的内置函数，产生一个(n,m)的整数序列，包含n但是不包含m
for i in range(1,11):
    #print(i)
    if i%2==0:
        print(i,'是偶数')

#计算1-10之间的累加和
s=0 #用于存储累加和
for i in range(1,11):
    s+=i
print(s)

#判断100~999之间的水仙花数
'''
153=1*1*1+5*5*5+3*3*3
'''
for i in range(100,1000):
    if i==(i%10)**3+((i//10)%10)**3+(i//100)**3:
        print(i,'是水仙花数')