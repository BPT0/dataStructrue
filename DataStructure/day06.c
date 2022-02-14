#include<stdio.h>
#include<stdlib.h>

// --- 포인터와 배열의 관계 ---
// 포인터와 배열은 밀접한 관계를 갖고 있으나, 분명한 차이점이 있다.
// 배열은 선언하게 되면 기본적으로 배열 자기 자신의 시작 주소를 갖고 있다.
// 포인터와 배열은 둘 다 주소를 가지고 연산을 진행하기 때문에 포인터를 배열처럼 접근할 수 있다.

// --- 동적 할당 ---
// 프로그램 중간에 메모리 공간의 크기를 지정해서 할당 받고 그공간을 사용 후, 원하는 시점에 해제하는 방식
// 메모리 공간을 할당 받을 때는 malloc() 함수를 사용해서 할당 받을 수 있다.
// 이때, 반드시 stdlib.h 헤더파일(c언어에서 추가기능을 담고있는)을 선언해줘야 한다.
// malloc()함수의 원형: 주소를 저장할 변수 = (저장할 변수의 자료형)malloc(크기);
// 동적 할당을 통해서 할당 받은 메모리 공간은 Heap영역에 해당한다.
// 동적 할당 받은 메모리 공간을 해제할 때는 free(해제할 공간의 주소); 형식으로 해제할 수 있다..
// 한 번의 동적 할당에는 반드시 한 번의 동적 해제가 진행되야 한다.
// malloc()함수에서 크기를 넘겨줄 때는 기본적으로 sizeof()연산자를 이용해서 넘겨준다.

int main() 
{
	// 실습1. 문자열의 입출력, 문자열 주소 출력
	/*char str[10];

	printf("str의 주소: %p\n", &str);
	printf("str의 값: %p\n", str);

	printf("입력: ");
	scanf("%s", str);
	
	printf("출력: %s\n", str);*/

	// 실습2. 문자열의 특징, 포인터와 배열의 관계
	// 1. 끝에 NULL 문자가 삽입된다.
	// 2. 포인터로 특정 문자열을 저장할 수 있다.
	// 배열은 자기 자신의 공간 사용
	// 포인터는 다른 공간을 생성해 사용함
	/*char str1[10] = "Hello";
	char* str2 = "Abcde"; */

	/*printf("str1: %s\n", str1);
	printf("str1: %s\n", str2);*/

	/*printf("str1: ");
	for (int i = 0; i < 5; i++){
		printf("%c", str1[i]);
	}
	printf("\nstr2: ");
	for (int i = 0; i < 5; i++) {
		printf("%c", str2[i]);
	}*/

	// 3. 포인터와 배열의 차이
	// -1. 리터럴 상수 형태로 저장 되었기 때문에 포인터가 가르킨 값은 변경할 수 없다
	/*str1[0] = 'B';
	str2[0] = 'Z';*/

	// 실습3. 동적할당 기초- 초기화, 해제
	// 주소를 저장할 변수(저장할 공간의 자료형* 변수명) = malloc(크기);
	// malloc 의 반환 값이 void* 이기 때문에 int*로 강제 형변환을 하여야 한다. 
	/*int* ptr = (int*)malloc(4);

	*ptr = 10;
	printf("출력: %d\n", *ptr);

	free(ptr);*/

	// 1. 여러개의 공간을 할당- sizeof(자료형), 인덱스로 접근
	/*int* ptr = (int*)malloc(sizeof(int)*34);
	ptr[0] = 10;
	ptr[1] = 20;

	printf("출력: %d %d\n", ptr[0], ptr[1]);

	free(ptr);*/

	// 문제1. 동적할당-사이즈 입력받아 영단어 입력*출력(역순)
	int size;
	
	printf("영단어 길이 입력: ");
	scanf("%d", &size);

	char* cPtr = (char*)malloc(sizeof(char) * size+1);
	
	printf("영단어 입력: ");
	scanf("%s", cPtr);
	
	printf("영단어 출력: ");
	for (int i = size-1; i >=0; i--){
		printf("%c", cPtr[i]);
	}

	free(cPtr);

	return 0;
}