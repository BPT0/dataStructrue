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

void Print(Stack** front) {
	// 전체 데이터를 출력
	Stack* tmp = *front;
	// 1. front의 data까지 찾아간다
	while (tmp){
		if (tmp->link) {
			// 가장 먼저 입력된것, 가장 밑에
			// 가장 나중에 입력된것, 가장 위에
			// 2. data를 순차적으로 출력한다
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
		printf("1. 삽입\n");
		printf("2. 삭제\n");
		printf("3. 출력\n");
		printf("4. 모두삭제\n");
		printf("5. 종료\n");
		printf("번호 입력 >> ");
		scanf("%d", &sel);
		switch (sel) {
		case 1:
			printf("데이터 입력: ");
			scanf("%d", &data.data);
			Enque(&front, &rear, data);
			system("pause");
				break;
		case 2:
			//Pop 함수 호출
			Deque(&front);
			system("pause");
			break;
		case 3:
			//Print 함수 호출
			Print(&front);
			system("pause");
			break;
		case 4:
		case 5:
			//Pop 함수 호출
			while (rear->link) printf("%d", Deque(&front));
			break;
		default:
			printf("1 ~ 4 중 하나를 입력해주세요.\n");
			system("pause");
		}
		system("cls");
	} while ((sel != 5));

	return 0;
}