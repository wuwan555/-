#define _CRT_SECURE_NO_WARNINGS 1
#include"stdio.h"
struct ListNode
{
	int val;
	struct ListNode *next;
};
typedef struct ListNode list;
struct ListNode *findcircle(struct ListNode *head)//�ж��Ƿ�Ϊѭ������
{
	list *fast = head;
	list *slow = head;
	while (fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return 1;
		}
	}

}
struct ListNode findmid(struct ListNode *head)//�ҵ���λ��
	{
	list *fast = head;
	list *slow = head;
	while (fast&&slow)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast->next == NULL)
		{
			printf("%d",slow->val);
		}
	}
}