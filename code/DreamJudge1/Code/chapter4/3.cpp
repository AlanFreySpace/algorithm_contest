#include <iostream>
#include <string>
using namespace std;

/*
C/C++����ͨ��ģ��ķ�������߾��ȵ����⣬�����ر����ڿ��Ե�ʱ���Լ��ֶ�ȥģ�������
�����⣬���������׳���ʧ�� ������Ǻܼ򵥵ļӼ������㣬��C/C++ģ��Ҳ��ͦ����ġ�
string��һЩ�﷨˵��:
  s1.swap(s2)���ڽ����ַ���s1��s2��ֵ
  insert(int p0, int n, char c); ��p0������n���ַ�c
  string(size_type n,char c)����һ������n��Ԫ�ص�string����
  ����ÿ��Ԫ�ض�����ʼ��Ϊ�ַ�c
*/
string Add(string a,string b){
    if(a.length()<b.length()) a.swap(b);//aһֱΪλ���ϳ����ַ���
    b.insert(0,a.length()-b.length(),'0');//�϶̵��ַ���ǰ�油0�������
    string res(a.length(),'0');//��������res����Ϊ�ϳ��ַ�������
    int carry=0;//��λ
    int sum=0;
    for(int i=a.length()-1;i>=0;i--){//�ӵ�λ��ʼģ����ʽ�ӷ�����
        sum=a[i]-'0'+b[i]-'0'+carry;
        carry=sum/10;
        res[i]=sum%10+'0';
    }
    if(carry>0){//�����Ľ�λ��Ϊ0,Ҫ�ڽ��ǰ�油λ
        /*
        insert(iterator it, char c);��it�������ַ�c
        res.insert(res.begin(),carry+'0');
        ��������res.insert(0,1,carry+'0');��Ч������ͬ��
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
