data=eval(input('请输入要匹配的数据：'))
match data:
    case {'name':'shy','age':'25'}:
        print('字典')
    case [10,20,30]:
        print('列表list')
    case (10,20,40):
        print('元组')
    case _:
        print('相当于if当中的else')