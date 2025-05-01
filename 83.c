#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct ListNode
{
	int 			val;
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

struct ListNode*	deleteDuplicates( struct ListNode* head )
{
	struct ListNode	*result = head;

	while (head && head->next)
	{
		if (head->val == head->next->val)
		{
			struct ListNode	*temp = head->next;
			head->next = head->next->next;
			free(temp);
		}
		else
			head = head->next;
	}
	return result;
}

int	main( void )
{
	struct ListNode	*list = malloc(sizeof(struct ListNode));
	list->val = 1;
	list->next = malloc(sizeof(struct ListNode));
	list->next->val = 1;
	list->next->next = malloc(sizeof(struct ListNode));
	list->next->next->val = 2;
	list->next->next->next = NULL;

	printf("=================== RESULT ===================\n");
	struct ListNode	*result = deleteDuplicates(list);
	struct ListNode	*temp = result;
	while (temp)
	{
		printf("[ %d ] ", temp->val);
		temp = temp->next;
	}
	printf("\n");
	delete(&result);
	return (0);
}
