#pragma once 

typedef int SDataType;

// ��������ڵ�
typedef struct slistnode{
	SDataType _data;
	struct slistnode *PNext;
}Node,* PNode;


//��������ṹ
typedef struct slist{
	PNode _Phead;// ��������ֻ��Ҫ�洢ͷ���
}slist;// ����������ȡ����

//  ��ʼ������
void slistinit(slist *s);


// �����β��
void slistpushback(slist *s,  SDataType data);
// �����βɾ
void slistpopback(slist*s);

// �����ͷ��
void slistpushfront(slist *s, SDataType data);
//  �����ͷɾ
void slistpopfront(slist *s);


// ����λ�ò�������
void slistinsert(PNode  pos, SDataType data);
// ���� λ�� ɾ��
void slisterase(slist *s,PNode pos);


// ɾ�������һ��ֵΪdata��Ԫ�� 
void slistremovoe(slist *s, SDataType data);
// ɾ����������ֵΪdata��Ԫ��
void slistremoveall(slist *s, SDataType data);

// �������
int slistclear(slist *s);
//  ��ǰ�����еĽڵ����
int slistsize(slist *s);



