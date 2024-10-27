#存储和读取一维数组
def my_write():
    #一维数据，可以使用列表，元组，或集合
    lst=['张三','李四','王五','陈六','麻七']
    with open('student.csv','w',encoding='utf-8') as file:
        file.write(','.join(lst))   #将列表转成字符串

def my_read():
    with open('student.csv','r',encoding='utf-8') as file:
        s=file.read()
        lst=s.split(',')
        print(lst)
#注意类型转换，写入时需列表转成字符串，读取时需字符串转成列表

#存储和读取二维数据
def my_write_table():
    lst=[
        ['商品名称','单价','采购数量'],
        ['水杯','98.5','20'],
        ['鼠标','89','100']
    ]
    with open('table.csv','w',encoding='utf-8') as file:
        for item in lst:
            file.write(','.join(item))
            file.write('\n')

def my_read_table():
    data=[]     #存储读取的数据
    with open('table.csv','r',encoding='utf-8') as file:
        lst=file.readlines()    #每一行是列表中的一个元素
        # print(type(lst),lst)
        for i in range(len(lst)):
            lst[i]=lst[i].rstrip('\n')
            new_lst=lst[i].split(',')
            data.append(new_lst)
    print(data)

if __name__ == '__main__':
    # my_write()
    # my_read()
    # my_write_table()
    my_read_table()