import re
pattern='\d\.\d+'
s='I study Python3.11 every day Python 2.11 I love you'
match=re.search(pattern,s)
print(match)

s2='4.10 Python I study every day'
match2=re.search(pattern,s2)
print(match2)

s3='Python I study every day'
match3=re.search(pattern,s3)        #None
print(match3)

print(match.group())
print(match2.group())
