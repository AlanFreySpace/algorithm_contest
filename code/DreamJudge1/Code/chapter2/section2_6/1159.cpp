#include <stdio.h>
#include <algorithm>
using namespace std;

struct Student{
    int id,score;
}stu[1005];

bool cmp(Student a,Student b){
    if(a.score==b.score) return a.id<b.id;
    return a.score<b.score;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d%d",&stu[i].id,&stu[i].score);
        sort(stu,stu+n,cmp);
        for(int i=0;i<n;i++) printf("%d %d\n",stu[i].id,stu[i].score);
    }
    return 0;
}
