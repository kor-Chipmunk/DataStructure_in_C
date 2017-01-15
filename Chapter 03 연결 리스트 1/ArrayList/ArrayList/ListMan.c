#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	/*** ArrayList�� ���� �� �ʱ�ȭ ***/
	List list;
	int data, i, sum = 0;
	ListInit(&list);

	/*** 5���� ������ ���� ***/
	/*
	LInsert(&list, 11);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 22);
	LInsert(&list, 33);
	*/

	/* 1���� 9���� ������ ���� */
	for (i = 0; i < 9; i++)
		LInsert(&list, i + 1);

	/*** ����� �������� ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data))    // ù ��° ������ ��ȸ
	{
		/* sum �߰� */
		printf("%d ", data);
		sum += data;

		while (LNext(&list, &data)) {    // �� ��° ������ ������ ��ȸ
			printf("%d ", data);
			sum += data;
		}
	}
	printf("�� ���� �� : %d\n\n", sum);

	/*** ���� 22�� Ž���Ͽ� ��� ���� ***/
	if (LFirst(&list, &data))
	{
		/* 2�� ��� �Ǵ� 3�� ����̸� ���� */
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);
		// if (data == 22)
		//	LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
		}
	}

	/*** ���� �� ����� ������ ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}