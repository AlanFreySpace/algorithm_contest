#include <iostream>
using namespace std;
// https://blog.csdn.net/qq_30534935/article/details/82683643
int main(){
	string a;
	cin>>a;
	string b=a; //输入字符串的拷贝 
	string::iterator it;//利用迭代器去掉字符串中的'-' 
	for(it=a.begin();it<a.end();it++){
		if(*it=='-'){
			a.erase(it);//删除该字符，因此下一步一定要it-- 使迭代器保持在当前位置 
			it--;
		}
	}
	int m=0;
	for(int i=0;i<a.length()-1;i++){
		int n=a[i]-'0';//char转 int，a[i]-'0'的ascii码直接就是int值 
		m=m+n*(i+1);
	}
	m=m%11;
	char c;
	if(m<10){
		c=m+'0';//int转char，m+'0'得到字符的ascii码 
	}else{
		c='X';
	}
	if(c==a[9]){
		cout<<"Right";
	}else{
		b[12]=c;
		cout<<b;
	}
}
