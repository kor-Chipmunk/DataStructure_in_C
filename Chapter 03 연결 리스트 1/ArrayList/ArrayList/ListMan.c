#include "ArrayList.h"

/*
void ArrayListMain()
{
	// ArrayList의 생성 및 초기화
	List list;
	int data, i, sum = 0;
	ListInit(&list);

	// 5개의 데이터 저장
	// LInsert(&list, 11);  LInsert(&list, 11);
	// LInsert(&list, 22);  LInsert(&list, 22);
	// LInsert(&list, 33);

	// 1부터 9까지 데이터 저장
	for (i = 0; i < 9; i++)
		LInsert(&list, i + 1);

	// 저장된 데이터의 전체 출력
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data))    // 첫 번째 데이터 조회
	{
		// sum 추가
		printf("%d ", data);
		sum += data;

		while (LNext(&list, &data)) {    // 두 번째 이후의 데이터 조회
			printf("%d ", data);
			sum += data;
		}
	}
	printf("총 더한 값 : %d\n\n", sum);

	// 숫자 22을 탐색하여 모두 삭제
	if (LFirst(&list, &data))
	{
		// 2의 배수 또는 3의 배수이면 삭제
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

	// 삭제 후 저장된 데이터 전체 출력
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
}
*/

/*
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
*/

void NameCardListMain()
{
	List list;
	NameCard * pnamecard;
	ListInit(&list);

	// 3개의 데이터 저장 //
	printf("[ 3개 데이터 저장 ]\n");
	pnamecard = MakeNameCard("김선재", "010-1234-5678");
	LInsert(&list, pnamecard);

	pnamecard = MakeNameCard("엄마", "010-1357-2468");
	LInsert(&list, pnamecard);

	pnamecard = MakeNameCard("아빠", "010-2468-1357");
	LInsert(&list, pnamecard);

	// 저장된 데이터의 출력 //
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &pnamecard))
	{
		// ShowNameCardInfo(pnamecard);
		if (!NameCompare(pnamecard, "엄마"))
		{
			printf("[ 변경 전 ]\n");
			ShowNameCardInfo(pnamecard);					// 변경 전
			ChangePhoneNum(pnamecard, "010-0000-0000");
			printf("[ 변경 후 ]\n");
			ShowNameCardInfo(pnamecard);					// 변경 후

			pnamecard = LRemove(&list);
			free(pnamecard);
		}

		while (LNext(&list, &pnamecard))
		{
			if (!NameCompare(pnamecard, "엄마"))
			{
				printf("[ 변경 전 ]\n");
				ShowNameCardInfo(pnamecard);					// 변경 전
				ChangePhoneNum(pnamecard, "010-0000-0000");
				printf("[ 변경 후 ]\n\n");
				ShowNameCardInfo(pnamecard);					// 변경 후
				printf("\n");

				pnamecard = LRemove(&list);
				free(pnamecard);
			}
		}
	}

	// 삭제 후 남은 데이터 전체 출력 //
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &pnamecard))
	{
		ShowNameCardInfo(pnamecard);

		while (LNext(&list, &pnamecard))
			ShowNameCardInfo(pnamecard);
	}
	printf("\n");
}

int main(void)
{
	// ArrayListMain();
	// PointListMain();
	NameCardListMain();
	return 0;
}