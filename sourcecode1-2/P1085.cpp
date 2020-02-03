#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
	int schoolTi[7], motherTi[7];
	for (int i = 0; i < 7; i++)
		cin >> schoolTi[i] >> motherTi[i];
	int unhappy, totalTi, max = 0;
	for (int i = 0; i < 7; i++) {
		totalTi = schoolTi[i] + motherTi[i];
		if (totalTi > 8 && totalTi > max) {
			max = totalTi;
			unhappy = i + 1;
		}
	}
	cout << unhappy << endl;
	return 0;
}