#include <iostream>
#include <cstring>
using namespace std;

int chartoint(char a){
	int ans;
	if(a>64) ans=a-55;
	else ans=a-48;
	return ans;
}

char inttochar(int a){
	char ans;
	if(a>9) ans=a+55;
	else ans=a+48;
	return ans;
}


string xor1(string a,string b){
	string ans;
	char a1,b1;
	int alen=a.length();
	for(int i=0;i<alen;i++) ans+=inttochar(chartoint(a[i])^chartoint(b[i]));
	return ans; 
}


int main(){
	//cout<<xor1("14151617","B4B5B6B7");
	/*
	string str="0x3F100000";
	int ttt=stoi(str,NULL,16);
	cout<<ttt<<endl;
	char str1[100];
	itoa(ttt,str1,16);
	cout<<str1<<endl;
	ttt=0x3F100000;
	printf("%X",str1);
	*/
	int n,s,l,l1,len,m,q;
	string l2;
	cin>>n>>s>>l;
	cin>>l1>>l2;
	int* exist=new int[n];
	memset(exist,0,n*sizeof(int));
	len=l2.length()/8;
	string* disk=new string[n];
	exist[l1]=1;
    disk[l1]=l2;
	for(int i=1;i<l;i++){
	    cin>>l1>>l2;
	    exist[l1]=1;
	    disk[l1]=l2;
	}
	cin>>m;
	string* ans=new string[m];
	for(int i=0;i<m;i++){
		cin>>q;
		int t=q%(s*n)/s;
		int p=(q/(s*n)+t)/(n-1);
		p=q/(s*n)+p;
		int k=q%(s*n)%s;
		int f=p*s+k;
		if(exist[t]==1){
			if(f<len) ans[i]=disk[t].substr(8*f,8);
			else ans[i]="-";
		}
		else{
			if(l==n-1){
				if(f<len){
					ans[i]="00000000";
					for(int j=0;j<n;j++){
						if(j!=t) ans[i]=xor1(ans[i],disk[j].substr(8*f,8));
					} 
				}
				else ans[i]="-";
			}
			else ans[i]="-";
		}
	}
	for(int i=0;i<m;i++) cout<<ans[i]<<endl;
	return 0;
} 
