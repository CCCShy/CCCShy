s='伟大的中国梦'
# 编码str->bytes
scode=s.encode(errors='replace')    #默认是utf-8，因为utf-8中文占3个字节
print(scode)

scode_gbk=s.encode('gbk', errors='replace') #gbk中中文占2个字节
print(scode_gbk)

#编码中的出错问题
#ignore
s2='耶✌'
scode2=s2.encode('gbk',errors='ignore')
print(scode2)    #忽略了后面的无法识别字符

#strict
# s2='耶✌'
# scode=s2.encode('gbk',errors='strict')
# print(scode)    #直接报错

#replace
s2='耶✌'
scode2=s2.encode('gbk',errors='replace')
print(scode2)    #直接替换为？

#解码过程  bytes->str
print(bytes.decode(scode_gbk,'gbk'))
print(bytes.decode(scode,'utf-8'))