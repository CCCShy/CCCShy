from multiprocessing import Queue

if __name__ == '__main__':
    #创建一个队列
    q=Queue(3)  #最多可以接收三条消息
    print('队列是否为空:',q.empty())      #True
    print('队列是否为满:',q.full())       #False
    #向队列中添加消息
    q.put('hello')
    q.put('world')
    print('队列是否为空:', q.empty())     #False
    print('队列是否为满:', q.full())      #False
    q.put('Python')
    print('队列是否为空:', q.empty())     #False
    print('队列是否为满:', q.full())      #True
    print('队列当中信息的个数:',q.qsize())

    #出队
    print(q.get())
    print('队列当中信息的个数:',q.qsize())
    #入队
    q.put_nowait('HTML')
    # q.put_nowait('SQL')     #queue.Full
    # q.put('SQL')              #不报错，会一直阻塞，等到队列中有空位

    #遍历
    if not q.empty():
        for i in range(q.qsize()):
            print(q.get_nowait())   #nowait() 不等待，如果没有消息出队直接报错
    print('队列是否为空:', q.empty())     #
    print('队列是否为满:', q.full())
    print('队列中的消息个数:', q.qsize())
