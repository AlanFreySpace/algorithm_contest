#include <stdio.h>
using namespace std;

int a[1005];
//快速排序代码模板
void quickSort(int l,int r){
    if(l>=r) return;
    int left=l,right=r,tmp=a[l];
    while(left<right){
        while(left<right&&a[right]>=tmp) right--;
        if(left<right) a[left++]=a[right];
        while(left<right&&a[left]<=tmp) left++;
        if(left<right) a[right--]=a[left];
    }
    a[left]=tmp;
    quickSort(l,left-1);
    quickSort(left+1,r);
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        quickSort(0,n-1);
        for(int i=0;i<n;i++) printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
