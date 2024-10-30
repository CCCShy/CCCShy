import socket

#(1)创建socket对象
socket_server=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

#(2)绑定服务器的ip和端口
ip='192.168.0.103'
port=7777
socket_server.bind((ip,port))

#(3)接收来自client消息
while 1:
    recv_data,client_addr=socket_server.recvfrom(1024)
    print(f'客户({client_addr})消息:{recv_data.decode('utf-8')}')
    if recv_data.decode('utf-8')=='bye':
        break

#(4)发送给client消息
    send_data=input('回复客户:')
    socket_server.sendto(send_data.encode('utf-8'),client_addr)
    if send_data == 'bye':
        break

#(5)关闭socket对象
socket_server.close()