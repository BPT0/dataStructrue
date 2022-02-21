#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
#define EMPTY 0

typedef struct node {
	char name[20];
	int age;
	struct node* link;
}Stack;

Stack* getNode() {
	Stack* tmp = (Stack*)malloc(sizeof(Stack));
	tmp->link = EMPTY;
	return tmp;
}
void Push(Stack** top, Stack data) {
	Stack* tmp = *top;
	*top = getNode();
	(*top)->age = data.age;
	strcpy((*top)->name, data.name);
	(*top)->link = tmp;
}

void Pop(Stack** top) {
	if (*top) {
		Stack* tmp;
		printf("���ŵ� �׸�: %d %s", (*top)->age, (*top)->name);
		tmp = *top;
		*top = (*top)->link;
		free(tmp);
	}
	else {
		printf("���ŵ� �����Ͱ� �����ϴ�!!");
	}
}

void Print(Stack** top) {
	int num = 1;
	Stack* tmp = *top;
	printf("    ����   �̸�\n");
	printf("----------------\n");
	while (tmp){ // tmp�� NULL�϶��� �˻�
		printf("%d   %d   %s\n", num, tmp->age,  tmp->name);
		if (!tmp->link) break;
		tmp = tmp->link;
		num++;
	}
	// free(tmp); // ���� ������ �����Ϸ��ϱ� ���� �߻�?
}
int main()
{
	Stack* top = EMPTY;
	int sel;
	Stack data;

	do{
		printf("1. �Է�\n");
		printf("2. ����\n");
		printf("3. ���\n");
		printf("4. ����\n");
		printf("��ȣ �Է� >> ");
		scanf("%d", &sel);
		fflush(stdin);
		switch (sel) {
		case 1:
			printf("���� �Է�: ");
			scanf("%d", &data.age);
			fflush(stdin);
			printf("�̸� �Է�: ");
			scanf("%s", data.name);
			fflush(stdin);
			Push(&top, data);
			system("pause");
				break;
		case 2:
			//Pop �Լ� ȣ��
			Pop(&top);
			system("pause");
			break;
		case 3:
			//Print �Լ� ȣ��
			Print(&top);
			system("pause");
			break;
		case 4:
			//Pop �Լ� ȣ��
			while (top) Pop(&top);

			break;
		default:
			printf("1 ~ 4 �� �ϳ��� �Է����ּ���.\n");
			system("pause");
		}
		system("cls");
	} while ((sel != 4));

	return 0;
}