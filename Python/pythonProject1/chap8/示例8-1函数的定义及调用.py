#函数的定义
def get_sum(num):   #num为形式参数
    s=0
    for i in range(num+1):
        s+=i
    print(f'1到{num}之间的累加和为:{s}')

#函数的调用
get_sum(10)     #10是实际参数
get_sum(2)