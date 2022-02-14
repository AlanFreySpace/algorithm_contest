#include <stdio.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

int main(){
    queue<int> q;//�������
    q.push(1);//Ԫ�����
    q.push(2);
    q.push(3);
    while(!q.empty()){
        printf("%d ",q.front());//ȡ����Ԫ��
        q.pop();//Ԫ�س���
    }//�����Ƚ��ȳ���������Ϊ:1 2 3

    stack<int> s;//����ջ
    s.push(1);//Ԫ����ջ
    s.push(10);
    s.push(7);
    while(!s.empty()){
        printf("%d ",s.top());//���ջ��Ԫ��
        s.pop();//Ԫ�س�ջ
    }//ջ����ȳ���������Ϊ:7 10 1

    //map���ڶ���ӳ���ϵ<key,value>,map�е�key�������ظ�
    map<string,int> dict;//����map
    dict["Tom"]=1; //����ӳ���ϵ,Ԫ����map�н�����key���ֵ�������
    dict["Jone"]=2;
    dict["Mary"]=1;
    if(dict.count("Mary"))//����dict��Mary���ֵĴ�������������
        printf("%s %d\n","Mary is in dict",dict["Mary"]);//������Ӧvalue
    //ʹ�õ���������map��key��value,ע��printf�������string����
    //(���������������char���鶨����ַ���),������cout�����
    for(map<string,int>::iterator it=dict.begin();it!=dict.end();it++)
        cout<<it->first<<" is in dict "<<it->second<<endl;
    dict.clear();//���map

    //set(����)STL,set����������Ԫ������ͬ��ֵ
    set<string> country;//���弯��
    country.insert("China");//�򼯺��в���Ԫ��,����󼯺ϻ�
    country.insert("America");//�����ֵ����Ԫ�ؽ�������
    country.insert("France");
    set<string>::iterator it1;//ʹ�õ�������������Ԫ��
    for(it1=country.begin();it1!=country.end();it1++)
        cout<<*it1<<endl;
    //ɾ��������Ԫ��,erase�ķ���ֵ�ǳɹ�ɾ����Ԫ�صĸ���
    printf("%d %d\n",country.erase("America"),country.erase("England"));
    for(it1=country.begin();it1!=country.end();it1++)
        cout<<*it1<<endl;
    if(country.count("China"))//ͳ��Ԫ�ظ���
        cout<<"China in country."<<endl;
    country.clear();
    return 0;
}
