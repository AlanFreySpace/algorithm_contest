#include "stdafx.h"
#include <iostream>
#include <iomanip> //setprecision��ͷ�ļ�
using namespace std;

int main() {
	int a;
	float b = 0;
	cin >> a;
	cout << fixed << setprecision(1);//�趨С�������1λС��
	//0.4463������c++��Ĭ��double����,����bΪfloat�Ὣ�����doubleתΪfloat��IDE����ʾwarning���ܶ�ʧ����
	if (a <= 150) b = 0.4463 * a;
	else if (a > 150 && a < 401) b = 0.4463 * 150 + (a - 150) * 0.4663;
	else b = 0.4463 * 150 + 0.4663 * 250 + (a - 400) * 0.5663;
	cout << b << endl;
	return 0;
}