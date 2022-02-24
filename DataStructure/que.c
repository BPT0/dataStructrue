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
		printf("���̻� �����Ͱ� �����ϴ�.");
		return 0;
	}
	// ó���� ����Ű�� �ִ� front�� ���� 2��° ��ġ�� ������ ����
	// �ؾ� �ϴµ� front�� ���� ���� ���� �ϰ� �Ǹ� ó���� ����Ű��
	// ������ ��� tmp�� ����� �صΰ� �׷��� front�� ���� �����ϰ�
	// tmp�� ���� free���ִ� ���̴�.
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

