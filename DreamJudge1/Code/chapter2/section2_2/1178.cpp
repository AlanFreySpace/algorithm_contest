#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    char s[35];
    while(scanf("%s",&s)!=EOF){
        int num[35];
        //��Ŷ�������,30λʮ���������Ϊ100��λ��������
        int ans[115];
        int len=strlen(s);
        int cur=0;
        int flag=0;
        for(int i=0;i<len;i++) num[i]=s[i]-'0';
        while(cur<len){
            ans[flag]=num[len-1]%2;//ȡ����
            num[len-1]-=ans[flag++];//����ע���д����
            for(int i=cur;i<len;i++){//ȡ��
                if(num[i]%2==1)//��ǰλ������,��λ
                    num[i+1]+=10;
                num[i]/=2;
            }
            if(num[cur]==0) cur++;//��ǰλ��Ϊ0,������һλ
        }
        for(int i=flag-1;i>=0;i--) printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}
