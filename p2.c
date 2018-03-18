//////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
2016/17 S1
Author and Lab Group: Chee Jun Yuan Glenn FSP7
Program name: FSP7_Chee Jun Yuan Glenn
Date: 09 November 2016
Purpose: Implementing the required functions for Assignment 1 (Question 2)*/

//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode
{
	int item;
	struct _listnode *next;
} ListNode;			// You should not change the definition of ListNode

typedef struct _linkedlist
{
	int size;
	ListNode *head;
} LinkedList;			// You should not change the definition of LinkedList


						//////////////////////// function prototypes /////////////////////////////////////

						// This is for question 2. You should not change the prototype of this function
void moveOddItemsToBack(LinkedList *ll);

// You may use the following functions or you may write your own
int insertSortedLL(LinkedList *ll, int item);
void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);


//////////////////////////// main() //////////////////////////////////////////////

int main()
{
	LinkedList ll;
	int c, i, j;
	c = 1;
	//Initialize the linked list 1 as an empty linked list
	ll.head = NULL;
	ll.size = 0;

	printf("1: Insert an integer to the sorted linked list:\n");
	printf("2: Moves all odd integers to the back of the linked list:\n");
	printf("0: Quit:\n");

	while (c != 0)
	{
		printf("Please input your choice(1/2/3/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to add to the linked list: ");
			scanf("%d", &i);
			j = insertSortedLL(&ll, i); // You may use question1 function or code this function
			printf("The resulting Linked List is: ");
			printList(&ll);
			break;
		case 2:
			moveOddItemsToBack(&ll); // You need to code this function
			printf("The resulting Linked List after moving odd integers to the back of the Linked List is: ");
			printList(&ll);
			removeAllItems(&ll);
			break;
		case 0:
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


void moveOddItemsToBack(LinkedList *ll) {
	/* add your code here */

	//if the LinkedList is EMPTY, don't do anything
	if (ll == NULL || ll[0].size < 1 || ll[0].head == NULL) {
		return;	//break out of function
	}
	//else, if the LinkedList is NOT empty
	else {
		ListNode *tempNode, *prevNode;	//initialise ListNode *tempNode to traverse LinkedList, and ListNode *prevNode to store previousNode
		int x = 0, y = 0;				//initialise x (counter), and y (index)

		//set tempNode to FirstNode
		tempNode = ll[0].head;
		prevNode = NULL;

		///Inserting and Removing nodes
		//traverse each element of the LinkedList only once, x (counter) < ll[0].size
		while (x < ll[0].size && tempNode != NULL) {
			//if item is an odd number
			if (tempNode[0].item % 2 != 0) {
				insertNode(ll, ll[0].size, tempNode[0].item);	//insert currentNode.item to the back of the LinkedList (ll[0].size)
				removeNode(ll, y);								//remove currentNode from the LinkedList
				tempNode = prevNode;							//set tempNode to previousNode as we have removed the current node from the LinkedList
				y--;											//decrement index counter
			}

			prevNode = tempNode;											//store address of previous node
			tempNode = tempNode != NULL ? tempNode[0].next : ll[0].head;	//traverse next node; if tempNode is NULL, set tempNode to FirstNode again, else traverse next node...
																			//increment counter(s)
			x++;	//counter
			y++;	//index
		}

		///Repointing LinkedList
		//traverse each element of the LinkedList only once, x (counter) < ll[0].size
		/*while (x < ll[0].size && tempNode != NULL) {
			//if item is an odd number
			if (tempNode[0].item % 2 != 0) {
				//if currentNode is firstNode
				if (prevNode == NULL) {
					//repoint ll[0].head to nextNode
					ll[0].head = tempNode[0].next;
				}
				//else if currentNode is not firstNode
				else {
					//repoint previousNode[0].next to nextNode
					prevNode[0].next = tempNode[0].next != NULL ? tempNode[0].next : NULL;
				}
				//repoint lastNode to currentNode
				findNode(ll, ll[0].size - 2)[0].next = tempNode;

				//end lastNode's tail
				tempNode[0].next = NULL;
				//decrement index
				y--;
			}

			prevNode = findNode(ll, y);			//store address of previous node
			tempNode = findNode(ll, y + 1);		//traverse next node
			
			//increment counter(s)
			x++;	//counter
			y++;	//index
		}*/
	}
}


int insertSortedLL(LinkedList *ll, int item) {
	/* add your code here (You may use question1 function or code this function) */

	//if the LinkedList is EMPTY, simply insert item to the first index (0)
	if (ll == NULL || ll[0].size < 1 || ll[0].head == NULL) {
		insertNode(ll, 0, item);
		return 0;	//return index
	}
	//else, if the LinkedList is NOT empty
	else {
		ListNode *tempNode;	//initialise ListNode *tempNode to traverse LinkedList
		int x = 0;			//initialise counter

							//set tempNode to FirstNode
		tempNode = ll[0].head;

		//traverse the LinkedList
		while (tempNode != NULL) {
			//if item is less than currentNode.item
			if (item < tempNode[0].item) {
				insertNode(ll, x, item);	//insert item to LinkedList just before the currentNode
				return x;
			}
			//else if item equals to currentNode.item
			else if (item == tempNode[0].item) {
				return -1;	//return invalid index
			}
			//else if item is greater than currentNode.item
			else {
				//if currentNode is LastNode OR if item is greater than currentNode.item AND lesser than nextNode.item
				if (tempNode[0].next == NULL || item < tempNode[0].next[0].item) {
					insertNode(ll, x + 1, item);	//simply insert item to LinkedList just after the currentNode
					return x + 1;
				}
				//do not insert if item is greater than tempNode.item AND nextNode.item
				//else {}
			}

			//traverse next node and increment counter
			tempNode = tempNode[0].next;
			x++;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////

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