#include "stdafx.h"
#include <iostream>
#include <iomanip> //setprecision的头文件
using namespace std;

int main() {
	int a;
	float b = 0;
	cin >> a;
	cout << fixed << setprecision(1);//设定小数点后保留1位小数
	//0.4463这种在c++中默认double类型,声明b为float会将结果从double转为float，IDE会提示warning可能丢失数据
	if (a <= 150) b = 0.4463 * a;
	else if (a > 150 && a < 401) b = 0.4463 * 150 + (a - 150) * 0.4663;
	else b = 0.4463 * 150 + 0.4663 * 250 + (a - 400) * 0.5663;
	cout << b << endl;
	return 0;
}