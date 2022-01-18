#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    char s[35];
    while(scanf("%s",&s)!=EOF){
        int num[35];
        //存放二进制数,30位十进制数最大为100多位二进制数
        int ans[115];
        int len=strlen(s);
        int cur=0;
        int flag=0;
        for(int i=0;i<len;i++) num[i]=s[i]-'0';
        while(cur<len){
            ans[flag]=num[len-1]%2;//取余数
            num[len-1]-=ans[flag++];//这里注意别写错了
            for(int i=cur;i<len;i++){//取商
                if(num[i]%2==1)//当前位不够除,进位
                    num[i+1]+=10;
                num[i]/=2;
            }
            if(num[cur]==0) cur++;//当前位变为0,考查下一位
        }
        for(int i=flag-1;i>=0;i--) printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}
