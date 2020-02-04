#include <iostream>
using namespace std;
// http://c.biancheng.net/view/1375.html
//思路：从一个矩形向左右两边扫描 
int main(){
	int n,leftNum,rightNum,square,maxSquare=0;
	cin>>n;
	int* a=new int[n];//声明一个动态数组 
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	for(int i=0;i<n;i++){
		for(int q=i;q>=0;q--){
			if(a[q]<a[i]){
				leftNum=i-q-1;
				break; //此处break生效会到下面那个for循环 
			}
			if(q==0){
				leftNum=i-q;
			}
		}
		
		for(int q=i;q<n;q++){
			if(a[q]<a[i]){
				rightNum=q-i-1;
				break;//此处break循环生效会返回外层for循环 
			}
			if(q==n-1){
				rightNum=q-i;
			}
		}
		
		square=(leftNum+rightNum+1)*a[i];
		if(square>maxSquare){
			maxSquare=square;
		}
	}
	cout<<maxSquare;
	return 0;
}
