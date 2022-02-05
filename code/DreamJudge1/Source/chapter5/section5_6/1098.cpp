#include <stdio.h>
#include <string.h>
using namespace std;

int trie[2005][26];
int isend[2005];
int sz;

/*
trie[i][j]!=0ʱ������Ϊi�Ľڵ�ָ����Ϊj�Ľڵ�,j��ָ��ڵ�������ĸ,
��j=0����a,j=1����b��
trie[i][j]==0ʱ��ʾ�ڵ�i��ָ���κνڵ�,��i�ڵ㲻����
isend[i]!=0��ʾ�ڵ�i��ĳ�����ʵĽ�β
*/
void createTrie(char* s){
    int len=strlen(s),u=0;
    for(int i=0;i<len;i++){
        int c=s[i]-'a';
        if(!trie[u][c]) trie[u][c]=sz++;
        u=trie[u][c];
    }
    isend[u]=1;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(!n) break;
        memset(trie,0,sizeof(trie));
        memset(isend,0,sizeof(isend));
        sz=1;
        char tmp[25];
        for(int i=0;i<n;i++){
            scanf("%s",&tmp);
            createTrie(tmp);
        }
        int ans=0;
        for(int i=0;i<sz;i++){
            int flag=0;
            if(isend[i]){
                for(int j=0;j<26;j++){
                    if(trie[i][j]){
                        flag=1;
                        break;
                    }
                }
                if(!flag) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
