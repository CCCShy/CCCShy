import os
import os.path
import re

#创建或验证replay文件
def create_replay():
    if not os.path.exists('replay.txt'):
        with open('replay.txt', 'w') as f:
            lst = [
                '订单|如果您有任何订单问题，可以登录淘宝账号，点击“我的订单”，查看订单详情\n',
                '物流|如果您有任何物流问题，可以登录淘宝账号，点击“我的订单”，查看商品物流\n',
                '账户|如果您有任何账户问题，可以联系淘宝客服，电话：XXXXX-XXXXX\n',
                '支付|如果您有任何支付问题，可以联系支付宝客服'
            ]
            f.writelines(lst)

def replay(question):
    with open('replay.txt', 'r') as f:
        while True:
            line=f.readline()
            if line=='':
                break
            keyword=line.split('|')[0]
            rep=line.split('|')[1]
            if keyword in question:
                return rep
    return False

if __name__ == '__main__':
    create_replay()
    question=input('HI,XXX你好，小蜜蜂在此等主人很久了，有什么烦恼快和小蜜蜂说吧~')
    while True:
        if not replay(question):
            question=input('小蜜蜂不知道您说的是什么，您可以问一些关于订单、物流、支付、账户等问题，退出请输入bye')
        else:
            print(replay(question))
            question=input('您还可以继续问一些关于订单、物流、支付等问题，退出请输入bye')
        if question=='bye':
            break
