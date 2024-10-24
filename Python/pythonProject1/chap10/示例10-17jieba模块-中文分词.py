import jieba

#读取数据
with open('Python学前指导.txt','r',encoding='utf-8') as file:
    s=file.read()
# print(s)

# 分词
lst=jieba.lcut(s)
# print(lst)
#
#去重操作
set1=set(lst)   #使用集合去实现去重
#统计词出现频率
#初始化字典，及其次数为0
d={}    #key:词  ，value:出现的次数
for item in set1:
    if len(item)>=2:
         d[item]=0
# print(d)
#
#计算每个词出现频率
for item in lst:
    if item in d:
        d[item]=d.get(item)+1
# print(d)

#字典转列表，因为需要排序
new_lst=[]
for item in d:
    new_lst.append([item,d[item]])
# print(new_lst)

#排序
new_lst.sort(key=lambda x:x[1],reverse=True)
print(new_lst[0:11])
input()
