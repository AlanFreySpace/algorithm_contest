#include <stdio.h>
#include <vector>
using namespace std;
//����ģ���ʹ��
int main(){
    vector<int> v; //����һ������
    for(int i=1;i<=10;i++) v.push_back(i*i); //����������β�����Ԫ��
    for(int i=0;i<v.size();i++) printf("%d ",v[i]); //����������Ԫ��
    return 0;
}
