luck_number=8
my_name='sun'
print('luck_number的数据类型是：',type(luck_number))
print(my_name,'的幸运数字是',luck_number)

#Python可以动态修改变量的数据类型，通过赋不同类型的值就可以直接修改
luck_number='北京欢迎你'
print('luck_number的数据类型是：',type(luck_number))

#在Python中允许多个变量指向同一个值
no=number=1024 #no与number都指向了1024这个整数值
print(no,number)
print(id(no)) #id()查看对象的内存地址
print(id(number))