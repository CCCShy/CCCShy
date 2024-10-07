#（1）创建字典
d={10:'cat',20:'dog',30:'pet',20:'zoo'}
print(d)    #当key相同时，value进行了覆盖

#（2）zip函数
lst1=[10,20,30,40]
lst2=['cat','dog','pet','zoo','car']
zipobj=zip(lst1,lst2)
print(zipobj)   #<zip object at 0x000002408CD0A880>     zip对象
#print(list(zipobj))     #[(10, 'cat'), (20, 'dog'), (30, 'pet'), (40, 'zoo')]   转成列表类型，列表元素为元组类型
d=dict(zipobj)
print(d)

#使用参数创建字典
d=dict(cat=10,dog=20,pet=30,zoo=40) #左侧是cat键key，右侧的是value
print(d)

t=(10,20,30)
print({t:10})   #t是key，10是value，元组是可以作为字典中的key

# lst=[10,20,30]
# print({lst:10}) #TypeError: unhashable type: 'list' 列表是不可以作为字典中的key，以为列表是可变数据类型，可变数据类型不能作为字典当中的键

#字典属于序列
print('max:',max(d))
print('min:',min(d))
print('len:',len(d))

#字典的删除
del d
# print(d)