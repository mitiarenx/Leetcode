#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct ListNode
{
	int				val;
	struct ListNode	*next;
};

static void	delete( struct ListNode **head )
{
	while ((*head))
	{
		struct ListNode	*temp = *head;
		(*head) = (*head) ->next;
		free(temp);
	}
}

static void	append( struct ListNode **head, int val )
{
	struct ListNode	*new, *temp;

	new = malloc(sizeof(struct ListNode));
	new->val = val;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

struct ListNode	*mergeTwoLists( struct ListNode *list1, struct ListNode *list2 )
{
	struct ListNode	*result = NULL;

	while (list1 || list2)
	{
		if ((list1 && list2 && list1->val <= list2->val) ||
			(list2 == NULL && list1))
		{
			append(&result, list1->val);
			list1 = list1->next;
		}
		else if ((list1 && list2 && list2->val < list1->val) ||
			(list1 == NULL && list2))
		{
			append(&result, list2->val);
			list2 = list2->next;
		}
	}
	return result;
}

int	main(void)
{
	struct ListNode	*l1 = malloc(sizeof(struct ListNode));
	l1->val = 1;
	l1->next = malloc(sizeof(struct ListNode));
	l1->next->val = 2;
	l1->next->next = malloc(sizeof(struct ListNode));
	l1->next->next->val = 4;
	l1->next->next->next = NULL;

	struct ListNode	*l2 = malloc(sizeof(struct ListNode));
	l2->val = 1;
	l2->next = malloc(sizeof(struct ListNode));
	l2->next->val = 3;
	l2->next->next = NULL;

	printf("=================== RESULT ===================\n");
	struct ListNode	*result = mergeTwoLists(l1, l2);
	struct ListNode	*temp = result;
	while (temp)
	{
		printf("%d ", temp->val);
		temp = temp->next;
	}
	printf("\n");

	delete(&l1);
	delete(&l2);
	delete(&result);
	return 0;
}
