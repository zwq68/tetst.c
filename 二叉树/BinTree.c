#include"bintree.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>


// 新建节点
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

//创建二叉树
//输入:   一个数组(元素  大小)
BTNode* _CreateBinTree(BTDataType *array, int size,int* index,BTDataType invalid){
	BTNode*	pRoot = NULL;
	if (*index < size && invalid!=array[*index]){
		//根节点
		
		pRoot = BuyBinTreeNode(array[*index]);
		(*index)++;
		//根的左子树
		pRoot->p_left = _CreateBinTree(array, size, index,invalid);
		//根的右子树
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
// 求该二叉树的所有节点个数
int GetBinTreeSize(BTNode*pRoot){
	//情况1  二叉树为空
	if (pRoot==NULL){
		return 0;
	}
	// 情况2   二叉树正常
	return GetBinTreeSize(pRoot->p_left) + GetBinTreeSize(pRoot->p_right) + 1;
}
// 求该二叉树的叶子节点个数
int GetLeafCount(BTNode*pRoot){
	// 情况1 : 该二叉树为空树
	if (pRoot == NULL){
		return 0;
	}
	// 情况2  该二叉树为光杆司令(只有一个根节点)
	if (pRoot->p_left == NULL&&pRoot->p_right == NULL){
		return 1;
	}
	// 情况三  该二叉树正常  (后继有人);
	return  GetLeafCount(pRoot->p_left) + GetLeafCount(pRoot->p_right);
}
int GetKLevelNodeSize(BTNode*pRoot,int k){
	//情况 1 此二叉树为空  或者 输入 K 值有误
	if (pRoot == NULL || k <=0){
		return 0;
	}
	// 情况  2   求第一层
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
// 在二叉树中找值为data 的节点
//  输入:  一个二叉树   和一个要寻找的值
BTNode*BinaryTreeFind(BTNode*pRoot, BTDataType x){
	// 情况1 该二叉树为空;
	if (NULL == pRoot){
		return  NULL;
	}
	// 情况2  在根节点位置找到了
	if (x == pRoot->_data){
		return pRoot;
	}
	//情况  3:  根节点没有找到,继续在左子树找
	BTNode*pRet = NULL;
	if (pRet == BinaryTreeFind(pRoot->p_left, x)){
		return pRet;
	}
	//  情况4   左子树没有找到,继续在右子树找(找到了就返回去,没有找到就返回空)
	return BinaryTreeFind(pRoot->p_right, x);
}

void testBinTree(){
	char *str = "ABD$$$CE$$F";

	BTNode* pRoot = CreateBinTree(str, strlen(str), '$');


	printf("前序遍历结果:");
	PreOrder(pRoot);
	printf("\n");


	printf("中序遍历结果:");
	InOrder(pRoot);
	printf("\n");

	printf("后续遍历结果:");
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



























