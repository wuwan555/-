#define _CRT_SECURE_NO_WARNINGS 1
#include"stdio.h"
//#define M (y*y+3*y)
//void main()
//{
//	int s, y;
//	printf("intput a number");
//	scanf("%d", &y);
//	s = 3 * M + 4 * M + 5 * M;
//	printf("s=%d\n", s);
//}
//#include<math.h>
//#define S(a,b,c)(a+b+c)/2
//#define Srt(a,b,c)S(a,b,c)*(S(a,b,c)-a)*(S(a,b,c)-b)*(S(a,b,c)-c)
//#define Area(a,b,c) sqrt(Srt(a,b,c))
//void main()
//{
//	int x = 44, y = 67, z = 30;
//	float area;
//	area = Area(x, y, z);
//	printf("area=%.2f\n", area);
//
//}
#define MAX(a, b) ( (a) > (b) ? (a) : (b) ) 
int main()
{
	int x = 5;
	int y = 8;
	int z = MAX(x++, y++);
	printf("x=%d y=%d z=%d\n", x, y, z);

}
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i<10; i++)
//	{
//		arr[i] = i;
//#ifdef __DEBUG__ 
//		printf("%d\n", arr[i]);
//#endif
//	}