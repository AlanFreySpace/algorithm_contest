#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

int main(){
    char r[105];
    while(scanf("%s",&r)!=EOF){
        char ans[105]="";
        int len=strlen(r);
        stack<char> s;
        for(int i=0;i<len;i++){
            if(r[i]=='('){
               ans[i]=' ';
               s.push(r[i]);
            }
            else if(r[i]==')'){
                if(s.empty()) ans[i]='?';
                else{
                    ans[i]=' ';
                    s.pop();
                }
            }
            else ans[i]=' ';
        }

        stack<char> s1;//ע��˴�������һ��ջ,��Ϊ��ʱsջ�п��ܲ�Ϊ��
        for(int i=len-1;i>=0;i--){
            if(r[i]==')') s1.push(r[i]);
            else if(r[i]=='('){
                if(s1.empty()) ans[i]='$';
                else s1.pop();
            }
        }

        printf("%s\n",r);
        printf("%s\n",ans);
    }
    return 0;
}
