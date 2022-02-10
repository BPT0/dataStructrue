#include<stdio.h>

void convertToUpperCase(char* s) {
	while (*s != NULL) {
		if(*s>='a'&& *s<='z')
			*s = *s - 32; // 아스키 코드표의 값 연산
		++s;
	}
}

void intputTwo(int* n1, int* n2) {
	printf("두 수 입력: ");
	scanf_s("%d %d", &n1, &n2);
}

void maxNum(int n1, int n2, int* max) {
	(n1 > n2) ? (*max = n1) : (*max = n2);
}

void transChar(char* c) {
	if (*c >= 'a' && *c <= 'z') *c -= 32;
	else if (*c >= 'A' && *c <= 'Z') *c += 32;
	else printf("해당문자는 영어 대*소문자가 아닙니다.");
}

void allPlus(int n, int* sum) {
	for (int i = 1; i <= n; i++) *sum += i;
}

void toUpper(char* s) {
	// 처음 문자 대문자로 변경
	if (*s>='a' && *s <= 'z') {
		*s -= 32;
	}
	s++;
	// 1.널문자가 들어오면 종료
	// 2.이전문자가 공백 문자라면 대문자로 변경
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
	// 실습1. 배열의 주소값을 이용하여 값변경
	//int arr[] = { 10, 20, 30, 40, 50 };
	//int *p = arr;
	//// 배열명은 값을 변경할 수 없는 포인터 상수이다.
	//printf("%d %d\n", p[0], p[1]);
	//printf("%d %d\n", *(arr+0), *(arr+1));
	//printf("%p, %p\n", &p[0], &p[1]);
	//printf("%p, %p\n", arr+0, arr+1);
	//// 배열이나 구조체일 경우 자료형의 크기만큼 주소가 이동함
	//char string[] = "characters";
	//printf("변환전 스트린 %s\n", string);
	//convertToUpperCase(string);
	//printf("변환 후 스트링 %s\n", string);

	int n1, n2, max;
	// 문제1. 함수입출력+포인터
	// -1. 큰수 출력
	/*intputTwo(&n1, &n2);
	maxNum(n1, n2, &max);
	printf("max = %d", max);*/

	// -2. 대소문자 변환
	/*char c;
	printf("문자 입력: ");
	scanf_s("%c", &c);
	transChar(&c);
	printf("%c", c);*/

	// -3. 1~n 까지의 합 구하기
	/*int n, sum=0;
	printf("숫자 입력: ");
	scanf_s("%d", &n);
	allPlus(n, &sum);
	printf("%d", sum);*/

	// -4. 문자열에 저장되어있는 단어들의 
	// 첫 영문자&앞의 공백을 포함한 문자)만 대문자로 변환
	char string[200];
	printf("문자열 입력: ");
	gets_s(string);
	toUpper(string);
	printf(string);
}