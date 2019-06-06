#include<stdio.h>
#include<stdlib.h>

//  交换函数
void swap(int *x,int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


// 排序算法哪家强 之  选择排序

// 输入:  一个数组(数组元素和数组大小)
//  实现过程:   首先假定数组首元素为数组元素中最大的元素,用maxpos来标记最大元素
//  接着遍历数组中其他元素,并将最大值与所遍元素比较,如果有那个元素大于maxpos标记的元素,就用maxpos来标记它(更新maxpos)
// 每一次遍历选出数组中最大值,并将其与数组尾部元素交换,交换完毕之后更新尾部元素
//  再将maxpos标记数组首元素,然后重复上述操作


// 选择排序
void selectsort(int *array, int size){
	// 第一层循环来控制遍历的次数  总共需要遍历size-2次
	for (int i = 0; i < size - 1; ++i){
		int maxpos = 0; // 每一次遍历都假定首位元素为最大值
		// 第二层循环来控制每次最多遍历的元素
		// 由于每一次遍历都已经选出来最大值,因此下次遍历的元素就少一位
		for (int j = 1; j < size-i; ++j){
			if (array[j]>array[maxpos]){
				maxpos = j;// 如果其他元素大于maxpos标记的值,就用该元素的下标来修改maxpos的值
			}
			// 每一次选出最大值就将其与数组尾部元素交换
			// 有可能原数组的元素就是升序序列,因此在交换之前先判断一下
			//  如果原数组元素就在合适的位置上就没有必要交换
			if (maxpos != size - 1 - i){
				swap(&array[maxpos], &array[size - 1 - i]);
			}
		}
	}
	
}
// 打印数组函数
void print(int *array, int size){
	for (int i = 0; i < size; ++i){
		printf("%d ", array[i]);
	}
	printf("\n");
}
int main(){
	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int size = sizeof(array) / sizeof(array[0]);
	selectsort(array, size);
	print(array, size);

	system("pause");
	return  0;
}