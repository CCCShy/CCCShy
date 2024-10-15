#函数的返回值
def calc(a,b):
    print(a+b)

calc(10,20)
print(calc(10,20))  #None

def calc(a,b):
    c=a+b
    return c
get_s=calc(10,20)
print(get_s)
get_s2=calc(calc(10,20),30)
print(get_s2)


#返回值可以是多个
def get_sum(num):
    s=0         #累加和
    odd_sum=0   #奇数和
    even_sum=0  #偶数和
    for i in range(num+1):
        if i % 2 == 0:
            even_sum+=i
        elif i % 2 == 1:
            odd_sum+=i
        s+=i
    return odd_sum,even_sum,s   #三个值
result=get_sum(10)
print(type(result))
print(result)
#解包赋值
a,b,c=get_sum(10)
print(a,b,c)