#include <stdio.h>
#include "ArrayList.h"

void ArrayListMain()
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
}

void PointListMain()
{
	List list;
	Point compPos;
	Point * ppos;

	ListInit(&list);

	// 4���� ������ ���� //
	ppos = (Point *)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point *)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point *)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point *)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	// ����� �������� ��� //
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	// xpos�� 2�� ��� ������ ���� //
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos))
	{
		if (PointComp(ppos, &compPos) == 1)
		{
			ppos = LRemove(&list);
			free(ppos);
		}

		while (LNext(&list, &ppos))
		{
			if (PointComp(ppos, &compPos) == 1)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	// ���� �� ���� ������ ��ü ��� //
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");
}

int main(void)
{
	// ArrayListMain();
	PointListMain();
	return 0;
}