#include <iostream>
#include <string>
#include <map>
using namespace std;


//ע��map��ʹ�÷���

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
        M[stu.id]=stu;//����id��ѧ���Ķ�Ӧ��ϵ
    }
    cin>>m;
    string tmp;
    for(int i=0;i<m;i++){
        cin>>tmp;
        if(M.find(tmp)!=M.end())//�ҵ���id
            cout<<M[tmp].id<<" "<<M[tmp].name<<" "<<M[tmp].sex<<" "
                <<M[tmp].age<<endl;
        else cout<<"No Answer!"<<endl;//δ�ҵ���id
    }
    return 0;
}
