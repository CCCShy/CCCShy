s='daskdhioahdaiowhoiaasjbfahuaofaoafdsklfh'
#(1)字符串拼接及not in去重
new_s=''
for items in s:
    if items not in new_s:
        new_s+=items
print(new_s)

#(2)使用索引+not in去重
new_s2=''
for i in range(len(s)):
    if s[i] not in new_s2:
        new_s2+=s[i]
print(new_s2)

#(3)通过集合去重+列表排序操作
new_s3=set(s)
lst=list(new_s3)
lst.sort(key=s.index)
print(''.join(lst))