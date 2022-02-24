#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
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

void Enque(Stack** front, Stack** rear, Stack data) {
	Stack* tmp = *front;
	if (!tmp) {
		*front = GetNode();
		*rear = *front;
		(*rear)->data = data.data;
		(*rear)->link = tmp;
	}
	else {
		tmp = *rear;
		*rear = GetNode();
		(*rear)->data = data.data;
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

void Print(Stack** front) {
	// ��ü �����͸� ���
	Stack* tmp = *front;
	// 1. front�� data���� ã�ư���
	while (tmp){
		if (tmp->link) {
			// ���� ���� �ԷµȰ�, ���� �ؿ�
			// ���� ���߿� �ԷµȰ�, ���� ����
			// 2. data�� ���������� ����Ѵ�
			printf("%d, %p\n", tmp->data, &tmp->data);
			tmp = tmp ->link;
		}
		else {
			printf("%d, %p\n", tmp->data, &tmp->data);
			break;
		}
	}
}

int main()
{
	Stack* front = EMPTY;
	Stack* rear = EMPTY;
	int sel;
	Stack data;

	do{
		printf("1. ����\n");
		printf("2. ����\n");
		printf("3. ���\n");
		printf("4. ��λ���\n");
		printf("5. ����\n");
		printf("��ȣ �Է� >> ");
		scanf("%d", &sel);
		switch (sel) {
		case 1:
			printf("������ �Է�: ");
			scanf("%d", &data.data);
			Enque(&front, &rear, data);
			system("pause");
				break;
		case 2:
			//Pop �Լ� ȣ��
			Deque(&front);
			system("pause");
			break;
		case 3:
			//Print �Լ� ȣ��
			Print(&front);
			system("pause");
			break;
		case 4:
		case 5:
			//Pop �Լ� ȣ��
			while (rear->link) printf("%d", Deque(&front));
			break;
		default:
			printf("1 ~ 4 �� �ϳ��� �Է����ּ���.\n");
			system("pause");
		}
		system("cls");
	} while ((sel != 5));

	return 0;
}