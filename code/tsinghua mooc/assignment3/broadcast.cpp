#include <cstdio>

#define MAXN 10001

struct ENode {
	int num;
	ENode* succ = NULL;
};

struct VNode {//flag为0表示顶点未被遍历到，flag为1代表广播站1，为2代表广播站2
	int flag = 0;
	ENode* firstEdge = NULL;
}vnode[MAXN];
//模拟bfs过程
int bfs(int n) {
	int* stack = new int[n];//模拟一个栈储存discovered的顶点
	int count = 1;
	stack[0] = 1;
	vnode[1].flag = 1;//bfs前准备工作，放入起始顶点
	while (count != 0) {
		int cur = stack[--count];
		for (ENode* e = vnode[cur].firstEdge; e; e=e->succ) {
			if (vnode[e->num].flag == 0) {//发现新顶点，将其与父节点置不同颜色，并将新顶点放入栈
				if (vnode[cur].flag == 1) vnode[e->num].flag = 2;
				else vnode[e->num].flag = 1;
				stack[count++] = e->num;
			}//若遍历到旧顶点，就检查颜色是否相同，相同则构造失败
			else if (vnode[e->num].flag == 1 && vnode[cur].flag == 1) return -1;
			else if (vnode[e->num].flag == 2 && vnode[cur].flag == 2) return -1;
		}
	}
	return 1;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int i, j;
	//利用邻接链表构建无向图
	for (int k = 0; k < m; k++) {
		scanf("%d %d", &i, &j);
		ENode *enodej = new ENode();
		enodej->num = j;
		enodej->succ = vnode[i].firstEdge;
		vnode[i].firstEdge = enodej;
		ENode* enodei = new ENode();
		enodei->num = i;
		enodei->succ = vnode[j].firstEdge;
		vnode[j].firstEdge = enodei;
	}
	printf("%d", bfs(n));
}