class Student:
    def __init__(self, name, gender):
        self.name = name
        self.__gender = gender  #self.__gender 私有的实例属性

    # 使用@property 修改方法，将方法转成属性使用
    @property
    def gender(self):
        return self.__gender

    @gender.setter
    def gender(self,value):
        if value != 'male' and value != 'female':
            print('性别有误，已将性别默认设置为male')
            self.__gender = 'male'
        else:
            self.__gender = value

stu=Student('hjr','female')
print(stu.name,'的性别是：',stu.gender)  #stu.gender就会去执行stu.gender()
#尝试修改属性值
# stu.gender='male'   #AttributeError: property 'gender' of 'Student' object has no setter
stu.gender='其他'
print(stu.name,'的性别是',stu.gender)