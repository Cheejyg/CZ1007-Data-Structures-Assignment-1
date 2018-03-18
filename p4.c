//////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
2016/17 S1
Author and Lab Group: Chee Jun Yuan Glenn FSP7
Program name: FSP7_Chee Jun Yuan Glenn
Date: 10 November 2016
Purpose: Implementing the required functions for Assignment 1 (Question 4)*/

//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _bstnode {
	int item;
	struct _bstnode *left;
	struct _bstnode *right;
} BSTNode;   // You should not change the definition of BSTNode

typedef struct _stackNode {
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

void insertBSTNode(BSTNode **node, int value) {
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

//////////////////////////////////////////////////////////////////////////////////

void printPostOrderIterative(BSTNode *root) {
	/* add your code here */

	///Postorder Traversal with a Stack (Iterative)
	//if root is EMPTY, don't do anything
	if (root == NULL || root[0].item == NULL) {
		return;	//break out of function
	}

	//Initialise two stacks
	Stack *firstStack, *secondStack;
	firstStack = malloc(sizeof(Stack));
	secondStack = malloc(sizeof(Stack));
	firstStack[0].top = NULL;
	secondStack[0].top = NULL;

	//if Stacks are NOT empty
	if (!isEmpty(firstStack)) {
		//removeAll(firstStack);	//empty stack
	}
	if (!isEmpty(secondStack)) {
		//removeAll(secondStack);	//empty stack
	}

	//push root onto the first Stack
	push(firstStack, root);

	//initialise BSTNode *tempNode to traverse BinarySearchTree
	BSTNode *tempNode;

	//loop while firstStack is NOT empty
	while (!isEmpty(firstStack) && firstStack != NULL) {
		//pop a BSTNode from firstStack into currentNode
		BSTNode *tempNode = pop(firstStack);
		//push currentNode into secondStack
		push(secondStack, tempNode);

		//if currentNode has a leftNode
		if (tempNode[0].left != NULL) {
			push(firstStack, tempNode[0].left);		//push currentNode.leftNode to firstStack
		}
		//if currentNode has a rightNode
		if (tempNode[0].right != NULL) {
			push(firstStack, tempNode[0].right);	//push currentNode.rightNode to firstStack
		}
	}

	//loop while secondStack is NOT empty
	while (!isEmpty(secondStack) && secondStack != NULL) {
		printf("%d ", pop(secondStack)[0].item);	//process (print) the values of secondStack
	}

	//////////////////////////////////////////////////////////////////////////////////
	///Postorder Traversal without a Stack (Recursive)
	/*//if root is EMPTY, don't do anything
	if (root == NULL || root[0].item == NULL) {
	return;	//break out of function
	}

	//POST-order, so left -> right -> process
	printPostOrderIterative(root[0].left);	//left
	printPostOrderIterative(root[0].right);	//right
	printf("%d ", root[0].item);			//process*/

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