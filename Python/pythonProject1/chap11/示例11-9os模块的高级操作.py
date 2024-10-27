import os
#删除文件
# os.remove('./a.txt')    #FileNotFoundError: [WinError 2] 系统找不到指定的文件。: './a.txt'     如果要删除的文件不存在，则程序报错

#重命名
# os.rename('./aa.txt','./new_aa.txt')

#获取path指定的文件信息
#转换时间的格式
import time
def date_format(longtime):
    s=time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(longtime))
    return s

#获取文件信息
info=os.stat('./new_aa.txt')

print(type(info))
print(info)

print('最后一次访问时间:',date_format(info.st_atime))
print('在windows操作系统中显示的文件创建时间:',date_format(info.st_ctime))
print('最后一次修改时间:',date_format(info.st_mtime))
print('文件的大小(单位是字节):',info.st_size)

#启动路径下的文件
# os.startfile('calc.exe')
#启动Python解释器
os.startfile(r'D:\Program Files\Python\Python312\python.exe')   #前面加r使所有转义字符失效