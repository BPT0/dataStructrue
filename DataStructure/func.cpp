#include<stdio.h>
// ---�Լ�: ����� ������ ������ �Լ� ---
// ��ȯ�ڷ��� �Լ��� (���μ�) {
//		�Լ� ����
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
//	printf("%s\n", s); // �ش� ���ڿ��� ã�ư��� null�� ������ ���
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
	// ���꺸�ٴ� �Լ� ȣ���� �켱��
	// ȣ���ߴ� �������� ���� ��ȯ�Ѵ�
}
void input(int* n1, int* n2) {
	printf("�� �Է�: ");
	scanf_s("%d %d", n1, n2);
}
void inputOne(int* n1) {
	printf("�� �Է�: ");
	scanf_s("%d", n1);
}
void output(int n) {
	printf("%d", n);
}
void outputDecimal(int n) {
	if (n == 2)printf("�Է� ���� �Ҽ���");
	else printf("�Ҽ��� �ƴ�");
}
void outputThree(int n) {
	printf("%d ", n);
	return outputThree(n/3);
}
int bigger(int n1, int n2) {
	// 1.ū�� ��ȯ
	if (n1 > n2) return n1;
	else return n2;
}
void isOdd(int n) {
	output(n);
	printf("Ȧ��\n");
}
void isEven(int n) {
	output(n);
	printf("¦��\n");
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
	// �ǽ�1. �Լ�(int��) �Ű�����, ��ȯ��
	/*int i, n, sum = 0;
	printf("�� �Է�: ");
	scanf_s("%d", &n);
	sum = sumFunc(n);
	printf("%d\n", sum);*/
	
	// �ǽ�2. �Լ�, �迭*�����Ͱ� �Ű������϶�
	/*char str[] = "test";
	int arr[] = { 10,20,30,40,50 };
	func(str, arr);
	int a = 100;
	func2(&a);*/
	// return 0;
	// ������ �ۼ����� �ʾƵ� ����� ��Ʃ������� 
	// �ڵ����� ó�����ֱ� ������ ������ ����

	// �ǽ�3. �Լ�, �Լ��� ȣ���Ҷ��� �⺻������ ���� ���簡 �Ͼ
	/*int a = 5, b = 10;
	func(a, b);
	printf("%d, %d\n", a, b);*/

	// �ǽ�4. ����Լ�
	/*int x = 5;
	printf("%d�� ���� %d �̴�\n", x, fact(x));*/
	

	// ����1. �Է�, ���, ���� �Լ� �ۼ�
	int n1, n2;
	// input(&n1, &n2);
	// output(bigger(n1, n2));
	// difPO(n1, n2);
	
	// -2. 3�� ����� ����
	/*inputOne(&n1);
	if (isThreeMul(n1)) output(n1);*/

	// -3. �Ҽ� �Ǻ��ϱ� 
	/*inputOne(&n1);
	outputDecimal(isDecimal(n1));*/

	//-4. �������� ��ȯ�ϱ�
	 inputOne(&n1);
	 output(toAbsVar(n1));
}