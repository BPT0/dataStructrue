#include<stdio.h>

void func2(int* a) {
	printf("a: %d\n", *a);
}

void func1(int** a) {
	func2(*a);
}

void func(int *a) {
	func1(&a);
}
int main() {
	// �ǽ�1. ������ ����
	/*char a;
	char* pa;
	pa = &a;
	*pa = 12345;
	printf("a : %d\n", a);
	printf("*pa : %d\n", *pa);
	
	int n = 100;
	int* pn = &n;
	int** ppn = &pn;
	int*** pppn = &ppn;*/

	// �ǽ�2. �Լ�+������
	int num = 1000;
	func(&num);

	// �ǽ�3. ����ȯ
	int test = 100;
	char* ch = (char*)&test;
	printf("�ȳ��ϼ���");
	char arr[] = "test";
	printf(arr);
	char c = 'A';
	printf(&c);

}