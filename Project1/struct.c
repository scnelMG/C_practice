# include <stdio.h>


struct GameInfo
{
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // ���� ��ü ����
};

typedef struct 
{
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // ���� ��ü ����
}GAME_INFO;

int main_struct(void)
{
	/*[���� ���]
	�̸� : �����ΰ���
	�߸ų⵵ : 2018��
	���� : 1025��
	���ۻ� : ��ŷ*/

	//char* name = "�����ΰ���";
	//int year = 2018;
	//int price = 50;
	//char* company = "��ŷ";

	///*[�� �ٸ� ���� ���]
	//�̸� : ����������
	//�߸ų⵵ : 2018��
	//���� : 10000��*/
	////���ۻ� : ����

	//char* name = "����������";
	//int year = 2018;
	//int price = 10000;
	//char* company = "����";

	// ����ü ���
	struct GameInfo gameInfo1;
	gameInfo1.name = "�����ΰ���";
	gameInfo1.year = 2018;
	gameInfo1.price = 50;
	gameInfo1.company = "��ŷ";

	// ����ü ���
	printf("-- ���� ��� ���� --\n");
	printf("  ���Ӹ�    : %s\n ", gameInfo1.name);
	printf("  ��ų⵵  : %d\n ", gameInfo1.year);
	printf("  ����      : %d\n ", gameInfo1.price);
	printf("  ���ۻ�    : %s\n\n ", gameInfo1.company);

	// ����ü�� �迭ó�� �ʱ�ȭ
	struct GameInfo gameInfo2 = { "����������", 2019, 10000, "����" };
	printf("\n\n-- ���� ���� ��� ���� --\n");
	printf("  ���Ӹ�    : %s\n ", gameInfo2.name);
	printf("  ��ų⵵  : %d\n ", gameInfo2.year);
	printf("  ����      : %d\n ", gameInfo2.price);
	printf("  ���ۻ�    : %s\n ", gameInfo2.company);

	// ����ü �迭
	struct GameInfo gameArray[2] = {
		{"�����ΰ���", 2018, 50, "��ŷ"},
		{ "����������", 2019, 10000, "����" }
	};

	// ����ü ������
	struct GameInfo* gamePtr; // �̼Ǹ�
	gamePtr = &gameInfo1;
	/*printf("-- �̼Ǹ��� ���� ��� ���� --\n");
	printf("  ���Ӹ�    : %s\n ", (*gamePtr).name);
	printf("  ��ų⵵  : %d\n ", (*gamePtr).year);
	printf("  ����      : %d\n ", (*gamePtr).price);
	printf("  ���ۻ�    : %s\n ", (*gamePtr).company);*/
	printf("\n\n-- �̼Ǹ��� ���� ��� ���� --\n");
	printf("  ���Ӹ�    : %s\n ", gamePtr->name);
	printf("  ��ų⵵  : %d\n ", gamePtr->year);
	printf("  ����      : %d\n ", gamePtr->price);
	printf("  ���ۻ�    : %s\n ", gamePtr->company);

	// ����ü �ȿ� ����ü
	// ���� ��ü ���� �Ұ�
	gameInfo1.friendGame = &gameInfo2;
	printf("\n\n-- ���� ��ü�� ���� ��� ���� --\n");
	printf("  ���Ӹ�    : %s\n ", gameInfo1.friendGame->name);
	printf("  ��ų⵵  : %d\n ", gameInfo1.friendGame->year);
	printf("  ����      : %d\n ", gameInfo1.friendGame->price);
	printf("  ���ۻ�    : %s\n ", gameInfo1.friendGame->company);

	// typedef
	// �ڷ����� ���� ����
	int i = 1;
	typedef int ����;
	typedef float �Ǽ�;
	���� �������� = 3; // int i = 3; �� ����
	�Ǽ� �Ǽ����� = 3.23f; // float f = 3.23f; �� ����
	printf("\n\n �������� : %d, �Ǽ����� : %.2f\n\n", ��������, �Ǽ�����);

	typedef struct GameInfo ��������;
	�������� game1;
	game1.name = "�ѱ� ����";
	game1.year = 2015;

	GAME_INFO game2;
	game2.name = "�ѱ� ����2";
	game2.year = 2014;

	/*struct GameInformation game3;
	game2.name = "�ѱ� ����3";*/
	return 0;
}