class Person(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def show(self):
        print(f'大家好，我叫{self.name}，我今年{self.age}岁')


#创建Person类对象
per=Person('nn',18)    #创建对象时会自动调用__init__()方法
print(dir(per))

print(per)  #自动调用了__str__方法