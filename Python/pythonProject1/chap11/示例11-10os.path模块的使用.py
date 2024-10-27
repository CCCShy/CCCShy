import os.path

print('获取目录或文件的绝对路径',os.path.abspath('./b.txt'))
print('判断目录或文件在磁盘上是否存在',os.path.exists('./b.txt'))  #相对路径   True
print('判断目录或文件在磁盘上是否存在',os.path.exists('./newb.txt'))  #相对路径    False
print('判断目录或文件在磁盘上是否存在',os.path.exists('./好好学习'))  #目录  False
print('拼接路径:',os.path.join(r'D:\Code\embedded_-learning_-code\Python\pythonProject1\chap11','b.txt'))
print('分割文件的名和文件后缀名:',os.path.splitext('b.txt'))    #元组类型
print('提取文件名:',os.path.basename(r'D:\Code\embedded_-learning_-code\Python\pythonProject1\chap11\b.txt'))    #b.txt
print('提取路径:',os.path.dirname(r'D:\Code\embedded_-learning_-code\Python\pythonProject1\chap11\b.txt'))      #D:\Code\embedded_-learning_-code\Python\pythonProject1\chap11
print('判断一个路径是否是有效路径:',os.path.isdir(r'D:\Code\embedded_-learning_-code\Python\pythonProject1\chap11')) #True
print('判断一个路径是否是有效路径:',os.path.isdir(r'D:\Code\embedded_-learning_-code\Python\pythonProject1\chap11\b.txt')) #False
print('判断一个file是否是有效文件:',os.path.isfile(r'D:\Code\embedded_-learning_-code\Python\pythonProject1\chap11\b.txt'))    #True
