#include <cstdio>
#include <cstring>
using namespace std;

#define N 20010
char str[N];
char tmp[N];

char* Zuma(char* s,int pos) {
	int len = strlen(s);
	int left, right;
	left = right = pos;
	char c = s[pos];
	int count = 1;

	while (--left >= 0 && s[left] == c) count++;
	while (++right < len && s[right] == c) count++;
	if (count >= 3) {
		strcpy(tmp, s + right);
		strcpy(s + left + 1, tmp);
		if (left < 0) left++; //防止char[]溢出
		return Zuma(s, left);
	}
	else
		return s;
}

int main() {
	scanf("%[^\n]", &str);//用换行符为结束输入标志，而不是默认的空格
	//gets_s(str); 这种方法默认换行为结束输入标志，但在oj上不能用
	//gets(str); oj上第二个输入带空格但又没说，很奇怪
	int n;
	scanf("%d", &n);
	while (n--) {
		int pos;
		char c;
		scanf("%d %c", &pos, &c);
		strcpy(tmp, str + pos);//将起始地址为str[pos]及其后续部分替换为赋给tmp
		str[pos] = c;
		strcpy(str + pos + 1, tmp);//str[pos+1]及其后续部分替换为tmp
		Zuma(str, pos);
		if (strlen(str) > 0)
			printf("%s\n", str);
		else
			printf("-\n");
	}
}