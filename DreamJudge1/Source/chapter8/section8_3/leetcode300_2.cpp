#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int nums[2505],d[2505];

int lengthOfLIS(){
    int len=1;
    d[1]=nums[1];
    for(int i=2;i<=n;i++){
        if(nums[i]>d[len]) d[++len]=nums[i];
        else{
            int index=lower_bound(d+1,d+len+1,nums[i])-d;
            d[index]=nums[i];
        }
    }
    return len;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++) scanf("%d",&nums[i]);
        int ans=lengthOfLIS();
        printf("%d\n",ans);
    }
    return 0;
}
