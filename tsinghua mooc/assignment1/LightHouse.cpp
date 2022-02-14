#include <cstdio>
using namespace std;

#define MAXN 4000000

struct Point {
	int x;
	int y;
}point[MAXN];

int src[MAXN];
int des[MAXN];
long count = 0;

/*
快速排序，其速度快于STL的快排，对p[l,r]，以横坐标为标准排序
*/
void quicksort(Point* p, int l, int r) {
	if (l < r) {
		int key = p[l].x;//轴点
		int tmpx = p[l].x, tmpy = p[l].y;
		int left = l, right = r;
		while (left < right) {//每次左右过程后需要判断左右指针不越界
			while (left < right && p[right].x>tmpx) --right;//右侧过程
			p[left].x = p[right].x;
			p[left].y = p[right].y;
			while (left < right && p[left].x < tmpx) ++left;//左侧过程
			p[right].x = p[left].x;
			p[right].y = p[left].y;
		}
		p[left].x = tmpx;
		p[left].y = tmpy;
		quicksort(p, l, left - 1);
		quicksort(p, left + 1, r);
	}
}

//对src[l,mid]和src[mid+1,r]进行归并
void merge(int* src, int* des, int l, int r, int mid) {
	int left = l, right = mid + 1;
	int k = 0;
	while (left <= mid && right <= r) {
		if (src[left] < src[right]) {
			count = count + r - right + 1;
			des[k++] = src[left++];
		}
		else
			des[k++] = src[right++];
	}
	if (left == mid + 1) {
		for (int i = right; i <= r; i++)
			des[k++] = src[i];
	}
	else {
		for (int i = left; i <= mid; i++)
			des[k++] = src[i];
	}
	for (int i = l; i <= r; i++)
		src[i] = des[i - l];
}

//对src[l,r]进行归并排序，des用于存放merge过程的中间数组
void mergesort(int* src, int* des, int l, int r) {
	if (l < r) {
		int mid = (l + r) >> 1;
		mergesort(src, des, l, mid);
		mergesort(src, des, mid + 1, r);
		merge(src, des, l, r, mid);
	}
}

/*
首先利用快速排序即quicksort()按横坐标从小到大对灯塔进行排序，
则若这样排序后两灯塔的纵坐标不构成逆序，则两灯塔可互相照亮，否则不能互相照亮。
逆序对或者顺序对的数量可利用归并排序的归并过程得到，这得益于
归并排序分而治之的过程总是从最平凡情况开始，逐步构建有序序列，这使得
不同部分的逆序对不会相互影响，从而可以正确得出最终的逆序对数量。
*/
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%d %d", &point[i].x, &point[i].y);
	quicksort(point, 0, n - 1);
	
	for (int i = 0; i < n; i++)
		src[i] = point[i].y;
	mergesort(src, des, 0, n - 1);
	printf("%ld", count);
	return 0;
}