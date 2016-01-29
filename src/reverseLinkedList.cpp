/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {

	if (!head){ return NULL; }
	else if (head->next == NULL){ return head; }
	else
	{
		struct node* previous_node = NULL, *current_node = head, *nextnode;
		while (current_node)
		{
			nextnode = current_node->next;
			current_node->next = previous_node;
			previous_node = current_node;
			current_node = nextnode;


		}
		head = previous_node;
	}

	return head;
}
