while True:
    try: #注意要有try except否则评测无法通过
        n=int(input())
        ans=[]
        if n==0:
            print(n)
        else:
            while n!=0:
                ans.append(n%2)
                n//=2 #注意此处应用地板除// 才和C++语义一致 (int)(n/2)因精度问题结果不正确,详见 Python文档 浮点算术：争议和限制
            ans.reverse()#地板除采用int类型 强制类型转换(int)(n/2)采用float类型
            for i in range(len(ans)):
                print(ans[i],end="")
            print()
    except:
        break