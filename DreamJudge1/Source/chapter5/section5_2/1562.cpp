#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int main(){
    char s[1005];
    while(scanf("%s",&s)!=EOF){
        if(strcmp(s,"END")==0) break;
        else{
            int sta[27]={0};
            int len=strlen(s);
            int ans1=8*len,ans2=0;
            double ans3=.0;
            for(int i=0;i<len;i++){
                if(s[i]=='_') sta[26]++;
                else sta[s[i]-'A']++;
            }
            priority_queue<int,vector<int>,greater<int> > q;
            for(int i=0;i<27;i++)
                if(sta[i]) q.push(sta[i]);
            if(q.size()==1) ans2=q.top();//尤其注意该句的处理,1382的代码没处理这个情况
            else{
                while(q.size()>1){
                    int num1=q.top();
                    q.pop();
                    int num2=q.top();
                    q.pop();
                    ans2+=(num1+num2);
                    q.push(num1+num2);
                }
            }
            ans3=(double)ans1/ans2;
            printf("%d %d %.1lf\n",ans1,ans2,ans3);
        }
    }
    return 0;
}
