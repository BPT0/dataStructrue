#include<stdio.h>
#include<string.h>
// ����� ���� �ڷ��� = ����ü
// typedef : Ÿ���� �����Ѵ�, ����ü �ϴܿ��� ��� ����
typedef struct student{
	char name[20];
	int age;
}ST;
ST func(ST a) {
	printf("�̸� �Է�: ");
	scanf_s("%s", a.name, sizeof(a.name));
	printf("���� �Է�: ");
	scanf_s("%d", &a.age);
	return a;
}

struct test {
	int num;
	char str[100];
	float fl;
};
typedef struct test T; // �Ʒ��ʿ� ��� ����
void input(T* a) {
	(*a).num = 12345;
	a->fl = 1.123; // ���� ������ ->(���ο�)�����ڷ� �����ϰ� ��ĥ�� �ִ�.
}
typedef struct aaa {
	int num;
	struct aaa* link;
}aaa;
typedef struct info {
	char name[20];
	int age;
}IF;
int main(void) {
	// �ǽ�1. ����ü ����
	//struct student s;
	//ST ss; // ���� ������ ������ ����ü�� �����ϴ� �ڵ��� �� �� ����
	//s.age = 12345;
	//printf("%d\n", s.age);
	//
	//strcpy_s(ss.name, sizeof(ss.name), "test");
	//printf("%s\n", ss.name);
	//ST b= func(ss);                                                  
	//printf("�Է� �� ����Դϴ�\n");
	//printf("�̸�: %s ����: %d", b.name, b.age);

	// �ǽ�2. ����ü+������
	/*T t;
	input(&t);
	printf("%d\n", t.num);
	printf("%.2f\n", t.fl);*/

	// �ǽ� 3. �ڱ����� ����ü-feat.������
	/*int a;
	int* pa = &a;
	aaa aa;
	aaa* pp = &aa;
	
	aaa a1, a2, a3;
	a1.num = 12345;
	a2.link = &a1;
	a3.link = &a2;
	printf("%d\n", a3.link->link->num);*/

	// �ǽ� 4. ����ü + �迭
	/*int arr[5] = { 10, 20, 30, 40, 50 };
	IF in[5] = {
		"ȫ�浿", 20,
		"�谳��", 30,
		"����", 40,
		"��浿", 50,
		"�����", 60
	};
	for (int i = 0; i < 5; i++)
	{
		printf("�̸�: %s ����: %d\n", in[i].name, in[i].age);
	}*/

	// �ǽ�5. ���ڿ� �� �Լ�
	char arr[10] = "test", arr1[10] = "test";
	printf("%d", strcmp(arr, arr1));
	if (strcmp(arr, arr1)==0) {
		printf("�� ���ڿ��� ����");
	}
	else {
		printf("�ٸ���");
	}
}