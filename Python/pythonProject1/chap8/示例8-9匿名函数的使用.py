def calc(a,b):
    return a+b
print(calc(10,20))

#匿名函数
s=lambda a,b:a+b    #s表示的就是一个匿名函数
print(type(s))      #<class 'function'>
#调用匿名函数
print(s(10,20))
print('-'*40)
#列表的正常遍历取值
lst=[10,20,30,40,50]
for i in range(len(lst)):
    print(lst[i])
print('-'*40)

for i in range(len(lst)):
    result=lambda x:x[i]    #根据索引取值，result的类型是function，x是形式参数
    print(result(lst))      #lst是实际参数

student_scores=[
    {'name':'张三','score':98},
    {'name': '李四', 'score': 95},
    {'name': '王五', 'score': 100},
    {'name': '老六', 'score': 65},
]
#对列表进行排序，排序的规则是字典的成绩
student_scores.sort(key=lambda x:x['score'],reverse=True)
print(student_scores)