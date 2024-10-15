def fun(s):
    lst=[]
    for j in range(len(s)):
        if s[j].isdigit():
            lst.append(int(s[j]))
    #求和
    sum1=sum(lst)
    return lst,sum1

string=input('请输入一个字符串:')
lst_num,x=fun(string)               #系列解包赋值
print(f'提取的数字列表为:{lst_num}')
print(f'累加和为:{x}')