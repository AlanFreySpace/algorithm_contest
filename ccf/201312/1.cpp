#include <iostream>
#include <cstring> //memsetʹ�õĿ� 
using namespace std;

const int MAX=10001;
int main(){
	int n,number,v,ans=0;
	cin>>n;//���ָ��� 
	int count[MAX];
	memset(count,0,sizeof(count));//��ʼ��count�����Ԫ�ؾ�Ϊ0 
	for(int i=0;i<n;i++){
		cin>>number;
		count[number]++;//��������֣�ͳ�Ƹ����ֳ��ִ��� 
	}
	for(int i=1;i<MAX;i++){
		if(count[i]>v){
			v=count[i]; 
			ans=i;//ͳ�Ƴ��ִ���(v)�������� (ans)
		}
	}
	cout<<ans<<endl;
	return 0;
} 
