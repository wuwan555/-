#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SLTDataType;
typedef struct SListNode node;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;
SListNode* BuySListNode(SLTDataType x)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void SListPrint(SListNode* plist)
{
	node*cur = plist;
	while (cur->next != NULL);
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}
void SListPushBack(SListNode** pplist, SLTDataType x)//�������β��
{
	    assert(pplist);
		node*cur;
		if (*pplist == NULL)//����Ǵ�ͷ�ڵ�Ŀյ�����ֱ�Ӳ���
		{
			*pplist = BuySListNode(x);
			(*pplist)->next = NULL;
		}
		else
		{
			cur = *pplist;
			while (cur->next != NULL)
			{
				cur = cur->next;
			}
			cur->next = BuySListNode(x);//��cur�ߵ�β�ڵ�ʱ������һ���½ڵ㡣
		}
	}
void SListPushFront(SListNode** pplist, SLTDataType x)//�������ͷ��
{
	assert(pplist);
	if (*pplist == NULL)//����Ǵ�ͷ�ڵ�Ŀյ�����ֱ�Ӳ���
	{
		*pplist = BuySListNode(x);
		(*pplist)->next = NULL;
	}
	else
	{
		BuySListNode(x)->next =*pplist;
	}
}
void SListPopBack(SListNode** pplist)//βɾ
{
	assert(pplist);
	node*cur = *pplist;
	node*pre = NULL;
	if (cur->next == NULL)
	{
		cur = NULL;
		free(cur);
	}
	else
	{

		while (cur->next != NULL)
		{
			pre = cur;
			cur = cur->next;
		}
		pre->next = NULL;
		free(cur);
	}
}
void SListPopFront(SListNode** pplist)//ͷɾ
{
	assert(pplist);
	node*cur = *pplist;
	cur = NULL;
	free(cur);
}
SListNode* SListFind(SListNode* plist, SLTDataType x)//����
{
	assert(plist);
	node*cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void SListInsertAfter(SListNode* pos, SLTDataType x)//��POSλ����x
{
	assert(pos);
	node*after = pos->next;
	node*cur = pos;
	cur->next = BuySListNode(x);
	cur->next->next = after;
}
void SListDestory(SListNode*plist)//��������
{
	assert(plist);
	node*cur = plist;
	node*next = plist;
	while (next)
	{
		cur = next;
		next = next->next;
		free(cur);
		cur = NULL;
	}
	plist = NULL;
}
