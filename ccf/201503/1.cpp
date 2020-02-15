#include <iostream>
using namespace std;
//找规律题，找好规律即可！ 
int main(){
	int n,m;
	cin>>n>>m;
	int** mat=new int*[n+1];
	int** trmat=new int*[m+1];
	for(int i=0;i<=n;i++) mat[i]=new int[m+1];
	for(int i=0;i<=m;i++) trmat[i]=new int[n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>mat[i][j];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			trmat[i][j]=mat[j][m-i+1];
			cout<<trmat[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
