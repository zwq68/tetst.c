#include<stdio.h>
#include<stdlib.h>

// 交换函数(特别注意,这里不能直接传值,形参无法修改实参,此处应该传指针)
void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
// 划分函数
int partion(int *array,int left,int right){
	// 用一下两个标记从首位开始遍历数组元素
	int begin = left; // 用begin来标记数组第一位元素的下标
	int end = right - 1;// 用end来标记数组最后一位元素的下标

	int key = array[right - 1];// 以数组最后一个元素来表示基准值

	//最外层循环用来控制不让begin和end相遇
	while (begin < end){
		
		// 让begin 从前往后走找比基准值大的元素
		while (begin < end&&array[begin] <= key){
			begin++;
		}
	  // 出了循环有两种情况
		// 情况 1 :已经遍历了所有的元素
		// 情况 2 : 已经找到了一个比基准值大的元素

		//让end 从后往前找比基准值小的元素
		while (begin<end&&array[end]>=key){
			end--;
		}
		// 出了循环有两种情况
		// 情况1 : 已经遍历了所有的元素
		// 情况2 :已经找到了比基准值小的元素

		// 经过上面两个循环.已经找到了比基准值大和比基准值小的元素
		// 如果begin 和end 还没有相遇就将两者进行交换
		if (begin != end){
			swap(&array[begin], &array[end]);
		}
	}
	// 出了这次循环,begin和end已经相遇,此时将基准值放在划分位置
	if (begin != right-1){
		swap(&array[begin], &array[right-1]);
	}
	return begin;// 将划分值返回
}
// 快排(递归版本)
//  输入: 一个数组 数组首元素  数组末尾元素
void quicksort(int *array, int left, int right){
	//  确保有元素的前提下进行排序  条件:(right - left) > 1
	if ((right - left) > 1){
		int div = partion(array, left, right);
		quicksort(array, left, div);
		quicksort(array, div + 1, right);

	}
}
	
// 打印数组元素
void print(int *array, int size){
	for (int i = 0; i < size; ++i){
		printf("%d ",array[i]);
	}
	printf("\n");
}
int main(){
	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int size = sizeof(array) / sizeof(array[0]);
	quicksort(array, 0, size);// 排序
	print(array, size);// 将数组元素进行打印

	system("pause");
	return 0;
}