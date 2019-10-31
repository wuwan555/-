#define _CRT_SECURE_NO_WARNINGS 1
#include"stdio.h"
void Maopao(int *arr, int len)
{
	int i = 0;
	int flag;
    for(i = 0; i < len - 1; i++)//比较的趟数
	{
		int j = 0;
		flag = 0;
		for(j = 0; j < len - 1 - i; j++)//每趟比较的次数
		{
			
			if(arr[j]>arr[j + 1])
			{
				 int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
			}
		}
		if (!flag)
		{
			break;
		}
	}
}
void show(int *arr, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{

	int arr[10] = { 12, 15, 19, 28, 64, 58, 17, 5, 6, 47 };
	int len = (sizeof(arr) / sizeof(arr[0]));
	Maopao(arr, len);
	show(arr, len);
	return 0;


}