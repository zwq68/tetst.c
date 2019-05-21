#include"heap.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


swap(HPDataType*x, HPDataType*y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
//向下调整
void AdjustDown(int *array, int size, int parent){
	//默认让child标记parent的左孩子以及(较小的孩子),因为完全二叉树中,如果只有一个孩子那么,此孩子一定是左孩子
	int child = parent * 2 + 1;
	
	while (child<size){
		//找双亲孩子中较小的孩子(前提是右孩子存在)
		if (child+1<size && array[child + 1] < array[child]){
			child += 1;

		}
		//找到较小的以后,再和双亲比较
		if (array[child] < array[parent]){
			swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			return; //该二叉树已经满足堆的性质,所以没有必要调整
		}
	}
	

}

void AdjustUp(HPDataType*array, int size, int child){
	int parent = (child - 1) / 2;
	while (child){
		if (array[child] < array[parent]){
			swap(&array[child], &array[parent]);
			child = parent;//让child走到parent的位置
			parent = (child - 1) / 2;
		}
		else{
			return;
		}
	}
}
void CheckCapacity(Heap*hp){
	assert(hp);
	if (hp->_size == hp->_capacity){
		int newcapacity = hp->_capacity * 2;
		HPDataType*pTmp = (HPDataType*)malloc(sizeof(HPDataType)*newcapacity);
		if (NULL == pTmp){
			assert(0);
			return;
		}
		//拷贝元素
		for (int i = 0; i < hp->_size; ++i){
			pTmp[i] = hp->_array[i];

		}
		//释放原空间
		free(hp->_array);
		//更新参数
		hp->_array = pTmp;
		hp->_capacity = newcapacity;
	}
	
}
//初始化堆
void InitHeap(Heap*hp, HPDataType*array, int size){
	assert(hp);
	//开辟空间
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*size);
	if (hp->_array == NULL){
		assert(0);
		return;
	}
	hp->_capacity = size;
	//将数组中的元素搬移到堆中
	for (int i = 0; i < size; ++i){
		hp->_array[i] = array[i];
	
	}
 	hp->_size = size;
	// 将该完全二叉树调整使其满足堆的性质

	//找完全二叉树中的倒数第一个非叶子节点
	int root = ((size - 2) >> 1);
	for (; root >= 0; --root){
		AdjustDown(hp->_array, size, root);
	}

}
void InsertHeap(Heap*hp, HPDataType data){
	//先判断是否需要扩容
	CheckCapacity(hp);
	//将元素放入堆中
	hp->_array[hp->_size] = data;
	hp->_size++;
	//放入之后有可能破坏堆的性质,如果 破坏了则需要调整
	AdjustDown(hp->_array, hp->_size, hp->_size - 1);
}

void EraseHeap(Heap*hp){
	if (HeapEmpty(hp)){
		return;
	}
	//先交换 再删除  再调整
	swap(&hp->_array[0], &hp->_array[hp->_size-1]);
	hp->_size--;
	AdjustDown(hp->_array, hp->_size, 0);
	

}
int HeapSize(Heap*hp){
	assert(hp);
	return hp->_size;
}
int HeapEmpty(Heap*hp){
	assert(hp);
	return 0 == hp->_size;
}
HPDataType HeapTop(Heap*hp){
	assert(hp);
	return hp->_array[0];
}
void DestoryHeap(Heap*hp){
	assert(hp);
	if (hp->_array){
		free(hp->_array);
		hp->_capacity = 0;
		hp->_size = 0;
	}
}

void TestHeap(){
	Heap hp;//定义一个堆
	int array[] = { 2, 3, 8, 0, 9, 1, 7, 4, 6, 5 };
	InitHeap(&hp, array, sizeof(array) / sizeof(array[0]));

	printf("%d ", HeapSize(&hp));
	printf("%d ", HeapTop(&hp));


	EraseHeap(&hp);
	printf("%d ", HeapTop(&hp));
	
	InsertHeap(&hp, 0);
	printf("%d ", HeapTop(&hp));

	DestoryHeap(&hp);
}

void HeapAdjust(int *array, int size, int parent){
	
	int child = parent * 2 + 1;
	while (child < size){
		//找到左右孩子中较大的孩子
		if (child + 1 < size && array[child + 1] > array[child]){
			child += 1;
		}
		//找到了较大的孩子,然后与双亲比较,
		if (array[child]>array[parent]){
			swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			return;
		}
	}
}

void HeapSort(int *array, int size){
	//:建堆-----大堆
	// 找到倒数第一个非叶子节点
	int root = ((size - 2) >> 1) ;
	for (;  root >= 0 ;--root){
		HeapAdjust(array, size, root);

	}
	//2.排序:用堆删除的思想
	int end = size - 1;
	while (end){
		swap(&array[0],&array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}

}
void testheap(){

	int array[] = { 2, 3, 8, 0, 9, 1, 7, 4, 6, 5 };
	HeapSort( array, sizeof(array) / sizeof(array[0]));

}
