t=(i for i in range(1,4))
print(t)    #只能看到生成器对象
# t=tuple(t)
# print(t)

#遍历
# for item in t:
#     print(item)
print(t.__next__())
print(t.__next__())
print(t.__next__())

t=tuple(t)
print(t)    #空的，已使用__next__()函数取出，相当于从地址拿出元素，已经取完