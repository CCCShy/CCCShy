import socket

#(1)创建socket对象
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#(2)IP地址和主机（服务器）端口  向服务器端发送请求
ip='192.168.0.103'
port=8888
client_socket.connect((ip, port))
print('与服务器连接建立成功')
#(3)发送数据
client_socket.send('Hello, client!'.encode('utf-8'))
#(4)关闭
client_socket.close()
print('发送完毕')