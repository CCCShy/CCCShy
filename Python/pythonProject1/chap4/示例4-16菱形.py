#菱形
row=eval(input('请输入菱形的行数：'))#7
top_row=(row+1)//2#4 上半部分的行数
#上半部分
for i in range(1,top_row+1):
    for j in range(1,top_row-i+1):
        print(' ',end='')
    for k in range(1,2*i):
        print('*',end='')
    print()
#下半部分
bottom_row=row//2
for i in range(1,bottom_row+1):
    for j in range(1,i+1):
        print(' ',end='')
    for k in range(1,row-(2*i)+1):
        print('*',end='')
    print()


