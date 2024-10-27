import random
import os
import os.path

def random_hex():
    num=hex(random.randint(0,16**10))
    return num

def create_file(num,path_1):
    lst = ['水果', '烟酒', '粮油', '肉蛋', '蔬菜']
    for i in range(1,num+1):
        with open(path_1+'{0:0>4}_{1}_{2}.txt'.format(str(i),random.choice(lst),random_hex()[-10:-1]), 'w'):
            pass

if __name__ == '__main__':
    random.seed()
    #在指定路径下创建文件
    path='./test_3000/'
    if not os.path.exists(path):
        os.mkdir(path)

    create_file(3000,path)