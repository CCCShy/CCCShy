from multiprocessing import Queue

if __name__ == '__main__':
    q=Queue(3)
    #向队列中添加元素（入队）
    q.put('hello')
    q.put('world')
    q.put('Python')

    q.put('html')