#include <cstdio>
using namespace std;

#define MAXN 1600000
int B[MAXN]; //���жϿ����Ե�ʻ������
int S[MAXN]; //��תä��
int ans[2 * MAXN]; //��Ų�������

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &B[i]);

	/*
	top:ջ���й������Ԫ�أ������ȳ��ĳ���������
	count:��ǰջ��Ԫ�ظ���   flag:�����Ƿ���ڲ�������
	*/
	int top = 0, count = 0, k = 0, flag = 1;
	for (int i = 0; i < n; i++) {
		while (count<m && B[i]>top) {//����ѹջ��ʹ��ջ��Ԫ���㹻��
			S[count++] = ++top;
			ans[k++] = 1;
			//printf("%s%d ","push",top);
		}
		if (count == m && top < B[i]) {//Sջ���������������޲�������
			flag = 0;
			printf("%s ", "No");
			break;
		}
		else if(top == B[i]) {//ջ��Ԫ�شﵽҪ�󣬿��Ե���
			count--;
			ans[k++] = 2;
			//printf("%s%d ", "pop", top);
		}
		if (B[i] < top) {//��ǰ����B��Ҫ��Ԫ��С��ջ���й������Ԫ��
			count--;
			if (S[count] == B[i]) {//ջ��Ԫ������Ҫ�󣬿��Ե���
				ans[k++] = 2;
				//printf("%s%d ", "pop", S[count]);
			}
			else {//ջ��Ԫ�ز�����Ҫ��û�в�������
				flag = 0;
				printf("%s", "No");
				break;
			}
		}
	}

	if (flag == 1) {
		for (int i = 0; i < k; i++) {
			if (ans[i] == 1)
				printf("%s", "push\n");
			else
				printf("%s", "pop\n");
		}
	}
	return 0;
}