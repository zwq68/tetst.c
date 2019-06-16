#include<stdio.h>
#include<stdlib.h>

// ��������(�ر�ע��,���ﲻ��ֱ�Ӵ�ֵ,�β��޷��޸�ʵ��,�˴�Ӧ�ô�ָ��)
void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
// ���ֺ���
int partion(int *array,int left,int right){
	// ��һ��������Ǵ���λ��ʼ��������Ԫ��
	int begin = left; // ��begin����������һλԪ�ص��±�
	int end = right - 1;// ��end������������һλԪ�ص��±�

	int key = array[right - 1];// ���������һ��Ԫ������ʾ��׼ֵ

	//�����ѭ���������Ʋ���begin��end����
	while (begin < end){
		
		// ��begin ��ǰ�������ұȻ�׼ֵ���Ԫ��
		while (begin < end&&array[begin] <= key){
			begin++;
		}
	  // ����ѭ�����������
		// ��� 1 :�Ѿ����������е�Ԫ��
		// ��� 2 : �Ѿ��ҵ���һ���Ȼ�׼ֵ���Ԫ��

		//��end �Ӻ���ǰ�ұȻ�׼ֵС��Ԫ��
		while (begin<end&&array[end]>=key){
			end--;
		}
		// ����ѭ�����������
		// ���1 : �Ѿ����������е�Ԫ��
		// ���2 :�Ѿ��ҵ��˱Ȼ�׼ֵС��Ԫ��

		// ������������ѭ��.�Ѿ��ҵ��˱Ȼ�׼ֵ��ͱȻ�׼ֵС��Ԫ��
		// ���begin ��end ��û�������ͽ����߽��н���
		if (begin != end){
			swap(&array[begin], &array[end]);
		}
	}
	// �������ѭ��,begin��end�Ѿ�����,��ʱ����׼ֵ���ڻ���λ��
	if (begin != right-1){
		swap(&array[begin], &array[right-1]);
	}
	return begin;// ������ֵ����
}
// ����(�ݹ�汾)
//  ����: һ������ ������Ԫ��  ����ĩβԪ��
void quicksort(int *array, int left, int right){
	//  ȷ����Ԫ�ص�ǰ���½�������  ����:(right - left) > 1
	if ((right - left) > 1){
		int div = partion(array, left, right);
		quicksort(array, left, div);
		quicksort(array, div + 1, right);

	}
}
	
// ��ӡ����Ԫ��
void print(int *array, int size){
	for (int i = 0; i < size; ++i){
		printf("%d ",array[i]);
	}
	printf("\n");
}
int main(){
	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int size = sizeof(array) / sizeof(array[0]);
	quicksort(array, 0, size);// ����
	print(array, size);// ������Ԫ�ؽ��д�ӡ

	system("pause");
	return 0;
}