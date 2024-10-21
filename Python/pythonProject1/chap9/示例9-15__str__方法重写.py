# #重写前
# class Person(object):
#     def __init__(self, name, age):
#         self.name = name
#         self.age = age
#
# #创建Person类的对象
# per=Person('nn',18)
# print(per)


#重写后
class Person(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age
#方法重写
    def __str__(self):
        return '这是一个人类，具有name和age两个实例属性'    #返回值是一个字符串


per=Person('nn',19)
print(per)  #不是内存地址了，是重写__str__()方法中的内容，默认调用了__str__()
print(per.__str__())    #手动调用