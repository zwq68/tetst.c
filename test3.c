#include<stdio.h>
#include<stdlib.h>
//二分查找(有序数列)

  int BinaryReserch(int arr[], int size, int to_find){
	int left = 0;
	int right = size - 1;
	while (left <= right){
		int mid = (left + right) / 2;
		if (arr[mid] > to_find){
			right = mid - 1;
		}
		else if (arr[mid] < to_find){
			left = mid + 1;
		}
		else{

			return mid;
		}
	}
	return -1;
}
int main(){
	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//printf("%d\n", size);

	int ret = BinaryReserch(arr, size,9);
	printf("%d\n", ret);

	system("pause");
	return 0;
}

	


