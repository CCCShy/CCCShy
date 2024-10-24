#主程序运行，防止在被调用时自动执行全局模块中的代码
if __name__ == '__main__':
    print('welcome to Beijing')
    name = 'Jerry'
    print(name)