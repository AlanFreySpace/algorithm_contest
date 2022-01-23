#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s;
    while(cin>>s){
        int len=s.length();
        string *a=new string[len];
        for(int i=0;i<len;i++) a[i]=s.substr(i,len-i);
        stable_sort(a,a+len);
        for(int i=0;i<len;i++) cout<<a[i]<<endl;
    }
    return 0;
}
