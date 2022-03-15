# include <stdio.h>
# include <time.h>

// ����Ⱑ 6������ �ִ�
// �̵��� ���׿� ��� �ִµ�, �縷�̴�
// �縷�� �ʹ� ����, �ʹ� �����ؼ� ���� ���� ���� ������ �Ѵ�
// ���� �� �����ϱ� ���� �������� ���׿� ���� �༭ ����⸦ �����
// ������ �ð��� �������� ���� Ŀ���� ���߿��� ��ƸԴ´�

int level;
int arrayFish[6];
int* cursor;

void initData();
void printfFishes();
void decreaseWater(long elapsedTime);

int main(void)
{
	long startTime = 0; // ���� ���� �ð�
	long totalElapsedTime = 0; // �� ��� �ð�
	long prevElapsedTime = 0; // ���� ��� �ð� (�ֱٿ� ���� �� �ð� ����)

	int num;; // �� �� ���׿� ���� �� ������, ����� �Է�
	initData(); // �ʱ� ������ �Է�

	cursor = arrayFish; // cursor[0], cursor[1], ...

	startTime = clock(); // ���� �ð��� millisecond (1000���� 1��) ������ ��ȯ
	while (1) 
	{
		printfFishes(); // ���� ���¸� ���
		printf("�� �� ���׿� ���� �ٰ��ΰ���? ");
		scanf_s("%d", &num);

		// �Է°� üũ
		if (num < 1 || num > 6)
		{
			printf("�Է°��� �߸��Ǿ����ϴ�\n");
			continue;
		}
		// �� ��� �ð�
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; 
		// ����ð� = ����ð� - ���۽ð� (�� ������ ������)
		printf("�� ��� �ð� : %ld ��\n", totalElapsedTime); // long ���̱� ������ %ld ���

		// ���� �� �� �ð� (���������� �� �� �ð�) ���ķ� �帥 �ð�
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("�ֱ� ��� �ð� : %ld ��\n", prevElapsedTime);

		// ������ ���� ���� (����)
		decreaseWater(prevElapsedTime);

		// ����ڰ� �Է��� ���׿� ���� �ش�
		// ������ ���� 0�̸�, ���� ���� �ʴ´� -> �̹� ����Ⱑ �׾���
		if (cursor[num - 1] <= 0)
		{
			printf("%d�� ������ �̹� �׾����ϴ�. ���� ���� �ʽ��ϴ�\n", num);
		}
		// ������ ���� 0�� �ƴ� ���, ���� �ش�. �� 100�� ���� �ʴ��� üũ
		else if (cursor[num - 1] + 1 <= 100)
		{
			// ���� �ش�
			printf("%d�� ���׿� ���� �ش�\n\n", num);
			cursor[num - 1] += 1; 
		}

		// �������� �� ���� Ȯ�� (�������� 20�ʸ��� �ѹ��� ����)
		if (totalElapsedTime / 20 > level - 1)
		{
			level++; 
			printf("*** ������! ���� %d�������� %d������ ���׷��̵�! ***\n\n", level - 1, level);

			// ���� ���� : 5
			if (level == 5)
			{
				printf("\n\n�����մϴ�, �ְ� ������ �޼��Ͽ����ϴ�. ������ �����մϴ�!");
				exit(0);
			}
		}

		// ��� ����Ⱑ �׾����� Ȯ��
		if (checkFishAlive() == 0)
		{
			// ����� ��� ����
			printf("��� ����Ⱑ �׾����ϴ�\n");
			exit(0);
		}
		else
		{
			// �ּ� �Ѹ��� �̻��� ������ ��� ����
			printf("����Ⱑ ���� ��� �ֽ��ϴ�\n");
		}
		prevElapsedTime = totalElapsedTime;

		// ó�� ���� ���� 10�� ���� -> �� ���� ���� �� ���� 15�� (prevElapsedTime = 5��)
		// 25�ʿ� ���� �شٸ� 25�� - 15��, �� �� 15�ʶ�� ���� prevElapsedTime�� ����

	}
	return 0;
}

void initData()
{
	level = 1; // ���� ���� (1 ~ 5)
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100; // ������ �� ���� (0 ~ 100)
	}
}

void printfFishes()
{
	printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6); 
	// %3d�� ��ĭ�Ҵ� 1 �ڷ� ��ĭ ��ĭ ("1 ")
	for (int i = 0; i < 6; i++)
	{
		printf(" %4d ", arrayFish[i]); 
		// "%3d�� "�� �� 3+ 2(��) + 1 (����) = 6ĭ => " %4d " ��ĭ 2�� + %4d = 6ĭ
	}
	printf("\n\n");
}

void decreaseWater(long elapsedTime)
{
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] -= (level * 3 * (int)elapsedTime); // ���̵� ������ ���� �����ϴ� �ð� ���� (������ 3)
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
			return 1; // �� True
	}
	return 0;
}