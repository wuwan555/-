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
void SListPushBack(SListNode** pplist, SLTDataType x)//单链表的尾插
{
	    assert(pplist);
		node*cur;
		if (*pplist == NULL)//如果是带头节点的空单链表，直接插入
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
			cur->next = BuySListNode(x);//当cur走到尾节点时，创建一个新节点。
		}
	}
void SListPushFront(SListNode** pplist, SLTDataType x)//单链表的头插
{
	assert(pplist);
	if (*pplist == NULL)//如果是带头节点的空单链表，直接插入
	{
		*pplist = BuySListNode(x);
		(*pplist)->next = NULL;
	}
	else
	{
		BuySListNode(x)->next =*pplist;
	}
}
void SListPopBack(SListNode** pplist)//尾删
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
void SListPopFront(SListNode** pplist)//头删
{
	assert(pplist);
	node*cur = *pplist;
	cur = NULL;
	free(cur);
}
SListNode* SListFind(SListNode* plist, SLTDataType x)//查找
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
void SListInsertAfter(SListNode* pos, SLTDataType x)//在POS位插入x
{
	assert(pos);
	node*after = pos->next;
	node*cur = pos;
	cur->next = BuySListNode(x);
	cur->next->next = after;
}
void SListDestory(SListNode*plist)//销毁数组
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
