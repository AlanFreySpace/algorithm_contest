#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

#define MAXN 40320
#define QSIZE 41000

int dist[MAXN];//���գ�������Ϊ0�����޷��任�ɸ�״̬�������Ǳ任�ɸ�״̬���貽��+1

int f[8];
//����׳�ֵ
void fCompute() {
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i < 8; i++)
		f[i] = i * f[i - 1];
}

struct Node {
	int a[10];
	int num;
	//int num = 0; ע�ⲻ������������num��������bfs()�����е�op = now;һ�佫���num�����ڵ��
	//����չ��     ����չ��ֵ�ۼӣ������ֵ�ǲ����ۼӵġ�
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
	//����������
	void op1() {
		for (int i = 1; i <= 4; i++) swap(a[i], a[9 - i]);
	}
	//ѭ������
	void op2() {
		a[0] = a[1];
		a[9] = a[8];
		for (int i = 1; i < 4; i++) a[i] = a[i + 1];
		a[4] = a[0];
		for (int i = 8; i > 5; i--) a[i] = a[i - 1];
		a[5] = a[9];
	}
	//��������ʱ����ת
	void op3() {
		a[0] = a[2];
		a[2] = a[3];
		a[3] = a[6];
		a[6] = a[7];
		a[7] = a[0];
	}
}queue[QSIZE];//����ģ�����

void bfs() {
	int from = 0, to = 0;
	Node now;
	for (int i = 1; i < 9; i++) now.a[i] = i;
	//queue[to++] = now;    ע��������˳������ôд������queue[0]�洢��Node��numֵ������δ����
	//dist[now.getCantor()] = 1; ��״̬
	dist[now.getCantor()] = 1;
	queue[to++] = now;
	Node op;//ע��now��op�����˲�ͬ�Ĵ洢�ռ䣬op=now��ɽ�now�и����ݸ��Ƶ�op�и�������Ĳ���

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

//��������bfs����״̬ͼ+����չ��(���ڼ��ٿռ临�Ӷ�)������ο����¾��㷨���46-50ҳ
//˼�룺�����ӳ�ʼ״̬12345678��������任�ɱ任�ɵ���ʽ
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