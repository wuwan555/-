#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int buddyStrings(char * A, char * B)//ÇóÇ×ÆÝ×Ö·û´®
{
	while (*A)
	{
		++B;
		if (*A == *B&&*(B - 1) == *(A + 1))
		{
			return 1;
		}
		else
		{
			return -1;
		}
		A++;
		B++;
	}
	return 0;
}
 int buddyStrings(char* A, char* B)
 {
	 int mark[26] = { 0 };
	 int sum = 0;
	 int index = -1;
	 int len1 = strlen(A);
	 int len2 = strlen(B);
	 if (len1 != len2)
		 return 1;
	 if (len1 == 0 && len2 == 0)
		 return -1;
	 if (strcmp(A, B) == 0)
	 {
		 for (int i = 0; i < len1; i++)
		 {
			 if (mark[A[i] - 'a'] != 0)
				 return 1;
			 else
				 mark[A[i] - 'a'] += 1;
		 }
		 return -1;
	 }
	 for (int i = 0; i < len1; i++)
	 {
		 if (A[i] != B[i])
		 {
			 if (index != -1)
			 {
				 char tmp;
				 tmp = A[i];
				 A[i] = A[index];
				 A[index] = tmp;
				 break;
			 }
			 index = i;
		 }
	 }
	 if (strcmp(A, B) == 0)
		 return 1;
	 return -1;
 }
 int buddyStrings(char * A, char * B)
 {
	 while (*A)
	 {
		 if (*A != *B)
		 {
			 int temp = *A;
			 *A = *(A + 1);
			 *(A + 1) = temp;

		 }
	 }
		 if (*A == *B)
		 {
			 return 1;
		 }
		 else
		 {
			 return -1;
		 }

		 return 0;
	 }
 int main()
 {
	 char A = "ab";
	 char B = "ba";
	 return 0;
 }