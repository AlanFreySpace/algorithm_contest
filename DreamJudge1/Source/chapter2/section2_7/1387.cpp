#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
注意substr和reverse的参数:前面参数要小于后面的
string s="abcd";
cout<<s.substr(0,2)<<endl; 输出ab 截取[0,2)
reverse(s.begin()+1,s.begin()+3); 反序[1,3)
cout<<s<<endl; 输出acbd
s.replace(1,3,"dkm"); 替换[1,1+3)
cout<<s<<endl; 输出adkm
*/
int main(){
    string s,order;
    int n;
    while(cin>>s){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>order;
            int len=order.length();
            if(order[0]=='0'){
                reverse(s.begin()+order[1]-'0',
                        s.begin()+order[1]-'0'+order[2]-'0');
                cout<<s<<endl;
            }
            else{
                s.replace(order[1]-'0',order[2]-'0',
                          order.substr(3,len));
                cout<<s<<endl;
            }
        }
    }
    return 0;
}
