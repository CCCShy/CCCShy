# 个数可变的位置参数
def fun(*para):
    print(type(para))
    for i in para:
        print(i)
#调用
fun(10,20,30,40,50)
fun(10)
fun(20,30)
fun([11,22,33,44])  #实际上传递的是一个参数
# 在调用时，参数前面加一颗星，将列表进行解包
fun(*[10,20,30,40])


#个数可变的关键字参数
def fun2(**kwpara):
    print(type(kwpara))
    for key,value in kwpara.items():
        print(key,value)
#调用
fun2(name='sun',age=18,height=180)  #关键字参数
d={'name':'sun','age':18,'height':180}
fun2(**d) #TypeError: fun2() takes 0 positional arguments but 1 was given