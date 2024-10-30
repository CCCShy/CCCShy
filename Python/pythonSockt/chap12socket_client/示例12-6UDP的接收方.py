import socket

#(1)创建socket对象
recv_socket=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
#(2)绑定IP地址和端口
ip='192.168.0.103'
port=9999
recv_socket.bind((ip,port))
#(3)接收来自发送方的数据
recv_data,addr=recv_socket.recvfrom(1024)
print('接收到的数据为:',recv_data.decode('utf-8'))
print('消息来源于:',addr)
#(4)准备回复对方的数据
data=input('请输入要回复的数据')
recv_socket.sendto(data.encode('utf-8'),addr)

#(5)关闭
recv_socket.close()