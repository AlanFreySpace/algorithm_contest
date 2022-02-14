#include <stdio.h>
using namespace std;

#define INF 1000000000

int a1[1005],a2[1005],a3[1005],a4[1005],a5[1005];

void insertionSort(int n){//插入排序
    int j,key;
    for(int i=1;i<n;i++){
        key=a1[i];
        j=i-1;
        while(j>=0&&a1[j]>key){
            a1[j+1]=a1[j];
            j--;
        }
        a1[j+1]=key;
    }
}

void shell(int n){//模拟一次步长为5的希尔排序过程
    for(int i=0;i<5;i++){
        for(int j=i+5;j<n;j+=5){//插入排序的过程
            int key=a2[j];
            int k=j-5;
            while(k>=i&&a2[k]>key){
                a2[k+5]=a2[k];
                k-=5;
            }
            a2[k+5]=key;
        }
    }
}

void selectionSort(int n){//选择排序,每次选出最小元素,移动到前面
    int minNum=INF;
    int index=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(a3[j]<minNum){
                minNum=a3[j];
                index=j;
            }
        }
        a3[index]=a3[i];
        a3[i]=minNum;
        minNum=INF;
    }
}

void quickSort(int l,int r){//快速排序
    if(l>=r) return;
    int left=l,right=r,tmp=a4[l];
    while(left<right){
        while(left<right&&a4[right]>=tmp) right--;
        if(left<right) a4[left++]=a4[right];
        while(left<right&&a4[left]<=tmp) left++;
        if(left<right) a4[right--]=a4[left];
    }
    a4[left]=tmp;
    quickSort(l,left-1);
    quickSort(left+1,r);
}

void merge1(int n){//模拟一趟二路归并排序
    int p=n/2;
    for(int i=0;i<p;i++){
        int tmp;
        if(a5[2*i]>a5[2*i+1]){
            tmp=a5[2*i];
            a5[2*i]=a5[2*i+1];
            a5[2*i+1]=tmp;
        }
    }
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&a1[i]);
            a2[i]=a1[i];
            a3[i]=a1[i];
            a4[i]=a1[i];
            a5[i]=a1[i];
        }
        insertionSort(n);
        for(int i=0;i<n;i++) printf("%d ",a1[i]);
        printf("\n");
        shell(n);
        for(int i=0;i<n;i++) printf("%d ",a2[i]);
        printf("\n");
        selectionSort(n);
        for(int i=0;i<n;i++) printf("%d ",a3[i]);
        printf("\n");
        quickSort(0,n-1);
        for(int i=0;i<n;i++) printf("%d ",a4[i]);
        printf("\n");
        merge1(n);
        for(int i=0;i<n;i++) printf("%d ",a5[i]);
        printf("\n");
    }
    return 0;
}
