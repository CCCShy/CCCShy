import socket

#(1)创建socket对象
client_socket=socket.socket()   #客户端创建socket对象不需要传参
#(2)主机（服务器）的IP地址和端口  向服务器端发送请求
client_socket.connect(('192.168.0.103',8888))
print('已建立服务器连接')
#(3)客户端先发送数据
info=''
while info != 'bye':
    #准备发送的数据
    send_data=input('请输入要发送给服务器的数据:')
    client_socket.send(send_data.encode('utf-8'))
    #判断
    if send_data == 'bye':
        break
    info=client_socket.recv(1024).decode('utf-8')
    print('收到服务器响应的数据:',info)

#(4)关闭socket对象
client_socket.close()
