#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//struct S//位段存储
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
	SLDataType* array; // 指向动态开辟的数组
	size_t size; // 有效数据个数
	size_t capicity; // 容量空间的大小
}SeqList;
// 基本增删查改接口
void SeqListInit(SeqList* psl, size_t capacity)//初始化
{
	assert(psl);
	psl->array = NULL;
	psl->size = 0;
	capacity = 0;
}
void SeqListDestory(SeqList* psl)//释放空间
{
	assert(psl);
	free(psl->array);
	psl->size = 0;
	psl->capicity = 0;
}

void CheckCapacity(SeqList* psl)//检查空间是否足够
{
	assert(psl);
	if (psl->size >= psl->capicity)
	{
		size_t newcapicity = psl->capicity == 0 ? 4 : psl->capicity *sizeof(SLDataType)* 2;//当空间为0时为4个字节，否则扩容二倍。
		psl->array=realloc(psl->array, newcapicity);
		psl->capicity = newcapicity;
	}

}
void SeqListPushBack(SeqList* psl, SLDataType x)//在顺序后面添加一个值x
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size++] == x;
	
}
void SeqListPopBack(SeqList* psl)//删除顺序表的最后一个有效值
{
	asserr(psl&&psl->size > 0);//保证有效数值大于0
	CheckCapacity(psl);
	psl->size--;

}
void SeqListPushFront(SeqList* psl, SLDataType x)//在顺训表的开始处插入一个数
{
	assert(psl);
	CheckCapacity(psl);
	int end = psl->size - 1;//把顺序表整体向后挪动一个位置
	for (; end <= 0; --end)
	{
		psl->array[end + 1] = psl->array[end];
	}
	psl->array[end] = x;//把数组开始值赋给x
	psl->size++;
}
void SeqListPopFront(SeqList* psl)//删除顺序表的第一个值
{
	assert(psl);
	CheckCapacity(psl);
	for (size_t i = 0; i < psl->size; ++i)//整体向前挪动一个位置
	{
		psl->array[i - 1] = psl->array[i];
	}
	psl->size--;
}

int SeqListFind(SeqList* psl, SLDataType x)//在顺序表中查找一个数
{
	sssert(psl);
	CheckCapacity(psl);
	int i;
	for ( i = 0; i < psl->size; i++);//比较顺序表的每一个值是否等于X
	{
		if (psl->array[i] == x)
		{
			return psl->array[i];
		}
	}
	return -1;//查询不到输出-1
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)//在顺序表的pos位置插入一个数
{
	assert(psl);
	CheckCapacity(psl);
	size_t end = psl->size + 1;
	while (end > pos)//在POS位的后面的数整体向后移动
	{
		psl->array[end ] = psl->array[end-1];
		--end;
	}
	psl->array[pos] = x;//给POS位赋值x
	psl->size++;
}
void SeqListErase(SeqList* psl, size_t pos)//在POS位整体前移动
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
void SeqListRemove(SeqList* psl, SLDataType x)//把顺序表向前移动x位
{
	int pos = SeqListFind(psl, x);
	if (pos>0)
	{
		SeqListErase(psl, pos);
	}
}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)//修改POS位的数的值
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[pos] = x;
}
void SeqListPrint(SeqList* psl)//打印顺序表
{
	for (int i = 0; i < psl->size; ++i)
	{
		printf("%d", psl->array[i]);
	}
	printf("\n");
}
