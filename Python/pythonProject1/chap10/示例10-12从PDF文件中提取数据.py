import pdfplumber

#打开pdf文件
with pdfplumber.open('常用快捷键整理.pdf') as pdf:
    for page in pdf.pages:          #遍历页
        print(page.extract_text())  #extract_text()方法提取内容
        print(f'-------------第{page.page_number}页结束-------------------')
        