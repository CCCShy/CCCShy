#b站视频音频分开

#requests模块     请求模块    专门爬虫
import requests

#视频
#准备一个网址
url='https://xy118x183x152x151xy.mcdn.bilivideo.cn:4483/upgcxcode/17/26/25981682617/25981682617_u1-1-100026.m4s?e=ig8euxZM2rNcNbdlhoNvNC8BqJIzNbfqXBvEqxTEto8BTrNvN0GvT90W5JZMkX_YN0MvXg8gNEV4NC8xNEV4N03eN0B5tZlqNxTEto8BTrNvNeZVuJ10Kj_g2UB02J0mN0B5tZlqNCNEto8BTrNvNC7MTX502C8f2jmMQJ6mqF2fka1mqx6gqj0eN0B599M=&uipk=5&nbs=1&deadline=1729345139&gen=playurlv2&os=mcdn&oi=1957834908&trid=00003985a5216f224a10bfb35df7f4225097u&mid=383623954&platform=pc&og=cos&upsig=d919e5e81bb93f5fafaf7a3cc67ad5ca&uparams=e,uipk,nbs,deadline,gen,os,oi,trid,mid,platform,og&mcdnid=50010313&bvc=vod&nettype=0&orderid=0,3&buvid=BF6F32DA-82FA-25C7-00D3-58DAA338CB6F06472infoc&build=0&f=u_0_0&agrr=0&bw=127126&logo=A0020000'

#伪装
wz={'user-agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/129.0.0.0 Safari/537.36',
    'referer':'https://www.bilibili.com/video/BV1wos8eCECm/?spm_id_from=333.1007.tianma.15-3-57.click&vd_source=77b15e04427b0519ec234352a6117f17'}

#请求网址 得到回应
res=requests.get(url,headers=wz)    #提交伪装信息
print(res.status_code)  #打印网址状态码
# print(res.content)      #
open('video.mp4', 'wb').write(res.content)



#音频
url='https://xy118x183x152x151xy.mcdn.bilivideo.cn:4483/upgcxcode/17/26/25981682617/25981682617_u1-1-30280.m4s?e=ig8euxZM2rNcNbdlhoNvNC8BqJIzNbfqXBvEqxTEto8BTrNvN0GvT90W5JZMkX_YN0MvXg8gNEV4NC8xNEV4N03eN0B5tZlqNxTEto8BTrNvNeZVuJ10Kj_g2UB02J0mN0B5tZlqNCNEto8BTrNvNC7MTX502C8f2jmMQJ6mqF2fka1mqx6gqj0eN0B599M=&uipk=5&nbs=1&deadline=1729345139&gen=playurlv2&os=mcdn&oi=1957834908&trid=00003985a5216f224a10bfb35df7f4225097u&mid=383623954&platform=pc&og=cos&upsig=fb6567a86bf8cb757fd78135a3847210&uparams=e,uipk,nbs,deadline,gen,os,oi,trid,mid,platform,og&mcdnid=50010313&bvc=vod&nettype=0&orderid=0,3&buvid=BF6F32DA-82FA-25C7-00D3-58DAA338CB6F06472infoc&build=0&f=u_0_0&agrr=0&bw=27166&logo=A0020000'
#伪装
wz={'user-agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/129.0.0.0 Safari/537.36',
    'referer':'https://www.bilibili.com/video/BV1wos8eCECm/?spm_id_from=333.1007.tianma.15-3-57.click&vd_source=77b15e04427b0519ec234352a6117f17'}

#请求网址 得到回应
res=requests.get(url,headers=wz)    #提交伪装信息
print(res.status_code)  #打印网址状态码
# print(res.content)      #
open('video.mp3', 'wb').write(res.content)




#把视频和音频合并    给视频设置背景音乐
#1.安装一个模块moviepy     pip install moviepy
from moviepy.editor import *
#import requests # 把requests这个模块导入
#用的时候 requests.get()

#2.加载素材
video = VideoFileClip('video.mp4')
audio = AudioFileClip('video.mp3')

#3.给视频设置音乐
final = video.set_audio(audio)

#4.保存
final.write_videofile('video_c.mp4')
#user-agent     用的什么浏览器
#cookie         用户的登录标识
#referer        引荐页 从哪一个网站找到我

# 伪装身份格式
# wz={'user-agent':'留空','cookie':'留空','referer':'留空'}
