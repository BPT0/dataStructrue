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
		printf("1. 입력\n");
		printf("2. 삭제\n");
		printf("3. 출력\n");
		printf("4. 종료\n");
		printf("번호 입력 >> ");
		scanf("%d", &sel);

		switch (sel) {
		case 1:
			scanf("%d", &age);
			scanf("%s", name);
			Push(&top, age, name);
			system("pause");
				break;
		case 2:
			//Pop 함수 호출
			system("pause");
			break;
		case 3:
			//Print 함수 호출
			system("pause");
			break;
		case 4:
			//Pop 함수 호출
			break;
		default:
			printf("1 ~ 4 중 하나를 입력해주세요.\n");
			system("pause");
		}
		system("cls");
	}

	return 0;
}