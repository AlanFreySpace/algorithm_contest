#include <stdio.h>
using namespace std;

/*
��1062�Ȿ��������,ֻ�Ǳ���Ҫ��ݹ����,
ע��ݹ�ĸ��Ӷȸ��ڽ�1062������鷽��
*/
int func(int i,int j){//���õݹ麯������
    if(j==0||j==i+1) return 1;//�߽�ֵ,�ݹ��
    return func(i-1,j-1)+func(i-1,j);//����
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n-1;i++){
            for(int j=0;j<=i+1;j++) printf("%d ",func(i,j));
            printf("\n");
        }
    }
    return 0;
}
