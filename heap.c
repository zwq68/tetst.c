#include<stdlib.h>
#include<stdio.h>


swap(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
//������
//   1   ����  ���(����)  С��(����)  �Դ��Ϊ��
//   2   ���� ����ɾ���Ѷ�Ԫ�ص�˼��

//�ѵĵ���
//  ����: һ������ (�����С,����Ԫ��)   ��������ʼ��
//  ����:  ����ʵ�ֵĹ���
//���:   һ����������ʵĶ�
void  HeapAdjust(int *array, int size, int parent){
	int child = parent * 2 + 1;
	while (child < size){
		// ���ҵ����Һ����нϴ���Ǹ�
		if (child + 1 < size && array[child + 1] > array[child]){
			child += 1;
		}
		//�ҵ��Ǹ��ϴ�ĺ���֮��,������˫�׽��бȽ�
		// ���������˫�������߽��н���
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

//�ѵ�����
void  HeapSort(int *array, int size){
	//  1����(���);
	// root Ϊ���е�һ����Ҷ�ӽڵ�
	int root = ((size - 2) >> 1);
	for (; root >= 0; --root){
		HeapAdjust(array, size, root);
	}

	//  2 ����
	int end = size - 1;
	while (end){
		swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;

	}
}
//  ����
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