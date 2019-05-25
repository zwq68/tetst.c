#pragma  once


// 定义二叉树的结构:   孩字表示法

typedef  double BTDataType;
typedef  struct  BTNode{
	 struct   BTNode*p_left;
	 struct	  BTNode*p_right;
	 BTDataType _data;
}BTNode;


BTNode* CreateBinTree(BTDataType *array, int size, BTDataType invalid);


void PreOrder(BTNode*pRoot);
void InOrder(BTNode*pRoot);
void PostOrder(BTNode*pRoot);


int GetKLevelNodeSize(BTNode*pRoot,int k);
int GetBinTreeSize(BTNode*pRoot);
int GetLeafCount(BTNode*pRoot);
int GetBinTreeHight(BTNode*pRoot);

BTNode*BinaryTreeFind(BTNode*pRoot, BTDataType x);


void DestoryBinTree(BTNode**pRoot);
void testBinTree();