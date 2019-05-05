#include<stdio.h>
#include<stdlib.h>

void swap(int*x, int*y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
typedef int(*Cmp)(int x, int y);
void Bubblesort(int arr[], int size, Cmp cmp) {
	int bound = 0;
	for (; bound < size; ++bound){
		for (int cur = size - 1; cur > bound; --cur) {
			if (!cmp(arr[cur - 1], arr[cur])) {
				swap(&arr[cur - 1], &arr[cur]);
			}
		}
	}
}
int less(int x, int y) {
	if (x < y) {
		return 1;
	}
	return 0;
}
/*int greater(int x, int y) {
	if (x > y) {
		return 1;
	}
	return 0;
}*/
int main(){
	int arr[4] = { 9,5,2,7 };
	Bubblesort(arr, 4, less/*greater*/);
	for (int i = 0; i < 4; ++i) {
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}