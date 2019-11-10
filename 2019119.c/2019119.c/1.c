#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
void Func1(int N)
{
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			++count;
		}
	}
	for (int k = 0; k < 2 * N; ++k)
	{
		++count;
	}
	int M = 10;
	while (M--)
	{
		++count;
	}
	printf("%d\n", count);
}
void Swap(int*a, int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void BubbleSort(int* a, int n)
{
	assert(a);
	for (size_t end = n; end > 0; --end)
	{
		int exchange = 0;
		for (size_t i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
}
int game(int* guess, int guessSize, int* answer, int answerSize)
{
	int count = 0, i = 3;
	while (i--)
	{
		if (*guess == *answer)
		{

			count++;
		}

		*guess++;
		*answer++;
	}
	return 0;
}
//int main()
//{
//	int guess[3] = { 1, 2, 3 };
//	int answer[3] = { 3, 2, 1 };
//game(guess,3,answer,3);
//return 0;
//}

//int main()
//{
//	int i, j, len = 0, k, n;
//	char a[50][50] = { 0 };
//
//	for (i = 0; i<50; i++)
//	{
//		if (scanf("%s", a[i]) == EOF)
//			break;
//		len++;
//	}
//	for (i = 0; i<(len - 1); i++)
//	{
//		for (j = i + 1; j<len; j++)
//		while ((!strcmp(a[i], a[j])) && (j<len))       
//		{
//			for (k = 0; k<strlen(a[j]);
//                    k++;
//				a[j][k] = '\0';
//			for (n = j; n<len - 1; n++)
//				strcpy(a[n], a[n + 1]);
//			len--;
//		}
//	}
//	printf("%d\n", len);
//
//	return 0;
//}
int main()
{
	char a[50][50] = {{ "BUTTER FLOUR" },
	{"HONEY FLOUR EGG"} };
	int i, j, count = 0;
	for (i = 0; i<50; i++)
	for (j = 0; j<50; j++)
	{
		if (*(*(a + i) + j) == ' ')
		{
			count++;
		}
	}
	count++;
	printf("%d", count);
	return 0;
}