#include <stdio.h>
#include <algorithm>
using namespace std;

struct drink{
    int m,w;//m:���� w:�ܼ�
}d[1005];

bool cmp(drink a,drink b){
    return (double)a.w/a.m<(double)b.w/b.m;
}

int main(){
    double x;
    int n;
    /*
    ע�����ʱ�������ͱ�д����:
    ����float���͵ı�����printf()�е�˵����������%f��%lf��
    ��scanf()�е�˵������ֻ����%f
    ����double���͵ı�����printf()�е�˵����������%f��%lf��
    ��scanf()�е�˵������ֻ����%lf
    ����long double���͵ı�����printf()�е�˵����������%Lf��
    ��scanf()�е�˵������ֻ����%Lf��
    */
    while(scanf("%lf%d",&x,&n)!=EOF){
        if(x==-1&&n==-1) break;
        else{
            double ans=0;
            for(int i=0;i<n;i++) scanf("%d%d",&d[i].m,&d[i].w);
            sort(d,d+n,cmp);
            for(int i=0;i<n;i++){
                if(x>d[i].w){
                    x-=d[i].w;
                    ans+=d[i].m;
                    //printf("%s %.3lf\n","1",ans);
                }
                else if(x==d[i].w){
                    ans+=d[i].m;
                    //printf("%s %.3lf\n","2",ans);
                    break;
                }
                else{
                    double pw=(double)d[i].w/d[i].m;
                    ans+=(x/pw);
                    //printf("%s %.3lf\n","3",ans);
                    break;
                }
            }
            printf("%.3lf\n",ans);
        }
    }
    return 0;
}
