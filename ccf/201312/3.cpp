#include <iostream>
using namespace std;
// http://c.biancheng.net/view/1375.html
//˼·����һ����������������ɨ�� 
int main(){
	int n,leftNum,rightNum,square,maxSquare=0;
	cin>>n;
	int* a=new int[n];//����һ����̬���� 
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	for(int i=0;i<n;i++){
		for(int q=i;q>=0;q--){
			if(a[q]<a[i]){
				leftNum=i-q-1;
				break; //�˴�break��Ч�ᵽ�����Ǹ�forѭ�� 
			}
			if(q==0){
				leftNum=i-q;
			}
		}
		
		for(int q=i;q<n;q++){
			if(a[q]<a[i]){
				rightNum=q-i-1;
				break;//�˴�breakѭ����Ч�᷵�����forѭ�� 
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
