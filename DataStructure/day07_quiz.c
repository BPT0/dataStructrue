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
	//Func2()�Լ��� ���� Func2()�ȿ��� data3�� 100�� ��������. 
	Func3(&p);
	//Func3()�Լ��� ���� Func3()�ȿ��� data4�� 200�� ��������.
}

int main() {
	// ���չ���
	// 1. ����ü-  ������ ����, ���
	//Data1* p = (Data1*)malloc(sizeof(Data1));
	//Func1(&p);
	////Func1()�Լ��� ���� Func1()�ȿ��� data1�� 100�� ��������.
	//Func2(p);
	////Func2()�Լ��� ���� Func2()�ȿ��� data2�� 200�� ��������.	
	////data1�� data2�� ����ϼ���.
	//printf("data1: %d, data2: %d", p->data1, p->data2);
	//// �������� �ڵ带 �߰��ϼ���.
	//free(p);

	// 2. ����ü - ������ �Է�
	//Data1* p = (Data1*)malloc(sizeof(Data1));
	//printf("�̸��� �Է��ϼ��� : ");
	////scanf()�� �̿��� name�� �̸��� �Է� ��������.
	//scanf("%s", &p->p.name);
	//printf("������ �Է��ϼ��� : ");
	////scanf()�� �̿��� score�� ������ �Է� ��������.
	//scanf("%d", &p->p.score);
	////�Է¹��� ���� ����ϼ���.
	//printf("�̸�: %s, ����: %d", p->p.name, p->p.score);
	//free(p);

	// 3. ����ü�����Ϳ� �����Ҵ��� ������ �Է�
	//Data1* p = (Data1*)malloc(sizeof(Data1));
	//p->p = (Element*)malloc(sizeof(Element));
	//printf("�̸��� �Է��ϼ��� : ");
	////scanf()�� �̿��� name�� �̸��� �Է� ��������.
	//scanf("%s", p->p->name);
	//printf("������ �Է��ϼ��� : ");
	////scanf()�� �̿��� score�� ������ �Է� ��������.
	//scanf("%d", &p->p->score);
	////�Է¹��� ���� ����ϼ���
	//printf("�̸�: %s, ����: %d", p->p->name, p->p->score);
	////���� ���� �ڵ带 �߰��ϼ���.
	//free(p->p);
	//free(p);

	// 4. ����ü �����Ϳ� �����Ҵ� + �����Ϳ� �����Ҵ�
	//Data1* p = (Data1*)malloc(sizeof(Data1));
	//p->p = (Element*)malloc(sizeof(Element));
	//p->p->name = (char*)malloc(sizeof(char)*Max_Len);
	//printf("�̸��� �Է��ϼ��� : ");
	////scanf()�� �̿��� name�� �̸��� �Է� ��������.
	//scanf("%s", p->p->name);
	//printf("������ �Է��ϼ��� : ");
	////scanf()�� �̿��� score�� ������ �Է� ��������.
	//scanf("%d", &p->p->score);
	////�Է¹��� ���� ����ϼ���.
	//printf("�̸�: %s, ����: %d", p->p->name, p->p->score);
	////���� ���� �ڵ带 �߰��ϼ���.
	//free(p->p->name);
	//free(p->p);
	//free(p);

	// 5. ����ü ������, �Լ��� �Ű����� ����
	Data1* p = (Data1*)malloc(sizeof(Data1));
	Func1(&p);
	//data3�� data4�� ����ϼ���.
	printf("data3: %d, data4: %d", p->p->data3, p->p->data4);
	free(p->p);
	free(p);

	return 0;
}