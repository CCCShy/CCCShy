from multiprocessing import Queue

if __name__ == '__main__':
    q=Queue(3)
    #向队列中添加元素（入队）
    q.put('hello')
    q.put('world')
    q.put('Python')

    q.put('html',block=True,timeout=2)  #等待2秒后，队列还没有空位置就抛异常