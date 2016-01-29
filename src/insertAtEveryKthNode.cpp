/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {

	if (!head || K <= 0){ return NULL; }
	else
	{
		struct node *p, *q;
		int  nodes = 0, iterate, i = 0;
		for (p = head; p != NULL; q = p, p = p->next, nodes++); p = head;
		if (K > nodes){ return head; }
		else{


			iterate = nodes / K;
			while (iterate--)
			{

				while (i<K - 1)
				{
					p = p->next;
					i++;
				}
				struct node*newnode = (struct node*)malloc(sizeof(struct node));
				newnode->next = p->next;
				p->next = newnode;
				newnode->num = K;
				p = newnode->next;
				i = 0;

			}
		}

		return head;
	}



}
