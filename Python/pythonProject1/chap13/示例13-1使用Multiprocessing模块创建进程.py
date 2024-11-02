from multiprocessing import Process
import os,time

def test():
    print(f'子进程(PID:{os.getpid()}),父进程为:{os.getppid()}')
    time.sleep(2)

if __name__ == '__main__':
    print('主进程开始执行')
    lst=[]
    #创建五个子进程
    for i in range(5):
        #创建子进程
        p = Process(target=test)
        #启动子进程
        p.start()
        #启动中的进程添加到列表中
        lst.append(p)

    #遍历lst，列表中的五个子进程
    for item in lst:        #item的数据类型是 Process类型
        item.join()         #阻塞主进程

    print('主进程执行结束')
    #主进程要等到所有的子进程执行完毕之后，主进程才会执行结束