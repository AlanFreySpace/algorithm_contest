#include <bits/stdc++.h>
using namespace std;

/*
����һ����ͼ:
####
#.##
##@#
####
�����ַ���
*/

char c[10][10];
int main(){
    //����һ:ע��jҪ��5����Ϊ�س�Ҳ��һ��char�ַ�
    for(int i=1;i<=4;i++){
        for(int j=1;j<=5;j++) scanf("%c",&c[i][j]);
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=5;j++) printf("%c",c[i][j]);
    }
    //������:��ʱ��c[i]�����ַ���,c[i]+1ָ���ַ����ĳ���,������Ϊ�ַ�����ĩβ��
    //������'\0',��ʱ�س�����Ϊ'\0'�����ʱ������Ϊ�ո�����Ƿ���һ�Ļس�
    for(int i=1;i<=4;i++) scanf("%s",c[i]+1);
    for(int i=1;i<=4;i++){
        for(int j=1;j<=5;j++) printf("%c",c[i][j]);
        printf("\n");//���Ҫ�ֶ��ӻس�
    }
    return 0;
}
