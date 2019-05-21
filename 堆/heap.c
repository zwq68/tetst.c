#include"heap.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


swap(HPDataType*x, HPDataType*y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
//���µ���
void AdjustDown(int *array, int size, int parent){
	//Ĭ����child���parent�������Լ�(��С�ĺ���),��Ϊ��ȫ��������,���ֻ��һ��������ô,�˺���һ��������
	int child = parent * 2 + 1;
	
	while (child<size){
		//��˫�׺����н�С�ĺ���(ǰ�����Һ��Ӵ���)
		if (child+1<size && array[child + 1] < array[child]){
			child += 1;

		}
		//�ҵ���С���Ժ�,�ٺ�˫�ױȽ�
		if (array[child] < array[parent]){
			swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			return; //�ö������Ѿ�����ѵ�����,����û�б�Ҫ����
		}
	}
	

}

void AdjustUp(HPDataType*array, int size, int child){
	int parent = (child - 1) / 2;
	while (child){
		if (array[child] < array[parent]){
			swap(&array[child], &array[parent]);
			child = parent;//��child�ߵ�parent��λ��
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
		//����Ԫ��
		for (int i = 0; i < hp->_size; ++i){
			pTmp[i] = hp->_array[i];

		}
		//�ͷ�ԭ�ռ�
		free(hp->_array);
		//���²���
		hp->_array = pTmp;
		hp->_capacity = newcapacity;
	}
	
}
//��ʼ����
void InitHeap(Heap*hp, HPDataType*array, int size){
	assert(hp);
	//���ٿռ�
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*size);
	if (hp->_array == NULL){
		assert(0);
		return;
	}
	hp->_capacity = size;
	//�������е�Ԫ�ذ��Ƶ�����
	for (int i = 0; i < size; ++i){
		hp->_array[i] = array[i];
	
	}
 	hp->_size = size;
	// ������ȫ����������ʹ������ѵ�����

	//����ȫ�������еĵ�����һ����Ҷ�ӽڵ�
	int root = ((size - 2) >> 1);
	for (; root >= 0; --root){
		AdjustDown(hp->_array, size, root);
	}

}
void InsertHeap(Heap*hp, HPDataType data){
	//���ж��Ƿ���Ҫ����
	CheckCapacity(hp);
	//��Ԫ�ط������
	hp->_array[hp->_size] = data;
	hp->_size++;
	//����֮���п����ƻ��ѵ�����,��� �ƻ�������Ҫ����
	AdjustDown(hp->_array, hp->_size, hp->_size - 1);
}

void EraseHeap(Heap*hp){
	if (HeapEmpty(hp)){
		return;
	}
	//�Ƚ��� ��ɾ��  �ٵ���
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
	Heap hp;//����һ����
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
		//�ҵ����Һ����нϴ�ĺ���
		if (child + 1 < size && array[child + 1] > array[child]){
			child += 1;
		}
		//�ҵ��˽ϴ�ĺ���,Ȼ����˫�ױȽ�,
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
	//:����-----���
	// �ҵ�������һ����Ҷ�ӽڵ�
	int root = ((size - 2) >> 1) ;
	for (;  root >= 0 ;--root){
		HeapAdjust(array, size, root);

	}
	//2.����:�ö�ɾ����˼��
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
