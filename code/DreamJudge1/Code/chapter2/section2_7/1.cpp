#include <stdio.h>
using namespace std;

int a[1005];

//二分查找模板
int main(){
    int n,q,x;//在n个数字进行q次查询,查询的元素是x
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);//输入一从小到大排列的数组
    for(int i=0;i<q;i++){
        scanf("%d",&x);
        int l=0,r=n-1,mid;
        while(l<=r){//在a[l,r]中进行查找
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
