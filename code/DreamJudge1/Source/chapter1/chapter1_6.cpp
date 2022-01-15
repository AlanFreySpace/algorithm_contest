#include <stdio.h>
#include <algorithm>
#include <functional>//greater���������ͷ�ļ���
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int a[10]={5,3,69,23,7,4,69,100,1,36};
    /*
    ��С����������bound���ʵ�ֶ��ֲ��ң���a[0,9]�в���
    lower_bound:����������һ�����ڵ���69��ֵ���ȣ��������ڷ���10
    upper_bound:����������һ������69��ֵ���ȣ��������ڷ���10
    */
    sort(a,a+10);
    printf("%d ",lower_bound(a,a+10,69)-a);//���7
    printf("%d ",upper_bound(a,a+10,69)-a);//���9
    /*
    �Ӵ�С������bound��greater���ʵ�ֶ��ֲ��ң���a[0,9]�в���
    lower_bound:����������һ��С�ڵ���69��ֵ���ȣ��������ڷ���10
    upper_bound:����������һ��С��69��ֵ���ȣ��������ڷ���10
    */
    sort(a,a+10,cmp);
    printf("%d ",lower_bound(a,a+10,69,greater<int>())-a);//���1
    printf("%d ",upper_bound(a,a+10,69,greater<int>())-a);//���3
    return 0;
}
