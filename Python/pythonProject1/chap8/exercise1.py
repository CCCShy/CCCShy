import random
lst=[random.randint(1,100) for item in range(10)]
print(lst)
def fun(lst):
    max=lst[0]
    for item in range(1,len(lst)):
        if lst[item]>max:
            max=lst[item]
    return max
print(fun(lst))