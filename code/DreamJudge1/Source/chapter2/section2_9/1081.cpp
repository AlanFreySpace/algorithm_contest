#include <stdio.h>
#include <vector>
using namespace std;

//�����ⷨ
int main(){
    int n,s,m;
    int ans[105];//��������˳�˳��
    vector<int> v;
    while(scanf("%d%d%d",&n,&s,&m)!=EOF){
       if(n==0&&s==0&&m==0) break;
       for(int i=0;i<n;i++) v.push_back(i+1);
       int cur=s-1;//cur��ʾ��ʼ�����ĺ��ӵ��±�
       for(int i=0;i<n;i++){
           int del=(cur+m-1)%v.size();//Ҫ�˳��ĺ����±�
           ans[i]=v[del];
           v.erase(v.begin()+del);
           //ע�����Ｋ������Ҫ����
           if(i<n-1) cur=del%v.size();//��һ��ʼ�����ĺ��ӵ��±�
       }
       for(int i=0;i<n-1;i++) printf("%d,",ans[i]);
       printf("%d",ans[n-1]);
       printf("\n");
    }
    return 0;
}
