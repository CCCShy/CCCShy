class Student:
    # 首位双下划线
    def __init__(self, name, age, gender):
        self._name=name # self._name受保护的，只能本类和子类访问
        self.__age=age  # self.__age表示私有的，只能类本身去访问
        self.gender=gender  #普通的实例属性，类的内部、外部，及子类都可以访问
    def _fun1(self):    #受保护的
        print('子类本身可以访问')

    def __fun2(self):   #私有的
        print('只有定义的类可以访问')

    def show(self):     #普通的实例方法
        self._fun1()    #类本身访问受保护的方法
        self.__fun2()   #类本身访问私有的方法
        print(self._name)   #受保护的实例属性
        print(self.__age)   #私有的实例属性

#创建一个学生类的对象
stu=Student('ssl',20,'女')
# 类的外部
print(stu._name)
# print(stu.__age)    #AttributeError: 'Student' object has no attribute '__age'. Did you mean: '_name'?

#调用受保护的实例方法
stu._fun1()
#私有方法
# stu.__fun2()          #AttributeError: 'Student' object has no attribute '__fun2'. Did you mean: '_fun1'?

#私有的实例属性和方法访问方法
print(stu._Student__age)
stu._Student__fun2()

#查看stu所属类内部所有的属性和方法
print(dir(stu))