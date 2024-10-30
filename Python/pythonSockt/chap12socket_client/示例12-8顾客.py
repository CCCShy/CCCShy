import socket

#(1)创建socket对象
socket_client=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

#(2)发送给server数据
while 1:
    send_data=input('发送给客服:')
    ip_port=('192.168.0.103',7777)
    socket_client.sendto(send_data.encode('utf-8'),ip_port)
    if send_data == 'bye':
        break

#(3)接收server数据
    recv_data,server_addr=socket_client .recvfrom(1024)
    print(f'客服人员({server_addr}):{recv_data.decode('utf-8')}')
    if recv_data.decode('utf-8') == 'bye':
        break

#(4)关闭socket对象
socket_client.close()
