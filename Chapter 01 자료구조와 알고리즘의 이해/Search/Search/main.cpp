#include <stdio.h>

int LSearch(int ar[], int len, int target)		// 순차 탐색 알고리즘 적용된 함수
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (ar[i] == target)
			return i;							// 찾은 대상의 인덱스 값 반환
	}
	return -1;									// 찾지 못했음을 의미하는 값 반환
}

int BSearch(int ar[], int len, int target)		// 이진 탐색 알고리즘 적용된 함수
{
	int first = 0;								// 탐색 대상의 시작 인덱스 값
	int last = len - 1;							// 탐색 대상의 마지막 인덱스 값
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;				// 탐색 대상의 중앙을 찾는다.

		if (target == ar[mid])
		{
			return mid;							// 탐색 완료!
		}
		else
		{
			if (target < ar[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
	}

	return -1;
}

int main(void)
{
	/*
	int arr[] = { 3, 5, 2, 4, 9 };
	int idx, target = -1;

	// 책 예제
	idx = LSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스 : %d\n", idx);

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스 : %d\n", idx);

	while (1)
	{
		printf("찾을 값 : ");
		scanf_s("%d", &target);

		if (target == -1)
			break;

		idx = LSearch(arr, sizeof(arr) / sizeof(int), target);
		if (idx == -1)
			printf("탐색 실패\n");
		else
			printf("타겟 저장 인덱스 : %d\n", idx);
	}
	*/

	int arr[] = { 1, 3, 5, 7 ,9 };
	int idx;

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스 : %d\n", idx);

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스 : %d\n", idx);

	return 0;
}