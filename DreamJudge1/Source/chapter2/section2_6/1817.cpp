#include <stdio.h>
#include <algorithm>
using namespace std;

struct Student{
    int chinese,math,english,sum;
    char name[100];
}stu[1005];

bool cmp(Student a,Student b){
    if(a.sum==b.sum){
        if(a.chinese==b.chinese){
            if(a.math==b.math) return a.english>b.english;
            return a.math>b.math;
        }
        return a.chinese>b.chinese;
    }
    return a.sum>b.sum;
}

int main(){
    int n;
    scanf("%d",&n);//注意本题不能循环读入,否则评测通不过
    for(int i=0;i<n;i++){
        scanf("%s%d%d%d",&stu[i].name,&stu[i].chinese,&stu[i].math,
                &stu[i].english);
        stu[i].sum=stu[i].chinese+stu[i].math+stu[i].english;
    }
    stable_sort(stu,stu+n,cmp);
    for(int i=0;i<n;i++)
        printf("%s %d %d %d\n",stu[i].name,stu[i].chinese,stu[i].math,
                stu[i].english);
    return 0;
}
