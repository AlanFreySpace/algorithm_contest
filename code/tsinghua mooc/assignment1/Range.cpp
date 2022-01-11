#include <cstdio>
using namespace std;

/*
效果不明显
const int SZ = 1 << 20;  //提升IO buff 
struct fastio {
	char inbuf[SZ];
	char outbuf[SZ];
	fastio() {
		setvbuf(stdin, inbuf, _IOFBF, SZ);
		setvbuf(stdout, outbuf, _IOFBF, SZ);
	}
}io;
*/

#define N 10000002
int points[N];

/*
points[i]最终代表小于等于i-1的坐标的数量
如此设置则[a,b]区间内坐标数量为points[b+1]-pints[a]，则points[a]不会成负数溢出
*/
int main(){
	int n, m, x, a, b;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < N; i++) {
		points[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		points[x+1] = 1;
	}

	for (int i = 1; i < N; i++) {
		points[i] += points[i - 1];
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		printf("%d \n", points[b+1] - points[a]);
	}
}