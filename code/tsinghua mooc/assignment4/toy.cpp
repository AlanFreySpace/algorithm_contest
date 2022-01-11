#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

#define MAXN 40320
#define QSIZE 41000

int dist[MAXN];//最终，若该项为0，则无法变换成该状态，否则，是变换成该状态所需步数+1

int f[8];
//计算阶乘值
void fCompute() {
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i < 8; i++)
		f[i] = i * f[i - 1];
}

struct Node {
	int a[10];
	int num;
	//int num = 0; 注意不能在这里声明num，否则在bfs()函数中的op = now;一句将造成num，即节点的
	//康托展开     康托展开值累加，而这个值是不能累加的。
	int getCantor() {
		num = 0;
		for (int i = 1; i <= 8; i++) {
			int count = 0;
			for (int j = i + 1; j <= 8; j++) {
				if (a[i] > a[j]) count++;
			}
			num += (count * f[8 - i]);
		}
		return num;
	}

	void swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}
	//交换上下行
	void op1() {
		for (int i = 1; i <= 4; i++) swap(a[i], a[9 - i]);
	}
	//循环左移
	void op2() {
		a[0] = a[1];
		a[9] = a[8];
		for (int i = 1; i < 4; i++) a[i] = a[i + 1];
		a[4] = a[0];
		for (int i = 8; i > 5; i--) a[i] = a[i - 1];
		a[5] = a[9];
	}
	//绕中心逆时针旋转
	void op3() {
		a[0] = a[2];
		a[2] = a[3];
		a[3] = a[6];
		a[6] = a[7];
		a[7] = a[0];
	}
}queue[QSIZE];//用于模拟队列

void bfs() {
	int from = 0, to = 0;
	Node now;
	for (int i = 1; i < 9; i++) now.a[i] = i;
	//queue[to++] = now;    注意这两句顺序不能这么写，否则queue[0]存储的Node的num值将处于未更新
	//dist[now.getCantor()] = 1; 的状态
	dist[now.getCantor()] = 1;
	queue[to++] = now;
	Node op;//注意now和op分配了不同的存储空间，op=now完成将now中各数据复制到op中各数据域的操作

	while (from != to) {
		now = queue[from++];
		op = now;

		op.op1();
		if (!dist[op.getCantor()]) {
			dist[op.num] = dist[now.num] + 1;
			queue[to++] = op;
		}

		op = now;
		op.op2();
		if (!dist[op.getCantor()]) {
			dist[op.num] = dist[now.num] + 1;
			queue[to++] = op;
		}

		op = now;
		op.op3();
		if (!dist[op.getCantor()]) {
			dist[op.num] = dist[now.num] + 1;
			queue[to++] = op;
		}
	}
}

//本题利用bfs搜索状态图+康托展开(用于减少空间复杂度)解决，参考罗勇军算法书的46-50页
//思想：搜索从初始状态12345678，经过逆变换可变换成的形式
int main() {
	fCompute();
	bfs();
	int n;
	Node x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 9; j++) scanf("%d", &x.a[j]);
		printf("%d\n", dist[x.getCantor()]-1);
	}
	/*
	Node *node = new Node();
	for (int i = 1; i <= 8; i++) node->a[i] = 9-i;
	printf("%d",node->getCantor());
	*/
	return 0;
}