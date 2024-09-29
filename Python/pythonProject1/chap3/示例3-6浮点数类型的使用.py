height=187.6 #身高
print(height)
print(type(height))

x=10
y=10.0
print('x的数据类型：',type(x))#int
print('y的数据类型：',type(y))#float

x=1.99E1413
print('科学计数法：',x,'x的数据类型：',type(x))
print(0.1+0.2) #不确定的尾数问题0.30000000000000004
print(round(0.1+0.2,1))#round函数保留小数后n位