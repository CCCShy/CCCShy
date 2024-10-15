def get_find(s,lst):
    for i in lst:
        if i==s:
            return True
    return False


lst=['hello','world','python']
string=input('请输入您要判断的字符串:')
if get_find(string,lst):
    print('存在')
else:
    print('不存在')