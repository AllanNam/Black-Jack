#include"Tool.h" 
#include<windows.h>

#pragma comment(lib, "winmm.lib")

int main()
{
	srand(time(NULL));
	int player = 0, num[] = { 0 }, dealer = 0;
	char key = 0;
	int LR, a = 0;

	randscore_1(&player, num);
	randscore_2(&dealer);

	while (1)
	{
		console(); //�ܼ�â ����
		mainscreen(); //����ȭ��
		system("pause>null");

		spacebar(); //�����̽��ٸ� ������ clear() ����

		gamemap(); // ���Ӹ�
		card1(num); // ī�� �ҷ�����
		score_1(&player, &dealer);// �ʱ� ���� �ҷ�����
		Gotoxy(24, 9);
		printf("%3d", dealer); // ������ ù��° ī��
		choice_bar(); // ������ hit || stand

		while (1) // ����Ű�� ���� ������ ���� (hit.stand)
		{
			LR = getch();
			if (LR == 224)
			{
				LR = getch();
				switch (LR)
				{
				case 75:
					Gotoxy(8, 15);
					while (1)
					{
						if (kbhit())
						{
							key = getch();

							switch (key)
							{
							case ' ': hit();
								score_2(&player, &dealer);
								break;
							default: continue;
							}
						}
					}
					break; // ����
				case 77:
					Gotoxy(26, 15);
					while (1)
					{
						if (kbhit())
						{
							key = getch();

							switch (key)
							{
							case ' ': stand();
								score_3(&player, &dealer);
								break;
							default: continue;
							}
						}
					}
					break; // ������
				default: continue;
				}
			}
		}
	}
	return 0;
}