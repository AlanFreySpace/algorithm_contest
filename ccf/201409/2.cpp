#include <iostream>
#include <cstring>
using namespace std;
//图片P2_3.jpg中标记了方格的坐标表示方式 
int main(){
	int n,count=0;
	int a[101][101]; //表明该单位面积是否被涂色 
	int b[4];//用来保存输入的数据 
	memset(a,0,sizeof(a));
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[0]>>b[1]>>b[2]>>b[3];
		int j=b[0]+1;
		while(j<=b[2]){
			int q=b[1]+1; //注意q在此处初始化，否则会造成错误！ 
			while(q<=b[3]){
				a[j][q]=1;
				q++;
			}
			j++;
		}
	}
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			if(a[i][j]==1) count++;
		}
	}
	cout<<count;
	return 0;
} 
