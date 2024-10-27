import os
import os.path

def create_newdir(path,num):
    for i in range(1,num+1):
        os.mkdir(path+str(i))

if __name__ == '__main__':
    path='./newdir/'
    if not os.path.exists(path):
        os.mkdir(path)
    n = eval(input('请输入要创建的目录个数:'))
    create_newdir(path,n)