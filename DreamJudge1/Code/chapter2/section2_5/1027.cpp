#include <string>
#include <iostream>
using namespace std;

/*
注意erase函数的使用方法
*/
int main(){
    string s;
    while(cin>>s){
        int len=s.length();
        if(len<3) cout<<s<<endl;
        else{
           for(int i=0;i<len-2;i++){
                if((s[i]=='g'||s[i]=='G')&&(s[i+1]=='z'||s[i+1]=='Z')&&
                   (s[i+2]=='u'||s[i+2]=='U')) s.erase(s.begin()+i,s.begin()+i+3);
           }
           cout<<s<<endl;
        }
    }
    return 0;
}
