import re
pattern='黑客|破解|反爬|杀人'
s='我想学习Python，想破解一些VIP视频，Python可以实现无底线反爬吗，如果实现不了我想杀人了'
new_s=re.sub(pattern,'***',s)
print(new_s)

s2='https://cn.bing.com/search?pglt=169&q=syl&cvid'
pattern='\?|&'
#pattern='[?|&]'
lst=re.split(pattern,s2)
print(lst)