#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>

#if 0
int main(){
	//sizeof(�����)��ռ�ڴ��С,ռ�����ֽ�

	printf("%d\n", sizeof(char));//1
	printf("%d\n", sizeof(short));//2
	printf("%d\n", sizeof(int));//4
	printf("%d\n", sizeof(long));//4
	printf("%d\n", sizeof(long long));//8
	printf("%d\n", sizeof(float));//4
	printf("%d\n", sizeof(double));//8
	printf("%d\n", sizeof(long double));//8
	system("pause");
	return 0;
# endif
#if 0	
	int main(){
		printf("hello world!\n");
		system("pause");
		return 0;
	}
#endif
#if 0
	//�ֲ�����(�����ڲ�)    ��ȫ�ֱ���(�����ⲿ)
	//���ֲ�������ȫ�ֱ���ͬ��ʱ,�ֲ���������ʹ��
	//�Ƽ�ʹ�þֲ�����
	int global = 2019;
	int main(){
		int local = 2018;//�ֲ�
		int global = 2020;//�ֲ�����
		printf("global=%d\n", global);
		system("pause");
		return 0;
	}
#endif

#if 0  
	int main(){
		int num1 = 0;
		int num2 = 0;
		int sum = 0;
		printf("please enter two number:\n");
		scanf("%d %d", &num1, &num2);
		sum = num1 + num2;
		printf("%d\n", sum);
		system("pause");
		return 0;

	}
#endif

#if 0
	//ת���ַ�
	int main(){
		printf("c:\code\test.c\n");//"\t"  ��һ��ת���ַ�  :ˮƽ�Ʊ�� 
		system("pause");
		return 0;
	}
#endif
#if 0
	int main(){
		printf("%d\n", strlen("abcdef"));//6
		printf("%d\n", sizeof("abcdef"));//7
		
		printf("%d\n", strlen("c:\test\328test.c"));//14   "\+����" :��ASCII����ֵ
		printf("%d\n", strlen("\32"));
		system("pause");
		return 0;
	}
#endif

#if 0
	int main(){
		printf("���������ǿ˧��?   ����1 ��ʾ˧   ����2��ʾ��˧\n");
		int choice = 0;
		scanf("%d", &choice);
		if (choice == 1){
			printf("��������۹�!");
		}
		else{
			printf("����۾�Ϲ����!");
			}
		system("pause");
		return 0;
		}

	int main(){
		printf("�������\n");
		int line = 0;
		while (line <= 2000){
			line++;
			printf("��Ҫ����Ŭ���ô���!\n");

		}
		if (line > 2000){
			printf("���������۷�");
		}
		system("pause");
		return 0;
	}

	//���1  ��100
	int main(){
		for (int i = 1; i <=100; ++i){
			printf("%d\n", i);
		}
		system("pause");
	}
	int main(){
		int i = 1;
		while (i <= 100){
		
			printf("%d\n",i);
			i++;
		}
		system("pause");
		return 0;
	}

	//���� �븴��
	int Add(int x,int y){
		
		int sum= x + y;
	}
	int main(){
		int sum = 0;
		int a = 100;
		int b = 10000;
		sum = Add(a, b);
		printf("%d\n", sum);
		system("pause");
		return 0;
	}

	int main(){
		int a = 10;
		
		printf("%p", &a);
		system("pause");
		return 0;
	}
	int main(){
		char ch = 'w';
		char*pc = &ch;
		//*pc = 'q';
		printf("%p\n", pc);
		printf("%c\n", ch);
		printf("%c\n",*pc);
		system("pause");
		return 0;
	}

	//ָ������Ĵ�С
	//ָ���ͱ�����32λƽ̨��4���ֽ�  ,��64λƽ̨��8���ֽ�
	int main(){
		printf("%d\n", sizeof(char*));
		printf("%d\n", sizeof(int*));
		printf("%d\n", sizeof(double*));
		printf("%d\n", sizeof(float*));
		system("pause");
		return 0;
	}


	
	int main(){
		int day=0;
		printf("����������!\n");
		
		scanf("%d", &day);

		switch (day){
		case 1:
			printf("����һ\n");
			break;
		case 2:
			printf("���ڶ�\n");
			break;
		case 3:
			printf("������\n"); 
			break;
		case 4:
			printf("������\n");
			break;
		case 5:
			printf("������\n");
			break;
		
		case 6:
			printf("������\n"); 
			break;
		case 7:
			printf("������\n");
			break;
			//�������
		default:
			printf("����ɵ����\n");
			break;
		}
		system("pause");
		return 0;
	}
	//switch���ע������:
	//1  break ����ʡ
	//2  ��ü���  default
	// 3 switch ���ж��ı�����������������,����д���ʽ
	// 4case �����ֻ��дһ����������
	//�������Ӧ�ó��������յ�����(���Ƽ�ʹ��)

	//while �е�break��continue
	int main(){
		int i = 1;
	}

	int main(){
		int num = 1;
		while (num <= 10){
			printf("%d\n", num);
			num++;
			
		}
		system("pause");
		return 0;
	}

	//ѭ�� 1--10 ��10������,������һ�����ı�����ֹͣѭ��
	int main(){
		int num = 1;
		while (num <= 10){
			printf("%d\n", num);
		if (num % 3 == 0){
			break;
			}
		num++;
		}
		system("pause");
		return 0;
	}

	//ѭ�� 1--10 ��10������,�������ı����Ͳ���ӡ
	int main(){
		int num = 1;
		while (num <= 10){
			if (num % 3 == 0){
				num++;
				continue;
			}
			else{
				printf("%d\n", num);
				//num++; ������Ҳ����
			}
			num++;
		}
		system("pause");
		return 0;
	}

	int main(){
		for (int num = 1; num <= 10; num++){

			if (num % 3 == 0){
				continue;
			}
			else{
				printf("%d\n", num);
			}
		}
		system("pause");
		return 0;
	}

	//�������Сд��ĸ�Ͳ����,��������
	int main(){
		char ch = 0;
		while ((ch = getchar()) != EOF){
			if (ch >='a'&&ch <='z'){
				continue;
			}
			else {
				putchar(ch);
			}
		
		}
		system("pause");
		return 0;

	}

	//���������
	//   num++   vs   ++num
	// 1  num++:  
	//   num++  �൱�� int tmp=num;     num=num+1;    return tmp;
	//2   ++num
	//++num    �൱�� num=num+1;  return num;

	//  ������   �� :  ѭ��ִ�ж��ٴ�   ��:   0��  
	int main(){
		int i = 0;
		int  k = 0;
		for (i = 0, k = 0; k == 0;i++,k++){
			k++;
			printf("hehe\n");
		}
		system("pause");
		return 0;
	}

	//С���  ����֮��    ִ��һ��
	int main(){
		int i = 0;
		int  k = 0;
		for (i = 0, k = 0; k == 0; i++, k++){
			k++;
			printf("hehe\n");
		}
		system("pause");
		return 0;
	}

	//��N�Ľ׳�
	int Factor(int n){
		int ret = 1;
		for (int i = 1; i <= n; ++i){
			ret = ret*i;
		}
		return ret;
	}
	int main(){
		printf("%d\n", Factor(5));
		system("pause");
		return 0;

//��  1!+2!+......+10!
		int Factor(int n){
			int ret = 1;
			for (int i = 1; i <= n; ++i){
				ret = ret*i;
			}
			return ret;
		}

		int main(){
			int sum = 0;
			for (int i = 1; i <= 10; ++i){
				sum = sum + Factor(i);
			}
			printf("%d\n", sum);
			system("pause");
			return 0;
		}

		int main(){
			char  str1[] = "welcome to bite!";
			char str2[] = "***************";
			int left = 0;
			int right = strlen(str2) - 1;//��ȡ���һ��Ԫ�ص��±�
			while (left <= right){
				printf("%s\n", str2);
				str2[left] = str1[left];
				str2[right] = str1[right];
				++left;
				--right;
				Sleep(100); // �����Ժ���ж�̬Ч��
				//system("cls");
				
			}
			system("pause");
			return 0;
		}

		


#endif
#if 0


		int main(){
			//char password[10] = { 0 };
			//scanf("%s", password);
			int i = 0;
			for (; i < 3; ++i){
				printf("����������:\n");
				char password[10] = { 0 };
				scanf("%s", password);
				if (strcmp(password, "20190504") == 0){
					break;
				}
			}
			if (i < 3){
				printf("��ϲ���½�ɹ�!\n");
			}
			else{
				printf("������������Ѿ�����3��,��¼ʧ��!\n");
			}
			system("pause");
			return 0;
		}
	//�����汾
		void menu(){
			printf("##############\n");
			printf("��������������\n");
			printf("##############\n");
           }

		int main(){
			menu();
			int i = 0;
			for (; i < 3; ++i){
				char  password[10] = { 0 };
				scanf("%s", password);
				if (strcmp(password, "20190504") == 0){
					printf("��¼�ɹ�!\n");
					break;
				}

			}
			if (i < 3){
				printf("��¼�ɹ�!\n");
			}
			else{
				printf("��������");
			}

			system("pause");
			return 0;
		}



		int main(){
			int arr[4] = { 9, 5, 2, 7 };
			int to_find = 10;
			int i = 0;
			for (; i <= 3; ++i){
				if (to_find == arr[i]){
					break;
					//printf("����!\n");
				}
			}
			if (  i <= 3){
				printf("����!\n");
			}
			else{
				printf("����!\n");
			}
			system("pause");
			return 0;
		}

		//���ֲ���(��������)
#include<stdlib.h>
#include<stdio.h>
		int main(){
			int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			int size = sizeof(arr) / sizeof(arr[0]) - 1;
			int left = 0;
			int right = size - 1;
			//[left,right]
			while (left <= right){
				int to_find = 3;
				int mid = (left + right) / 2;
				if (arr[mid] > to_find){
					right = mid - 1;
				}
				else if (arr[mid] < to_find){
					left = mid + 1;
				}
				else{
					//printf("�ҵ���!\n");
					break;
				}

			}
			if (left <= right){
				printf("�ҵ���!\n");
			}
			else{
				printf("û�ҵ�!\n");
			}
			system("pause");
			return 0
		//���ֲ���(�����汾)
#include<stdlib.h>
#include<stdio.h>
			, int to_fint BinaryReserch(int arr[], int to_find){
				int left = 0;
				int right = size - 1;
				while (left <= right){
					int mid = (left + right) / 2;
					if (arr[mid] > to_find){
						right = mid - 1;
					}
					else if (arr[mid] < to_find){
						left = mid + 1;
					}
					else{

						return mid;
					}
				}
				return -1;
			}
			int main(){
				int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
				int size = sizeof(arr) / sizeof(arr[0]);
				//printf("%d\n", size);

				int ret = BinaryReserch(arr, size, 9);
				printf("%d\n", ret);

				system("pause");
				return 0;
			}


		
		//��������Ϸ
			int Menu(){
				printf("*********************\n");
				printf("1 ��ʼ��Ϸ 2 ������Ϸ\n");
				printf("********************\n");
				printf("����������ѡ��!\n");
				int choice = 0;
				scanf("%d", &choice);
				return choice;//���뷵��
			}
			int Game(){
				//����� �Զ�����һ���������(1��100)
				int to_Guess = rand() % 100 + 1;
				//���û����������
				int i = 0;
				while (i<5){
					int num = 0;
					printf("������Ҫ�µ�����:");
					scanf("%d", &num);
					//���û��µ����ֺ����ɵ����ֽ��бȽ�,Ȼ�����ʵ���໥��С,���"����"  ����   "����"     
					if (num > to_Guess){
						printf("����!");
					}
					else if (num < to_Guess){
						printf("����!");
					}
					else{
						printf("��ϲ��¶���!");
						break;
					}
					++i;
				}
				if (i < 5){
					printf("��ϲ��¶���!\n");
				}
				else{
					printf("�Ҹ���������˿���û�а���ס��\n");
				}
				}
				
			int main(){
				//ʱ���
				srand(( unsigned int)time(0));
				while (1){
					int choice = Menu();
					if (choice == 1){
						Game();
					}
					else if (choice == 2){
						printf("goodbye!\n");
					}
					else{
						printf("������������!\n");
					}
				}
				system("pause");
				return 0;
			}
	
//��ӡ100��200֮�������(����1��������֮�ⲻ�ܱ�����������)
			int main(){
				int n;
				int i;
			
				for (n= 100; n < 201; n++){
					for (i= 2; i<n; i++){
						if (n%i == 0){
						break;
						}
						
					}
					if (i == n){
						printf("%d\n", n);
					}
					
					}
				
				system("pause");
				
//�������������ֵ
int Max(int x, int y){
	if (x > y){
		return x;
	}
	else{
	return y;
	}
	
}
	int main(){
					int a = 10;
					int b = 20;
					Max(a, b);
					printf("%d\n", Max(a, b));
					system("pause");
					return 0;
				}

	void swap(int x, int y){
		int tmp = x;
		x = y;
	    y = tmp;
	}
	int main(){
		int a = 100;
		int b = 123;
		//���´����ͬ��  swap(a,b)
		int x = a;//��x��ʼ��
		int y = b;//��y��ʼ��
		int tmp = x;
		x = y;
		y = tmp;


		//swap(a, b);
		printf("%d %d\n",a,b );
		system("pause");
		return 0;
	}

	void swap(int*x, int*y){
		int tmp = *x;//  �൱��  int tmp=a;
		 *x = *y;//�൱��  a=b;
		 *y = tmp;//�൱��  b=tmp;
	}
	int main(){
		int a = 10;
		int b = 20;
		swap(&a,&b);
		printf("%d %d\n", a, b);
		system("pause");
		return 0;
	}
	//Լ�� ����1 ��ʾ  ������   ���� 0 ��ʾ ��������
	int Issushu(int x){
		//���ǷǷ��������ʶ
		if (x ==1){
			return 0;
		}
		else if (x <= 0){
			return 0;
		}
	for (int i = 2; i < x; ++i){
			if (x%i == 0){
				return 0;
			}
		}
	return 1;
		
	}
	int main(){
			int ret = Issushu(11);
		printf("%d\n", ret);
		system("pause");
		return 0;

	}

	//Լ�� ����1 ��ʾ  ������        0 ��ʾ ��������
	int Isrunnian(int x)
	{
		//�����Ϊ��ͨ�������������
		if (x % 100 == 0){
			if (x % 400){
				return 1;
			}
			else {
				return 0;
			}
		}
		else{
			if (x % 4 == 0){
				return 1;
			}
			else{
				return 0;
			}

		}
	}
	int main(){
		int ret = Isrunnian(2020);
		printf("%d\n", ret);
		system("pause");
		return 0;
	}

	//дһ������  ÿ����һ��ʹ��num��ֵ+1
	void  func(int*x){
		*x += 1;
	}
	int main(){
		int a = 4;
		func(&a);
		printf("%d\n", a);
		system("pause");
		return 0;
	}

	void  func(x){
		x += 1;
	}
	int main(){
		int a = 4;
		func(a);
		printf("%d\n", a);
		system("pause");
		return 0;
	}

#include<stdio.h>
#include<stdlib.h>

	void swap(int*x, int*y) {
		int tmp = *x;
		*x = *y;
		*y = tmp;
	}
	typedef int(*Cmp)(int x, int y);
	void Bubblesort(int arr[], int size, Cmp cmp) {
		int bound = 0;
		for (; bound < size; ++bound){
			for (int cur = size - 1; cur > bound; --cur) {
				if (!cmp(arr[cur - 1], arr[cur])) {
					swap(&arr[cur - 1], &arr[cur]);
				}
			}
		}
	}
	int less(int x, int y) {
		if (x < y) {
			return 1;
		}
		return 0;
	}
	/*int greater(int x, int y) {
	if (x > y) {
	return 1;
	}
	return 0;
	}*/
	int main(){
		int arr[4] = { 9, 5, 2, 7 };
		Bubblesort(arr, 4, less/*greater*/);
		for (int i = 0; i < 4; ++i) {
			printf("%d\n", arr[i]);
		}
		system("pause");
		return 0;
	}
	//����
	int main(){
		int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
		//�����������ǰ����  const  �ؼ��־�ֻ�ܶ�������ж�����д
		//const  int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
		//  1   ���������"д��"����
		for (int i = 0; i < 10; ++i){
			arr[i] = 100 + i;
		}//  2    ���������"��ȡ"����
		for (int i = 0; i < 10; ++i){
			printf("%d\n", arr[i]);
			
		}
     //����Խ��,��ʱ���ʵ��ǷǷ��ڴ�,������ֵ�����ֵ;
		//printf("%d\n", arr[16]);//�ƶĶ�
		system("pause");
		return 0;
	
	//��ά����
	int main(){
		//  1,2  ���ű��ʽ  ��ʾ���Ƕ��ź����ֵ
		int arr[3][4] = { (1, 2), (3, 4), (5, 6) };
		system("pause");
		return 0;
	}

	//��ά����
	int main(){
		int arr[3][4] = { 0 };
		for (int row = 0; row < 3; ++row){
			for (int col = 0; col < 4; ++col){
				printf("%d ", arr[row][col]);
			}
			printf("\n");
		}
		system("pause");
		return 0;
	}

	//ð������(����汾)
	void  swap(int *x, int *y){
		int tmp = *x;
		*x = *y;
		*y = tmp;
	}
	void BubbleSort(int arr[], int size){
         //����������[0,bound)     δ��������[bound,size)
		int bound = 0;
		for (int bound = 0; bound < size; ++bound){
			for (int cur = size -1; cur >bound; --cur){
				if (arr[cur - 1]>arr[cur]){
					swap(&arr[cur - 1], &arr[cur]);
				}
			}
		}
	}
	int main(){
		int arr[4] = { 9,5,2,7 };
		int size = sizeof(arr) / sizeof(arr[0]) ;
		 BubbleSort(arr, size);
		 for (int i = 0; i < 4; ++i){
			 printf("%d\n", arr[i]);
		 }
		 system("pause");
		 return 0;
	
	int main(){
		//int ret = 1 / 2;//���Ϊ0
		//double ret = 1 / 2;//���Ϊ0.00000000
		//double ret = 1.0 / 2.0;//���Ϊ0.500000
		int ret = 1.0 / 2;// 1.0/2=>  1.0/2.0 =>0.5000=>  0
		printf("%d\n", ret);
		system("pause");
		return 0;
	}

// ������
	// 1  ����һ����,����һλ����2
	// 2 ����һ����.����һλ����2
	// �����  ������ ��Ϊ1  ���Ϊ1   ������Ϊ0;
	// �����  ��������Ϊ 0  ���Ϊ0  ���� ���Ϊ1
	// ������   ��ͬΪ0  �෴Ϊ1
	// ȡ������   0 =>1 ;1=> 0

	//������ʱ����  ������������

	int main(){
		int a = 10;
		int b = 20;
	    //a = a + b;
		//b = a - b;
		//a = a - b;
		a = a^b;
		b = a^b;
		a = a^b;

		printf("%d %d\n", a, b);
		system("pause");
		return 0;
	}

	int main(){
	
		int x = 10;
		int* p;
		p = &x;
		printf("%d\n", sizeof(p));
		printf("%p\n", p);
		printf("%d\n", *p);
		system("pause");
			return 0;
	}

	int  main(){
		int n = 10;
		int *p = &n;
		int n2 = 10;
		int *p2 = &n2;
		printf("%p\n", p);
		printf("%p\n", p2);
		if (p == p2){//ָ��Ƚϵ�ʱ��Ƚϵ��ǵ�ַ   ����ַ�Ƿ���ͬ
			printf("hehe\n");
		}
		else{
			printf("haha\n");
		}

		system("pause");
		return 0;
	
	void  func(int *p){
		printf("%d\n", *p);//���  1
			printf("%d\n", *(p + 1));//��� 2
	}
	int main(){
		int arr[4] = { 1, 2, 3, 4 };
		func(arr);
		system("pause");
		return 0;
	
	int main(){
		int arr[4] = { 9, 5, 2, 7 };
		printf("%p\n", arr);
		printf("%p\n", &arr[0]);
		system("pause");
		return 0;
	
	
	int main(){
		int arr[4] = { 9, 5, 2, 7 };
		int *p = arr;
		int size = sizeof(arr) / sizeof(arr[0]);
		for (int i = 0; i < size; ++i){

//	printf("%d\n", arr[i]);
			
	printf("%d\n", *(p + i));
		}
		system("pause");
		return 0;
	
	int main(){
		int arr[4] = { 9, 5, 2, 7 };
		printf("%p\n", arr);
		
	printf("%p\n",&arr[0]);
		printf("%p\n", &arr);
		system("pause");
		return 0;

	}


// ����ṹ������
		struct student {
			char name[20];
			int  id;
		};
		int main(){
			struct student s = { "wangkaixin", 10 };//����ṹ����� s ���������г�ʼ��;
 		//	s.id = 20;   �޸�ֵ;
			//strcpy(s.name, "lisi");  �޸�ֵ;
			printf("%d\n", s.id);
			printf("%s\n", s.name);
			system("pause");
			return 0;

		}
		//GBK  �������ֽڱ�ʾһ������;
		//UTF-8  �������ֽڱ�ʾ  һ������;

		//С��ϰ:  ����һ���ṹ������,��������г�ʼ��;
//#endif
		struct  student{
			int number;
			char name[1024];
			char sex[1024];
			char address[1024];
			int scores ;
		};
		int main(){
			struct student s = { 9,5,2,7, "������", "man", "����",100 };
			printf("NO=%d\n", s.number);
			printf("name=%s\n", s.name);
			printf("sex=%s\n", s.sex);
			printf("address=%s\n",s.address);
			printf("�ɼ�=%d\n", s.scores);
			system("pause");
			return 0;

		}


		int  menu(){
			printf("*********************************************\n");
			printf("��Ը������ô�����, 1��ʾԸ��  2��ʾ ��Ը��\n");
			printf("*********************************************\n");
			printf("����������ѡ��:");
			int choice = 0;
			scanf("%d", &choice);
			return choice;
          }
		int main1(){
			int choice = 0;
			choice = menu();
			if (choice == 1){
				printf("������������!");
			}
			else{
				printf("rubbsh!");
			}
			system("pause");
			return 0;
		}
#endif
		


			

		
	
		

	
		

	
