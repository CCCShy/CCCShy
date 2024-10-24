from datetime import datetime
from datetime import timedelta

# str1=input('请输入开始日期:(20241001)后按回车:')
# dt1=datetime(int(str1[0:4]),int(str1[4:6]),int(str1[6:8]))
# num=eval(input('请输入时间间隔:'))
# td1=timedelta(num)
# print('您推算的日期是:',dt1+td1)

def input_usage():
    inputdate=input('请输入开始日期:(20280101)后按回车:')
    datestr=inputdate[0:4]+'-'+inputdate[4:6]+'-'+inputdate[6:]
    #类型转换
    dt=datetime.strptime(datestr,'%Y-%m-%d')
    return dt

if __name__=='__main__':
    date=input_usage()
    #输入间隔天数
    in_num=eval(input('请输入间隔天数:'))
    date=date+timedelta(days=in_num)
    print('您推算的日期是:',date)