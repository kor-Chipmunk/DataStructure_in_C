#include <stdio.h>

/* 하노이 타워 재귀함수 단계
	1. 작은 원반 3개를 (맨 아래의 원반을 제외한 나머지 원반을) A에서 B로 이동
	2. 큰 원반(맨 아래의 원반) 1개를 A에서 C로 이동
	3. 작은 원반(B로 옮겨진 원반) 3개를 B에서 C로 이동
*/

void HanoiTowerMove(int num, char from, char by, char to)
{
	if (num == 1)														// 이동할 원반의 수가 1개라면,
	{
		printf("원반1을 %c에서 %c로 이동\n", from, to);
	}
	else
	{
		HanoiTowerMove(num - 1, from, to, by);							// 3단계 중 1단계
		printf("원반%d을(를) %c에서 %c로 이동\n", num, from, to);		// 3단계 중 2단계
		HanoiTowerMove(num - 1, by, from, to);							// 3단계 중 3단계
	}
}

int main(void) {
	// 막대A의 원반 4개를 막대B를 경유하여 막대 C로 옮기기
	HanoiTowerMove(4, 'A', 'B', 'C');
	return 0;
}