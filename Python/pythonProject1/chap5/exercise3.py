lst1=['G1569','G1567','G9817','G203']
lst2=[('北京南-天津南','18:06','18:39','00:33'),
      ('北京南-天津南','18:15','18:49','00:34'),
      ('北京南-天津西','18:20','19:19','00:59'),
      ('北京南-天津南','18:35','19:09','00:34')]
d=dict(zip(lst1,lst2))
print('车次\t\t\t出发站-到达站\t\t出发时间\t\t到达时间\t\t历时时长')
for key,value in d.items():
    print(key,value[0],value[1],value[2],value[3],sep='\t\t')
num=input('请输入要购买的车次:')
while True:
    if num in d.keys():
        name=input('请输入乘车人，如果是多位乘车人使用逗号分隔:')
        break
    else:
        print('输入车次信息错误，请重新输入正确车次信息！')
print('您已购买了',d[num][0],' ',d[num][1],'  ',d[num][2],'开，请',name,'尽快换取纸制车票。 【铁路客服】',sep='')