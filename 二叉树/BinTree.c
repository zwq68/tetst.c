#include"bintree.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>


// �½��ڵ�
BTNode* BuyBinTreeNode(BTDataType data){
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (pNewNode == NULL){
		assert(0);
		return;
	}
	pNewNode->_data = data;
	pNewNode->p_left = NULL;
	pNewNode->p_right = NULL;
	return pNewNode;
}

//����������
//����:   һ������(Ԫ��  ��С)
BTNode* _CreateBinTree(BTDataType *array, int size,int* index,BTDataType invalid){
	BTNode*	pRoot = NULL;
	if (*index < size && invalid!=array[*index]){
		//���ڵ�
		
		pRoot = BuyBinTreeNode(array[*index]);
		(*index)++;
		//����������
		pRoot->p_left = _CreateBinTree(array, size, index,invalid);
		//����������
		(*index)++;
		pRoot->p_right = _CreateBinTree(array, size, index,invalid);
	}
  
	return pRoot;
}
BTNode* CreateBinTree(BTDataType *array, int size, BTDataType invalid){
	int index = 0;
	return	  _CreateBinTree(array, size, &index, invalid);
}



void PreOrder(BTNode*pRoot){
	if (pRoot){
		printf("%c ", pRoot->_data);
		PreOrder(pRoot->p_left);
		PreOrder(pRoot->p_right);
	}
}
void InOrder(BTNode*pRoot){
	if (pRoot){
		InOrder(pRoot->p_left);
		printf("%c ", pRoot->_data);
		InOrder(pRoot->p_right);
	}
}
// ��ö����������нڵ����
int GetBinTreeSize(BTNode*pRoot){
	//���1  ������Ϊ��
	if (pRoot==NULL){
		return 0;
	}
	// ���2   ����������
	return GetBinTreeSize(pRoot->p_left) + GetBinTreeSize(pRoot->p_right) + 1;
}
// ��ö�������Ҷ�ӽڵ����
int GetLeafCount(BTNode*pRoot){
	// ���1 : �ö�����Ϊ����
	if (pRoot == NULL){
		return 0;
	}
	// ���2  �ö�����Ϊ���˾��(ֻ��һ�����ڵ�)
	if (pRoot->p_left == NULL&&pRoot->p_right == NULL){
		return 1;
	}
	// �����  �ö���������  (�������);
	return  GetLeafCount(pRoot->p_left) + GetLeafCount(pRoot->p_right);
}
int GetKLevelNodeSize(BTNode*pRoot,int k){
	//��� 1 �˶�����Ϊ��  ���� ���� K ֵ����
	if (pRoot == NULL || k <=0){
		return 0;
	}
	// ���  2   ���һ��
	if (k == 1){
		return 1;
	}
	return GetKLevelNodeSize(pRoot->p_left, k - 1)+
		   GetKLevelNodeSize(pRoot->p_right, k - 1);
}



void PostOrder(BTNode*pRoot){
	if (pRoot){
		PostOrder(pRoot->p_left);
		PostOrder(pRoot->p_right);
		printf("%c ", pRoot->_data);
	}
}

void DestoryBinTree(BTNode** pRoot){
	assert(pRoot);
	if (*pRoot){
		DestoryBinTree(&(*pRoot)->p_left);
		DestoryBinTree(&(*pRoot)->p_right);
		free(*pRoot);
		*pRoot = NULL;
	}
}
// �ڶ���������ֵΪdata �Ľڵ�
//  ����:  һ��������   ��һ��ҪѰ�ҵ�ֵ
BTNode*BinaryTreeFind(BTNode*pRoot, BTDataType x){
	// ���1 �ö�����Ϊ��;
	if (NULL == pRoot){
		return  NULL;
	}
	// ���2  �ڸ��ڵ�λ���ҵ���
	if (x == pRoot->_data){
		return pRoot;
	}
	//���  3:  ���ڵ�û���ҵ�,��������������
	BTNode*pRet = NULL;
	if (pRet == BinaryTreeFind(pRoot->p_left, x)){
		return pRet;
	}
	//  ���4   ������û���ҵ�,��������������(�ҵ��˾ͷ���ȥ,û���ҵ��ͷ��ؿ�)
	return BinaryTreeFind(pRoot->p_right, x);
}

void testBinTree(){
	char *str = "ABD$$$CE$$F";

	BTNode* pRoot = CreateBinTree(str, strlen(str), '$');


	printf("ǰ��������:");
	PreOrder(pRoot);
	printf("\n");


	printf("����������:");
	InOrder(pRoot);
	printf("\n");

	printf("�����������:");
	PostOrder(pRoot);
	printf("\n");

	printf("k=3 :%d\n",GetKLevelNodeSize(pRoot,3));

	if (BinaryTreeFind(pRoot, 'G')){
		printf(" is  in BinTree!!!\n");
	}
	else{
		printf(" is  not in BinTree!!!\n");
	}
	DestoryBinTree(&pRoot);
}



























