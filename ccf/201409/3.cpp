#include <iostream>
#include <cstring>
#include <algorithm> //transform������Ҫ�õ�ͷ�ļ� 
using namespace std;

//https://www.csdn.net/gather_23/NtDagg2sNjItYmxvZwO0O0OO0O0O.html
//https://blog.csdn.net/zhouxinxin0202/article/details/77862615/ 
int main(){
	string s;
	int a,n=0;
	cin>>s>>a>>n;
	string* inputS=new string[n];
	string* convertS=new string[n];
	int* exists=new int[n];
	memset(exists,0,sizeof(exists));
	for(int i=0;i<n;i++){
		cin>>inputS[i];
		convertS[i]=inputS[i];
		string::size_type st;//����ͳ���ַ���a���Ƿ����ĳ�ַ���b��Ҫ�õ���(���ִ�Сд)�� 
		if(a==1){
			//find�������س����ַ���b���ֵ���λ�� 
			st=inputS[i].find(s);//����ͳ���ַ���a���Ƿ����ĳ�ַ���b��Ҫ�õ���(���ִ�Сд)����find  
			if(st!=string::npos) exists[i]=1;//��st==string::npos����δ�ҵ� 
		}else{
			//�����ִ�Сдʱ�Ĳ��ԣ�����convert������ʹ��transform���ַ���ת��Ϊ����Сд 
			transform(convertS[i].begin(),convertS[i].end(),convertS[i].begin(),::tolower);
			transform(s.begin(),s.end(),s.begin(),::tolower);
			st=convertS[i].find(s);
			if(st!=string::npos) exists[i]=1;
		}
	}
	for(int i=0;i<n;i++){
		if(exists[i]==1) cout<<inputS[i]<<endl;
	}
	return 0;
}

