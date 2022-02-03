#include <iostream>
#include <string>
using namespace std;

void postOrder(string pre,string in){
    if(pre.size()==0) return;
    char r=pre[0];
    int index=in.find(r);
    string leftpre=pre.substr(1,index);
    string rightpre=pre.substr(index+1);
    string leftin=in.substr(0,index);
    string rightin=in.substr(index+1);
    postOrder(leftpre,leftin);
    postOrder(rightpre,rightin);
    cout<<r;
}

int main(){
    string pre,in;
    while(cin>>pre>>in){
        postOrder(pre,in);
        cout<<endl;
    }
    return 0;
}
