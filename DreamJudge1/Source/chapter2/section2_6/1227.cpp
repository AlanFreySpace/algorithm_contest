#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*
注意C++的substr(pos,len)意为从pos开始截取长度为len的字符串
注意:
string y="1765.3",r="23.7";
int u=0;
if(y<r) u=1;
cout<<u<<endl;
测试后发现y<r,因此string是左对齐后按字典序进行比较的,这里应该尤其注意
这对代码能否正确实现尤为关键
*/

struct record{
    string name;
    string date;
    string time;
    string run1;//小数点后部分
    string run2;//小数点前部分
}rec[10005];

bool cmp(record a,record b){
    if(a.run2==b.run2&&a.run1==b.run1){
        if(a.date==b.date) return a.time<b.time;
        return a.date<b.date;
    }
    if(a.run2==b.run2) return a.run1<b.run1;
    if(a.run2.length()!=b.run2.length())
        return a.run2.length()<b.run2.length();
    return a.run2<b.run2;
}

int main(){
    int k=0;
    string s;
    while(getline(cin,s)){
        int len=s.length();
        int i;
        for(i=len-1;;i--){
            if(s[i]=='.'){
                rec[k].run1=s.substr(i,len-i);
                break;
            }
        }
        int z;
        for(z=i-1;;z--){
            if(s[z]!=' '&&s[z-1]==' '){
                rec[k].run2=s.substr(z,i-z);
                break;
            }
        }
        int j;
        for(j=z-1;;j--){
            if(s[j]!=' '&&s[j-1]==' '){
                rec[k].time=s.substr(j,z-j);
                break;
            }
        }
        int v;
        for(v=j-1;;v--){
            if(s[v]!=' '&&s[v-1]==' '){
                rec[k].date=s.substr(v,j-v);
                break;
            }
        }
        rec[k].name=s.substr(0,v);
        //cout<<rec[k].name<<rec[k].date<<rec[k].time<<rec[k].run<<endl;
        k++;
    }
    sort(rec,rec+k,cmp);
    for(int i=0;i<k;i++)
        cout<<rec[i].name<<rec[i].date<<rec[i].time<<rec[i].run2
            <<rec[i].run1<<endl;
    return 0;
}
