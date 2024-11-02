from multiprocessing import Queue,Process
import time

a=100

def write_msg(q):   #q 队列
    global a
    if not q.full():
        for i in range(6):
            a-=10
            q.put(a)    #入队
            print(f'a入队时的值:{a}')

#出队
def read_msg(q):
    time.sleep(1)
    while not q.empty():
        print(f'出队时a的值:{q.get()}')

if __name__ == '__main__':
    print('父进程开始执行')
    q=Queue()   #父进程创建队列，没有指定参数，说明可接收消息的个数没有上限
    #创建两个子进程
    p1=Process(target=write_msg, args=(q,))
    p2=Process(target=read_msg, args=(q,))
    #启动两个子进程
    p1.start()
    p2.start()
    #等待写的进程执行结束，再去执行主进程
    p1.join()
    p2.join()
    print('父进程执行完毕')