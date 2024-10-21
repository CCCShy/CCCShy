class Student(object):
    def __init__(self, name, age, gender, score):
        self.name = name
        self.age = age
        self.gender = gender
        self.score = score

    #示例方法
    def info(self):
        print(f'{self.name}\t{self.age}\t{self.gender}\t{self.score}')

print('请输入5位学生信息：格式为（姓名#年龄#性别#成绩）')
lst_m=[]
for i in range(5):
    message=input(f'请输入第{i+1}位学生信息及成绩:')
    lst=message.split('#')
    s=Student(lst[0],lst[1],lst[2],lst[3])
    lst_m.append(s)

for i in range(5):
    lst_m[i].info()