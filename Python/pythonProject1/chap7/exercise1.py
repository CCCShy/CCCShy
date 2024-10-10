try:
    score=int(input('请输入分数:'))
    if score>100 or score<0:
        raise ValueError('分数不正确')
except ValueError as e:
    print(e)
else:
    print(f'分数为:{score}')