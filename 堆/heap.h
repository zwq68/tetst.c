#pragma 

typedef int HPDataType;

typedef struct Heap{
	HPDataType *_array;//指向一段连续的空间
	int _capacity;
	int  _size;
} Heap;

//创建堆
void InitHeap(Heap*hp,HPDataType*array, int size);

void InsertHeap(Heap*hp, HPDataType data);
void EraseHeap(Heap*hp);
int HeapSize(Heap*hp);
int HeapEmpty(Heap*hp);
HPDataType HeapTop(Heap*hp);
void DestoryHeap(Heap*hp);
void TestHeap();
void HeapSort(int *array, int size);
