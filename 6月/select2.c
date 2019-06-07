#include<stdio.h>
#include<stdlib.h>



void swap(int* x, int* y){
	int  tmp = *x;
	*x = *y;
	*y = tmp;
}
//  排序算法哪家强之选择排序(双管齐下版);
// 输入: 数组元素   和数组大小
void selectsort2(int *array, int size){
	//  [begin, end] 表示待排序区间
	int begin = 0;
	int end = size - 1;
	// 第一层循环控制待排序区间有元素
	while (begin < end){
		int minpos = begin;// 用minpos  标记最小值元素的位置,每次遍历前都让它从待排序区间第一个元素开始
		int maxpos = begin;// 用 maxpos  标记最大值元素的位置,每次遍历前都让它从待排序区间第一个元素开始
		int index = begin + 1;// 用 index表示 待排序区间将要拿来比较的元素
		// 第二层循环控制遍历的范围
		while (index <= end){
			if (array[index]>array[maxpos]){
				maxpos = index;
			}
			if (array[index] < array[minpos]){
				minpos = index;
			}
			index++;//更新index  ,让它继续标记下一个元素
		}
		//因为先处理的是最大值的问题,有这样一种情况:  排序前  最小值就在待排序数组中最后一个位置,此时用minpos标记
		// 如果在其他位置找到最大值元素,然后将两者交换,那么minpos不在表示原来的最小值,最小值的位置已经变为最大值,
		// 因此 应该更新minpos 否则会发生错误
		if (minpos == end){
			minpos = maxpos;
		}
		// 将最大值放在数组最后一个位置
		// 因为, 原数组可能本来就是有序数组即 最大值元素就在数组末尾,此时不需要进行交换
		// 所以在交换前需要做一个判断
		if (maxpos != end){
			swap(&array[maxpos], &array[end]);
		}
		// 将最小值放在第一个位置
		// 因为, 原数组可能本来就是有序数组即 最小值元素就在数组首位,此时不需要进行交换
		// 所以在交换前需要做一个判断
		if (minpos != begin){
			swap(&array[minpos], &array[begin]);
		}
		begin++;
		end--;
	}

}
void print(int *array, int size){
	for (int i = 0; i < size; i++){
		printf("%d ", array[i]);

	}
	printf("\n");
}
int  main(){

	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int size = sizeof(array) / sizeof(array[0]);
	selectsort2(array, size);
	print(array, size);

	system("pause");
	return 0;
}