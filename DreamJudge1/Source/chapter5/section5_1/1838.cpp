#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

int main(){
    char r[10005];
    while(scanf("%s",&r)!=EOF){
        int len=strlen(r);
        stack<char> s;
        for(int i=0;i<len;i++){
            if(!s.empty()){
                char now=s.top();
                if((now=='<'&&r[i]=='>')||(now=='('&&r[i]==')')
                   ||(now=='{'&&r[i]=='}')||(now=='['&&r[i]==']'))
                   s.pop();
                else s.push(r[i]);
            }
            else s.push(r[i]);
        }
        if(s.empty()) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
