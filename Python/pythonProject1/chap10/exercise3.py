import jieba
from wordcloud import WordCloud

#读取数据
with open('Python学前指导.txt','r',encoding='utf-8') as file:
    s=file.read()
#中文分词
lst=jieba.lcut(s)
#排除词
stopword=['视频','主要','使用','工作','可能']
txt=' '.join(lst)
#绘制词云图
wordcloud=WordCloud(background_color='white',font_path='msyh.ttc',stopwords=stopword,width=800,height=600)
#由txt生成词云图
wordcloud.generate(txt)
#保存图片
wordcloud.to_file('Python指导词云图.png')

