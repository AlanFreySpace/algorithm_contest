#include <iostream>
using namespace std;

int main(){
	int n,m=0;
	cin>>n>>m;
	int **first=new int*[n]; //ע���ά��������������first�������½����꣬second�������Ͻ����� 
	int **second=new int*[n];
	/*λ��i�Ĵ��ڱ�ţ������λ��0,��position[0]=6������㴰�ڱ��Ϊ7(���ת��) */ 
	int *position=new int[n];
	int **click=new int*[m];//�����λ������ 
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
					//continue;��������ã���������������籾�������㴰�ڣ���������ɵ��¸�ѭ������䶼����ִ�� 
				}else{
					//�任���ڵ�λ�� �⴦��Ҫʱ����ϰ �е����� 
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
