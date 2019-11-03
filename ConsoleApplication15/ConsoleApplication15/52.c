#define _CRT_SECURE_NO_WARNINGS 1
#include"stdio.h"
#define N 3
#if 0
void shuzu(int arr[N][N])
{
	int i = 0; int j = 0; int tmp = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if ((arr[i][j])>(arr[i][j + 1]))
			{
				tmp = arr[i][j];
				arr[i][j] = arr[i][j + 1];
				arr[i][j + 1] = tmp;

			}
		}
	}
	for (j = 0; j < N; j++)
	{
		for (i = 0; i < N; i++)
		{
			if ((arr[i][j])>(arr[i + 1][j]))
			{
				tmp = arr[i][j];
				arr[i][j] = arr[i + 1][j];
				arr[i + 1][j] = tmp;
			}
		}
	}
}
void chazhao(int k, int arr[N][N])
{
	int i; int j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (k == arr[i][j])
			{
				printf("%d在数组arr中", k);
			}
		}
	}
}
void show(int arr[N][N])
{
	int i; int j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d", arr[i][j]);
		}
	}
}
int main()
{
	int arr[3][3] = { 1, 5, 7, 6, 8, 2, 3, 4, 9 };
	shuzu(arr);
	chazhao(5, arr);
	show(arr);
}
#endif
char * my_strcpy(char* dst, const char*src)
{
	assert(dst);
	assert(src);
	char* ret = dst;
	while (*dst++ = *src++)
	{
		return ret;
	}
}
int main()
{
	char* p1 = "hello";
	char p2[10];
	my_strcpy(p2, p1);
	printf("%s", p2);
}
