#include <bits/stdc++.h>
using namespace std;

int main(){
    double cost;
    //ʹ��%g�����Զ�ȥ��С���������0�������������ʾ����
    while(scanf("%lf",&cost)!=EOF){
        if(cost>=5000) printf("discount=0.8,pay=%g",cost*0.8);
        else if(cost>=3000) printf("discount=0.85,pay=%g",cost*0.85);
        else if(cost>=2000) printf("discount=0.9,pay=%g",cost*0.9);
        else if(cost>=1000) printf("discount=0.95,pay=%g",cost*0.95);
        else printf("discount=1,pay=%g",cost);
    }
    return 0;
}
