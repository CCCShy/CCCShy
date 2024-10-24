from PIL import Image
# 加载图片
im=Image.open('pic.jpg')
# print(type(im),im)
#提取RGB图像颜色通道，返回结果是图像的副本
r,g,b=im.split()
# print(r)
# print(g)
# print(b)
# 合并通道
om=Image.merge(mode='RGB',bands=(g,r,b))
om.save('new_google.jpg')