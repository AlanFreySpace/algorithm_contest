#include <iostream>
using namespace std;
// https://blog.csdn.net/qq_30534935/article/details/82683643
int main(){
	string a;
	cin>>a;
	string b=a; //�����ַ����Ŀ��� 
	string::iterator it;//���õ�����ȥ���ַ����е�'-' 
	for(it=a.begin();it<a.end();it++){
		if(*it=='-'){
			a.erase(it);//ɾ�����ַ��������һ��һ��Ҫit-- ʹ�����������ڵ�ǰλ�� 
			it--;
		}
	}
	int m=0;
	for(int i=0;i<a.length()-1;i++){
		int n=a[i]-'0';//charת int��a[i]-'0'��ascii��ֱ�Ӿ���intֵ 
		m=m+n*(i+1);
	}
	m=m%11;
	char c;
	if(m<10){
		c=m+'0';//intתchar��m+'0'�õ��ַ���ascii�� 
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
