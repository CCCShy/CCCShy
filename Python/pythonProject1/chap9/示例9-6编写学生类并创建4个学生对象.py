class Student:
    #类属性：定义在类中，方法外的变量
    school='hdu'

    #初始化方法
    def __init__(self,xm,age):    #name,age是方法的参数，是局部变量，name、age的作用域是整个__init__方法
        self.name=xm              #=左侧是实例属性，xm是局部变量，将局部变量的值xm赋给实例属性self.name
        self.age=age              #实例属性的名称可以和局部变量的名称可以相同

#定义在类中的函数，称为方法，自带一个参数self
    def show(self):
        print(f'我叫{self.name},我今年{self.age}岁了')

#根据类创建n多个对象
stu=Student('hjr',18)
stu2=Student('ccm',20)
stu3=Student('ssy',24)
stu4=Student('ddl',23)
print(type(stu))
print(type(stu2))
print(type(stu3))
print(type(stu4))

Student.school='Python' #给类的属性赋值

#将学生对象存储到列表中
lst=[stu,stu2,stu3,stu4]    #列表中的元素是Student类型的对象
for item in lst:            #item是列表中的元素，是Student类型的对象
    item.show()             #对象名打点调用实例方法
print(Student.school)
