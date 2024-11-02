import threading
from threading import Thread, current_thread
import time

#编写函数
def test():
    for i in range(3):
        time.sleep(1)
        print(f'线程{threading.current_thread().name}正在执行{i}')

if __name__ == '__main__':
    #主程序运行
    start_time = time.time()
    print('主线程开始执行')

    #线程
    lst=[Thread(target=test) for i in range(2)]
    for item in lst:
        #启动线程
        item.start()
    #阻塞主线程直到子线程执行完毕
    for item in lst:
        item.join()
    print(f'一共消耗时间:{time.time() - start_time}')