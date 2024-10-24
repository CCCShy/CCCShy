#(1)import...
import my_info

print(my_info.name)
my_info.info()

import my_info as a #起别名
print(a.name)
a.info()

#(2)from ... import
from my_info import name    #导入的是一个具体的变量名称
print(name)     #不需要写模块名称

from my_info import info    #导入的是一个具体的函数名称
info()

#通配符
from my_info import *
print(name)
info()

#同时导入多个模块
import math,time,random