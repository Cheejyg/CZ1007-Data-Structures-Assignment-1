# Assignment 1 (Total 100 marks)

## A. Problems (Total 100 marks)
___Program templates for questions 1-4___ are given in the Appendix. You ___must use___ them to implement your functions. The program contains a _main()_ function, which includes a switch statement to execute different functions that you should implement. Each function can be called multiple times depending on the user’s choice.

1. Write a C function _insertSortedLL()_ that asks the user to input an integer, then inserts it to the linked list in ascending order. The function, _insertSortedLL()_, should not allow to insert an integer if it is already existing in the current linked list. The function should return the index position where the new item was added; if the function could not complete successfully, it should return a value of -1. You can assume that the linked list is either a sorted linked list or an empty list.
	
	If the current linked list is: **`2 3 5 7 9`**
	
	Calling _insertSortedLL()_ with a value of **8** will result the following linked list: **`2 3 5 7 8 9`**
	
	The function should return the index position where the new item was added as follows: 
	
	`The value 8 was added at index 4`
	
	If the current linked list is: **`5 7 9 11 15`**
	
	Calling insertSortedLL() with a value of **7** will result the following linked list: **`5 7 9 11 15`**
	
	The function does not complete successfully (does not insert value of 7 to the linked list) hence it should return a value of -1: 
	
	`The value 7 was added at index -1`
	
	The function prototype is given as follows: 
	
	```
    int insertSortedLL(LinkedList *ll, int item);
	```
	
	Your function should print the contents of the linked list after it has been created. This function may be called multiple times for each time your program is run.
	
	Some sample inputs and outputs are given as follows: 
	
	```
    1: Insert an integer to the sorted linked list:
    2: Print the index of the most recent input value:
    3: Print sorted linked list:
    0: Quit:
    
    Please input your choice(1/2/3/0): 1
    Input an integer that you want to add to the linked list: 2
    The resulting linked list is: 2
    
    Please input your choice(1/2/3/0): 1
    Input an integer that you want to add to the linked list: 3
    The resulting linked list is: 2 3
    
    Please input your choice(1/2/3/0): 1
    Input an integer that you want to add to the linked list: 5
    The resulting linked list is: 2 3 5
    
    Please input your choice(1/2/3/0): 1
    Input an integer that you want to add to the linked list: 7
    The resulting linked list is: 2 3 5 7
    
    Please input your choice(1/2/3/0):1
    Input an integer that you want to add to the linked list: 9
    The resulting linked list is: 2 3 5 7 9
    
    Please input your choice(1/2/3/0): 1
    Input an integer that you want to add to the linked list: 8
    The resulting linked list is: 2 3 5 7 8 9
    
    Please input your choice(1/2/3/0): 2
    The value 8 was added at index 4
    
    Please input your choice(1/2/3/0):3
    The resulting sorted linked list is: 2 3 5 7 8 9
    
    Please input your choice(1/2/3/0): 1
    Input an integer that you want to add to the linked list: 5
    The resulting linked list is: 2 3 5 7 8 9
    
    Please input your choice(1/2/3/0): 2
    The value 5 was added at index -1
    
    Please input your choice(1/2/3/0):3
    The resulting sorted linked list is: 2 3 5 7 8 9
    
    Please input your choice(1/2/3/0): 1
    Input an integer that you want to add to the linked list: 11
    The resulting linked list is: 2 3 5 7 8 9 11
    
    Please input your choice(1/2/3/0): 2
    The value 11 was added at index 6
    
    Please input your choice(1/2/3/0):3
    The resulting sorted linked list is: 2 3 5 7 8 9 11
	```

2. Write a C function _moveOddItemsToBack()_ that moves all the odd integers to the back of the linked list. The odd values should be still in ascending order. Note that, you may use **Question 1** function, _insertSortedLL()_, to create the initial linked list in ascending order.
	
	**The function prototype is given as follows:** 
	
	```
    void moveOddItemsToBack(LinkedList *ll);
    int insertSortedLL(LinkedList *ll, int item);
	```
	
	Some sample inputs and outputs sessions are given below: 
	
	```
    If the current linked list is 2 3 4 7 15 18:
    
    The resulting Linked List after moving odd integers to the back of
    the Linked List is: 2 4 18 3 7 15
    
    If the current linked list is 1 3 5:
    
    The resulting Linked List after moving odd integers to the back of
    the Linked List is: 1 3 5
    
    If the current linked list is 2 4 6:
    
    The resulting Linked List after moving odd integers to the back of
    the Linked List is: 2 4 6
	```

3. Write a C function _createQueueFromLinkedList()_ to create a queue (linked-list-based) by enqueuing all integers which are stored in the linked list. The first node of the linked list is enqueued first, and then the 2nd node, and so on. Remember to empty the queue at the beginning if the queue is not empty.
	
	After the queue is built, write another C function _removeOddValues()_ to remove all odd integers in the queue. Note that you should only use enqueue() or dequeue() when you add or remove integers from queues.
	
	**The function prototypes are given as follows:** 
	
	```
    void createQueueFromLinkedList(LinkedList *ll , Queue *q);
    void removeOddValues(Queue *q)
	```
	
	A sample input and output session is given below (if the current linked list is 1 2 3 4 5): 
	
	```
    The resulting linked list is: 1 2 3 4 5
    
    Please input your choice(1/2/3/0): 2
    The resulting queue is: 1 2 3 4 5
    
    Please input your choice(1/2/3/0): 3
    The resulting queue after removing odd integers is: 2 4
	```

4. Write an iterative C function _printPostOrderIterative()_ that prints the post-order traversal of a binary search tree using ___two stacks___. Note that you should ___only___ use push () or pop () operations when you add or remove integers from the stacks. Remember to empty the stacks at the beginning, if the stacks are not empty.
	
	**The function prototype is given as follows:** 
	
	```
    void printPostOrderIterative(BSTNode *root);
	```
	
	A sample input and output session is given below: (Add the following nodes to a binary search tree in the order they appear: 6 34 17 19 16 10 23 3)
	
	```
    Please input your choice(1/2/0): 1
    Input an integer that you want to insert into the Binary Search
    Tree: 6
    
    Please input your choice(1/2/0): 1
    Input an integer that you want to insert into the Binary Search
    Tree: 34
    
    Please input your choice(1/2/0): 1
    Input an integer that you want to insert into the Binary Search
    Tree: 17
    
    Please input your choice(1/2/0): 1
    Input an integer that you want to insert into the Binary Search
    Tree: 19
    
    Please input your choice(1/2/0): 1
    Input an integer that you want to insert into the Binary Search
    Tree: 16
    
    Please input your choice(1/2/0): 1
    Input an integer that you want to insert into the Binary Search
    Tree: 10
    
    Please input your choice(1/2/0): 1
    Input an integer that you want to insert into the Binary Search
    Tree: 23
    
    Please input your choice(1/2/0): 1
    Input an integer that you want to insert into the Binary Search
    Tree: 3
    
    Please input your choice(1/2/0): 2
    The resulting post-order traversal of the binary search tree is: 3
    10 16 23 19 17 34 6
	```

## A. Submission

1. Deadline for program submission: ___November 14th, 2016 (Monday) 11.59 pm___. You are required to submit the soft copies of the report and source program.

2. Penalty on late submission: Deduction of 10% of the total mark each day (working day) after the submission deadline.

3. ___Report___ - Your report should contain the following: 

	1. **Program listings**: Give the program listing with comments. The source program should be presented **with proper indentation** and **appropriate comments: Indentation** - code indentation is to improve the readability of the program. **Comments** - write the purpose and your basic idea of each function at the beginning of each function, and if you declare variables by yourself, write comments to explain the meaning of the variable.
	
	2. **Test cases**: For each problem, give the results of the testing of your programs using the test cases specified in this manual. You may also use other test cases to show the testing of your programs.
	
4. ___Source Code and Report Submission___

	1. Please put the source programs (**p1.c**, **p2.c**, **p3.c**, and **p4.c** only) into a zip file with file name using your group number and your name (e.g. **FS3_Bill Gates**). Please make sure that the source programs for the problems are correctly named according to this manual
	2. Please put the report with file name using your group number and your name (e.g. **FS3_Bill Gates**).
	3. Upload the source file and the report into the NTULearn. If you are not sure how to do this, please go to **Software Projects Lab (N4-B1B-11)** and check with the lab supervisor or technician.
	4. Upload the source codes to the online **PSA** submission system (Please check user manual for more details \[**Using PSA System – Assignment submission.pdf**\])
	5. Please make sure that you upload your programs before the deadline.
	
5. ___Marking Scheme___

	The marking of each problem of the assignment will be based on the following criteria: 
	
	1. Correctness of the program.
	2. Presentation and documentation of the C codes (whether the program is properly indented, and whether the program is well commented to aid understanding).

6. ___Plagiarism___
	
	Please be reminded that PLAGIARISM (or copying part of/complete assignment) is considered as CHEATING, which is strictly prohibited. You will get zero mark on your assignment if you are found guilty of plagiarism.

## C. Appendix -- PROGRAM TEMPLATE
```
/* CE1007/CZ1007 Data Structures
    2016/17 S1
    Author and Lab Group: yourname labgroup
    Program name: labgroup_yourname.c
    Date: xx November 2016
    Purpose: Implementing the required functions for Assignment 1*/
```

### Question No 1.
```
/* CE1007/CZ1007 Data Structures
2016/17 S1
Author and Lab Group: yourname labgroup
Program name: labgroup_yourname
Date: xx November 2016
Purpose: Implementing the required functions for Assignment 1 (Question 1)*/


//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode {
    int item;
    struct _listnode *next;
} ListNode;            // You should not change the definition of ListNode                

typedef struct _linkedlist {
    int size;
    ListNode *head;
} LinkedList;            // You should not change the definition of LinkedList


///////////////////////// function prototypes ////////////////////////////////////

// This is for question 1. You should not change the prototype of this function
int insertSortedLL(LinkedList *ll, int item);

// You may use the following functions or you may write your own
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
    printf("2: Print the index of the most recent input value:\n");
    printf("3: Print sorted linked list:\n");
    printf("0: Quit:");

    while (c != 0)
    {
        printf("\nPlease input your choice(1/2/3/0): ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("Input an integer that you want to add to the linked list: ");
            scanf("%d", &i);
            j = insertSortedLL(&ll, i);
            printf("The resulting linked list is: ");
            printList(&ll);
            break;
        case 2:
            printf("The value %d was added at index %d\n", i, j);
            break;
        case 3:
            printf("The resulting sorted linked list is: ");
            printList(&ll);
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

int insertSortedLL(LinkedList *ll, int item) {
    /* add your code here */
}

void printList(LinkedList *ll)
{
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

ListNode * findNode(LinkedList *ll, int index)
{
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

int insertNode(LinkedList *ll, int index, int value)
{
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

int removeNode(LinkedList *ll, int index)
{
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
```

### Question No 2.
```
/* CE1007/CZ1007 Data Structures
2016/17 S1
Author and Lab Group: yourname labgroup
Program name: labgroup_yourname
Date: xx November 2016
Purpose: Implementing the required functions for Assignment 1 (Question 2)*/


//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode
{
    int item;
    struct _listnode *next;
} ListNode;            // You should not change the definition of ListNode

typedef struct _linkedlist
{
    int size;
    ListNode *head;
} LinkedList;            // You should not change the definition of LinkedList


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
            j = insertSortedLL(&ll, i); // You may use Question1 function or
                                        // code this function
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

void moveOddItemsToBack(LinkedList *ll)
{
    /* add your code here */
}


int insertSortedLL(LinkedList *ll, int item)
{
    /* add your code here (You may use question1 function or code this function) */
}

void printList(LinkedList *ll)
{
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

ListNode * findNode(LinkedList *ll, int index)
{
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

int insertNode(LinkedList *ll, int index, int value)
{
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

int removeNode(LinkedList *ll, int index)
{
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
```

### Question No 3.
```
/* CE1007/CZ1007 Data Structures
2016/17 S1
Author and Lab Group: yourname labgroup
Program name: labgroup_yourname
Date: xx November 2016
Purpose: Implementing the required functions for Assignment 1 (Question 3)*/


//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode
{
    int item;
    struct _listnode *next;
} ListNode;    // You should not change the definition of ListNode

typedef struct _linkedlist
{
    int size;
    ListNode *head;
} LinkedList;    // You should not change the definition of LinkedList


typedef struct _queue
{
    LinkedList ll;
} Queue;  // You should not change the definition of Queue


///////////////////////// function prototypes ////////////////////////////////////

// This is for question 3. You should not change the prototypes of these functions
void createQueueFromLinkedList(LinkedList *ll, Queue *q);
void removeOddValues(Queue *q);

// You may use the following functions or you may write your own
void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode* findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int isEmptyQueue(Queue *q);
void removeAllItemsFromQueue(Queue *q);

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

void createQueueFromLinkedList(LinkedList *ll, Queue *q)
{
    /* add your code here */
}

void removeOddValues(Queue *q)
{
    /* add your code here */
}

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

//////////////////////////////////////////////////////////////////////////////////////////

void printList(LinkedList *ll)
{
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


ListNode * findNode(LinkedList *ll, int index)
{
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

int insertNode(LinkedList *ll, int index, int value)
{
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


int removeNode(LinkedList *ll, int index)
{
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
```

### Question No 4.
```
/* CE1007/CZ1007 Data Structures
2016/17 S1
Author and Lab Group: yourname labgroup
Program name: labgroup_yourname
Date: xx November 2016
Purpose: Implementing the required functions for Assignment 1 (Question 4)*/


//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _bstnode
{
    int item;
    struct _bstnode *left;
    struct _bstnode *right;
} BSTNode;   // You should not change the definition of BSTNode

typedef struct _stackNode
{
    BSTNode *item;
    struct _stackNode *next;
}StackNode; // You should not change the definition of StackNode

typedef struct _stack
{
    StackNode *top;
}Stack; // You should not change the definition of Stack

///////////////////////// function prototypes ////////////////////////////////////

// This is for question 4. You should not change the prototypes of these functions
void insertBSTNode(BSTNode **node, int value);
void printPostOrderIterative(BSTNode *root);

// You may use the following functions or you may write your own
void push(Stack *stack, BSTNode *node);
BSTNode * pop(Stack *s);
BSTNode * peek(Stack *s);
int isEmpty(Stack *s);
void removeAll(BSTNode **node);

///////////////////////////// main() /////////////////////////////////////////////

int main()
{
    int c, i;

    //Initialize the Binary Search Tree as an empty Binary Search Tree
    BSTNode *root;
    c = 1;
    root = NULL;

    printf("1:Insert an integer into the binary search tree;\n");
    printf("2:Print the post-order traversal of the binary search tree;\n");
    printf("0:Quit;\n");


    while (c != 0)
    {
        printf("Please input your choice(1/2/0): ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("Input an integer that you want to insert into the Binary Search Tree: ");
            scanf("%d", &i);
            insertBSTNode(&root, i);
            break;
        case 2:
            printf("The resulting post-order traversal of the binary search tree is: ");
            printPostOrderIterative(root); // You need to code this function
            printf("\n");
            break;
        case 0:
            removeAll(&root);
            break;
        default:
            printf("Choice unknown;\n");
            break;
        }

    }

    return 0;
}


//////////////////////////////////////////////////////////////////////////////////


void insertBSTNode(BSTNode **node, int value)
{
    if (*node == NULL)
    {
        *node = malloc(sizeof(BSTNode));

        if (*node != NULL) {
            (*node)->item = value;
            (*node)->left = NULL;
            (*node)->right = NULL;
        }
    }
    else
    {
        if (value < (*node)->item)
        {
            insertBSTNode(&((*node)->left), value);
        }
        else if (value >(*node)->item)
        {
            insertBSTNode(&((*node)->right), value);
        }
        else
            return;
    }
}

void printPostOrderIterative(BSTNode *root)
{
    /* add your code here */
}


//////////////////////////////////////////////////////////////////////////////////

void push(Stack *stack, BSTNode *node)
{
    StackNode *temp;

    temp = malloc(sizeof(StackNode));

    if (temp == NULL)
        return;
    temp->item = node;

    if (stack->top == NULL)
    {
        stack->top = temp;
        temp->next = NULL;
    }
    else
    {
        temp->next = stack->top;
        stack->top = temp;
    }
}


BSTNode* pop(Stack * s)
{
    StackNode *temp, *t;
    BSTNode * ptr;
    ptr = NULL;

    t = s->top;
    if (t != NULL)
    {
        temp = t->next;
        ptr = t->item;

        s->top = temp;
        free(t);
        t = NULL;
    }

    return ptr;
}

BSTNode* peek(Stack * s)
{
    StackNode *temp;
    temp = s->top;
    if (temp != NULL)
        return temp->item;
    else
        return NULL;
}

int isEmpty(Stack *s)
{
    if (s->top == NULL)
        return 1;
    else
        return 0;
}


void removeAll(BSTNode **node)
{
    if (*node != NULL)
    {
        removeAll(&((*node)->left));
        removeAll(&((*node)->right));
        free(*node);
        *node = NULL;
    }
}
```
