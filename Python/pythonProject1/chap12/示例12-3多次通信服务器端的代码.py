import socket

#(1)创建socket对象
socket_obj=socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#(2)绑定主机IP地址和端口
ip='192.168.0.103'  #127.0.0.1相当于local
port=8888           #端口的范围
socket_obj.bind((ip,port))

#(3)使用listen开始监听
socket_obj.listen(5)
print('server is starting,waiting for a connection')

#(4)等待客户端的连接
client_socket,client_address=socket_obj.accept()

#接收数据
info=client_socket.recv(1024).decode('utf-8')                  #while 循环的四个步骤 info是初始化变量
while info != 'bye':                                        #条件判断
    if info != '':
        print('接收到的数据是:',info)
    #准备发送的数据
    data=input('请输入要发送的数据:')

    #服务器端回复客户端
    client_socket.send(data.encode('utf-8'))
    if data=='bye':
        break
    info = client_socket.recv(1024).decode('utf-8')            #改变变量

#关闭socket对象
client_socket.close()
socket_obj.close()