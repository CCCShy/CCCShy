#
import admin.my_info as a #包名.模块名  admin是包名，my_info是模块名
a.info()                  #包内代码自动执行

print('-'*40)
from admin import my_info as b #from 包名 import模块 as 别名
b.info()                       #__init__.py包内代码不会被执行

print('-'*40)
from admin.my_info import info  #from 包名.模块名 import 函数/变量等
info()

print('-'*40)
from admin.my_info import *     #from 包名.模块名 import *
info()
print(name)