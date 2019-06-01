#include<stdio.h>
#include<stdlib.h>

void swap(int* x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


// �����㷨�ļ�ǿ ֮��������
void  InsertSort(int *array, int size){
	//��һ��ѭ������Ҫ�����Ԫ��
	for (int i = 1; i < size; ++i){
		int key = array[i];// ��key ����¼Ҫ�����Ԫ��
		int end = i - 1;// ��end����ʾҪ�����Ԫ�ص�ǰһ��Ԫ��
		while (end>=0&&key<array[end]){
			array[end + 1] = array[end];
			end--; 
		}
		array[end + 1] = key;
	}

}

// ��ӡ����
void  print(int array[], int size){
	for (int i = 0; i < size; ++i){
		printf("%d", array[i]);
	}
	printf("\n");
}



// �����㷨�ļ�ǿ֮ ��������������  ----ϣ�������㷨
//  ����˼��:  ����  �ȼ����ԭ�������  ������ɴ�С  gap
void ShellSort(int *array, int size){
	int gap = 3;   //  1 2 3 4 5 6 7 8 9 0
	//  ��һ��ѭ�� ��������(���� gap ������)
	while (gap){
		// �ڶ���ѭ�� �������Ƹ����� Ҫ�����Ԫ��
		for (int i = gap; i < size; ++i){
			int key = array[i];
			int end = i - gap;
			// ������ѭ�� ͨ�������ķ�ʽ��Ҫ�����Ԫ����������ڱȽ�.
			//һֱ����ֱ��������ѭ������,Ȼ�����Ԫ��
			while (end >= 0 && key < array[end]){
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
		gap--;
	}
}

//  �����㷨�ļ�ǿ֮ѡ������ 
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





