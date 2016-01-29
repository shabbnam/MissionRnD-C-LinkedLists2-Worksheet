/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (!head){ return -1; }
	else
	{
		struct node *fast_pointer = head, *slow_pointer = head;
		while (fast_pointer->next && fast_pointer->next->next)
		{
			fast_pointer = fast_pointer->next->next;
			slow_pointer = slow_pointer->next;
		}

		return fast_pointer->next == NULL ? (slow_pointer->num) : ((slow_pointer->num + slow_pointer->next->num) / 2);
	}
}