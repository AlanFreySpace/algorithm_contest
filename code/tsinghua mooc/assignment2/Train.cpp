#include <cstdio>
using namespace std;

#define MAXN 1600000
int B[MAXN]; //待判断可行性的驶出序列
int S[MAXN]; //中转盲端
int ans[2 * MAXN]; //存放操作次序

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &B[i]);

	/*
	top:栈中有过的最大元素，即调度出的车厢的最大编号
	count:当前栈中元素个数   flag:表明是否存在操作序列
	*/
	int top = 0, count = 0, k = 0, flag = 1;
	for (int i = 0; i < n; i++) {
		while (count<m && B[i]>top) {//不断压栈，使得栈顶元素足够大
			S[count++] = ++top;
			ans[k++] = 1;
			//printf("%s%d ","push",top);
		}
		if (count == m && top < B[i]) {//S栈的容量不够导致无操作序列
			flag = 0;
			printf("%s ", "No");
			break;
		}
		else if(top == B[i]) {//栈顶元素达到要求，可以弹出
			count--;
			ans[k++] = 2;
			//printf("%s%d ", "pop", top);
		}
		if (B[i] < top) {//当前序列B中要求元素小于栈中有过的最大元素
			count--;
			if (S[count] == B[i]) {//栈顶元素满足要求，可以弹出
				ans[k++] = 2;
				//printf("%s%d ", "pop", S[count]);
			}
			else {//栈顶元素不满足要求，没有操作序列
				flag = 0;
				printf("%s", "No");
				break;
			}
		}
	}

	if (flag == 1) {
		for (int i = 0; i < k; i++) {
			if (ans[i] == 1)
				printf("%s", "push\n");
			else
				printf("%s", "pop\n");
		}
	}
	return 0;
}