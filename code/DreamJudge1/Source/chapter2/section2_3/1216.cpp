#include <stdio.h>
using namespace std;
/*
找规律的题目,注意应用printf("%-4d",ans[i][j]);
格式化输出整数。-4表示每个数字占4个空,且左对齐
若改为4则是右对齐
*/
int main(){
    int n;
    int ans[20][20];
    while(scanf("%d",&n)!=EOF){
        int num=1;
        for(int i=0;i<=n/2;i++){//按下右上左的规律放数字
            for(int j=i;j<n-i;j++) ans[j][i]=num++;
            for(int j=i+1;j<n-i;j++) ans[n-i-1][j]=num++;
            for(int j=n-i-2;j>=i;j--) ans[j][n-i-1]=num++;
            for(int j=n-i-2;j>i;j--) ans[i][j]=num++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) {
                printf("%-4d",ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
