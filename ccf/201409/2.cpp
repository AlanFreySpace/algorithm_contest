#include <iostream>
#include <cstring>
using namespace std;
//ͼƬP2_3.jpg�б���˷���������ʾ��ʽ 
int main(){
	int n,count=0;
	int a[101][101]; //�����õ�λ����Ƿ�Ϳɫ 
	int b[4];//����������������� 
	memset(a,0,sizeof(a));
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[0]>>b[1]>>b[2]>>b[3];
		int j=b[0]+1;
		while(j<=b[2]){
			int q=b[1]+1; //ע��q�ڴ˴���ʼ�����������ɴ��� 
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
