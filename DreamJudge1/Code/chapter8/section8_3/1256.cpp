#include <stdio.h>
#include <algorithm>
#include <functional>//ע��greater�����ͷ�ļ���
using namespace std;

int a[30],d[30],k;

void lengthOfLDS(){//��ݼ�������
    int len=1;
    d[1]=a[0];
    for(int i=1;i<k;i++){
        if(d[len]>=a[i]) d[++len]=a[i];
        else{//��d�е�һ��С��a[i]�����ֵ���
            int index=upper_bound(d+1,d+len+1,a[i],greater<int>())-d;
            d[index]=a[i];
        }
    }
    printf("%d\n",len);
}

int main(){
    while(scanf("%d",&k)!=EOF){
        for(int i=0;i<k;i++) scanf("%d",&a[i]);
        lengthOfLDS();
    }
    return 0;
}
