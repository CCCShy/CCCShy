#倒三角形
i=5
while i>0:
    for j in range(1,i+1):
        print('*',end='')
    print()
    i-=1
print('-------------------------------------')
for i in range(1,6):
    for j in range(1,7-i):
        print('*',end='')
    print()
print('-------------------------------------')

#等腰三角形
x=eval(input('请输入等腰三角形的边长：'))
for i in range(1,x+1):  #外层循环x次
    # 倒三角形
    for j in range(1,x-i+1):
        print(' ',end='')
    #1,3,5,7...等腰三角形 range(1,2) range(1,4) range(1,6) range(1.8) range(1.10)
    for k in range(1,2*i):
        print('*',end='')
    print()