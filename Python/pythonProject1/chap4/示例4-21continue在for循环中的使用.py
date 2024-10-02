s=0
for i in range(1,101):
    if i%2==1:  #奇数
        continue    #不执行循环内后续代码
    #累加求和
    s+=i
print('1-100之间的偶数和：',s)