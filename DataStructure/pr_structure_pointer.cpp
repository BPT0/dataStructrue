#include<stdio.h>
#include<string.h>
#include<Windows.h>
#define MAX_INFO 100
typedef struct user {
	char id[20];
	char pwd[20];
	int use;
	int isLogin;
}I;
typedef struct manager {
	char name[20], stNum[20];
	int use, age;
}M;
int addUser(I* info, char* id, char* pwd, int cnt) {
	int i;
	for (i = 0; i < cnt+1; i++){
		if (info[i].use == 1 && !strcmp(info[i].id, id)) {
			printf("������� ID�Դϴ�.\n");
			return 0;
		}
	}
	for (i = 0; i < cnt+1; i++){
		if (info[i].use == 0) {
			info[i].use = 1;
			strcpy(info[i].id, id);
			strcpy(info[i].pwd, pwd);
			return 1;
		}
	}
	return 0;
}
int checkUser(I* info, char* id, char* pwd, int mCnt) {
	int i;
	for (i = 0; i < mCnt+1; i++){
		if (info[i].use == 1 && !strcmp(info[i].id, id)) {
			if (!strcmp(info[i].pwd, pwd)) {
				printf("������ ����߽��ϴ�.\n");
				printf("�����մϴ�.\n");
				return 1;
			}
			else {
				printf("��й�ȣ�� Ʋ�Ƚ��ϴ�!!!\n");
				return 0;
			}
		}
	}
	printf("��ȿ���� ���� ID�Դϴ�!!!\n");
	return 0;
}
int delUser(I* info, char* id, char* pwd, int mCnt) {
	for (int i = 0; i < mCnt+1; i++){
		if (!strcmp(info[i].id, id) && !strcmp(info[i].pwd, pwd) 
			&& info[i].use == 1) {
			info[i].use == 0;
			strcpy(info[i].id, "");
			strcpy(info[i].pwd, "");
			printf("Ż�� ����\n");
			return 1;
		}
	}
	printf("Ż�� ����\n");
	return 0;
}
int adminStu(M* stu, char* stNum, int scnt) {
	int i;
	for (i = 0; i < scnt+1; i++){
		if (!strcmp(stu[i].stNum, stNum) && stu[i].use==1) {
			printf("�ش� �й��� �̹� �����մϴ�\n");
			return 0;
		}
	}
	for (i = 0; i < scnt+1; i++){
		if (stu[i].use == 0) {
			printf("�̸�: ");
			scanf_s("%s", stu[i].name, 20);
			printf("����: ");
			scanf_s("%d", &stu[i].age);
			stu[i].use = 1;
			return 1;
		}
	}
	return 0;
}
int editStu(M* stu, char* stNum, int scnt) {
	int i;
	for (i = 0; i < scnt+1; i++){
		if (stu[i].use == 1 && !strcmp(stu[i].stNum, stNum)) {
			printf("������ �̸��� �Է��ϼ���: ");
			scanf_s("%s", stu[i].name, 20);
			printf("�л� �̸��� %s�� �����Ǿ����ϴ�.\n", stu[i].name);
			return 1;
		}
	}
	printf("�ش� �л��� �������� �ʽ��ϴ�\n");
	return 0;
}
int delStu(M* stu, char* stNum, int scnt) {
	int i, sel, age, nCnt=0, aCnt=0;
	char name[20], stnum[20];
	if (scnt == 0) {
		printf("�л� 1�� �������� ����\n");
		return 0;
	}
	for (i = 0; i < scnt+1; i++){
		if (!strcmp(stu[i].stNum, stNum) && stu[i].use == 1) {
			stu[i].use = 0;
			strcpy(stu[i].name, "");
			stu[i].age = 0;
			printf("%s�й� �л� ���� ����\n", stu[i].stNum);
			return 1;
		}
	}
	// �̸��� ���̷ε� �˻� -> ���� -> ����
	printf("�ش� �й��� �������� �ʽ��ϴ�.");
	printf("1.�̸����� �˻�\n 2.���̷� �˻�: ");
	scanf_s("%d", &sel);
	switch (sel)
	{
		case 1:
			printf("�̸� �Է�: ");
			scanf_s("%s", name);
			for (i = 0; i < scnt + 1; i++) {
				if (!strcmp(stu[i].name, name) && stu[i].use == 1) {
					nCnt++;
				}
			}
			// �̸� ������ 1��
			if (nCnt <= 1) {
				if (!strcmp(stu[i].name, name) && stu[i].use == 1) {
					for (i = 0; i < scnt + 1; i++) {
						stu[i].use = 0;
						strcpy(stu[i].name, "");
						stu[i].age = 0;
						printf("%s�л� ���� ����\n", stu[i].name);
						return 1;
					}
				}
			}
			else {
				// �̸� ������ 2�� �̻�
				for (i = 0; i <= nCnt; i++) {
					if (!strcmp(stu[i].name, name) && stu[i].use == 1) {
						printf("%s�л�, �й�: %s, ����: %d, ���翩��: %d\n", stu[i].name, stu[i].stNum,
							stu[i].age, stu[i].use);
					}
				}
				printf("������ �л��� �й�: ");
				scanf_s("%s", stnum, 20);
				for (i = 0; i < scnt + 1; i++) {
					if (!strcmp(stu[i].stNum, stnum) && stu[i].use == 1) {
						stu[i].use = 0;
						strcpy(stu[i].name, "");
						stu[i].age = 0;
						printf("%s�й� �л� ���� ����\n", stu[i].stNum);
						return 1;
					}
				}
			}
		case 2:
			printf("���� �Է�: ");
			scanf_s("%d", &age);
			for (i = 0; i < scnt + 1; i++) {
				if (stu[i].age!=0 && stu[i].use == 1) {
					nCnt++;
				}
			}
			// ���� 1��
			if (nCnt <= 1) {
				for (i = 0; i < scnt + 1; i++) {
					if (stu[i].age != 0 && stu[i].use == 1) {
						stu[i].use = 0;
						strcpy(stu[i].name, "");
						stu[i].age = 0;
						printf("%s�й� �л� ���� ����\n", stu[i].stNum);
						return 1;
					}
				}
			}
			else {
				// ���� ���� 2�� �̻�
				for (i = 0; i <= nCnt; i++) {
					if (stu[i].age != 0 && stu[i].use == 1) {
						printf("%s�л�, �й�: %s, ����: %d, ���翩��: %d\n", stu[i].name, stu[i].stNum,
							stu[i].age, stu[i].use);
					}
				}
				printf("������ �л��� �й�: ");
				scanf_s("%s", stnum, 20);
				for (i = 0; i < scnt + 1; i++) {
					if (stu[i].age != 0 && stu[i].use == 1) {
						stu[i].use = 0;
						strcpy(stu[i].name, "");
						stu[i].age = 0;
						printf("%s�й� �л� ���� ����\n", stu[i].stNum);
						return 1;
					}
				}
			}
		default:
			printf("�ùٸ� ��ȣ�� �����ϼ���...\n");
			return 0;
	}
	

	printf("�л� ���� ����\n");
	return 0;
}
int searchStu(M* stu, char* name, int scnt) {
	for (int i = 0; i < scnt + 1; i++) {
		if (!strcmp(stu[i].name, name) && stu[i].use == 1) {
			printf("%s�л� ����: 1.�л� ���� ����: %d\n", stu[i].name, stu[i].use);
			return 1;
		}
	}
	printf("%s�л��� �������� ����\n", name);
	return 0;
}
void allStu(M* stu, char* name, int scnt) {
	if (scnt == 0) {
		printf("�л� �������� ����\n");
		return;
	}
	for (int i = 0; i < scnt; i++){
		printf("%s�л�: 1.���翩��: %d\n", stu[i].name, stu[i].use);
	}
	return;
}
int main() {
	int sel, mCnt = 0, logon = 0;
	char id[20], pwd[20];
	I info[MAX_INFO];
	for (int i = 0; i < MAX_INFO; i++){
		info[i].use = 0;
	}
	do
	{
		system("cls");
		printf("���ϴ� ����� �����ϼ���.\n");
		printf("1. �α׿�\n");
		printf("2. ȸ�� ����\n");
		printf("3. ȸ�� Ż��\n");
		printf("4. ����\n");
		printf("Select...");
		scanf_s("%d", &sel);
		fflush(stdin);
		switch (sel)
		{
		case 1:
			printf("ID: ");
			scanf_s("%s", id, 20);
			printf("Password: ");
			scanf_s("%s", pwd, 20);
			if (checkUser(info, id, pwd, mCnt)) {
				sel = 4;
				logon = 1;
				break;
			}
			break;
		case 2:
			printf("ID: ");
			scanf_s("%s", id, 20);
			if (strlen(id) < 1) {
				printf("ID�� ���̰� �ʹ� ª��.\n");
				system("pause");
				continue;
			}
			printf("Password: ");
			scanf_s("%s", pwd, 20);
			if (strlen(pwd) < 1) {
				printf("Password�� ���̰� �ʹ� ª��.\n");
				system("pause");
				continue;
			}
			if (addUser(info, id, pwd, mCnt)) {
				mCnt++;
				printf("��� ����\n");
			}
			else printf("��� ����\n");
			break;
		case 3:
			printf("ID: ");
			scanf_s("%s", id, 20);
			printf("Password: ");
			scanf_s("%s", pwd, 20);
			if (delUser(info, id, pwd, mCnt)) {
				mCnt--;
			}
			break;
		default:
			break;
		}
		if (!logon) continue;
		system("pause");
	} while (sel!=4);
	
	if (logon) {
		M stu[MAX_INFO];
		char stNum[20];
		int sCnt = 0, msel;
		for (int i = 0; i < MAX_INFO; i++) {
			stu[i].use = 0;
			stu[i].age = 0;
		}
		do
		{
			system("cls");
			printf("---�л����� ���α׷�---\n");
			printf("���ϴ� ����� �����ϼ���.\n");
			printf("1. �л� ���\n");
			printf("2. �л� ����\n");
			printf("3. �л� ����\n");
			printf("4. �˻�-�л����� ����\n");
			printf("5. ��� �л����� ����\n");
			printf("6. ����\n");
			printf("Select...");
			scanf_s("%d", &msel);
			fflush(stdin);
			switch (msel)
			{
			case 1:
				// �й� -> �̸�, ���� �Է��ϵ��� ����
				printf("�й� �Է�: ");
				scanf_s("%s", stNum, 20);
				if (adminStu(stu, stNum, sCnt)) {
					printf("��� ����\n");
					sCnt++;
				}
				else printf("��� ����\n");
				break;
			case 2:
				printf("�й� �Է�: ");
				scanf_s("%s", stNum, 20);
				editStu(stu, stNum, sCnt);
				break;
			case 3:
				printf("�й� �Է�: ");
				scanf_s("%s", stNum, 20);
				if (delStu(stu, stNum, sCnt))sCnt--;
				break;
			case 4:
				printf("�й� �Է�: ");
				scanf_s("%s", stNum, 20);
				searchStu(stu, stNum, sCnt);
				break;
			case 5:
				printf("---��� �л� ����---\n");
				allStu(stu, stNum, sCnt);
				break;
			default:
				break;
			}
			system("pause");
		} while (msel != 6);
		printf("�л� ���� ���α׷� ����...\n");
	}
	system("cls");
	printf("�α����� �Ǿ����� ����\n");
}