#include <iostream>
using namespace std;

int main(){
    //C++ cin cout加速
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //位运算加速运算
    int a,b;
    cin>>a;
    //与运算和移位运算,等价于:if(a%2==1) a/=2;
    if(a&1==1) a>>=1;
    cout<<a<<endl;
    //异或运算:某数a异或同一个数b偶数次,它的值不变
    cin>>a>>b;
    int ans1=a^b^b;//结果为a
    int ans2=b^a^b^b^b;//结果为a
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
