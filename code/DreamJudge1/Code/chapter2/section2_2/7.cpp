#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

int main(){
    /*
    �ַ���ת������:
    c_str()������stringת��Ϊ�ַ�����,��atof()���ַ�����ת��Ϊ������,
    ע��atof�ķ���ֵ��double����
    */
    string a="31.75";
    float x1=atof(a.c_str());
    double x2=atof(a.c_str());
    printf("%g %g \n",x1,x2);

    /*
    ������ת�ַ���
    */
    float a1=31.25;
    double a2=33.96;
    stringstream ss;
    ss<<a1;
    string ans1=ss.str();
    ss.str("");//���ss�Ļ�����
    ss<<a2;
    string ans2=ss.str();
    cout<<ans1<<" "<<ans2<<endl;

    //�ַ���ת����
    string t1="139";
    int ans3=atoi(t1.c_str());

    /*
    ����ת�ַ���:itoa()������3����������һ��������Ҫת�������֣�
    �ڶ���������Ҫд��ת�������Ŀ���ַ�����
    ������������ת������ʱ���õĻ�����
    */
    int t2=567;
    char ans4[105];
    itoa(t2,ans4,10);
    printf("%d %s\n",ans3,ans4);
    return 0;
}
