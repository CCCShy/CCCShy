#requests模块     请求模块    专门爬虫
import requests
url='https://v1.kwaicdn.com/ksc2/zzaCvLrnVMynO1-tXRZkSBkdL-IVM2keJpV2BVTULYC1DCFk5EtZhHUvJhT6zNCZsOu8zqQA6TF4pHrhJRQqH1_XGjyLLGDjE5r2CWkR-BFTsLMwoWuk_PK-5Z4HTlK9Op55JwM3LhrlMdMp6BH_qFXkyNpJoJsskIWofxtZxQyrJtgwM15Y3a5pdkWwII0y.mp4?pkey=AAU_N8zrXabuKmtnMFYkWpS97qmFW1uq27GNrT9C-cSlgSFeGB3vPaa5yO7y1hKWuI6EJuCkKrxlR3mq8TzhshxEDROxkAghZHBF77E5OzW518KiMLMEXGNaSN1IsKDSQ1Q&tag=1-1729259299-unknown-0-bcqw8xzz9x-7ba630414af0cd33&clientCacheKey=3xnub9sf98g3ptc_b.mp4&di=74b2309c&bp=10004&tt=b&ss=vp'
res=requests.get(url)
print(res.status_code)  #打印网址状态码
print(res.content)      #
open('video.mp4', 'wb').write(res.content)

