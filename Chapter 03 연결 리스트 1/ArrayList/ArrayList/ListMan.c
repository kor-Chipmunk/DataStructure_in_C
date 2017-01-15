#include <stdio.h>
#include "ArrayList.h"

void ArrayListMain()
{
	/*** ArrayList의 생성 및 초기화 ***/
	List list;
	int data, i, sum = 0;
	ListInit(&list);

	/*** 5개의 데이터 저장 ***/
	/*
	LInsert(&list, 11);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 22);
	LInsert(&list, 33);
	*/

	/* 1부터 9까지 데이터 저장 */
	for (i = 0; i < 9; i++)
		LInsert(&list, i + 1);

	/*** 저장된 데이터의 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data))    // 첫 번째 데이터 조회
	{
		/* sum 추가 */
		printf("%d ", data);
		sum += data;

		while (LNext(&list, &data)) {    // 두 번째 이후의 데이터 조회
			printf("%d ", data);
			sum += data;
		}
	}
	printf("총 더한 값 : %d\n\n", sum);

	/*** 숫자 22을 탐색하여 모두 삭제 ***/
	if (LFirst(&list, &data))
	{
		/* 2의 배수 또는 3의 배수이면 삭제 */
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

	/*** 삭제 후 저장된 데이터 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

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

	// 4개의 데이터 저장 //
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

	// 저장된 데이터의 출력 //
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	// xpos가 2인 모든 데이터 삭제 //
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

	// 삭제 후 남은 데이터 전체 출력 //
	printf("현재 데이터의 수: %d \n", LCount(&list));

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