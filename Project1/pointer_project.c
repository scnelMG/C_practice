# include <stdio.h>
# include <time.h>

// 물고기가 6마리가 있다
// 이들은 어항에 살고 있는데, 사막이다
// 사막이 너무 덥고, 너무 건조해서 물이 아주 빨리 증발을 한다
// 물이 다 증발하기 전에 부지런히 어항에 물을 줘서 물고기를 살려라
// 물고기는 시간이 지날수록 점점 커져서 나중에는 잡아먹는다

int level;
int arrayFish[6];
int* cursor;

void initData();
void printfFishes();
void decreaseWater(long elapsedTime);

int main(void)
{
	long startTime = 0; // 게임 시작 시간
	long totalElapsedTime = 0; // 총 경과 시간
	long prevElapsedTime = 0; // 직전 경과 시간 (최근에 물을 준 시간 간격)

	int num;; // 몇 번 어항에 물을 줄 것인지, 사용자 입력
	initData(); // 초기 데이터 입력

	cursor = arrayFish; // cursor[0], cursor[1], ...

	startTime = clock(); // 현재 시간을 millisecond (1000분의 1초) 단위로 반환
	while (1) 
	{
		printfFishes(); // 어항 상태를 출력
		printf("몇 번 어항에 물을 줄것인가요? ");
		scanf_s("%d", &num);

		// 입력값 체크
		if (num < 1 || num > 6)
		{
			printf("입력값이 잘못되었습니다\n");
			continue;
		}
		// 총 경과 시간
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; 
		// 경과시간 = 현재시간 - 시작시간 (초 단위로 보여줌)
		printf("총 경과 시간 : %ld 초\n", totalElapsedTime); // long 형이기 때문에 %ld 사용

		// 직전 물 준 시간 (마지막으로 물 준 시간) 이후로 흐른 시간
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("최근 경과 시간 : %ld 초\n", prevElapsedTime);

		// 어항의 물을 감소 (증발)
		decreaseWater(prevElapsedTime);

		// 사용자가 입력한 어항에 물을 준다
		// 어항의 물이 0이면, 물을 주지 않는다 -> 이미 물고기가 죽었음
		if (cursor[num - 1] <= 0)
		{
			printf("%d번 물고기는 이미 죽었습니다. 물을 주지 않습니다\n", num);
		}
		// 어항의 물이 0이 아닌 경우, 물을 준다. 단 100을 넘지 않는지 체크
		else if (cursor[num - 1] + 1 <= 100)
		{
			// 물을 준다
			printf("%d번 어항에 물을 준다\n\n", num);
			cursor[num - 1] += 1; 
		}

		// 레벨업을 할 건지 확인 (레벨업은 20초마다 한번씩 수행)
		if (totalElapsedTime / 20 > level - 1)
		{
			level++; 
			printf("*** 레벨업! 기존 %d레벨에서 %d레벨로 업그레이드! ***\n\n", level - 1, level);

			// 최종 레벨 : 5
			if (level == 5)
			{
				printf("\n\n축하합니다, 최고 레벨을 달성하였습니다. 게임을 종료합니다!");
				exit(0);
			}
		}

		// 모든 물고기가 죽었는지 확인
		if (checkFishAlive() == 0)
		{
			// 물고기 모두 죽음
			printf("모든 물고기가 죽었습니다\n");
			exit(0);
		}
		else
		{
			// 최소 한마리 이상의 물고기는 살아 있음
			printf("물고기가 아직 살아 있습니다\n");
		}
		prevElapsedTime = totalElapsedTime;

		// 처음 물을 준지 10초 지남 -> 그 다음 물을 줄 떄가 15초 (prevElapsedTime = 5초)
		// 25초에 물을 준다면 25초 - 15초, 이 때 15초라는 값을 prevElapsedTime에 저장

	}
	return 0;
}

void initData()
{
	level = 1; // 게임 레벨 (1 ~ 5)
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100; // 어항의 물 높이 (0 ~ 100)
	}
}

void printfFishes()
{
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6); 
	// %3d는 세칸할당 1 뒤로 빈칸 두칸 ("1 ")
	for (int i = 0; i < 6; i++)
	{
		printf(" %4d ", arrayFish[i]); 
		// "%3d번 "은 총 3+ 2(번) + 1 (띄어쓰기) = 6칸 => " %4d " 빈칸 2개 + %4d = 6칸
	}
	printf("\n\n");
}

void decreaseWater(long elapsedTime)
{
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] -= (level * 3 * (int)elapsedTime); // 난이도 조절을 위한 감소하는 시간 조절 (레벨당 3)
		if (arrayFish[i] < 0)
		{
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive()
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
			return 1; // 참 True
	}
	return 0;
}