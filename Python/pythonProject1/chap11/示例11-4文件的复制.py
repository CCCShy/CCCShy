def copy(src,new_path):
    # 文件的复制就是边读边写操作
    #(1)打开源文件
    file_src=open(src,'rb')
    #(2)打开目标文件
    file_new=open(new_path,'wb')
    #(3)开始复制
    s=file_src.read()   #源文件读取所有
    file_new.write(s)   #向目标文件写入所有
    #(4)关闭文件
    file_new.close()
    file_src.close()    #先打开的后关，后打开的先关

if __name__ == '__main__':
    src='./pic.jpg'     # . 代表的是当前目录
    new_path='../chap10/copy_google.jpg'  # ..表示的是上一级目录，相当于windows后退
    copy(src,new_path)
    print('文件复制完毕')