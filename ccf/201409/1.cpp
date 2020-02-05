#include <iostream>
using namespace std;
//注意输入里可能有负数 ，因此采取策略：先将输入排序，在判断相邻两数之间是否差1
 
int main(){
	int n,m=0;
	cin>>n;
	int* a=new int[n];//再次注意声明动态数组的方法 
	for(int i=0;i<n;i++){
		cin>>m;
		a[i]=m;
	}
	for(int i=n;i>0;i--){
		for(int j=0;j<i-1;j++){
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	int count=0;
	for(int i=0;i<n-1;i++){
		if(a[i]==a[i+1]-1) count++;
	}
	cout<<count;
	return 0;
	}
