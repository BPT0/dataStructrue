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
	// 실습1. 포인터 기초
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

	// 실습2. 함수+포인터
	int num = 1000;
	func(&num);

	// 실습3. 형변환
	int test = 100;
	char* ch = (char*)&test;
	printf("안녕하세요");
	char arr[] = "test";
	printf(arr);
	char c = 'A';
	printf(&c);

}