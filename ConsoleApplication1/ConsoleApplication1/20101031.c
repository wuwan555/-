#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
int ret = 0; int k = 0; int n = 3;
int a[3] = { 1, 2, 3 };
for(k = 0; k<n - 1; k++)
{
	if (a[k]>a[k + 1])
	{
		int t = a[k];
		a[k] = a[k + 1];
		a[k + 1] = a[k];
	}
}
ret = a[n - 1] * a[n - 2] * a[n - 3];
printf("%d", ret);
}
