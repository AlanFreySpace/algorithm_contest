#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

#define MAXN 100010
char s1[2 * MAXN];
char s2[MAXN];

//思路:将两个s1拼接在一起，若s2是循环移位得到，则s1与s1的拼接中应包含s2
int main() {
	while (scanf("%s %s", &s1, &s2) != EOF) {
		if (strlen(s1) != strlen(s2))
			printf("%s\n", "NO");
		else {
			int len = strlen(s1);
			for (int i = 0; i < len; i++) s1[len + i] = s1[i];
			//printf("%s\n", strstr(s1, s2));strstr返回
			//s1中第一次出现s2的位置后面的所有字符，若s2未在s1中出现
			//返回null
			if (strstr(s1, s2) != NULL) printf("%s\n", "YES");
			else printf("%s\n", "NO");
		}
	}
	return 0;
}