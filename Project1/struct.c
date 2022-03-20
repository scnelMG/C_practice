# include <stdio.h>


struct GameInfo
{
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // 연관 업체 게임
};

typedef struct 
{
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // 연관 업체 게임
}GAME_INFO;

int main_struct(void)
{
	/*[게임 출시]
	이름 : 오병민게임
	발매년도 : 2018년
	가격 : 1025원
	제작사 : 오킹*/

	//char* name = "오병민게임";
	//int year = 2018;
	//int price = 50;
	//char* company = "오킹";

	///*[또 다른 게임 출시]
	//이름 : 오혜린게임
	//발매년도 : 2018년
	//가격 : 10000원*/
	////제작사 : 오퀸

	//char* name = "오혜린게임";
	//int year = 2018;
	//int price = 10000;
	//char* company = "오퀸";

	// 구조체 사용
	struct GameInfo gameInfo1;
	gameInfo1.name = "오병민게임";
	gameInfo1.year = 2018;
	gameInfo1.price = 50;
	gameInfo1.company = "오킹";

	// 구조체 출력
	printf("-- 게임 출시 정보 --\n");
	printf("  게임명    : %s\n ", gameInfo1.name);
	printf("  밸매년도  : %d\n ", gameInfo1.year);
	printf("  가격      : %d\n ", gameInfo1.price);
	printf("  제작사    : %s\n\n ", gameInfo1.company);

	// 구조체를 배열처럼 초기화
	struct GameInfo gameInfo2 = { "오혜린게임", 2019, 10000, "오퀸" };
	printf("\n\n-- 차기 게임 출시 정보 --\n");
	printf("  게임명    : %s\n ", gameInfo2.name);
	printf("  밸매년도  : %d\n ", gameInfo2.year);
	printf("  가격      : %d\n ", gameInfo2.price);
	printf("  제작사    : %s\n ", gameInfo2.company);

	// 구조체 배열
	struct GameInfo gameArray[2] = {
		{"오병민게임", 2018, 50, "오킹"},
		{ "오혜린게임", 2019, 10000, "오퀸" }
	};

	// 구조체 포인터
	struct GameInfo* gamePtr; // 미션맨
	gamePtr = &gameInfo1;
	/*printf("-- 미션맨의 게임 출시 정보 --\n");
	printf("  게임명    : %s\n ", (*gamePtr).name);
	printf("  밸매년도  : %d\n ", (*gamePtr).year);
	printf("  가격      : %d\n ", (*gamePtr).price);
	printf("  제작사    : %s\n ", (*gamePtr).company);*/
	printf("\n\n-- 미션맨의 게임 출시 정보 --\n");
	printf("  게임명    : %s\n ", gamePtr->name);
	printf("  밸매년도  : %d\n ", gamePtr->year);
	printf("  가격      : %d\n ", gamePtr->price);
	printf("  제작사    : %s\n ", gamePtr->company);

	// 구조체 안에 구조체
	// 연관 업체 게임 소개
	gameInfo1.friendGame = &gameInfo2;
	printf("\n\n-- 연관 업체의 게임 출시 정보 --\n");
	printf("  게임명    : %s\n ", gameInfo1.friendGame->name);
	printf("  밸매년도  : %d\n ", gameInfo1.friendGame->year);
	printf("  가격      : %d\n ", gameInfo1.friendGame->price);
	printf("  제작사    : %s\n ", gameInfo1.friendGame->company);

	// typedef
	// 자료형에 별명 지정
	int i = 1;
	typedef int 정수;
	typedef float 실수;
	정수 정수변수 = 3; // int i = 3; 과 같음
	실수 실수변수 = 3.23f; // float f = 3.23f; 와 같음
	printf("\n\n 정수변수 : %d, 실수변수 : %.2f\n\n", 정수변수, 실수변수);

	typedef struct GameInfo 게임정보;
	게임정보 game1;
	game1.name = "한글 게임";
	game1.year = 2015;

	GAME_INFO game2;
	game2.name = "한글 게임2";
	game2.year = 2014;

	/*struct GameInformation game3;
	game2.name = "한글 게임3";*/
	return 0;
}