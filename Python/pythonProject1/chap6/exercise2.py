import re
s='HelloPython,HelloJava,hellophp'
search_char=input('请输入要统计的字符:')
result=re.findall(search_char,s,re.I)
print('{0}在{1}中一共出现了{2}次'.format(search_char,s,len(result)))