#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[505][505];

int main(){
    string word1,word2;
    while(cin>>word1>>word2){
        int len1=word1.length(),len2=word2.length();
        if(len1*len2==0) cout<<len1+len2<<endl;
        for(int j=1;j<=len2;j++) dp[0][j]=j;
        for(int i=1;i<=len1;i++) dp[i][0]=i;
        dp[1][0]=1;
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                int tmp1=min(dp[i-1][j],dp[i][j-1])+1;
                int tmp2=dp[i-1][j-1];
                if(word1[i-1]!=word2[j-1]) tmp2+=1;
                dp[i][j]=min(tmp1,tmp2);
            }
        }
        cout<<dp[len1][len2]<<endl;
    }
}
