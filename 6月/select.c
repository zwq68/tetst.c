#include<stdio.h>
#include<stdlib.h>

//  ��������
void swap(int *x,int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


// �����㷨�ļ�ǿ ֮  ѡ������

// ����:  һ������(����Ԫ�غ������С)
//  ʵ�ֹ���:   ���ȼٶ�������Ԫ��Ϊ����Ԫ��������Ԫ��,��maxpos��������Ԫ��
//  ���ű�������������Ԫ��,�������ֵ������Ԫ�رȽ�,������Ǹ�Ԫ�ش���maxpos��ǵ�Ԫ��,����maxpos�������(����maxpos)
// ÿһ�α���ѡ�����������ֵ,������������β��Ԫ�ؽ���,�������֮�����β��Ԫ��
//  �ٽ�maxpos���������Ԫ��,Ȼ���ظ���������


// ѡ������
void selectsort(int *array, int size){
	// ��һ��ѭ�������Ʊ����Ĵ���  �ܹ���Ҫ����size-2��
	for (int i = 0; i < size - 1; ++i){
		int maxpos = 0; // ÿһ�α������ٶ���λԪ��Ϊ���ֵ
		// �ڶ���ѭ��������ÿ����������Ԫ��
		// ����ÿһ�α������Ѿ�ѡ�������ֵ,����´α�����Ԫ�ؾ���һλ
		for (int j = 1; j < size-i; ++j){
			if (array[j]>array[maxpos]){
				maxpos = j;// �������Ԫ�ش���maxpos��ǵ�ֵ,���ø�Ԫ�ص��±����޸�maxpos��ֵ
			}
			// ÿһ��ѡ�����ֵ�ͽ���������β��Ԫ�ؽ���
			// �п���ԭ�����Ԫ�ؾ�����������,����ڽ���֮ǰ���ж�һ��
			//  ���ԭ����Ԫ�ؾ��ں��ʵ�λ���Ͼ�û�б�Ҫ����
			if (maxpos != size - 1 - i){
				swap(&array[maxpos], &array[size - 1 - i]);
			}
		}
	}
	
}
// ��ӡ���麯��
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