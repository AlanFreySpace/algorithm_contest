#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string a[105];

//ÀûÓÃsort¶Ô×Ö·û´®°´×ÖµäÐòÅÅÐò
int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        for(int i=0;i<n;i++) cout<<a[i]<<endl;
    }
    return 0;
}
