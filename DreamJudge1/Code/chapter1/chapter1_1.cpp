#include <bits/stdc++.h>  //����ͷ�ļ��������е��������֧��
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <functional>
#include <string>  //����ͷ�ļ�
using namespace std;

int main(){
    int x1;
    double x2;
    char x3;
    char x4[10];//�ַ����Ϊ9����Ϊ�н�����\0
    scanf("%d %lf %c %s",&x1,&x2,&x3,&x4);//����int double char �ַ����������ͱ���
    printf("%d\n%lf\n%c\n%s\n",x1,x2,x3,x4);//�����

    int year,month,day;//����������ɽ���2019-10-21����������Ϊ������
    scanf("%d-%d-%d",&year,&month,&day);
    printf("%d %d %d\n",year,month,day);

    int hour,minute,second;//����18:21:30������ʱ��
    scanf("%d:%d:%d",&hour,&minute,&second);
    printf("%d %d %d\n",hour,minute,second);

    char s[105];//������ַ������ո�Ӧ����gets.��Ϊscanf�����ո�ʱ���Զ�����
    getchar();//��getchar�������һ��scanf�Ľ�����������,һ����scanf��gets�м�ʹ��getchar����
    //�����س�'\n'��Ӱ�죬getchar()���ڶ��뵥���ַ�
    gets(s);//����:how are you?
    printf("%s\n",s);

    char c1=getchar();//getchar() ���뵥���ַ�
    putchar(c1);//putchar(char) ��������ַ�
    printf("\n");

    //�������ת��
    int a=10;//ʮ����
    printf("%x\n",a);//Сдʮ���������:a
    printf("%X\n",a);//��дʮ���������:A
    printf("%o\n",a);//�˽������:12

    //�������ǰ��0
    a=5;
    printf("%02d\n",a);//����2������,����ĵط���0����,���05
    printf("%04d\n",a);//���Ƶĺ��壬���:0005

    //�������С��
    double a1;
    scanf("%lf",&a1);
    printf("%.2lf\n",a1);//���������λС��    ���ӣ��ֱ�����3.6 3 5.769 �ֱ����
    //3.60 3.00 5.77
    printf("%g\n",a1);//����С�����С����ûС��������� ���3.6 3 5.769

    long long x5;//int��Χ����ʱ��long long��int��Χ-1e9��1e9��long long��Χ-1e18��1e18
    scanf("%lld",&x5);
    printf("%lld\n",x5);

    //����ַ���ASCII�룬ע��char�ַ���intֵ�����໥ת��
    printf("%d\n",'a');//���97
    printf("%d\n",'A');//���65

    //C++�����������ע��string����������ֻ����cin cout
    //printf������Ҫ��coutͬʱʹ�ã����ܷ���һЩ���ɿص�����
    int x6,x7;
    cin>>x6>>x7;
    cout<<x6+x7;
    return 0;
}

