#include <iostream>
#include <string>
#include <map>
using namespace std;


//注意map的使用方法

struct student{
    string id,name,sex;
    int age;
};

int main(){
    int n,m;
    cin>>n;
    map<string,student> M;
    for(int i=0;i<n;i++){
        student stu;
        cin>>stu.id>>stu.name>>stu.sex>>stu.age;
        M[stu.id]=stu;//构建id与学生的对应关系
    }
    cin>>m;
    string tmp;
    for(int i=0;i<m;i++){
        cin>>tmp;
        if(M.find(tmp)!=M.end())//找到该id
            cout<<M[tmp].id<<" "<<M[tmp].name<<" "<<M[tmp].sex<<" "
                <<M[tmp].age<<endl;
        else cout<<"No Answer!"<<endl;//未找到该id
    }
    return 0;
}
