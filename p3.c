//////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
2016/17 S1
Author and Lab Group: Chee Jun Yuan Glenn FSP7
Program name: FSP7_Chee Jun Yuan Glenn
Date: 09 November 2016
Purpose: Implementing the required functions for Assignment 1 (Question 3)*/

//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode
{
	int item;
	struct _listnode *next;
} ListNode;	// You should not change the definition of ListNode

typedef struct _linkedlist
{
	int size;
	ListNode *head;
} LinkedList;	// You should not change the definition of LinkedList


typedef struct _queue
{
	LinkedList ll;
} Queue;  // You should not change the definition of Queue

		  ///////////////////////// function prototypes ////////////////////////////////////

		  // This is for question 3. You should not change the prototypes of these functions
void createQueueFromLinkedList(LinkedList *ll, Queue *q);
void removeOddValues(Queue *q);


void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int isEmptyQueue(Queue *q);
void removeAllItemsFromQueue(Queue *q);


// You may use the following functions or you may write your own
void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

//////////////////////////// main() //////////////////////////////////////////////

int main()
{
	int c, i;
	LinkedList ll;
	Queue q;

	c = 1;

	// Initialize the linked list as an empty linked list
	ll.head = NULL;
	ll.size = 0;

	// Initialize the Queue as an empty queue
	q.ll.head = NULL;
	q.ll.size = 0;


	printf("1: Insert an integer into the linked list:\n");
	printf("2: Create the queue from the linked list:\n");
	printf("3: Remove odd numbers from the queue:\n");
	printf("0: Quit:\n");


	while (c != 0)
	{
		printf("Please input your choice(1/2/3/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want insert into the List: ");
			scanf("%d", &i);
			insertNode(&ll, ll.size, i);
			printf("The resulting linked list is: ");
			printList(&ll);
			break;
		case 2:
			createQueueFromLinkedList(&ll, &q); // You need to code this function
			printf("The resulting queue is: ");
			printList(&q.ll);
			break;
		case 3:
			removeOddValues(&q); // You need to code this function
			printf("The resulting queue after removing odd integers is: ");
			printList(&q.ll);
			removeAllItemsFromQueue(&q);
			removeAllItems(&ll);
			break;
		case 0:
			removeAllItemsFromQueue(&q);
			removeAllItems(&ll);
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}

	}

	return 0;
}


//////////////////////////////////////////////////////////////////////////////////

void createQueueFromLinkedList(LinkedList *ll, Queue *q) {
	/* add your code here */

	//if the Queue is NOT empty
	while (!isEmptyQueue(q)) {
		dequeue(q);	//empty the queue
	}
	//if the LinkedList is EMPTY, don't do anything
	if (ll == NULL || ll[0].size < 1 || ll[0].head == NULL) {
		return;	//break out of function
	}
	//else, if the LinkedList is NOT empty
	else {
		ListNode *tempNode;	//initialise ListNode* tempNode to traverse LinkedList

		//set tempNode to FirstNode
		tempNode = ll[0].head;

		//traverse the LinkedList
		while (tempNode != NULL) {
			enqueue(q, tempNode[0].item);	//enqueue currentNode.item
			tempNode = tempNode[0].next;	//traverse next node
		}
	}
}

void removeOddValues(Queue *q) {
	/* add your code here */

	//initialise x (counter), and y (initial size of queue)
	int x, y;
	y = q[0].ll.size;	//set y counter to initial size of queue
	
	//loop through the queue
	for (x = 0; x < y; x++) {
		int temp = dequeue(q);	//dequeue the queue into temp
		if (temp % 2 == 0) {	//if temp is an even number
			enqueue(q, temp);	//requeue temp back to the queue
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////

void enqueue(Queue *q, int item) {
	insertNode(&(q->ll), q->ll.size, item);
}

int dequeue(Queue *q) {
	int item;

	if (!isEmptyQueue(q)) {
		item = ((q->ll).head)->item;
		removeNode(&(q->ll), 0);
		return item;
	}
	return -1;
}

int isEmptyQueue(Queue *q) {
	if ((q->ll).size == 0)
		return 1;
	return 0;
}

void removeAllItemsFromQueue(Queue *q)
{
	int count, i;
	if (q == NULL)
		return;
	count = q->ll.size;

	for (i = 0; i < count; i++)
		dequeue(q);
}


void printList(LinkedList *ll) {

	ListNode *cur;
	if (ll == NULL)
		return;
	cur = ll->head;
	if (cur == NULL)
		printf("Empty");
	while (cur != NULL)
	{
		printf("%d ", cur->item);
		cur = cur->next;
	}
	printf("\n");
}


void removeAllItems(LinkedList *ll)
{
	ListNode *cur = ll->head;
	ListNode *tmp;

	while (cur != NULL) {
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	ll->head = NULL;
	ll->size = 0;
}


ListNode * findNode(LinkedList *ll, int index) {

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0) {
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList *ll, int index, int value) {

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0) {
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		if (ll->head == NULL)
		{
			exit(0);
		}
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL) {
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		if (pre->next == NULL)
		{
			exit(0);
		}
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}


int removeNode(LinkedList *ll, int index) {

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0) {
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;
		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL) {

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}