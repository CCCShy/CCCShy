import math
class Circle:
    def __init__(self, radius):
        self.radius = radius

    def get_area(self):
        return math.pi*self.radius**2

    def get_perimeter(self):
        return 2*math.pi*self.radius

r=eval(input('请输入圆的半径:'))
print('圆的面积为：',round(Circle(r).get_area(),2))
print('圆的周长为：',round(Circle(r).get_perimeter(),2))