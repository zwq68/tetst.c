#include<stdlib.h>
#include<stdio.h>


swap(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
//堆排序
//   1   建堆  大堆(升序)  小堆(降序)  以大堆为例
//   2   排序 利用删除堆顶元素的思想

//堆的调整
//  输入: 一个数组 (数组大小,数组元素)   调整的起始点
//  处理:  函数实现的功能
//输出:   一个满足堆性质的堆
void  HeapAdjust(int *array, int size, int parent){
	int child = parent * 2 + 1;
	while (child < size){
		// 先找到左右孩子中较大的那个
		if (child + 1 < size && array[child + 1] > array[child]){
			child += 1;
		}
		//找到那个较大的孩子之后,将其与双亲进行比较
		// 如果大于其双亲则将两者进行交换
		if (array[child] > array[parent]){
			swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			return;
		}
	}
	
}

//堆的排序
void  HeapSort(int *array, int size){
	//  1建堆(大堆);
	// root 为堆中第一个非叶子节点
	int root = ((size - 2) >> 1);
	for (; root >= 0; --root){
		HeapAdjust(array, size, root);
	}

	//  2 排序
	int end = size - 1;
	while (end){
		swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;

	}
}
//  测试
	void testheap(){
		int array[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
		HeapSort(array, sizeof(array) / sizeof(array[0]));
		for (int i = 0; i < 10; ++i){
			printf("%d \n", array[i]);
		}
	}


	int main(){
		testheap();
		system("pause");
		return 0;
	}