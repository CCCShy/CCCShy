from datetime import datetime   #从datetime模块中 导入datetime类
dt=datetime.now()
print('当前的系统时间为:',dt)

#datetime是一个类，手动创建这个类的对象
dt2=datetime(2028,8,8,8,8,8)
print('dt2的数据类型：',type(dt2),'dt2所表示的日期时间：',dt2)
print('年：',dt2.year,'月：',dt2.month,'日：',dt2.day,'时：',dt2.hour,'分：',dt2.minute,'秒：',dt2.second)

#比较两个datetime类型对象的大小
labor_day=datetime(2028,8,8,8,8,8)
now_day=datetime.now()
print(labor_day<now_day)

#datetime类型与字符串进行转换
nowdt=datetime.now()
nowdt_str=nowdt.strftime('%Y%m%d %H:%M:%S')
print('nowdt的数据类型：',type(nowdt),nowdt)
print('nowdt_str的数据类型：',type(nowdt_str),nowdt_str)

#字符串类型转成datetime类型
str_datetime='2024年10月22号10点56分59秒'
dt3=datetime.strptime(str_datetime,'%Y年%m月%d号%H点%M分%S秒')
print('str_datetime的数据类型：',type(str_datetime),str_datetime)
print('dt3的数据类型：',type(dt3),dt3)