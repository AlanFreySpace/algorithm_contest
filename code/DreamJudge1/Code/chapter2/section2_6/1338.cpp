#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct Student{
    int id,score;
    char name[10];
}stu[100005];

bool cmp1(Student a,Student b){
    return a.id<b.id;
}

/*
ע��c�����ַ�������ֵ���ȽϺ���:strcmp
��ֵС��0˵��a.name���ֵ�������b.name���ֵ���
*/
bool cmp2(Student a,Student b){
    if(strcmp(a.name,b.name)==0) return a.id<b.id;
    return strcmp(a.name,b.name)<0;
}

bool cmp3(Student a,Student b){
    if(a.score==b.score) return a.id<b.id;
    return a.score<b.score;
}

int main(){
    int n,c;
    while(scanf("%d%d",&n,&c)!=EOF&&n!=0){
        for(int i=0;i<n;i++)
            scanf("%d%s%d",&stu[i].id,&stu[i].name,&stu[i].score);
        if(c==1) sort(stu,stu+n,cmp1);
        else if(c==2) sort(stu,stu+n,cmp2);
        else sort(stu,stu+n,cmp3);

        printf("Case:\n");
        for(int i=0;i<n;i++)
            printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].score);
    }
    return 0;
}
