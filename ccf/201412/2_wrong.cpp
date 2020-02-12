#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* ans = new int[n*n];
	memset(ans, 0, n*n * sizeof(int));
	int** square = new int*[n];
	for (int i = 0; i<n; i++) square[i] = new int[n];
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) cin >> square[i][j];
	}
	int lr = 0, ud = 0;
	ans[0] = square[0][0];
	int ju = 0, v = 0, w = 1;
	
	while (true) {
		if (ju % 4 == 0) ans[++v] = square[lr][++ud];
		else if (ju % 4 == 1) {
			int k = w;
			while (k>0) {
				ans[++v] = square[++lr][--ud];
				k--;
			}
			if (w == n - 1){
				ju=3;
				break;
			}
			w++;
		}
		else if (ju % 4 == 2) ans[++v] = square[++lr][ud];
		else {
			int k = w;
			while (k>0) {
				ans[++v] = square[--lr][++ud];
				k--;
			}
			if (w == n - 1){
				ju=1;
				break;
			} 
			w++;
		}
		ju++;
	}
	w--;
	while(true){
		if(v==n*n-1) break;
		if(ju%4==0){
			int k=w;
			while(k>0){
				ans[++v]=square[--lr][++ud];
				k--;
			}
			w--;
		}
		else if(ju%4==1) ans[++v] = square[++lr][ud];
		else if(ju%4==2){
			int k=w;
			while(k>0){
				ans[++v] = square[++lr][--ud];
				k--;
			}
			w--;
		}
		else ans[++v] = square[lr][++ud];
		ju++;
	}
	
	for (int i = 0; i<n*n; i++) cout << ans[i] << " ";
	return 0;
}
