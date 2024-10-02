number=eval(input("请输入6位中奖号码:"))
#if...else
if number==987654:
    print('恭喜您中大奖了！')
    print('可以去买车了！')
else:
    print('很遗憾您未中奖')
    print('回家洗洗睡吧！')

print('-----以上代码可以使用条件表达式进行简化-----')
result='恭喜您中奖了' if number==987654 else '您未中本期大奖'
print(result)
print('恭喜您中奖了' if number==987654 else '您未中本期大奖')