#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define EMPTY 0

typedef struct node {
	char name[20];
	int age;
	struct node* link;
}Stack;

void Push(Stack** top, int age, char* name) {
	Stack* tmp;
	tmp = *top;

}

int main()
{
	Stack* top = EMPTY;
	int sel, age;
	char name[20];
	Stack data;

	while (1) {
		printf("1. �Է�\n");
		printf("2. ����\n");
		printf("3. ���\n");
		printf("4. ����\n");
		printf("��ȣ �Է� >> ");
		scanf("%d", &sel);

		switch (sel) {
		case 1:
			scanf("%d", &age);
			scanf("%s", name);
			Push(&top, age, name);
			system("pause");
				break;
		case 2:
			//Pop �Լ� ȣ��
			system("pause");
			break;
		case 3:
			//Print �Լ� ȣ��
			system("pause");
			break;
		case 4:
			//Pop �Լ� ȣ��
			break;
		default:
			printf("1 ~ 4 �� �ϳ��� �Է����ּ���.\n");
			system("pause");
		}
		system("cls");
	}

	return 0;
}