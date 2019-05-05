#include<stdio.h>
#include<stdlib.h>
void swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
	void Bubblesort(int arr[], int size){
		int bound = 0;
		for (; bound < size; ++bound) {
			for (int cur = size - 1; cur > bound; --cur) {
				if(arr[cur-1]>arr[cur]) {
					swap(&arr[cur-1], &arr[cur]);
				}
			}
		}
	}

int main() {
	int arr[4] = { 9,5,2,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Bubblesort(arr, size);
	for (int i = 0; i < 4; ++i) {
		printf("%d\n", arr[i]);
		
	}
	system("pause");
	return 0;
}