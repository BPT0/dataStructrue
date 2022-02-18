#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0

typedef struct node {
	int data;
	struct node* link;
}Stack;

Stack* GetNode()
{
	Stack* tmp;
	tmp = (Stack*)malloc(sizeof(Stack));
	tmp->link = EMPTY;
	return tmp;
}

void Push(Stack** top, int data)
{
	Stack* tmp;
	tmp = *top;
	*top = GetNode();
	(*top)->data = data;
	(*top)->link = tmp;
}

void Pop(Stack** top) {
	if (*top) {
		Stack* tmp;
		printf("data: %d\n", (*top)->data);
		tmp = *top;
		*top = (*top)->link;
		free(tmp);
	}
	else {
		printf("Stack is Empty!!");
	}
}

int main()
{
	Stack* top = EMPTY;

	Push(&top, 10);
	Push(&top, 20);
	Push(&top, 30);

	Pop(&top);
	Pop(&top);
	Pop(&top);
	Pop(&top);

	return 0;
}