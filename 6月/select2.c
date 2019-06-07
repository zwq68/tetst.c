#include<stdio.h>
#include<stdlib.h>



void swap(int* x, int* y){
	int  tmp = *x;
	*x = *y;
	*y = tmp;
}
//  �����㷨�ļ�ǿ֮ѡ������(˫�����°�);
// ����: ����Ԫ��   �������С
void selectsort2(int *array, int size){
	//  [begin, end] ��ʾ����������
	int begin = 0;
	int end = size - 1;
	// ��һ��ѭ�����ƴ�����������Ԫ��
	while (begin < end){
		int minpos = begin;// ��minpos  �����СֵԪ�ص�λ��,ÿ�α���ǰ�������Ӵ����������һ��Ԫ�ؿ�ʼ
		int maxpos = begin;// �� maxpos  ������ֵԪ�ص�λ��,ÿ�α���ǰ�������Ӵ����������һ��Ԫ�ؿ�ʼ
		int index = begin + 1;// �� index��ʾ ���������佫Ҫ�����Ƚϵ�Ԫ��
		// �ڶ���ѭ�����Ʊ����ķ�Χ
		while (index <= end){
			if (array[index]>array[maxpos]){
				maxpos = index;
			}
			if (array[index] < array[minpos]){
				minpos = index;
			}
			index++;//����index  ,�������������һ��Ԫ��
		}
		//��Ϊ�ȴ���������ֵ������,������һ�����:  ����ǰ  ��Сֵ���ڴ��������������һ��λ��,��ʱ��minpos���
		// ���������λ���ҵ����ֵԪ��,Ȼ�����߽���,��ôminpos���ڱ�ʾԭ������Сֵ,��Сֵ��λ���Ѿ���Ϊ���ֵ,
		// ��� Ӧ�ø���minpos ����ᷢ������
		if (minpos == end){
			minpos = maxpos;
		}
		// �����ֵ�����������һ��λ��
		// ��Ϊ, ԭ������ܱ��������������鼴 ���ֵԪ�ؾ�������ĩβ,��ʱ����Ҫ���н���
		// �����ڽ���ǰ��Ҫ��һ���ж�
		if (maxpos != end){
			swap(&array[maxpos], &array[end]);
		}
		// ����Сֵ���ڵ�һ��λ��
		// ��Ϊ, ԭ������ܱ��������������鼴 ��СֵԪ�ؾ���������λ,��ʱ����Ҫ���н���
		// �����ڽ���ǰ��Ҫ��һ���ж�
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