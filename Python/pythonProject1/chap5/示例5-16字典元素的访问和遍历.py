d={'hello':10,'world':20,'python':10}
#访问字典中的元素
#（1）使用d[key]
print(d['hello'])
#（2）d.get(key)
print(d.get('hello'))

#二者之间是有区别的，如果key不存在，d[key]报错d.get(key)可以指定默认值
#print(d['java'])    #KeyError: 'java'
print(d.get('java'))
print(d.get('java',20))

#字典的遍历
for item in d.items():
    print(item) #key=value组成的一个元素

#在使用for循环时，分别使用key,value
for key,value in d.items():
    print(key,value)