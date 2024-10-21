class Person:   #默认继承了object
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def show(self):
        print(f'大家好，我叫{self.name}，我今年：{self.age}岁')

#Student继承Person类
class Student(Person):
    #编写初始化的方法
    def __init__(self, name, age, stuno):
        super().__init__(name, age) #调用父类的初始化方法
        self.stuno = stuno
    def show(self):
        super().show()
        print(f'我的学号是{self.stuno}')

#Doctor继承Person类
class Doctor(Person):
    def __init__(self, name, age, department):
        super().__init__(name, age)
        self.department = department
    def show(self):
        # super().show()                  #调用父类中show方法
        print(f'大家好我叫{self.name},我今年{self.age}岁,我的工作科室是:{self.department}')

#创建第一个子类
stu=Student('hjr',24,'1001')
stu.show()

doctor=Doctor('zyy',26,'外科')
doctor.show()       #调用子类自己的show()方法