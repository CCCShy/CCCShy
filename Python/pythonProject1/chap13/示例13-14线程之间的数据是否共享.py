from threading import Thread

a=100#全局变量
def add():
    print('加线程开始执行')
    global a
    a+=30
    print(f'a的值为:{a}')
    print('加线程结束')

def sub():
    print('减线程开始执行')
    global a
    a-=50
    print(f'a的值为:{a}')
    print('减线程结束')

if __name__ == '__main__':
    #主线程
    print('主线程开始执行')
    print('全局变量a的值为:',a)
    #线程
    p_add=Thread(target=add)
    p_sub=Thread(target=sub)

    p_add.start()
    p_sub.start()
    p_add.join()
    p_sub.join()
    print('主线程执行结束')