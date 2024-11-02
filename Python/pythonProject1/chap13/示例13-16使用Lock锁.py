import threading
from threading import Thread,Lock
import time

ticket=50   #代表50张车票

lock_obj=Lock() #创建锁对象

def sale_ticket():
    global ticket
    #每个窗口有100人
    for i in range(100): #每个线程要循环100次
        lock_obj.acquire()  #上锁
        if ticket>0:
            print(f'{threading.current_thread().name}正在出售第{ticket}张票')
            ticket-=1
        time.sleep(1)
        lock_obj.release()  #释放锁

if __name__ == '__main__':
    for i in range(3): #创建三个线程，代表三个售票窗口
        t=Thread(target=sale_ticket)
        t.start()