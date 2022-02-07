#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    int a[10];
    memset(a,693,sizeof(a));
    for(int i=0;i<10;i++)
        printf("%d ",a[i]);
    return 0;
}
