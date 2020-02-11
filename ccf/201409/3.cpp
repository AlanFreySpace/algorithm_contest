#include <iostream>
#include <cstring>
#include <algorithm> //transform函数需要用的头文件 
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
		string::size_type st;//用于统计字符串a中是否出现某字符串b需要用到的(区分大小写)量 
		if(a==1){
			//find函数返回出现字符串b出现的首位置 
			st=inputS[i].find(s);//用于统计字符串a中是否出现某字符串b需要用到的(区分大小写)函数find  
			if(st!=string::npos) exists[i]=1;//若st==string::npos表明未找到 
		}else{
			//不区分大小写时的策略，引入convert，使用transform将字符串转换为都是小写 
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

