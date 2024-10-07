t=('python','hello','world')
# 根据索引访问元素
print(t[0])
t2=t[0:3:2]  #元组支持切片操作
print(t2)

#元组的遍历
#使用遍历循环for遍历元组元素
for item in t:
    print(item)

#使用for循环，range()函数，len()函数，根据索引进行遍历
for i in range(0,len(t)):
    print(i,t[i])

# 使用enumerate()
for index,item in enumerate(t):
    print(index,item)

for index,item in enumerate(t,start=10):    #更改起始值
    print(index,item)