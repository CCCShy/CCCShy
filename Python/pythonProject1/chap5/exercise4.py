s=set()
for i in range(1,6):
    #print('请输入第',i,'位好友的姓名与手机号码:',end='',sep='')
    s.add(input(f'请输入第{i}位好友的姓名与手机号码:'))
for item in s:
    print(item)