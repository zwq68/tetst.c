#include<stdio.h>
#include<stdlib.h>

void swap(int* x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


// 排序算法哪家强 之插入排序
void  InsertSort(int *array, int size){
	//第一层循环控制要插入的元素
	for (int i = 1; i < size; ++i){
		int key = array[i];// 用key 来记录要插入的元素
		int end = i - 1;// 用end来表示要插入的元素的前一个元素
		while (end>=0&&key<array[end]){
			array[end + 1] = array[end];
			end--; 
		}
		array[end + 1] = key;
	}

}

// 打印数组
void  print(int array[], int size){
	for (int i = 0; i < size; ++i){
		printf("%d", array[i]);
	}
	printf("\n");
}



// 排序算法哪家强之 插入排序升级版  ----希尔排序算法
//  核心思想:  首先  等间隔将原数组分组  间隔数由大到小  gap
void ShellSort(int *array, int size){
	int gap = 3;   //  1 2 3 4 5 6 7 8 9 0
	//  第一层循环 控制组数(根据 gap 划分组)
	while (gap){
		// 第二层循环 用来控制该组中 要插入的元素
		for (int i = gap; i < size; ++i){
			int key = array[i];
			int end = i - gap;
			// 第三层循环 通过遍历的方式将要插入的元素逐个在组内比较.
			//一直遍历直到不满足循环条件,然后插入元素
			while (end >= 0 && key < array[end]){
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
		gap--;
	}
}

//  排序算法哪家强之选择排序 
void  ChooseSort(int *array,int size){
	for (int i = 0; i < size - 1; ++i){
		int maxpos = 0;
		for (int j = 1; j < size-i; ++j){
			if (array[j]>array[maxpos]){
				maxpos = j;
			}
			if (maxpos != size - i-1){
				swap(&array[maxpos], &array[size - i-1]);
			}
		}
	}
	
}

int main(){
	int array[] = { 1, 9, 4, 2, 3, 6, 5 };
	int size = sizeof(array) / sizeof(array[0]);
	print(array, size);
   //ShellSort(array, size);
	//InsertSort(array, size);
	ChooseSort(array, size);
	print(array, size);
	system("pause");
	return 0;
}





