import random
rand=random.randint(1,100)
x=0
count=0
while x!=rand:
    x=eval(input('在我心中有个数，1-100之间，请你猜一猜:'))
    if x>rand:
        print('大了')
    elif x<rand:
        print('小了')
    count+=1
else:
    print('恭喜你！猜对了！一共猜了'+str(count)+'次')