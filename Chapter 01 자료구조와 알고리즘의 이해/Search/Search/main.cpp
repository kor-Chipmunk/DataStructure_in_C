#include <stdio.h>

int LSearch(int ar[], int len, int target)		// ���� Ž�� �˰��� ����� �Լ�
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (ar[i] == target)
			return i;							// ã�� ����� �ε��� �� ��ȯ
	}
	return -1;									// ã�� �������� �ǹ��ϴ� �� ��ȯ
}

int BSearch(int ar[], int len, int target)		// ���� Ž�� �˰��� ����� �Լ�
{
	int first = 0;								// Ž�� ����� ���� �ε��� ��
	int last = len - 1;							// Ž�� ����� ������ �ε��� ��
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;				// Ž�� ����� �߾��� ã�´�.

		if (target == ar[mid])
		{
			return mid;							// Ž�� �Ϸ�!
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

	// å ����
	idx = LSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε��� : %d\n", idx);

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε��� : %d\n", idx);

	while (1)
	{
		printf("ã�� �� : ");
		scanf_s("%d", &target);

		if (target == -1)
			break;

		idx = LSearch(arr, sizeof(arr) / sizeof(int), target);
		if (idx == -1)
			printf("Ž�� ����\n");
		else
			printf("Ÿ�� ���� �ε��� : %d\n", idx);
	}
	*/

	int arr[] = { 1, 3, 5, 7 ,9 };
	int idx;

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε��� : %d\n", idx);

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε��� : %d\n", idx);

	return 0;
}