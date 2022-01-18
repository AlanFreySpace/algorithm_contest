#include <iostream>
#include <string>
using namespace std;

/*
C/C++可以通过模拟的方法解决高精度的问题，不是特别建议在考试的时候自己手动去模拟大整数
的问题，这样很容易出现失误。 但如果是很简单的加减法运算，用C/C++模拟也是挺不错的。
string的一些语法说明:
  s1.swap(s2)用于交换字符串s1和s2的值
  insert(int p0, int n, char c); 在p0处插入n个字符c
  string(size_type n,char c)创建一个包含n个元素的string对象，
  其中每个元素都被初始化为字符c
*/
string Add(string a,string b){
    if(a.length()<b.length()) a.swap(b);//a一直为位数较长的字符串
    b.insert(0,a.length()-b.length(),'0');//较短的字符串前面补0方便计算
    string res(a.length(),'0');//初步设置res长度为较长字符串长度
    int carry=0;//进位
    int sum=0;
    for(int i=a.length()-1;i>=0;i--){//从低位开始模拟竖式加法运算
        sum=a[i]-'0'+b[i]-'0'+carry;
        carry=sum/10;
        res[i]=sum%10+'0';
    }
    if(carry>0){//若最后的进位不为0,要在结果前面补位
        /*
        insert(iterator it, char c);在it处插入字符c
        res.insert(res.begin(),carry+'0');
        上面这句和res.insert(0,1,carry+'0');的效果是相同的
        */
        res.insert(0,1,carry+'0');
    }
    return res;
}

int main(){
    string a,b;
    while(cin>>a>>b){
        cout<<Add(a,b)<<endl;
    }
    return 0;
}
