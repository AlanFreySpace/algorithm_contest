#include <stdio.h>
#include <string.h>
using namespace std;

int trie[2005][26];
int isend[2005];
int sz;

/*
trie[i][j]!=0时代表编号为i的节点指向编号为j的节点,j是指向节点代表的字母,
如j=0代表a,j=1代表b等
trie[i][j]==0时表示节点i不指向任何节点,或i节点不存在
isend[i]!=0表示节点i是某个单词的结尾
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
