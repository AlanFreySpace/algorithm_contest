#include <iostream>
using namespace std;

int main(){
    //C++ cin cout����
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //λ�����������
    int a,b;
    cin>>a;
    //���������λ����,�ȼ���:if(a%2==1) a/=2;
    if(a&1==1) a>>=1;
    cout<<a<<endl;
    //�������:ĳ��a���ͬһ����bż����,����ֵ����
    cin>>a>>b;
    int ans1=a^b^b;//���Ϊa
    int ans2=b^a^b^b^b;//���Ϊa
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
