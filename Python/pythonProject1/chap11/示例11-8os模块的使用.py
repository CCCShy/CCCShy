import os

#获取当前的工作路径
print('当前的工作路径:',os.getcwd())

#获取path路径下的文件和目录信息
lst=os.listdir()
print('当前路径下所有目录及文件:',lst)
print('指定路径下所有目录及文件:',os.listdir('D:\\Code\\embedded_-learning_-code\\Python\\pythonProject1'))

#在指定路径下创建目录
# os.mkdir('好好学习')    #FileExistsError: [WinError 183] 当文件已存在时，无法创建该文件。: '好好学习'     如果创建的文件存在则报错
# os.makedirs('./aa/bb/cc')

#删除目录
# os.rmdir('./好好学习')  #./表示当前路径   FileNotFoundError: [WinError 2] 系统找不到指定的文件。: './好好学习'   如果删除的文件不存在则报错
# os.removedirs('./aa/bb/cc')

#把path设置为当前目录
os.chdir('D:\\Code\\embedded_-learning_-code\\Python\\pythonProject1')
print('当前的工作路径:',os.getcwd())   #再写代码，工作路径就已经改变
print('-'*40)

#遍历目录树，结果为元组，包含所有的路径名、所有目录列表和文件列表,相当于递归操作
for dirs,dirlst,filelst in os.walk('D:\\Code\\embedded_-learning_-code\\Python\\pythonProject1\\chap10'):
    print('路径名',dirs)
    print('目录列表',dirlst)
    print('文件列表',filelst)
    print('-'*40)