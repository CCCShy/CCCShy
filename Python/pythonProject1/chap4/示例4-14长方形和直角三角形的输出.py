#长方形
for i in range(1,4):    #外层循环 行
    for j in range(1,5):#内层循环 列
        print('*',end='')
    print()             #空print语句，作用是换行
print('----------------------------------------')

#直接三角形
i=0
j=0
while i<5:
    while j<i+1:
        print('*',end='')
        j+=1
    j=0
    i+=1
    print('')
print('-----------------------------------------')
for i in range(1,6): #5行
    for j in range(1,i+1):
        print('*',end='')
    print()