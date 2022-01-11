#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cmath>

#define MAXN 4000000
#define M pow(2,32)

struct Node {
	long long priority;//注意这个数要开的足够大
	char name[9];
}node[MAXN];

/*
在结构体(或类？)内定义双目运算符必须加friend(友元) 否则在类外定义
友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数
就相当于在类外定义
*/
bool operator<(Node a, Node b) {
	if (a.priority != b.priority) return a.priority < b.priority;
	return strcmp(a.name, b.name) < 0;
}

void swap(Node& a, Node& b) {
	Node temp;
	temp = a;
	a = b;
	b = temp;
}

int size = 0;

void insert(Node n) {
	node[size++] = n;
	int cur = size - 1, next = (cur - 1) / 2;
	while (next >= 0 && node[cur] < node[next]) {
		swap(node[cur], node[next]);
		cur = next;
		next = (cur - 1) / 2;
	}
}

/*
注意del函数的更简单实现：
void down(int p) {
    int s = p * 2;
    while (s <= n) {
        if (s < n && heap[s+1] < heap[s]) s++;
        if (heap[s] < heap[p]) {
            swap(heap[p], heap[s]);
            p = s;
            s *= 2;
        } else break;
    }
}(下标默认从1开始)(我的写法下标从0开始)
*/
Node del() {
	if (size == 1) return node[--size];
	int cur = 0;
	//node[cur] = node[--size];
	swap(node[cur], node[--size]);
	int child1 = 1, child2 = 2;
	while (true) {
		if (child2 < size) {
			if (node[child1] < node[child2]) {
				if (node[child1] < node[cur]) {
					swap(node[child1], node[cur]);
					cur = child1;
					child1 = 2 * cur + 1;
					child2 = 2 * cur + 2;
				}
				else break;
			}
			else {
				if (node[child2] < node[cur]) {
					swap(node[child2], node[cur]);
					cur = child2;
					child1 = 2 * cur + 1;
					child2 = 2 * cur + 2;
				}
				else break;
			}
		}
		else if (child1 < size) {
			if (node[child1] < node[cur]) swap(node[child1], node[cur]);
			break;
		}
		else break;
	}
	return node[size];
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Node x;
	for (int i = 0; i < n; i++) {
		/*
		注意数据范围 这里若写scanf("%d %s", &x.priority, &x.name);会出错
		*/
		scanf("%lld %s", &x.priority, &x.name);
		insert(x);
	}
	for (int i = 0; i < m; i++) {
		if (size > 0) {
			x = del();
			printf("%s\n", x.name);
			x.priority *= 2;
			if (x.priority < M) insert(x);
		}
		else break;
	}
	return 0;
}