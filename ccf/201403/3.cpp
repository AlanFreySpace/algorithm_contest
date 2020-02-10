#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*
这道题出的不怎么好，题目没有说清楚意思，不过如果意思说清楚了还是一道比较好的模拟题
意思：如果出现一个合法的无参数选项，那就一定要把它在输出中体现出来；
      如果出现一个合法的带参数选项，无论它后面是不是带参数，在输出中一定要体现出它
	  举几个例子：第一行如果输入 ab:                         解释 
	  ls -a -b 输出-a -b                              -b不带参数也要输出 
	  ls -b -a -a 输出-a -b -a       -a是选项 -b选项后面带一参数-a，类似-a这种形式也可以做参数 
	  
	  ls -b -a -b 输出-b -a     如果带参数选项出现两次，第二次却不带参数(也可说成是命令行的最后一个字符串，因为如果带参数选项出现在中间，那它后面串
	                             必作为参数) 那么以有参数的为准，不会将该选项的字符串置为空 
	  ls -b -w -b 输出-b -w  
	  再举一例：
	  ab:c
      1
      ls -c -b
      Case 1: -b  -c 
	  总结一下该题就是：每个命令行都是以空格为准则，分为若干个字符串进行处理
	  关键句：当你的工具遇到某个字符串既不是合法的选项,又不是某个合法选项的参数时,分析就停止
	  也就说当字符串既不是合法选项，又不是合法选项的参数时，才不记录该串。
	  是合法选项便记录，是参数便记录，即使带参数选项后面没参数该选项也要记录。
	  如果一个带参数选项同时有带参数和不带参数的情况，记录带参数的情况。      
*/     
 
const int A=26;
string options,commands;//options有哪些选项，commands命令行 
int types[A];//记录选项类型，0选项不存在 1不带参数选项 2带参数选项 
int record[A];//记录命令行中是否出现对应合法选项 
string para[A];//记录参数 

int main(){
	memset(types,0,sizeof(types));
	cin>>options;
	int l=options.length();
	for(int i=0;i<l;i++){
		int temp=options[i]-'a';
		if(i==l-1){
			if(islower(options[i])) types[temp]=1;
		}else{
			if(islower(options[i])){
				if(options[i+1]==':') types[temp]=2;
				else types[temp]=1;
			}
		}
	}
	
	int n=0;
	cin>>n;
	string c;//以空格为标准截取字符串 
	string* ans=new string[n];
	getchar();//getline前需要getchar 
	for(int i=0;i<n;i++){
		memset(record,0,sizeof(record));
		for(int k=0;k<A;k++) para[k]="";
		getline(cin,commands);
		int v=-1;//记录下一个字符串应该是选项(=-1)还是参数(=其他值) 
		int j=0;
		l=commands.length();
		while(j<l&&commands[j]!=' ') j++;
		j++;
		for(;j<l;){
			c="";
			while(j<l&&commands[j]!=' ') c+=commands[j++];
			if(v==-1){
				if(c.length()==2&&c[0]=='-'&&islower(c[1])){
					v=c[1]-'a';
					if(types[v]==0) break;
					record[v]=1;
					if(types[v]==1) v=-1;
				}
				else break;
			}
			else{
				para[v]=c;
				v=-1;
			}
			j++;
		}
		string ii=to_string(i+1);
		ans[i]="Case "+ii+":";
		for(int k=0;k<A;k++){
			char temp='a'+k;
			if(record[k]==1&&types[k]==1) ans[i]=ans[i]+" "+"-"+temp;
			else if(record[k]==1&&types[k]==2)
				ans[i]=ans[i]+" "+"-"+temp+" "+para[k];
		}
	} 
	
	for(int i=0;i<n;i++) cout<<ans[i]<<endl;
	return 0;	
	}


