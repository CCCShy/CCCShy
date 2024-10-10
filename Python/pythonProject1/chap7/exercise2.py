from logging import raiseExceptions

try:
    num_lst=[]
    for i in range(3):
        num_lst.append(int(input(f"请输入第{i+1}条边:")))
    if num_lst[0]+num_lst[1]<=num_lst[2] or num_lst[0]+num_lst[2]<=num_lst[1] or num_lst[1]+num_lst[2]<=num_lst[0]:
        raise Exception('a={0},b={1},c={2},不能构成三角形'.format(num_lst[0],num_lst[1],num_lst[2]))
except Exception as e:
    print(e)
else:
    print('三角形的边长为:a={0},b={1},c={2}'.format(num_lst[0],num_lst[1],num_lst[2]))