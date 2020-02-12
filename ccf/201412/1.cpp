#include <iostream>
using namespace std;
//注意！动态数组能用memset初始化！但不能写成如静态数组sizeof(num)这种形式了，要写成n*sizeof(int) 
int main(){
	int n,reader;
	cin>>n;
	int* num=new int[n+1]; 
	int* ti=new int[n+1];
	for(int i=0;i<=n;i++){
		num[i]=0;
		ti[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>reader;
		ti[reader]++;
		num[i]=ti[reader];
	} 
	for(int i=1;i<=n;i++) cout<<num[i]<<" ";
	return 0;
} 

