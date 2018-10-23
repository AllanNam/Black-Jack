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
		console(); //콘솔창 설정
		mainscreen(); //메인화면
		system("pause>null");

		spacebar(); //스페이스바를 누르면 clear() 실행

		gamemap(); // 게임맵
		card1(num); // 카드 불러오기
		score_1(&player, &dealer);// 초기 점수 불러오기
		Gotoxy(24, 9);
		printf("%3d", dealer); // 딜러의 첫번째 카드
		choice_bar(); // 선택지 hit || stand

		while (1) // 방향키에 따라 선택지 고르기 (hit.stand)
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
					break; // 왼쪽
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
					break; // 오른쪽
				default: continue;
				}
			}
		}
	}
	return 0;
}