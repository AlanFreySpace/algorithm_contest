#include <stdio.h>
using namespace std;

int num;
void hanoi(int n,char from,char mid,char to){
    if(n==1){
        printf("%c-->%c   ",from,to);
        num++;
        if(num%5==0) printf("\n");
        return;
    }
    hanoi(n-1,from,to,mid);
    printf("%c-->%c   ",from,to);
    num++;
    if(num%5==0) printf("\n");
    hanoi(n-1,mid,from,to);
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        num=0;
        hanoi(n,'A','B','C');
        printf("\n");
    }
    return 0;
}
