#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct Student{
    int age,score;
    char name[105];
}stu[1005];

bool cmp(Student a,Student b){
    if(a.score==b.score){
        if(strcmp(a.name,b.name)==0) return a.age<b.age;
        return strcmp(a.name,b.name)<0;
    }
    return a.score<b.score;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%s%d%d",&stu[i].name,&stu[i].age,&stu[i].score);
        sort(stu,stu+n,cmp);
        for(int i=0;i<n;i++)
            printf("%s %d %d\n",stu[i].name,stu[i].age,stu[i].score);
    }
    return 0;
}
