#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	float money = a + 0.1 * b;
	int amount = money / 1.9; //���Զ�����ȡ��
	cout << amount << endl;
	return 0;
}