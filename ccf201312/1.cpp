#include <iostream>
#include <cstring> //memset使用的库 
using namespace std;

const int MAX=10001;
int main(){
	int n,number,v,ans=0;
	cin>>n;//数字个数 
	int count[MAX];
	memset(count,0,sizeof(count));//初始化count数组各元素均为0 
	for(int i=0;i<n;i++){
		cin>>number;
		count[number]++;//输入各数字，统计各数字出现次数 
	}
	for(int i=1;i<MAX;i++){
		if(count[i]>v){
			v=count[i]; 
			ans=i;//统计出现次数(v)最多的数字 (ans)
		}
	}
	cout<<ans<<endl;
	return 0;
} 
