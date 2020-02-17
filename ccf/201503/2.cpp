#include <iostream>
#include <algorithm>
using namespace std;

const int A=1001;
struct arr{
	int num;
	int freq;
	bool operator <(const arr &t) const{
		return freq==t.freq?num<t.num:freq>t.freq;
	}
}a[A];

int main(){
	int n,m;
	cin>>n;
	for(int i=0;i<A;i++){
		a[i].num=i;
		a[i].freq=0;
	}
	for(int i=0;i<n;i++){
		cin>>m;
		a[m].freq++;
	}
	sort(a,a+A);
	for(int i=0;a[i].freq!=0;i++) cout<<a[i].num<<" "<<a[i].freq<<endl;
	return 0;
}
