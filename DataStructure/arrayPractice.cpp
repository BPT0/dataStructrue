#include<stdio.h>

int main()
{
	// 배열이란?
	/*int arr[5] = { 1,2,3,4,5 };
	for (int i = 0; i < sizeof(arr) / 4; i++)
	{
		printf("%d, %u\n", arr[i], &arr[i]);
	}*/

	// 실습1. 오름차순 정렬
	/*int num[5] = { 4,8,2,7,6 };
	int tmp, i, j;
	for ( i = 0; i < 5; i++)
	{
		for ( j = i+1; j < 5; j++)
		{
			if (num[i]>num[j])
			{
				tmp = num[i];
				num[i] = num[j];
				num[j]= tmp;
			}
		}
		printf("%d ", num[i]);
	}*/

	// 문제1. 점수에 따라 등수 산출하기
	int jumsu[5] = { 82,85,76,79,96 };
	int rank[5] = { 1, 1,1,1,1 };
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for ( j = 0; j < 5; j++)
		{
			if (jumsu[i]<jumsu[j])
			{
				rank[i]++;
			}
		}
		printf("점수: %d, 등수: %d\n", jumsu[i], rank[i]);
	}
 }