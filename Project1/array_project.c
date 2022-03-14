# include <stdio.h>
# include <time.h>

int main(void)
{
	srand(time(NULL));
	printf("\n\n === �����̴� ��Ӹ� ���� === \n\n");
	int answer; // ����� �Է°�
	int treatment = rand() % 4; // �߸��� ����(���� ����) (0~3)

	int cntShowBottle = 0; // �̹� �õ��� ������ �� ����
	int prevCntShowBottle = 0; // �� �õ��� ������ �� ����
	// ���� �����ִ� �� ������ �ٸ��� �Ͽ� ����� ��� (ó���� 2�� -> ������ 3��)


	// 3���� ��ȸ (3���� �߸��� ���� �õ�)
	for (int i = 1; i <= 3; i++)
	{
		int bottle[4] = { 0, 0, 0, 0 }; // 4���� ��
		do {
			cntShowBottle = rand() % 2 + 2; // ������ �� ���� (0~1 + 2 -> 2~3)
		} while (cntShowBottle == prevCntShowBottle);
		prevCntShowBottle = cntShowBottle;

		int isIncluded = 0; // ������ �� �߿� �߸����� ���ԵǾ����� ���� (1�̸� ����, 0�̸� ������)
		printf(" > %d��° �õ� ", i);

		// ������ �� ����(n��°)�� ���� ������ŭ ����
		for (int j = 0; j < cntShowBottle; j++)
		{
			int randBottle = rand() % 4; // 0~3

			// ���� ���õ��� ���� ���̸�, ���� ó��
			if (bottle[randBottle] == 0)
			{
				bottle[randBottle] = 1;
				if (randBottle == treatment)
				{
					isIncluded = 1;
				}
			}
			// �̹� ���õ� ���̸�, �ߺ��̹Ƿ� �ٽ� ����
			else
			{
				j--; // j++�� �� ���� �ǵ����� ����

			}
		}


		// ����ڿ��� ���� ǥ��
		for (int k = 0; k < 4; k++)
		{
			if (bottle[k] == 1)
			{
				printf("%d ", k + 1);
			}
		}
		printf("������ �Ӹ��� �ٸ��ϴ�\n\n");

		if (isIncluded == 1)
		{
			printf(" >> ���� : �Ӹ��� �����!!\n");
		}
		else
		{
			printf(" >> ���� : �Ӹ��� ���� �ʾҾ��..\n");
		}
		printf("\n.... ��� �Ϸ��� �ƹ�Ű�� ��������...");
		getchar(); // �ƹ� Ű ������ �� �������� �Ѿ
	}

	printf("\n\n�߸����� �� ���ϱ��? ");
	scanf_s("%d", &answer);

	if (answer == treatment + 1)
	{
		printf("\n >> �����Դϴ�!!\n");
	}
	else
	{
		printf("\n >> ��! Ʋ�Ƚ��ϴ�. ������ %d�Դϴ�\n",treatment +1);
	}

	return 0;
}