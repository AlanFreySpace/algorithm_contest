#include <stdio.h>
using namespace std;

int a[1005];

//���ֲ���ģ��
int main(){
    int n,q,x;//��n�����ֽ���q�β�ѯ,��ѯ��Ԫ����x
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);//����һ��С�������е�����
    for(int i=0;i<q;i++){
        scanf("%d",&x);
        int l=0,r=n-1,mid;
        while(l<=r){//��a[l,r]�н��в���
            mid=(l+r)/2;
            if(a[mid]==x){
                printf("find\n");
                break;
            }
            else if(a[mid]<x) l=mid+1;
            else r=mid-1;
        }
        if(a[mid]!=x) printf("no\n");
    }
    return 0;
}
