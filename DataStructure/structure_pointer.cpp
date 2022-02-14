#include<stdio.h>
#include<string.h>
// 사용자 정의 자료형 = 구조체
// typedef : 타입을 정의한다, 구조체 하단에도 명시 가능
typedef struct student{
	char name[20];
	int age;
}ST;
ST func(ST a) {
	printf("이름 입력: ");
	scanf_s("%s", a.name, sizeof(a.name));
	printf("나이 입력: ");
	scanf_s("%d", &a.age);
	return a;
}

struct test {
	int num;
	char str[100];
	float fl;
};
typedef struct test T; // 아래쪽에 명시 가능
void input(T* a) {
	(*a).num = 12345;
	a->fl = 1.123; // 위의 연산을 ->(에로우)연산자로 간단하게 합칠수 있다.
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
	// 실습1. 구조체 기초
	//struct student s;
	//ST ss; // 위와 동일한 형태의 구조체를 생성하는 코드라고 볼 수 있음
	//s.age = 12345;
	//printf("%d\n", s.age);
	//
	//strcpy_s(ss.name, sizeof(ss.name), "test");
	//printf("%s\n", ss.name);
	//ST b= func(ss);                                                  
	//printf("입력 값 출력입니다\n");
	//printf("이름: %s 나이: %d", b.name, b.age);

	// 실습2. 구조체+포인터
	/*T t;
	input(&t);
	printf("%d\n", t.num);
	printf("%.2f\n", t.fl);*/

	// 실습 3. 자기참조 구조체-feat.포인터
	/*int a;
	int* pa = &a;
	aaa aa;
	aaa* pp = &aa;
	
	aaa a1, a2, a3;
	a1.num = 12345;
	a2.link = &a1;
	a3.link = &a2;
	printf("%d\n", a3.link->link->num);*/

	// 실습 4. 구조체 + 배열
	/*int arr[5] = { 10, 20, 30, 40, 50 };
	IF in[5] = {
		"홍길동", 20,
		"김개똥", 30,
		"고도리", 40,
		"고길동", 50,
		"김길이", 60
	};
	for (int i = 0; i < 5; i++)
	{
		printf("이름: %s 나이: %d\n", in[i].name, in[i].age);
	}*/

	// 실습5. 문자열 비교 함수
	char arr[10] = "test", arr1[10] = "test";
	printf("%d", strcmp(arr, arr1));
	if (strcmp(arr, arr1)==0) {
		printf("두 문자열은 같다");
	}
	else {
		printf("다르다");
	}
}