#include <iostream>
using namespace std;

bool isyear(int a){
	if(a%400==0||(a%4==0&&a%100!=0)) return true;
	return false;
}

int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int t=2,day1=0; 

int main(){
	int a,b,c,y1,y2;
	cin>>a>>b>>c>>y1>>y2;
	int* day=new int[y2-y1+1];
	for(int i=1850;i<=y2;i++){
		if(i>=y1){
			if(isyear(i)) month[2]=29;
			for(int j=1;j<a;j++) t+=month[j];
			day1=t%7;
			if(day1==0&&c==7) c=0;
			if(c>=day1) day[i-y1]=7*(b-1)+c-day1+1;
			else day[i-y1]=7*b+c-day1+1;
			if(day[i-y1]>month[a]) day[i-y1]=0;
			for(int j=a;j<=12;j++) t+=month[j];
			month[2]=28;
		}else{
			if(isyear(i)) t+=366;
			else t+=365;
		}
	}
	for(int i=y1;i<=y2;i++){
		if(day[i-y1]==0) cout<<"none"<<endl;
		else{
			string a1=to_string(a);
			string a2=to_string(day[i-y1]);
			if(a<10) a1="0"+a1;
			if(day[i-y1]<10) a2="0"+a2;
			cout<<to_string(i)<<"/"<<a1<<"/"<<a2<<endl;
		}
	} 
	return 0;
} 
