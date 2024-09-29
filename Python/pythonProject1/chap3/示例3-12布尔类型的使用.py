x=True
print(x)
print(type(x))
print(x+10)     #11 --> 1+10
print(False+10) #10 --> 0+10
print('-------------------------')
print(bool(18)) #测试一下整数18的bool值 True
print(bool(0),bool(0.0)) #False
#总结：非0的整数布尔值都为True
print(bool('0')) #True
print(bool(''))  #False
#所有非空字符串的布尔值都是True
print(bool(True))   #True
print(bool(False))  #False
print(bool(None))   #False