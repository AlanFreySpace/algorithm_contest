#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;

const int N=5001;
struct record{
		double price;
		int num;
		bool operator <(const record &a) const{
			return price>a.price;
		}
	}a[N];

int main(){
	string s;
	int p=0,t=0;
	int cancel[N];
	double ppri=0.0;
	long long pnum=0;
	memset(cancel,0,sizeof(cancel));
	priority_queue<record> buy,sell;
	while(cin>>s){
		p++;
		if(s[0]=='c'){
			cin>>t;
			cancel[p]=1;
			cancel[t]=1;
		}
		else{
			cin>>a[p].price>>a[p].num;
			if(s[0]=='b') a[p].price=-a[p].price;
		}
	}
	for(int i=1;i<=p;i++){
		if(cancel[i]==1) continue;
		if(a[i].price>0) sell.push(a[i]);
		else buy.push(a[i]);
	}
	while(true){
		if(buy.empty()) break;
		if(sell.empty()) break;
		record bu=buy.top(),se=sell.top();
		bu.price=-bu.price;
		buy.pop();
		sell.pop();
		if(bu.price<se.price) break;
		int temp=min(bu.num,se.num);
		ppri=bu.price;
		pnum+=temp;
		bu.num-=temp;
		se.num-=temp;
		bu.price=-bu.price;
		if(bu.num>0) buy.push(bu);
		if(se.num>0) sell.push(se);
	} 
	printf("%.2f",ppri);
	cout<<" "<<pnum;
	return 0;
} 
