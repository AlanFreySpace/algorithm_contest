#include <bits/stdc++.h>
using namespace std;

int main(){//注意本题如何写代码更简洁
    int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char rule[11]={'1','0','X','9','8','7','6','5','4','3','2'};
    string id;
    while(cin>>id){
        int res=0;//注意res应在此处初始化
        if(id.length()!=18) printf("ID Wrong\n");
        else{
            for(int i=0;i<17;i++) res+=(id[i]-'0')*weight[i];
            res%=11;
            if(rule[res]==id[17]) printf("ID Corrent\n");
            else printf("ID Wrong\n");
        }
    }
    return 0;
}
