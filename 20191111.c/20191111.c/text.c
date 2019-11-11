#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//struct S//λ�δ洢
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//int main()
//{
//	//printf("%d", sizeof(struct S));
//	struct S s = { 0 };
//	s.a = 10; s.b = 12; s.c = 3; s.d = 4;
//	printf("%d,%d,%d,%d", s.a, s.b, s.c, s.d);
//	return 0;
//}
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array; // ָ��̬���ٵ�����
	size_t size; // ��Ч���ݸ���
	size_t capicity; // �����ռ�Ĵ�С
}SeqList;
// ������ɾ��Ľӿ�
void SeqListInit(SeqList* psl, size_t capacity)//��ʼ��
{
	assert(psl);
	psl->array = NULL;
	psl->size = 0;
	capacity = 0;
}
void SeqListDestory(SeqList* psl)//�ͷſռ�
{
	assert(psl);
	free(psl->array);
	psl->size = 0;
	psl->capicity = 0;
}

void CheckCapacity(SeqList* psl)//���ռ��Ƿ��㹻
{
	assert(psl);
	if (psl->size >= psl->capicity)
	{
		size_t newcapicity = psl->capicity == 0 ? 4 : psl->capicity *sizeof(SLDataType)* 2;//���ռ�Ϊ0ʱΪ4���ֽڣ��������ݶ�����
		psl->array=realloc(psl->array, newcapicity);
		psl->capicity = newcapicity;
	}

}
void SeqListPushBack(SeqList* psl, SLDataType x)//��˳��������һ��ֵx
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size++] == x;
	
}
void SeqListPopBack(SeqList* psl)//ɾ��˳�������һ����Чֵ
{
	asserr(psl&&psl->size > 0);//��֤��Ч��ֵ����0
	CheckCapacity(psl);
	psl->size--;

}
void SeqListPushFront(SeqList* psl, SLDataType x)//��˳ѵ��Ŀ�ʼ������һ����
{
	assert(psl);
	CheckCapacity(psl);
	int end = psl->size - 1;//��˳����������Ų��һ��λ��
	for (; end <= 0; --end)
	{
		psl->array[end + 1] = psl->array[end];
	}
	psl->array[end] = x;//�����鿪ʼֵ����x
	psl->size++;
}
void SeqListPopFront(SeqList* psl)//ɾ��˳���ĵ�һ��ֵ
{
	assert(psl);
	CheckCapacity(psl);
	for (size_t i = 0; i < psl->size; ++i)//������ǰŲ��һ��λ��
	{
		psl->array[i - 1] = psl->array[i];
	}
	psl->size--;
}

int SeqListFind(SeqList* psl, SLDataType x)//��˳����в���һ����
{
	sssert(psl);
	CheckCapacity(psl);
	int i;
	for ( i = 0; i < psl->size; i++);//�Ƚ�˳����ÿһ��ֵ�Ƿ����X
	{
		if (psl->array[i] == x)
		{
			return psl->array[i];
		}
	}
	return -1;//��ѯ�������-1
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)//��˳����posλ�ò���һ����
{
	assert(psl);
	CheckCapacity(psl);
	size_t end = psl->size + 1;
	while (end > pos)//��POSλ�ĺ��������������ƶ�
	{
		psl->array[end ] = psl->array[end-1];
		--end;
	}
	psl->array[pos] = x;//��POSλ��ֵx
	psl->size++;
}
void SeqListErase(SeqList* psl, size_t pos)//��POSλ����ǰ�ƶ�
{
	assert(psl&&pos < psl->size);
	CheckCapacity(psl);
	size_t i = pos + 1;
	while (i < psl->size)
	{
		psl->array[i - 1] = psl->array[i];
		++i;
	}
	psl->size--;
}
void SeqListRemove(SeqList* psl, SLDataType x)//��˳�����ǰ�ƶ�xλ
{
	int pos = SeqListFind(psl, x);
	if (pos>0)
	{
		SeqListErase(psl, pos);
	}
}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)//�޸�POSλ������ֵ
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[pos] = x;
}
void SeqListPrint(SeqList* psl)//��ӡ˳���
{
	for (int i = 0; i < psl->size; ++i)
	{
		printf("%d", psl->array[i]);
	}
	printf("\n");
}
