list1=[88,89,90,98,00,99]
print('原列表：',list1)

for i in range(0,len(list1)):
    if list1[i]==0:
        list1[i]+=2000
    else:
        list1[i]+=1900
print(list1)

list1=[88,89,90,98,0,99]
print('原列表：',list1)
for i in range(0,len(list1)):
    if list1[i]==0:
        list1[i]='200'+str(list1[i])
    else:
        list1[i]='19'+str(list1[i])
print(list1)

#使用enumerate()函数
list1=[88,89,90,98,0,99]
for index,item in enumerate(list1):
    if item == 0:
        list1[index] = '200' + str(item)
    else:
        list1[index] = '19' + str(item)
print(list1)