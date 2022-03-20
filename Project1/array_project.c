# include <stdio.h>
# include <time.h>

int main_array_project(void)
{
	srand(time(NULL));
	printf("\n\n === 병민이는 대머리 게임 === \n\n");
	int answer; // 사용자 입력값
	int treatment = rand() % 4; // 발모제 선택(정답 설정) (0~3)

	int cntShowBottle = 0; // 이번 시도에 보여줄 병 갯수
	int prevCntShowBottle = 0; // 앞 시도에 보여준 병 갯수
	// 서로 보여주는 병 갯수를 다르게 하여 정답률 향상 (처음에 2개 -> 다음엔 3개)

	// 3번의 기회 (3번의 발모제 투여 시도)
	for (int i = 1; i <= 3; i++)
	{
		int bottle[4] = { 0, 0, 0, 0 }; // 4개의 병
		do {
			cntShowBottle = rand() % 2 + 2; // 보여줄 병 개수 (0~1 + 2 -> 2~3)
		} while (cntShowBottle == prevCntShowBottle);
		prevCntShowBottle = cntShowBottle;

		int isIncluded = 0; // 보여줄 병 중에 발모제가 포함되었는지 여부 (1이면 포함, 0이면 미포함)
		printf(" > %d번째 시도 ", i);

		// 보여줄 병 종류(n번째)를 정한 개수만큼 선택
		for (int j = 0; j < cntShowBottle; j++)
		{
			int randBottle = rand() % 4; // 0~3

			// 아직 선택되지 않은 병이면, 선택 처리
			if (bottle[randBottle] == 0)
			{
				bottle[randBottle] = 1;
				if (randBottle == treatment)
				{
					isIncluded = 1;
				}
			}
			// 이미 선택된 병이면, 중복이므로 다시 선택
			else
			{
				j--; // j++을 한 것을 되돌리기 위해

			}
		}


		// 사용자에게 문제 표시
		for (int k = 0; k < 4; k++)
		{
			if (bottle[k] == 1)
			{
				printf("%d ", k + 1);
			}
		}
		printf("물약을 머리에 바릅니다\n\n");

		if (isIncluded == 1)
		{
			printf(" >> 성공 : 머리가 났어요!!\n");
		}
		else
		{
			printf(" >> 실패 : 머리가 나지 않았어요..\n");
		}
		printf("\n.... 계속 하려면 아무키나 누르세요...");
		getchar(); // 아무 키 눌렀을 때 다음으로 넘어감
	}

	printf("\n\n발모제는 몇 번일까요? ");
	scanf_s("%d", &answer);

	if (answer == treatment + 1)
	{
		printf("\n >> 정답입니다!!\n");
	}
	else
	{
		printf("\n >> 땡! 틀렸습니다. 정답은 %d입니다\n",treatment +1);
	}

	return 0;
}