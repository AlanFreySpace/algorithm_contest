#include <iostream>
#include <cstring>
using namespace std;

const int A=1001; 
int pos_num[A],neg_num[A];

int main(){
	memset(pos_num,0,sizeof(pos_num));
	memset(neg_num,0,sizeof(neg_num));
	int n,m,count=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		if(m>0) pos_num[m]++;
		if(m<0) neg_num[-m]++;
	}
	for(int i=0;i<A;i++){
		if(pos_num[i]==1&&neg_num[i]==1) count++;
	}
	cout<<count;
	return 0;
}
