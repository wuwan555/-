#define _CRT_SECURE_NO_WARNINGS 1
#include"stdio.h"
#if 0
void isPowerOfFour(int num)//�ж�һ�����Ƿ�Ϊ4���ݴη�
{
	int i = 0;
	int began = 1;
	while (i<32)
	{
		if (num & 1)
		{
			printf("false\n");
		}
		began = began << 1;
		if (num == began)
		{
			printf("true\n");
		}
		i++;

	}
}
int main()
{
	int num = 16;
	isPowerOfFour(num);
	return 0;
}
#endif
//struct stu
//{
//	int num;
//	char*name;
//	char sex;
//	float score;
//
//}stu[5] = {
//	{ 101, "��Ʒ", 'M', 45 },
//	{ 102, "��ƽ", 'M', 65 },
//	{ 103, "�η�", 'F', 82 },
//	{ 104, "����", 'F', 68 },
//	{ 105, "����", 'F', 74 }
//};
//int main()
//{
//	int i, c = 0;
//	float ave, s = 0;
//	for (i = 0; i < 5; i++)
//	{
//		s += stu[i].score; //��������ͬѧ���ܷ֡�
//		if (stu[i].score < 60)//�����������
//			c += 1;
//
//	}printf("s=%f\n", s);
//	ave = s / 5;//ƽ����
//	printf("average=%f\n count=%d\n", ave, c);
//	return 0;
//}
//struct stu
//{
//	int num;
//	char*name;
//	char sex;
//	float score;
//}stu1 = {101,"����",'M',78.2},*pstu;
//int main()
//{
//	pstu = &stu1;
//	printf("Number=%d\n Name=%s\n", stu1.num, stu1.name);
//	printf("Sex=%c\n Score=%f\n", stu1.sex, stu1.score);
//	printf("Number=%d\n Name=%s\n", (*pstu).num, (*pstu).name);
//	printf("Sex=%c\n Score=%f\n", (*pstu).sex, (*pstu).score);
//	printf("Number=%d\n Nume=%s\n", pstu->num, pstu->name);
//	printf("Sex=%c\n Score=%f\n", pstu->sex, pstu->score);
//	return 0;
//}
struct S1
{
	char c1;
	int i;
	char c2;
};
;
struct S2
{
	char c1;
	char c2;
	int i;
};
struct S3
{
	double d;
	char c;
	int i;
};

struct S4
{
	char c1;
	struct S3 s3;
	double d;
};
int main()
{
	printf("%d\n", sizeof(struct S1));
	printf("%d\n", sizeof(struct S2)); 
	printf("%d\n", sizeof(struct S3));
	printf("%d\n", sizeof(struct S4));
	return 0;
}

