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
		printf("제거된 항목: %d %s", (*top)->age, (*top)->name);
		tmp = *top;
		*top = (*top)->link;
		free(tmp);
	}
	else {
		printf("제거될 데이터가 없습니다!!");
	}
}

void Print(Stack** top) {
	int num = 1;
	Stack* tmp = *top;
	printf("    나이   이름\n");
	printf("----------------\n");
	while (tmp){ // tmp가 NULL일때를 검사
		printf("%d   %d   %s\n", num, tmp->age,  tmp->name);
		if (!tmp->link) break;
		tmp = tmp->link;
		num++;
	}
	// free(tmp); // 없는 공간을 해제하려니까 오류 발생?
}
int main()
{
	Stack* top = EMPTY;
	int sel;
	Stack data;

	do{
		printf("1. 입력\n");
		printf("2. 삭제\n");
		printf("3. 출력\n");
		printf("4. 종료\n");
		printf("번호 입력 >> ");
		scanf("%d", &sel);
		fflush(stdin);
		switch (sel) {
		case 1:
			printf("나이 입력: ");
			scanf("%d", &data.age);
			fflush(stdin);
			printf("이름 입력: ");
			scanf("%s", data.name);
			fflush(stdin);
			Push(&top, data);
			system("pause");
				break;
		case 2:
			//Pop 함수 호출
			Pop(&top);
			system("pause");
			break;
		case 3:
			//Print 함수 호출
			Print(&top);
			system("pause");
			break;
		case 4:
			//Pop 함수 호출
			while (top) Pop(&top);

			break;
		default:
			printf("1 ~ 4 중 하나를 입력해주세요.\n");
			system("pause");
		}
		system("cls");
	} while ((sel != 4));

	return 0;
}