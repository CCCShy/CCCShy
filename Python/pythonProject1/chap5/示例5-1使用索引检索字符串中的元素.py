#正向递增索引
s='helloworld'
for i in range(0,len(s)):
    print(i,s[i],end='\t\t')
print('\n---------------------------------')
for i in range(-10,0):
    print(i,s[i],end='\t\t')
print('\n',s[9],s[-1])