# include <stdio.h>

int main(void)
{
	// ������ ź�ٰ� ����, �л� / �Ϲ������� ���� (�Ϲ��� : 20�� �̻�)
	//int age = 15;
	//// if (����) { } else { }
	//if (age >= 20)
	//{
	//	printf("�Ϲ��� �Դϴ�");
	//}
	//else
	//{
	//	printf("�л��Դϴ�");
	//}

	// �ʵ��л� (8~13) / ���л� (14~16) / �����л����� ���� (17~19)
	// if / else if / else
	/*int age = 23;
	if (age >= 8 && age <= 13)
	{
		printf("�ʵ��л��Դϴ�\n");
	}
	else if (age >= 14 && age <= 16)
	{
		printf("���л��Դϴ�\n");
	}
	else if (age >= 17 && age <= 19)
	{
		printf("�����л� �Դϴ�\n");
	}
	else
	{
		printf("�л��� �ƴմϴ�\n");
	}*/

	// break / continue
	// 1������ 30������ �ִ� �ݿ��� 1������ 5������ ���� ��ǥ�� �մϴ�.
	
	/*for (int i = 1; i <= 30; i++)
	{
		if (i >= 6)
		{
			printf("������ �л��� ���� ������\n");
			break;
		}
		printf("%d�� �л��� ���� ��ǥ �غ� �ϼ���\n", i);
	}*/
	
	// 7���� �����ϰ� 6������ 10������ ���� ��ǥ�� �ϼ���
	/*for (int i = 1; i <= 30; i++)
	{
		if (i >= 6 && i <= 10)
		{
			if (i == 7)
			{
				printf("%d�� ������ �Ἦ�Դϴ�\n", i);
				continue;
			}
			printf("%d�� �л��� ���� ��ǥ �غ� �ϼ���\n", i);
		}
	}*/
	
	// && ||
	/*int a = 10;
	int b = 10;
	int c = 12;
	int d = 13;
	if (a == b || c == d)
	{
		printf("a �� b, Ȥ�� c �� d �� ���� �����ϴ�\n");
	}
	else
	{
		printf("���� ���� �ٸ��ϴ�\n");*/

	// ���� 0 / ���� 1 / �� 2
	/*srand(time(NULL));
	int i = rand() % 3; // 0 ~ 2 ��ȯ
	if (i ==0)
	{
		printf("����\n");
	}
	else if (i == 1)
	{
		printf("����\n");
	}
	else if (i == 2)
	{
		printf("��\n");
	}
	else
	{
		printf("�����\n");
	}*/

	/*srand(time(NULL));
	int i = rand() % 3; // 0 ~ 2 ��ȯ
	switch (i)
	{
	case 0:printf("����\n"); break;
	case 1:printf("����\n"); break;
	case 2:printf("��\n"); break;
	default:printf("�����\n"); break;
	}*/

	/*int age = 17;
	switch (age)
	{
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:printf("�ʵ��л��Դϴ�\n"); break;
	case 14:
	case 15:
	case 16:printf("���л��Դϴ�\n"); break;
	case 17:
	case 18:
	case 19:printf("�����л��Դϴ�\n"); break;
	default: printf("�л��� �ƴմϴ�\n"); break;
	}*/

	// Up and Down
	srand(time(NULL));
	int num = rand() % 100 + 1; // 1 ~ 100 ���� ���� ����
	printf("���� : %d\n", num);
	int answer = 0; // ����
	int chance = 5; // ��ȸ
	while (chance > 0)
	{
		printf("���� ��ȸ: %d ��\n", chance--);
		printf("���ڸ� ���纸���� (���� : 1~100) : ");
		scanf_s("%d", &answer);

		if (answer > num)
		{
			printf("DOWN \n\n");
		}
		else if (answer < num)
		{
			printf("UP \n\n");
		}
		else if (answer == num)
		{
			printf("�����Դϴ�! \n\n");
			break;
		}
		else
		{
			printf("�� �� ���� ������ �߻��߽��ϴ�");
		}

		if (chance == 0)
		{
			printf("��� ��ȸ�� �� ����߽��ϴ�. �����߽��ϴ�");
		}
	}


	return 0;
}