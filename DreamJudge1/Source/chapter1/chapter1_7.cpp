#include <stdio.h>
#include <queue>
using namespace std;

//���ȼ����е�ʹ��,Ĭ���Ǵ󶥶�
int main(){
    priority_queue<int> q;//�������ȼ�����
    q.push(1);//���
    q.push(2);
    q.push(3);
    while(!q.empty()){//�ж϶��в�Ϊ��
        printf("%d ",q.top());//ȡ����Ԫ��(�Ѷ�)
        q.pop();//�Ѷ�����
    }//�����Ǵ󶥶ѣ�������Ϊ:3 2 1
    return 0;
}
