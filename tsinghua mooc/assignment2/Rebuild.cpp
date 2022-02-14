#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

#define MAXN 4000000
int pre[MAXN];
int post[MAXN];

struct Node {
	int lc = 0;
	int rc = 0;
	int value = 0;
}node[MAXN];

void rebuild(int el, int er, int tl, int tr) {
	if (el == er) //处理到只有一个顶点的情况
		node[pre[el]].value = pre[el];
	else {
		/*
		Node root = node[pre[el]]; 注意这样会新分配一块内存，而不是在原内存上操作，是不对的
		root.value = pre[el];
		root.lc = pre[el + 1];
		root.rc = post[tr - 1];
		*/
		//得到当前子树根节点的左孩子和右孩子
		node[pre[el]].value = pre[el]; 
		node[pre[el]].lc = pre[el + 1];
		node[pre[el]].rc = post[tr - 1];
		int i = tl;
		//得到左子树和右子树的序列，并分别处理进行rebuild
		while (post[i] != node[pre[el]].lc) i++;
		rebuild(el + 1, el + 1 + i - tl, tl, i);
		rebuild(el + 2 + i - tl, er, i + 1, tr - 1);
	}
}
//中序遍历
void inOrder(Node root) {
	if (root.lc == 0 && root.rc == 0) {
		printf("%d ", root.value);
		return;
	}
	inOrder(node[root.lc]);
	printf("%d ", root.value);
	inOrder(node[root.rc]);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &pre[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &post[i]);

	rebuild(0, n - 1, 0, n - 1);
	inOrder(node[pre[0]]);
}