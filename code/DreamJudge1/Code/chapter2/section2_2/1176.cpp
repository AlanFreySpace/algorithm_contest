#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    char s[1050];//A的字符串形式
    int one[1050];//用于加1
    one[0]=1;
    while(scanf("%s",&s)!=EOF){
        int len=strlen(s);
        //注意要将数组初始化为0,否则会出错
        int A[1050]={0},B[1050]={0},tmp[5000]={0};
        for(int i=0;i<len;i++) A[i]=s[i]-'0';
        int cur=0,flag=0;
        while(cur<len){//十进制转2进制,类似1178题
            tmp[flag]=A[len-1]%2;
            A[len-1]-=tmp[flag++];
            for(int i=cur;i<len;i++){
                if(A[i]%2==1) A[i+1]+=10;
                A[i]/=2;
            }
            if(A[cur]==0) cur++;
        }
        //for(int i=flag-1;i>=0;i--) printf("%d",tmp[i]);
        int Blen=1;
        /*
        二进制逆序数转十进制,例如逆序二进制的10110101转十进制
        的过程:0*2+1=1 1*2+0=2 2*2+1=5 5*2+1=11
        11*2+0=22 22*2+1=45 45*2+0=90 90*2+1=181
        */
        for(int i=0;i<flag;i++){//处理tmp的第i位
            for(int j=0;j<Blen;j++) B[j]*=2;
            for(int j=0;j<Blen;j++){
                B[j+1]+=(B[j]/10);
                B[j]%=10;
            }//以上模拟大数乘2过程,类似1475题
            if(B[Blen]!=0) Blen++;
            if(tmp[i]==1){
                for(int j=0;j<Blen;j++){
                    B[j]+=one[j];
                    if(B[j]>9){
                        B[j+1]+=(B[j]/10);
                        B[j]%=10;
                    }
                }
                if(B[Blen]!=0) Blen++;
            }//以上模拟大数加1过程,类似1474题
        }
        for(int i=Blen-1;i>=0;i--) printf("%d",B[i]);
        printf("\n");
    }
    return 0;
}
