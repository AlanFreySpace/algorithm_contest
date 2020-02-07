#include <iostream>
using namespace std;

int main(){
	int n,m=0;
	cin>>n>>m;
	int **first=new int*[n]; //注意二维数组声明方法，first窗口左下角坐标，second窗口右上角坐标 
	int **second=new int*[n];
	/*位置i的窗口编号，最顶层是位置0,如position[0]=6代表最顶层窗口编号为7(编号转换) */ 
	int *position=new int[n];
	int **click=new int*[m];//点击的位置坐标 
	for(int i=0;i<n;i++){
		first[i]=new int[2];
		second[i]=new int[2];
	}
	for(int i=0;i<n;i++){
		cin>>first[i][0]>>first[i][1]>>second[i][0]>>second[i][1];
		position[i]=n-i-1;
	}
	for(int i=0;i<m;i++) click[i]=new int[2];
	for(int i=0;i<m;i++) cin>>click[i][0]>>click[i][1];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int window=position[j];
			if(click[i][0]>=first[window][0]&&click[i][0]<=second[window][0]&&click[i][1]>=first[window][1]&&click[i][1]<=second[window][1]){
				if(j==0){
					//https://zhidao.baidu.com/question/148734533.html 
					//continue;这个不能用，否则会结果错误，例如本该输出最顶层窗口，结果这句造成底下该循环内语句都不能执行 
				}else{
					//变换窗口的位置 这处需要时常温习 有点绕弯 
					int temp=position[1];
					position[1]=position[0];
					for(int p=2;p<=j;p++){
						int temp1=position[p];
						position[p]=temp;
						temp=temp1;
					}
					position[0]=window;
				}
				cout<<window+1<<endl;
				break;
			}else{
				if(j==n-1) cout<<"IGNORED"<<endl;
			}
		}
	}
	return 0;
} 
