#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

#define MAXN 100010
char s1[2 * MAXN];
char s2[MAXN];

//˼·:������s1ƴ����һ����s2��ѭ����λ�õ�����s1��s1��ƴ����Ӧ����s2
int main() {
	while (scanf("%s %s", &s1, &s2) != EOF) {
		if (strlen(s1) != strlen(s2))
			printf("%s\n", "NO");
		else {
			int len = strlen(s1);
			for (int i = 0; i < len; i++) s1[len + i] = s1[i];
			//printf("%s\n", strstr(s1, s2));strstr����
			//s1�е�һ�γ���s2��λ�ú���������ַ�����s2δ��s1�г���
			//����null
			if (strstr(s1, s2) != NULL) printf("%s\n", "YES");
			else printf("%s\n", "NO");
		}
	}
	return 0;
}