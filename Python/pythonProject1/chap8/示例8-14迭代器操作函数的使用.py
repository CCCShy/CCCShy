lst=[54,56,77,4,567,34]
#(1)排序操作
asc_lst=sorted(lst)
desc_lst=sorted(lst,reverse=True)
print('原列表:',lst)
print('升序:',asc_lst)
print('降序:',desc_lst)

#(2)reversed 反向
new_lst=reversed(lst)
print(type(new_lst),list(new_lst))  #<class 'list_reverseiterator'> 迭代器对象

#(3)zip
x=['a','b','c','d']
y=[10,20,30,40,50]
zipobj=zip(x,y)
#print(type(zipobj),list(zipobj))    #<class 'zip'>

#(4)enumerate
enum=enumerate(y,start=1)
print(type(enum),tuple(enum))   #<class 'enumerate'>

#(5)all
lst2=[10,20,'',30]
print(all(lst))     #True
print(all(lst2))    #False 列表内空字符串的布尔值是False

#(6)any
lst3=['','']
print(any(lst2))    #True
print(any(lst3))    #False

#(7)next
print(next(zipobj))
print(next(zipobj))
print(next(zipobj))
print(next(zipobj))

#(8)filter      将range(10)中的所有放到fun中执行一遍，将返回结果为True的保留下来
def fun(num):
    return num%2==1
obj=filter(fun,range(10))   #将range(10),0-9的整数,都执行一次fun操作
print(list(obj))

#(9)map
def upper(x):
    return x.upper()
new_lst=['hello','world','python']
up_lst=map(upper,new_lst)
print(list(up_lst))