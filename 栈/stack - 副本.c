#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


void CheckCapacity(Stack*ps){
	assert(ps);
	if (ps->_size == ps->_capacity)  {
		// 1 开辟新空间
		int newcapacity = ps->_capacity * 2;
		SDataType*pTemp = (SDataType*)(sizeof(SDataType)*newcapacity);
		if (NULL == pTemp){
			assert(0);
			return;
		}
		//  2 拷贝元素
		for (int i = 0; i < ps->_size; ++i){
			pTemp[i] = ps->_array[i];
		}
		//3 释放旧空间
		free(ps->_array);
		ps->_array = pTemp;

		//4更新参数
		ps->_capacity = newcapacity;

	}
}


void  StackInit(Stack*ps){
	assert(ps);
	ps->_array = (SDataType*)malloc(sizeof(SDataType)* 3);
	if (NULL == ps->_array){
		assert(0);
		return ;
	}
	ps->_capacity = 3;
	ps->_size = 0;
}
void  StackPush(Stack*ps, SDataType data){
	//检测是否有足够空间
	CheckCapacity(ps);



	ps->_array[ps->_size] = data;
	ps->_size++;
}
void StackPop(Stack*ps){
	assert(ps);
	if (StackEmpty(ps)){
		return;
	}
	ps->_size --;
}
SDataType StackTop(Stack*ps){
	assert(ps);
	return ps->_array[ps->_size - 1];
}
int  StackSize(Stack*ps){
	assert(ps);
	return ps->_size;
}
int  StackEmpty(Stack*ps){
	assert(ps);
	return 0 == ps->_size;
}
void StackDestory(Stack*ps){
	assert(ps);
	if (ps->_array){
		free(ps->_array);
		ps->_capacity = 0;
		ps->_size = 0;
	}
}
void TestStack(){
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	printf("size=%d\n", StackSize(&s));
	printf("Top=%d\n", StackTop(&s));

	StackPush(&s, 4);
	StackPush(&s, 5);
	printf("size=%d\n", StackSize(&s));
	printf("Top=%d\n", StackTop(&s));


	StackPop(&s);
	StackPop(&s);
	printf("size=%d\n", StackSize(&s));
	printf("Top=%d\n", StackTop(&s));

	StackDestory(&s);
}