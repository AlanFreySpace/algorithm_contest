#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
����2:����id,���ж�������,��ȷ��sort�Ľ�����ȶ���
*/
struct Student{
    string name;
    int score,id;
}stu[1005];

bool compareDesc(Student a,Student b){
    if(a.score==b.score) return a.id<b.id;
    return a.score>b.score;
}

bool compareAsc(Student a,Student b){
    if(a.score==b.score) return a.id<b.id;
    return a.score<b.score;
}

int main(){
    int n,order;
    while(cin>>n){
        cin>>order;
        for(int i=0;i<n;i++){
            cin>>stu[i].name>>stu[i].score;
            stu[i].id=i;
        }
        if(order==0) sort(stu,stu+n,compareDesc);
        else sort(stu,stu+n,compareAsc);
        for(int i=0;i<n;i++) cout<<stu[i].name<<" "<<stu[i].score<<endl;
    }
    return 0;
}
