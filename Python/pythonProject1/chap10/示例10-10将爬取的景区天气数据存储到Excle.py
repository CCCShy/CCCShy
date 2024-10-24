import openpyxl
import weather

html=weather.get_html()         #发请求，得到响应结果
lst=weather.parse_html(html)    #解析数据

#创建新的一个Excle工作簿
workbook=openpyxl.Workbook()    #创建对象
#在Excle文件中创建工作表
sheet=workbook.create_sheet('景区天气')
# #向工作表中添加数据
for item in lst:
    sheet.append(item)  #一次添加一行
#保存
workbook.save('景区天气.xlsx')