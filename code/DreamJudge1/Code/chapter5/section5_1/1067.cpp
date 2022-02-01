#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

/*
1501的框架用于判断是否匹配
三个else if用于判定优先级(嵌套顺序)是否符合要求
*/
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            char r[300]="";
            scanf("%s",&r);
            int len=strlen(r),flag=0;
            stack<char> s;
            for(int j=0;j<len;j++){
                if(!s.empty()){
                    char now=s.top();
                    if((now=='{'&&r[j]=='}')||(now=='['&&r[j]==']')
                       ||(now=='('&&r[j]==')')||(now=='<'&&r[j]=='>'))
                        s.pop();
                    else if(now=='['&&r[j]=='{'){
                        printf("NO\n");
                        flag=1;
                        break;
                    }
                    else if(now=='('&&(r[j]=='{'||r[j]=='[')){
                        printf("NO\n");
                        flag=1;
                        break;
                    }
                    else if(now=='<'&&(r[j]=='{'||r[j]=='['||r[j]=='(')){
                        printf("NO\n");
                        flag=1;
                        break;
                    }
                    else s.push(r[j]);
                }
                else s.push(r[j]);
            }
            if(!flag){
                if(s.empty()) printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}
