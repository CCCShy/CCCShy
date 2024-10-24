import requests
import re

def get_html():
    url='https://www.weather.com.cn/weather1d/101010100.shtml'  #爬虫打开浏览器网页
    resp=requests.get(url)  #打开浏览器并打开网址
    resp.encoding='utf-8'
    # print(resp.text)    #resp响应对象， 对象名.属性名 resp.text
    return resp.text

def parse_html(html_str):
    city=re.findall('<span class="name">([\u4e00-\u9fa5]*)</span>',html_str)
    weather=re.findall('<span class="weather">([\u4e00-\u9fa5]*)</span>',html_str)
    wd=re.findall('<span class="wd">(.*)</span>',html_str)
    zs=re.findall('<span class="zs">([\u4e00-\u9fa5]*)</span>',html_str)

    lst=[]
    for a,b,c,d in zip(city,weather,zs,wd):
        lst.append([a,b,c,d])
    return lst