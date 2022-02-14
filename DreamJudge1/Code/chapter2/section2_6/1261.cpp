#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string s1,string s2){
    return s1.length()<s2.length();
}

int main(){
    int n;
    while(cin>>n){
        string *s=new string[n];
        int len=0;
        getchar();//getline会将cin后的回车当作一行,为消除其影响,getchar()
        for(int i=0;i<n;i++){
            getline(cin,s[i]);
            if(s[i]=="stop") break;
            else len++;
        }
        stable_sort(s,s+len,cmp);
        for(int i=0;i<len;i++) cout<<s[i]<<endl;
    }
    return 0;
}
