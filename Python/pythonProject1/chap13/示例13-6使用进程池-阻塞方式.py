from multiprocessing import Pool
import time,os

#编写任务
def task(name):
    print(f'子进程的PID:{os.getpid()},执行的任务:{name}')
    time.sleep(1)

if __name__ == '__main__':
    #主进程
    start = time.time()
    print('主进程开始执行')
    #创建进程池
    p=Pool(3)
    #创建任务
    for i in range(10):
        #以非阻塞的方式
        p.apply(func = task, args=(i,))

    p.close()   #关闭进程池不再接收新任务
    p.join()    #阻塞一下父进程，等待所有的子进程执行完毕之后，才会执行父进程中的代码
    print('所有的子进程执行完毕，父进程执行结束')
    print(time.time()-start)