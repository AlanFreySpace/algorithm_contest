#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
����һ:ʹ���ȶ�����stable_sort���
*/

struct Student{
    string name;
    int score;
}stu[1005];
//��������
bool compareDesc(Student a,Student b){
    return a.score>b.score;
}
//��������
bool compareAsc(Student a,Student b){
    return a.score<b.score;
}

int main(){
    int n,order;
    while(cin>>n){
        cin>>order;
        for(int i=0;i<n;i++) cin>>stu[i].name>>stu[i].score;
        if(order==0) stable_sort(stu,stu+n,compareDesc);
        else stable_sort(stu,stu+n,compareAsc);
        for(int i=0;i<n;i++) cout<<stu[i].name<<" "<<stu[i].score<<endl;
    }
    return 0;
}
