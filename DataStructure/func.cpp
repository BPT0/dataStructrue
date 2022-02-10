#include<stdio.h>
// ---함수: 기능을 가지고 있으면 함수 ---
// 반환자료형 함수명 (가인수) {
//		함수 내용
// }
//
int sumFunc(int n) {
	int i, sum = 0;
	for (i = 0; i <= n; i++)
	{
		sum += i;
	}
	return sum;
}
//void func(char* s, int* a) {
//	printf("%s\n", s); // 해당 문자열을 찾아가서 null값 전까지 출력
//	printf("%d %d\n", a[0], a[1]);
//}
void func(int a, int b) {
	a += 5;
	b *= 10;
	printf("%d, %d\n", a, b);
}
void func2(int* s) {

}
int fact(int n) {
	if (n == 1)
		return 1;
	else
		return n * fact(n - 1);
	// 연산보다는 함수 호출이 우선임
	// 호출했던 지역으로 값을 반환한다
}
void input(int* n1, int* n2) {
	printf("수 입력: ");
	scanf_s("%d %d", n1, n2);
}
void inputOne(int* n1) {
	printf("수 입력: ");
	scanf_s("%d", n1);
}
void output(int n) {
	printf("%d", n);
}
void outputDecimal(int n) {
	if (n == 2)printf("입력 값은 소수임");
	else printf("소수가 아님");
}
void outputThree(int n) {
	printf("%d ", n);
	return outputThree(n/3);
}
int bigger(int n1, int n2) {
	// 1.큰수 반환
	if (n1 > n2) return n1;
	else return n2;
}
void isOdd(int n) {
	output(n);
	printf("홀수\n");
}
void isEven(int n) {
	output(n);
	printf("짝수\n");
}
void difPO(int n1, int n2) {
	if (n1 % 2 == 0) isEven(n1);
	else isOdd(n1);
	if (n2 % 2 == 0) isEven(n2);
	else isOdd(n2);
}
bool isThreeMul(int n1) {
	if (n1 % 3 == 0) return true;
	else return false;
}
int isDecimal(int n1) {
	int cnt=0;
	for (int i = 1; i <= n1 ; i++) {
		if (n1 % i == 0)
			cnt++;
	}
	return cnt;
}
int toAbsVar(int n1) {
	if (n1 < 0) return -n1;
	else return n1;
}
void outputStr(const char str) {
	printf("%s", str);
}
int main() {
	// 실습1. 함수(int형) 매개변수, 반환값
	/*int i, n, sum = 0;
	printf("수 입력: ");
	scanf_s("%d", &n);
	sum = sumFunc(n);
	printf("%d\n", sum);*/
	
	// 실습2. 함수, 배열*포인터가 매개변수일때
	/*char str[] = "test";
	int arr[] = { 10,20,30,40,50 };
	func(str, arr);
	int a = 100;
	func2(&a);*/
	// return 0;
	// 리턴을 작성하지 않아도 비쥬얼 스튜디오에서 
	// 자동으로 처리해주기 때문에 생략이 가능

	// 실습3. 함수, 함수를 호출할때는 기본적으로 값의 복사가 일어남
	/*int a = 5, b = 10;
	func(a, b);
	printf("%d, %d\n", a, b);*/

	// 실습4. 재귀함수
	/*int x = 5;
	printf("%d의 값은 %d 이다\n", x, fact(x));*/
	

	// 문제1. 입력, 출력, 연산 함수 작성
	int n1, n2;
	// input(&n1, &n2);
	// output(bigger(n1, n2));
	// difPO(n1, n2);
	
	// -2. 3의 배수를 구별
	/*inputOne(&n1);
	if (isThreeMul(n1)) output(n1);*/

	// -3. 소수 판별하기 
	/*inputOne(&n1);
	outputDecimal(isDecimal(n1));*/

	//-4. 절댓값으로 변환하기
	 inputOne(&n1);
	 output(toAbsVar(n1));
}