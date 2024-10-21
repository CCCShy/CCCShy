class Car:
    def __init__(self, car_type, license_number):
        self.car_type = car_type
        self.license_number = license_number

    def start_car(self):
        pass

    def stop_car(self):
        pass

class PrivateCar(Car):
    def __init__(self, car_type, license_number, name):
        super().__init__(car_type, license_number)
        self.name = name

    def start_car(self):
        print(f'我是{self.name}，我的汽车我做主')

    def stop_car(self):
        print('目的地到了，我们去玩吧')

class TaxiCar(Car):
    def __init__(self, car_type, license_number, company):
        super().__init__(car_type, license_number)
        self.company = company

    def start_car(self):
        print(f'乘客您好！\n我是{self.company}的，我的车牌是：{self.license_number}，您要去哪里？')

    def stop_car(self):
        print('目的地到了，请您付款下车，欢迎下次乘坐')

pc=PrivateCar('小轿车','新A88888','老司机')
pc.start_car()
pc.stop_car()
print('-'*40)
tc=TaxiCar('小轿车','京A88888','北京天龙人出租车有限公司')
tc.start_car()
tc.stop_car()