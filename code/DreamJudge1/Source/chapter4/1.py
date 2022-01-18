while True: #Python大数相加代码
    try:
        a,b=map(int,input().split())
        c=a+b
        print(c)
    except: #读到文件末尾抛出异常结束循环
        break
