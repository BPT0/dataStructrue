#include<stdio.h>

void convertToUpperCase(char* s) {
	while (*s != NULL) {
		if(*s>='a'&& *s<='z')
			*s = *s - 32; // �ƽ�Ű �ڵ�ǥ�� �� ����
		++s;
	}
}

void intputTwo(int* n1, int* n2) {
	printf("�� �� �Է�: ");
	scanf_s("%d %d", &n1, &n2);
}

void maxNum(int n1, int n2, int* max) {
	(n1 > n2) ? (*max = n1) : (*max = n2);
}

void transChar(char* c) {
	if (*c >= 'a' && *c <= 'z') *c -= 32;
	else if (*c >= 'A' && *c <= 'Z') *c += 32;
	else printf("�ش繮�ڴ� ���� ��*�ҹ��ڰ� �ƴմϴ�.");
}

void allPlus(int n, int* sum) {
	for (int i = 1; i <= n; i++) *sum += i;
}

void toUpper(char* s) {
	// ó�� ���� �빮�ڷ� ����
	if (*s>='a' && *s <= 'z') {
		*s -= 32;
	}
	s++;
	// 1.�ι��ڰ� ������ ����
	// 2.�������ڰ� ���� ���ڶ�� �빮�ڷ� ����
	while (*s){
		if (*(s - 1) == ' ') {
			if (*s >= 'a' && *s <= 'z') {
				*s -= 32;
			}
		}
		s++;
	}
}

int main() {
	// �ǽ�1. �迭�� �ּҰ��� �̿��Ͽ� ������
	//int arr[] = { 10, 20, 30, 40, 50 };
	//int *p = arr;
	//// �迭���� ���� ������ �� ���� ������ ����̴�.
	//printf("%d %d\n", p[0], p[1]);
	//printf("%d %d\n", *(arr+0), *(arr+1));
	//printf("%p, %p\n", &p[0], &p[1]);
	//printf("%p, %p\n", arr+0, arr+1);
	//// �迭�̳� ����ü�� ��� �ڷ����� ũ�⸸ŭ �ּҰ� �̵���
	//char string[] = "characters";
	//printf("��ȯ�� ��Ʈ�� %s\n", string);
	//convertToUpperCase(string);
	//printf("��ȯ �� ��Ʈ�� %s\n", string);

	int n1, n2, max;
	// ����1. �Լ������+������
	// -1. ū�� ���
	/*intputTwo(&n1, &n2);
	maxNum(n1, n2, &max);
	printf("max = %d", max);*/

	// -2. ��ҹ��� ��ȯ
	/*char c;
	printf("���� �Է�: ");
	scanf_s("%c", &c);
	transChar(&c);
	printf("%c", c);*/

	// -3. 1~n ������ �� ���ϱ�
	/*int n, sum=0;
	printf("���� �Է�: ");
	scanf_s("%d", &n);
	allPlus(n, &sum);
	printf("%d", sum);*/

	// -4. ���ڿ��� ����Ǿ��ִ� �ܾ���� 
	// ù ������&���� ������ ������ ����)�� �빮�ڷ� ��ȯ
	char string[200];
	printf("���ڿ� �Է�: ");
	gets_s(string);
	toUpper(string);
	printf(string);
}