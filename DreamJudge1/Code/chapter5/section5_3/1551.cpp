#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

/*
将树补充成满二叉树,然后分层判断对称性
*/
int main(){
    char a[3005]="";
    while(scanf("%s",&a)!=EOF){
        int len=strlen(a),left=0,right=0;
        int p=log2(len)+1;
        int len1=pow(2,p)-1;
        for(int i=len;i<len1;i++) a[i]='#';
        int flag=1;
        while(left<len1){
            int l=left,r=right;
            while(l<r){
                if((a[l]=='#'&&a[r]!='#')||(a[l]!='#'&&a[r]=='#')){
                    flag=0;
                    break;
                }
                l++;
                r--;
            }
            if(flag==0) break;
            left=right+1;
            right=2*right+2;
        }
        if(flag==1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
