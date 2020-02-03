#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int start = a * 60 + b;
	int finish = c * 60 + d;
	int e = (finish - start) / 60;
	int f = (finish - start) - e * 60;
	cout << e << " " << f << endl;
	return 0;
}