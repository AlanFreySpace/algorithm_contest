#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*
�������Ĳ���ô�ã���Ŀû��˵�����˼�����������˼˵����˻���һ���ȽϺõ�ģ����
��˼���������һ���Ϸ����޲���ѡ��Ǿ�һ��Ҫ��������������ֳ�����
      �������һ���Ϸ��Ĵ�����ѡ������������ǲ��Ǵ��������������һ��Ҫ���ֳ���
	  �ټ������ӣ���һ��������� ab:                         ���� 
	  ls -a -b ���-a -b                              -b��������ҲҪ��� 
	  ls -b -a -a ���-a -b -a       -a��ѡ�� -bѡ������һ����-a������-a������ʽҲ���������� 
	  
	  ls -b -a -b ���-b -a     ���������ѡ��������Σ��ڶ���ȴ��������(Ҳ��˵���������е����һ���ַ�������Ϊ���������ѡ��������м䣬�������洮
	                             ����Ϊ����) ��ô���в�����Ϊ׼�����Ὣ��ѡ����ַ�����Ϊ�� 
	  ls -b -w -b ���-b -w  
	  �پ�һ����
	  ab:c
      1
      ls -c -b
      Case 1: -b  -c 
	  �ܽ�һ�¸�����ǣ�ÿ�������ж����Կո�Ϊ׼�򣬷�Ϊ���ɸ��ַ������д���
	  �ؼ��䣺����Ĺ�������ĳ���ַ����Ȳ��ǺϷ���ѡ��,�ֲ���ĳ���Ϸ�ѡ��Ĳ���ʱ,������ֹͣ
	  Ҳ��˵���ַ����Ȳ��ǺϷ�ѡ��ֲ��ǺϷ�ѡ��Ĳ���ʱ���Ų���¼�ô���
	  �ǺϷ�ѡ����¼���ǲ������¼����ʹ������ѡ�����û������ѡ��ҲҪ��¼��
	  ���һ��������ѡ��ͬʱ�д������Ͳ����������������¼�������������      
*/     
 
const int A=26;
string options,commands;//options����Щѡ�commands������ 
int types[A];//��¼ѡ�����ͣ�0ѡ����� 1��������ѡ�� 2������ѡ�� 
int record[A];//��¼���������Ƿ���ֶ�Ӧ�Ϸ�ѡ�� 
string para[A];//��¼���� 

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
	string c;//�Կո�Ϊ��׼��ȡ�ַ��� 
	string* ans=new string[n];
	getchar();//getlineǰ��Ҫgetchar 
	for(int i=0;i<n;i++){
		memset(record,0,sizeof(record));
		for(int k=0;k<A;k++) para[k]="";
		getline(cin,commands);
		int v=-1;//��¼��һ���ַ���Ӧ����ѡ��(=-1)���ǲ���(=����ֵ) 
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


