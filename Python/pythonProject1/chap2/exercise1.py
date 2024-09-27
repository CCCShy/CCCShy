#练习1：输出“人生苦短，我用Python”到文本文件“text.txt”
#coding=gbk
fp=open('text.txt','w') #打开文件
print('人生苦短，我用Python',file=fp) #输出内容到文件
fp.close() #关闭文件