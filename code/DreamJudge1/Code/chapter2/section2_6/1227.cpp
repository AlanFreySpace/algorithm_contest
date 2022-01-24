#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*
ע��C++��substr(pos,len)��Ϊ��pos��ʼ��ȡ����Ϊlen���ַ���
ע��:
string y="1765.3",r="23.7";
int u=0;
if(y<r) u=1;
cout<<u<<endl;
���Ժ���y<r,���string���������ֵ�����бȽϵ�,����Ӧ������ע��
��Դ����ܷ���ȷʵ����Ϊ�ؼ�
*/

struct record{
    string name;
    string date;
    string time;
    string run1;//С����󲿷�
    string run2;//С����ǰ����
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
