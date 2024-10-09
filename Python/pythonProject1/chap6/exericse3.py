product_list=[['01','电风扇','美的',500],
              ['02','洗衣机','TCL',1000],
              ['03','微波炉','老板',400]]
print('编号\t\t名称\t\t\t品牌\t\t单价')
for item in product_list:
    print('{0}\t\t{1}\t\t{2}\t\t{3}'.format(item[0],item[1],item[2],item[3]))
print('编号\t\t\t名称\t\t\t品牌\t\t单价')
for item in product_list:
    print('{0:0<6}\t\t{1}\t\t{2}\t\t￥{3:.2f}'.format(item[0], item[1], item[2], item[3]))