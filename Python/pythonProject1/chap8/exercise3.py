def lower_upper(s):
    ad_lst=[]
    for i in range(len(s)):
        if s[i].islower():
            ad_lst.append(s[i].upper())
        elif s[i].isupper():
            ad_lst.append(s[i].lower())
        else:
            ad_lst.append(s[i])
    return ''.join(ad_lst)

def lower_upper_teach(s):
    lst=[]
    for item in s:
        if 'A'<= item <= 'Z':
            lst.append(chr(ord(item)+32))  #ord()将字母转成Unicode码整数，加上32，chr()整数码转成字符
        elif 'a'<= item <= 'z':
            lst.append(chr(ord(item)-32))
        else:
            lst.append(item)
    return ''.join(lst)

string=input('请输入一个字符串:')
new_string=lower_upper_teach(string)
print(new_string)

