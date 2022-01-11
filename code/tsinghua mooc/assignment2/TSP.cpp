#include <cstdio>
using namespace std;

#define MAXN 1000001
#define GetMax(a,b) a>b?a:b

//代表边的顶点
struct ENode {
	int num = 0;//顶点号
	ENode* succ = NULL;//顶点后继
};

//邻接表的表头顶点
struct VNode {
	int in = 0, len = 0;//in是入度，len代表到该点的最长路径
	ENode* firstEdge = NULL;//指向其第一条边
}vnode[MAXN];

int longR = 0;//最长路径

//利用零入度的拓扑排序框架寻找最长路径
int TSort(int n) {
	int* Stack = new int[n];
	int count = 0;
	for (int i = 1; i <= n; i++) {//将零入度顶点压入栈
		if (vnode[i].in == 0) Stack[count++] = i;
	}
	while (count != 0) {
		int cur = Stack[--count];
		for (ENode* e = vnode[cur].firstEdge; e; e = e->succ) {//遍历零入度顶点的邻居节点
			int num = e->num;
			vnode[num].len = GetMax(vnode[num].len, vnode[cur].len + 1);//更新邻居节点的最长路径
			longR = GetMax(longR, vnode[num].len);//更新最长路径
			if (--vnode[num].in == 0) Stack[count++] = num;//若邻居顶点的入度变为0，则应压入栈
		}
	}
	return longR;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int i, j;
	for (int k = 0; k < m; k++) {
		scanf("%d %d", &i, &j);
		ENode* enode = new ENode();
		//构造邻接表，注意，顶点i最后读入的邻居顶点反而会成为firstEdge
		enode->num = j;
		enode->succ = vnode[i].firstEdge;
		vnode[j].in++;
		vnode[i].firstEdge = enode;
	}
	int ans = TSort(n);
	printf("%d", ans + 1);
	return 0;
}