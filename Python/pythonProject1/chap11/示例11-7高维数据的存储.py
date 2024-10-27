import json
#准备高维数据
lst=[
    {'name':'nn','age':18,'score':90},
    {'name':'jerry','age':21,'score':99.5},
    {'name':'tom','age':19,'score':80}
]
#
s=json.dumps(lst,ensure_ascii=False,indent=4)   #ensure_ascii正常显示中文     indent增加数据的缩进，美观用的，JSON格式的字符串更具有可读性
print(type(s))  #编码 lst-->str，列表中是字典
print(s)

#解码
lst2=json.loads(s)
print(type(lst2))
print(lst2)

#编码到文件中
with open('student.txt','w') as file:
    json.dump(lst,file,ensure_ascii=False,indent=4)

#解码到程序
with open('student.txt','r') as file:
    lst3=json.load(file)
    print(type(lst3))
    print(lst3)