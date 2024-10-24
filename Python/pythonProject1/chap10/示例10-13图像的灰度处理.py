import numpy as np
import matplotlib.pyplot as plt     #pip install matplotlib

#读取图片
n1=plt.imread('pic.jpg')
print(type(n1),n1)  #数组，三维数组，最高维度表示的是图像的高，次高维度表示的是图像的宽，最低维度[R,G,B]颜色
plt.imshow(n1)

#编写一个灰度公式
n2=np.array([0.299,0.587,0.114])    #创建数组
#将数组n1(RGB)颜色与数组n2(灰度公式固定)，进行点乘运算
x=np.dot(n1,n2)
#传入数组，显示灰度
plt.imshow(x,cmap='gray')
#显示图像
plt.show()


#获取google的logo图片
# import requests
# url='https://bkimg.cdn.bcebos.com/pic/8601a18b87d6277f9e2f489d866f0830e924b8995644?x-bce-process=image/format,f_auto/quality,Q_70/resize,m_lfit,limit_1,w_536'
# resp=requests.get(url)
# with open('pic.jpg','wb') as f:
#     f.write(resp.content)