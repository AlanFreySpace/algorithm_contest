#include <stdio.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

int main(){
    queue<int> q;//定义队列
    q.push(1);//元素入队
    q.push(2);
    q.push(3);
    while(!q.empty()){
        printf("%d ",q.front());//取队首元素
        q.pop();//元素出队
    }//队列先进先出，因此输出为:1 2 3

    stack<int> s;//定义栈
    s.push(1);//元素入栈
    s.push(10);
    s.push(7);
    while(!s.empty()){
        printf("%d ",s.top());//输出栈顶元素
        s.pop();//元素出栈
    }//栈后进先出，因此输出为:7 10 1

    //map用于定义映射关系<key,value>,map中的key不可以重复
    map<string,int> dict;//定义map
    dict["Tom"]=1; //定义映射关系,元素在map中将按照key的字典序排列
    dict["Jone"]=2;
    dict["Mary"]=1;
    if(dict.count("Mary"))//查找dict中Mary出现的次数，若出现则
        printf("%s %d\n","Mary is in dict",dict["Mary"]);//输出其对应value
    //使用迭代器遍历map的key和value,注意printf不能输出string类型
    //(即不能输出不是用char数组定义的字符串),必须用cout来输出
    for(map<string,int>::iterator it=dict.begin();it!=dict.end();it++)
        cout<<it->first<<" is in dict "<<it->second<<endl;
    dict.clear();//清空map

    //set(集合)STL,set不允许两个元素有相同的值
    set<string> country;//定义集合
    country.insert("China");//向集合中插入元素,插入后集合会
    country.insert("America");//按照字典序对元素进行排列
    country.insert("France");
    set<string>::iterator it1;//使用迭代器遍历集合元素
    for(it1=country.begin();it1!=country.end();it1++)
        cout<<*it1<<endl;
    //删除集合内元素,erase的返回值是成功删除的元素的个数
    printf("%d %d\n",country.erase("America"),country.erase("England"));
    for(it1=country.begin();it1!=country.end();it1++)
        cout<<*it1<<endl;
    if(country.count("China"))//统计元素个数
        cout<<"China in country."<<endl;
    country.clear();
    return 0;
}
