#include <stdio.h>
using namespace std;

/*
和1062题本质无区别,只是本题要求递归计算,
注意递归的复杂度高于解1062题的数组方法
*/
int func(int i,int j){//利用递归函数计算
    if(j==0||j==i+1) return 1;//边界值,递归基
    return func(i-1,j-1)+func(i-1,j);//规律
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
