/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (!head1&&!head2){ return NULL; }
	else if (!head1&&head2){ return head2; }
	else if (!head2&& head1){ return head1; }
	else
	{
		struct node *temp, *head;
		if (head1->num< head2->num){

			temp = head1;
			head1 = head1->next;
		}
		else{
			temp = head2;
			head2 = head2->next;
		}

		head = temp;
		while (head1&&head2){
			if (head1->num< head2->num){
				temp->next = head1;
				temp = head1;              //update temp
				head1 = head1->next;       //move head1 to next node
			}
			else{
				temp->next = head2;
				temp = head2;         //update temp
				head2 = head2->next; //move  head2 to next node
			}
		}
		if (!head1){
			temp->next = head2; //attach leftover nodes of head2 if any
		}
		else if (!head2){
			temp->next = head1;  //attach leftover nodes of head1 if any
		}
		return head;
	}

}
