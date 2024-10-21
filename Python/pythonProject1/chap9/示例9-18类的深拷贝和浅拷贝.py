class CPU:
    pass
class Disk:
    pass

class Computer():
    #计算机由CPU和硬盘组成
    def __init__(self, cpu, disk):
        self.cpu = cpu
        self.disk = disk

cpu=CPU()   #创建了一个CPU对象
disk=Disk() #创建了一个硬盘对象

#创建一个计算机对象
com=Computer(cpu,disk)
#变量（对象）的赋值
com1=com
print(com,'子对象的内存地址:',com.cpu,com.disk)         #<__main__.Computer object at 0x0000025B5D80DE80> 子对象的内存地址: <__main__.CPU object at 0x0000025B5D80DEE0> <__main__.Disk object at 0x0000025B5D80DE50>
print(com1,'子对象的内存地址:',com1.cpu,com1.disk)      #<__main__.Computer object at 0x0000025B5D80DE80> 子对象的内存地址: <__main__.CPU object at 0x0000025B5D80DEE0> <__main__.Disk object at 0x0000025B5D80DE50>
#变量地址，子对象地址均相同


#类对象的浅拷贝
import copy
com2=copy.copy(com) #com2是新产生的对象，com2的子对象：cpu，disk
print(com,'子对象的内存地址:',com.cpu,com.disk)         #<__main__.Computer object at 0x0000025B5D80DE80> 子对象的内存地址: <__main__.CPU object at 0x0000025B5D80DEE0> <__main__.Disk object at 0x0000025B5D80DE50>
print(com2,'子对象的内存地址:',com2.cpu,com2.disk)      #<__main__.Computer object at 0x0000025B5D80DF40> 子对象的内存地址: <__main__.CPU object at 0x0000025B5D80DEE0> <__main__.Disk object at 0x0000025B5D80DE50>
#变量地址不相同，子对象地址相同


#类对象的深拷贝
import copy
com3=copy.deepcopy(com) #com3是新产生的对象，com3的子对象：cpu，disk
print(com,'子对象的内存地址:',com.cpu,com.disk)         #<__main__.Computer object at 0x0000025B5D80DE80> 子对象的内存地址: <__main__.CPU object at 0x0000025B5D80DEE0> <__main__.Disk object at 0x0000025B5D80DE50>
print(com3,'子对象的内存地址:',com3.cpu,com3.disk)      #<__main__.Computer object at 0x0000015EA0F2E540> 子对象的内存地址: <__main__.CPU object at 0x0000015EA0F2E5D0> <__main__.Disk object at 0x0000015EA0F2E840>
#变量地址不相同，子对象地址也不相同