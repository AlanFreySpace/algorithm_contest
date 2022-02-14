#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

#define MAXN 600001

char list[MAXN][41];//注意第2维度长度即字符串最大长度，需至少为41，原因是字符串需要有结束符。

//独立链节点
struct slot {
	char* data;
	int repeat = 0;
	slot* succ = NULL;
}bucket[MAXN];

int hashFunc(char* c) {//计算字符串的hash值
	int len = strlen(c);
	int res = 0;
	for (int i = 0; i < len; i++)
		res += (c[i] - 'a' + 1) * (i + 1);
	return res;
}

void insert(char* c, slot* s) {//向独立链里插入节点
	slot* sl = new slot();
	sl->data = c;
	sl->succ = s->succ;
	s->succ = sl;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &list[i]);
		int res = hashFunc(list[i]);
		slot* p = bucket[res].succ;
		while (p) {
			if (!strcmp(list[i], p->data)) {//出现一重复字符串
				if (p->repeat == 0) {//判断是否重复过
					p->repeat = 1;
					printf("%s\n", list[i]);
				}
				break;
			}
			p = p->succ;
		}
		if (!p) insert(list[i], &bucket[res]);//插入一新的字符串
	}
	return 0;
}