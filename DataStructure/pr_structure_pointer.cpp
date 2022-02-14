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
			printf("사용중인 ID입니다.\n");
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
				printf("인증을 통과했습니다.\n");
				printf("감사합니다.\n");
				return 1;
			}
			else {
				printf("비밀번호가 틀렸습니다!!!\n");
				return 0;
			}
		}
	}
	printf("유효하지 않은 ID입니다!!!\n");
	return 0;
}
int delUser(I* info, char* id, char* pwd, int mCnt) {
	for (int i = 0; i < mCnt+1; i++){
		if (!strcmp(info[i].id, id) && !strcmp(info[i].pwd, pwd) 
			&& info[i].use == 1) {
			info[i].use == 0;
			strcpy(info[i].id, "");
			strcpy(info[i].pwd, "");
			printf("탈퇴 성공\n");
			return 1;
		}
	}
	printf("탈퇴 실패\n");
	return 0;
}
int adminStu(M* stu, char* stNum, int scnt) {
	int i;
	for (i = 0; i < scnt+1; i++){
		if (!strcmp(stu[i].stNum, stNum) && stu[i].use==1) {
			printf("해당 학번은 이미 존재합니다\n");
			return 0;
		}
	}
	for (i = 0; i < scnt+1; i++){
		if (stu[i].use == 0) {
			printf("이름: ");
			scanf_s("%s", stu[i].name, 20);
			printf("나이: ");
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
			printf("수정할 이름을 입력하세요: ");
			scanf_s("%s", stu[i].name, 20);
			printf("학생 이름이 %s로 수정되었습니다.\n", stu[i].name);
			return 1;
		}
	}
	printf("해당 학생은 존재하지 않습니다\n");
	return 0;
}
int delStu(M* stu, char* stNum, int scnt) {
	int i, sel, age, nCnt=0, aCnt=0;
	char name[20], stnum[20];
	if (scnt == 0) {
		printf("학생 1명도 존재하지 않음\n");
		return 0;
	}
	for (i = 0; i < scnt+1; i++){
		if (!strcmp(stu[i].stNum, stNum) && stu[i].use == 1) {
			stu[i].use = 0;
			strcpy(stu[i].name, "");
			stu[i].age = 0;
			printf("%s학번 학생 삭제 성공\n", stu[i].stNum);
			return 1;
		}
	}
	// 이름과 나이로도 검색 -> 선택 -> 삭제
	printf("해당 학번은 존재하지 않습니다.");
	printf("1.이름으로 검색\n 2.나이로 검색: ");
	scanf_s("%d", &sel);
	switch (sel)
	{
		case 1:
			printf("이름 입력: ");
			scanf_s("%s", name);
			for (i = 0; i < scnt + 1; i++) {
				if (!strcmp(stu[i].name, name) && stu[i].use == 1) {
					nCnt++;
				}
			}
			// 이름 같은거 1개
			if (nCnt <= 1) {
				if (!strcmp(stu[i].name, name) && stu[i].use == 1) {
					for (i = 0; i < scnt + 1; i++) {
						stu[i].use = 0;
						strcpy(stu[i].name, "");
						stu[i].age = 0;
						printf("%s학생 삭제 성공\n", stu[i].name);
						return 1;
					}
				}
			}
			else {
				// 이름 같은거 2개 이상
				for (i = 0; i <= nCnt; i++) {
					if (!strcmp(stu[i].name, name) && stu[i].use == 1) {
						printf("%s학생, 학번: %s, 나이: %d, 존재여부: %d\n", stu[i].name, stu[i].stNum,
							stu[i].age, stu[i].use);
					}
				}
				printf("삭제할 학생의 학번: ");
				scanf_s("%s", stnum, 20);
				for (i = 0; i < scnt + 1; i++) {
					if (!strcmp(stu[i].stNum, stnum) && stu[i].use == 1) {
						stu[i].use = 0;
						strcpy(stu[i].name, "");
						stu[i].age = 0;
						printf("%s학번 학생 삭제 성공\n", stu[i].stNum);
						return 1;
					}
				}
			}
		case 2:
			printf("나이 입력: ");
			scanf_s("%d", &age);
			for (i = 0; i < scnt + 1; i++) {
				if (stu[i].age!=0 && stu[i].use == 1) {
					nCnt++;
				}
			}
			// 나이 1개
			if (nCnt <= 1) {
				for (i = 0; i < scnt + 1; i++) {
					if (stu[i].age != 0 && stu[i].use == 1) {
						stu[i].use = 0;
						strcpy(stu[i].name, "");
						stu[i].age = 0;
						printf("%s학번 학생 삭제 성공\n", stu[i].stNum);
						return 1;
					}
				}
			}
			else {
				// 동일 나이 2개 이상
				for (i = 0; i <= nCnt; i++) {
					if (stu[i].age != 0 && stu[i].use == 1) {
						printf("%s학생, 학번: %s, 나이: %d, 존재여부: %d\n", stu[i].name, stu[i].stNum,
							stu[i].age, stu[i].use);
					}
				}
				printf("삭제할 학생의 학번: ");
				scanf_s("%s", stnum, 20);
				for (i = 0; i < scnt + 1; i++) {
					if (stu[i].age != 0 && stu[i].use == 1) {
						stu[i].use = 0;
						strcpy(stu[i].name, "");
						stu[i].age = 0;
						printf("%s학번 학생 삭제 성공\n", stu[i].stNum);
						return 1;
					}
				}
			}
		default:
			printf("올바른 번호를 선택하세요...\n");
			return 0;
	}
	

	printf("학생 삭제 실패\n");
	return 0;
}
int searchStu(M* stu, char* name, int scnt) {
	for (int i = 0; i < scnt + 1; i++) {
		if (!strcmp(stu[i].name, name) && stu[i].use == 1) {
			printf("%s학생 정보: 1.학생 존재 여부: %d\n", stu[i].name, stu[i].use);
			return 1;
		}
	}
	printf("%s학생이 존재하지 않음\n", name);
	return 0;
}
void allStu(M* stu, char* name, int scnt) {
	if (scnt == 0) {
		printf("학생 존재하지 않음\n");
		return;
	}
	for (int i = 0; i < scnt; i++){
		printf("%s학생: 1.존재여부: %d\n", stu[i].name, stu[i].use);
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
		printf("원하는 기능을 선택하세요.\n");
		printf("1. 로그온\n");
		printf("2. 회원 가입\n");
		printf("3. 회원 탈퇴\n");
		printf("4. 종료\n");
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
				printf("ID의 길이가 너무 짧음.\n");
				system("pause");
				continue;
			}
			printf("Password: ");
			scanf_s("%s", pwd, 20);
			if (strlen(pwd) < 1) {
				printf("Password의 길이가 너무 짧음.\n");
				system("pause");
				continue;
			}
			if (addUser(info, id, pwd, mCnt)) {
				mCnt++;
				printf("등록 성공\n");
			}
			else printf("등록 실패\n");
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
			printf("---학생관리 프로그램---\n");
			printf("원하는 기능을 선택하세요.\n");
			printf("1. 학생 등록\n");
			printf("2. 학생 수정\n");
			printf("3. 학생 삭제\n");
			printf("4. 검색-학생정보 보기\n");
			printf("5. 모든 학생정보 보기\n");
			printf("6. 종료\n");
			printf("Select...");
			scanf_s("%d", &msel);
			fflush(stdin);
			switch (msel)
			{
			case 1:
				// 학번 -> 이름, 나이 입력하도록 수정
				printf("학번 입력: ");
				scanf_s("%s", stNum, 20);
				if (adminStu(stu, stNum, sCnt)) {
					printf("등록 성공\n");
					sCnt++;
				}
				else printf("등록 실패\n");
				break;
			case 2:
				printf("학번 입력: ");
				scanf_s("%s", stNum, 20);
				editStu(stu, stNum, sCnt);
				break;
			case 3:
				printf("학번 입력: ");
				scanf_s("%s", stNum, 20);
				if (delStu(stu, stNum, sCnt))sCnt--;
				break;
			case 4:
				printf("학번 입력: ");
				scanf_s("%s", stNum, 20);
				searchStu(stu, stNum, sCnt);
				break;
			case 5:
				printf("---모든 학생 정보---\n");
				allStu(stu, stNum, sCnt);
				break;
			default:
				break;
			}
			system("pause");
		} while (msel != 6);
		printf("학생 관리 프로그램 종료...\n");
	}
	system("cls");
	printf("로그인이 되어있지 않음\n");
}