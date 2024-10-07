lst1=[]
lst2=[]
lst3=[]
for i in range(0,5):
    mes=input('请输入商品的编号和商品的名称进行商品入库，每次只能输入一件商品：')
    lst1.append(mes[0:4])
    lst2.append(mes[4:])
d=dict(zip(lst1,lst2))
for key,value in d.items():
    print(key,value,sep='')
while True:
    num=input('请输入要购买的商品编号:')
    if num in d.keys():
        lst3.append(num+d[num])
        print('商品已成功添加到购物车')
    elif num=='q':
        break
    else:
        print('该商品不存在！')
print('------------------------------------')
print('您购物车里已选择的商品为：')
lst3.reverse()
for i in range(0,len(lst3)):
    print(lst3[i])