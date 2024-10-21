class Student:
    school='hdu'
    def __init__(self,xm,age):
        self.name=xm
        self.age=age

    def show(self):
        print(f'我叫{self.name},今年{self.age}岁了')

stu1=Student('ysj',20)
stu2=Student('nn',20)
print(stu1.name,stu1.age)
print(stu2.name,stu2.age)

#为stu2动态绑定一个实例属性
stu2.gender='女'
print(stu2.name,stu2.age,stu2.gender)

# print(stu1.gengder)  #AttributeError: 'Student' object has no attribute 'gengder'
#动态绑定方法
def introduce():
    print('这是一个函数，被动态绑定成了stu2对象的方法')
stu2.fun=introduce  #函数的一个赋值，不能加小括号()
#fun就是stu2对象的方法
#调用
stu2.fun()