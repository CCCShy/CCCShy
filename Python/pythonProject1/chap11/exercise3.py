import time

#记录日志
def write_loginfo(username):
    with open('log.txt', 'a',encoding='utf-8') as file:
        s=f'用户名:{username},登录时间:{time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(time.time()))}\n'
        file.write(s)

#登录系统
def log_in(user_id,password):
    if user_id=='admin' and password=='admin':
        print('Login successful!')
        result=True
    else:
        print('Login failed!')
        result=False
    return result

#读取日志
def read_loginfo():
    with open('log.txt','r',encoding='utf-8') as file:
        while True:
            line=file.readline()
            if line=='':
                break
            else:
                print(line)

#操作系统
def a():
    print('输入提示数字，执行相应操作:0:退出    1:查看登录日志')
    n=input('输入操作数字:')
    if n=='0':
        print('退出成功')
        return True
    elif n=='1':
        print('查看登录日志')
        read_loginfo()
        return False
    else:
        print('输入无效指令，请重新输入')
        return True

if __name__ == '__main__':
    userid=input('请输入用户名:')
    pw=input('请输入密码:')
    if log_in(userid,pw):
        #将登录信息写进日志文件
        write_loginfo(userid)
        while 1:
            #用户操作
            if a():
                break


