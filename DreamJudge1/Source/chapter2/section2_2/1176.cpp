#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    char s[1050];//A���ַ�����ʽ
    int one[1050];//���ڼ�1
    one[0]=1;
    while(scanf("%s",&s)!=EOF){
        int len=strlen(s);
        //ע��Ҫ�������ʼ��Ϊ0,��������
        int A[1050]={0},B[1050]={0},tmp[5000]={0};
        for(int i=0;i<len;i++) A[i]=s[i]-'0';
        int cur=0,flag=0;
        while(cur<len){//ʮ����ת2����,����1178��
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
        ������������תʮ����,������������Ƶ�10110101תʮ����
        �Ĺ���:0*2+1=1 1*2+0=2 2*2+1=5 5*2+1=11
        11*2+0=22 22*2+1=45 45*2+0=90 90*2+1=181
        */
        for(int i=0;i<flag;i++){//����tmp�ĵ�iλ
            for(int j=0;j<Blen;j++) B[j]*=2;
            for(int j=0;j<Blen;j++){
                B[j+1]+=(B[j]/10);
                B[j]%=10;
            }//����ģ�������2����,����1475��
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
            }//����ģ�������1����,����1474��
        }
        for(int i=Blen-1;i>=0;i--) printf("%d",B[i]);
        printf("\n");
    }
    return 0;
}
