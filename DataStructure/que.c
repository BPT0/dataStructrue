#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0

typedef struct node {
	int data;
	struct node* link;
}Stack;
Stack* GetNode() {
	Stack* tmp;
	tmp = (Stack*)malloc(sizeof(Stack));
	return tmp;
}

void Enque(Stack** front, Stack** rear, int data) {
	Stack* tmp = *front;
	if (!tmp) {
		*front = GetNode();
		*rear = *front;
		(*rear)->data = data;
		(*rear)->link = tmp;
	}
	else {
		tmp = *rear;
		*rear = GetNode();
		(*rear)->data = data;
		(*rear)->link = 0;
		tmp->link = *rear;
	}
}

int Deque(Stack** front) {
	Stack* tmp;
	int data;
	if (*front == 0) {
		printf("더이상 데이터가 없습니다.");
		return 0;
	}
	// 처음을 가리키고 있는 front의 값을 2번째 위치의 값으로 변경
	// 해야 하는데 front의 값을 먼저 변경 하게 되면 처음을 가리키는
	// 변수가 없어서 tmp에 백업을 해두고 그런후 front의 값을 변경하고
	// tmp의 값을 free해주는 것이다.
	tmp = *front;
	data = tmp->data;
	*front = (*front)->link;
	free(tmp);
	return data;
}

int main()
{
	Stack* front = 0;
	Stack* rear = 0;

	Enque(&front, &rear, 10);
	Enque(&front, &rear, 20);
	Enque(&front, &rear, 30);

	printf("%d", Deque(&front));
	printf("%d", Deque(&front));
	printf("%d", Deque(&front));
	printf("%d", Deque(&front));

	return 0;
}

