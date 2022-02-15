#include<stdio.h>
#include<stdlib.h>
#define Max_Len 20
//typedef struct {
//	int data1, data2;
//}Data1;
//void Func1(Data1** p) {
//	(*p)->data1 = 100;
//}
//void Func2(Data1* p) {
//	p->data2 = 200;
//}

//typedef struct
//{
//	char name[20];
//	int score;
//}Element;
//typedef struct
//{
//	int data1;
//	int data2;
//	Element p;
//}Data1;

//typedef struct
//{
//	char name[20];
//	int score;
//}Element;
//typedef struct
//{
//	int data1;
//	int data2;
//	Element* p;
//}Data1;

//typedef struct
//{
//	char* name;
//	int score;
//}Element;
//
//typedef struct
//{
//	int data1;
//	int data2;
//	Element* p;
//}Data1;

typedef struct
{
	int data3;
	int data4;
}Data2;
typedef struct
{
	int data1;
	int data2;
	Data2* p;
}Data1;
void Func2(Data2* p) {
	p->data3 = 100;
}
void Func3(Data1*** p) {
	(**p)->p->data4 = 200;
}
void Func1(Data1** p)
{
	Data2* p2 = (Data2*)malloc(sizeof(Data2));
	(*p)->p = p2;

	Func2((*p)->p);
	//Func2()함수를 만들어서 Func2()안에서 data3에 100을 넣으세요. 
	Func3(&p);
	//Func3()함수를 만들어서 Func3()안에서 data4에 200을 넣으세요.
}

int main() {
	// 종합문제
	// 1. 구조체-  데이터 삽입, 출력
	//Data1* p = (Data1*)malloc(sizeof(Data1));
	//Func1(&p);
	////Func1()함수를 만들어서 Func1()안에서 data1에 100을 넣으세요.
	//Func2(p);
	////Func2()함수를 만들어서 Func2()안에서 data2에 200을 넣으세요.	
	////data1과 data2를 출력하세요.
	//printf("data1: %d, data2: %d", p->data1, p->data2);
	//// 동적해제 코드를 추가하세요.
	//free(p);

	// 2. 구조체 - 데이터 입력
	//Data1* p = (Data1*)malloc(sizeof(Data1));
	//printf("이름을 입력하세요 : ");
	////scanf()를 이용해 name에 이름을 입력 받으세요.
	//scanf("%s", &p->p.name);
	//printf("점수를 입력하세요 : ");
	////scanf()를 이용해 score에 점수를 입력 받으세요.
	//scanf("%d", &p->p.score);
	////입력받은 값을 출력하세요.
	//printf("이름: %s, 점수: %d", p->p.name, p->p.score);
	//free(p);

	// 3. 구조체포인터에 동적할당해 데이터 입력
	//Data1* p = (Data1*)malloc(sizeof(Data1));
	//p->p = (Element*)malloc(sizeof(Element));
	//printf("이름을 입력하세요 : ");
	////scanf()를 이용해 name에 이름을 입력 받으세요.
	//scanf("%s", p->p->name);
	//printf("점수를 입력하세요 : ");
	////scanf()를 이용해 score에 점수를 입력 받으세요.
	//scanf("%d", &p->p->score);
	////입력받은 값을 출력하세요
	//printf("이름: %s, 점수: %d", p->p->name, p->p->score);
	////동적 해제 코드를 추가하세요.
	//free(p->p);
	//free(p);

	// 4. 구조체 포인터에 동적할당 + 데이터에 동적할당
	//Data1* p = (Data1*)malloc(sizeof(Data1));
	//p->p = (Element*)malloc(sizeof(Element));
	//p->p->name = (char*)malloc(sizeof(char)*Max_Len);
	//printf("이름을 입력하세요 : ");
	////scanf()를 이용해 name에 이름을 입력 받으세요.
	//scanf("%s", p->p->name);
	//printf("점수를 입력하세요 : ");
	////scanf()를 이용해 score에 점수를 입력 받으세요.
	//scanf("%d", &p->p->score);
	////입력받은 값을 출력하세요.
	//printf("이름: %s, 점수: %d", p->p->name, p->p->score);
	////동적 해제 코드를 추가하세요.
	//free(p->p->name);
	//free(p->p);
	//free(p);

	// 5. 구조체 포인터, 함수의 매개변수 형식
	Data1* p = (Data1*)malloc(sizeof(Data1));
	Func1(&p);
	//data3와 data4를 출력하세요.
	printf("data3: %d, data4: %d", p->p->data3, p->p->data4);
	free(p->p);
	free(p);

	return 0;
}