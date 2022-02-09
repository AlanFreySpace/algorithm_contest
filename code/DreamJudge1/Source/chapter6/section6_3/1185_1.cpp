#include <stdio.h>
#include <string.h>

char s[10],ans[10];
int flag[10]={0};//标记该位是否被占

void permu(int len,int index){//全排列递归函数
    if(index==len) printf("%s\n",ans);
    else{
        for(int i=0;i<len;i++){
            if(flag[i]==0){
                ans[index]=s[i];
                flag[i]=1;
                permu(len,index+1);
                flag[i]=0;
            }
        }
    }
}

int main(){
    while(gets(s)!=NULL){
        memset(ans,0,sizeof(ans));
        int len=strlen(s);
        for(int i=0;i<len-1;i++)//将输入的字符串按字典序排序
            for(int j=i+1;j<len;j++)
                if(s[i]>s[j]){
                    char t=s[i];
                    s[i]=s[j];
                    s[j]=t;
                }
        permu(len,0);
    }
    return 0;
}
