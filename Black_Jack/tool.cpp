#include"Tool.h"

void Gotoxy(int x, int y)
{
	COORD Pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void console()
{
	system("title Black_Jack");
	system("mode con:cols=80 lines=21");
	system("color 07");
}
void clear()
{
	system("cls");
}

void less()
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void mainscreen() // 衛濛�飛�
{
	int Map[20][40] = {
		{ 5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4 },
		{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
		{ 3,0,0,2,2,2,0,0,2,0,0,0,0,2,2,0,0,2,2,2,2,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
		{ 3,0,0,2,0,0,2,0,2,0,0,0,2,0,0,2,0,2,0,0,0,0,2,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
		{ 3,0,0,2,2,2,0,0,2,0,0,0,2,0,0,2,0,2,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
		{ 3,0,0,2,0,0,2,0,2,0,0,0,2,2,2,2,0,2,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
		{ 3,0,0,2,0,0,2,0,2,0,0,0,2,0,0,2,0,2,0,0,0,0,2,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
		{ 3,0,0,2,2,2,0,0,2,2,2,0,2,0,0,2,0,2,2,2,2,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
		{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
		{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
		{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,2,2,0,0,2,2,2,2,0,2,0,0,2,0,0,0,3 },
		{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,2,0,2,0,0,0,0,2,0,2,0,0,0,0,3 },
		{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,2,0,2,0,0,0,0,2,2,0,0,0,0,0,3 },
		{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,2,2,2,0,2,0,0,0,0,2,2,0,0,0,0,0,3 },
		{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,2,0,0,2,0,0,2,0,2,0,0,0,0,2,0,2,0,0,0,0,3 },
		{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,2,0,0,2,0,2,2,2,2,0,2,0,0,2,0,0,0,3 },
		{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
		{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
		{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
		{ 4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5 }
	};

	int i, j;

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j< 40; j++)
		{
			if (Map[i][j] == 0)
			{
				printf("  ");
			}
			if (Map[i][j] == 1)
			{
				printf("〥");
			}
			if (Map[i][j] == 2)
			{
				printf("﹥");
			}
			if (Map[i][j] == 3)
			{
				printf("〦");
			}
			if (Map[i][j] == 4)
			{
				printf("〨");
			}
			if (Map[i][j] == 5)
			{
				printf("〧");
			}
		}
			puts("");
	}

	Gotoxy(11, 17);
	printf("-衛濛ж溥賊 蝶む檜蝶夥蒂 援腦撮蹂-");

}

void gamemap() // 啪歜 晦獄 裘
{
	int i, j;
	int Map[20][40] = { 
	{ 5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4 },
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
	{ 4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5 }
	};

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j< 40; j++)
		{
			if (Map[i][j] == 0)
			{
				printf("  ");
			}
			if (Map[i][j] == 1)
			{
				printf("〥");
			}
			if (Map[i][j] == 2)
			{
				printf("﹥");
			}
			if (Map[i][j] == 3)
			{
				printf("〦");
			}
			if (Map[i][j] == 4)
			{
				printf("〨");
			}
			if (Map[i][j] == 5)
			{
				printf("〧");
			}
		}
		puts("");
	}

}

void card1(int *num) // 蘋萄 鎰晦
{ 
	Gotoxy(4, 5);
	printf("忙式式式式式式式式式忖    忙式式式式式式式式式忖");
	Gotoxy(22, 5);
	printf("忙式式式式式式式式式忖    忙式式式式式式式式式忖");
	Gotoxy(4, 6);
	printf("弛         弛    弛         弛");
	Gotoxy(22, 6);
	printf("弛         弛    弛         弛");
	Gotoxy(4, 7);
	printf("弛         弛    弛         弛");
	Gotoxy(22, 7);
	printf("弛         弛    弛         弛");
	Gotoxy(4, 8);
	printf("弛         弛    弛         弛");
	Gotoxy(22, 8);
	printf("弛         弛    弛         弛");
	Gotoxy(4, 9);
	printf("弛         弛    弛         弛");
	Gotoxy(22, 9);
	printf("弛         弛    弛    ?    弛");
	Gotoxy(4, 10);
	printf("弛         弛    弛         弛");
	Gotoxy(22, 10);
	printf("弛         弛    弛         弛");
	Gotoxy(4, 11);
	printf("弛         弛    弛         弛");
	Gotoxy(22, 11);
	printf("弛         弛    弛         弛");
	Gotoxy(4, 12);
	printf("弛         弛    弛         弛");
	Gotoxy(22, 12);
	printf("弛         弛    弛         弛");
	Gotoxy(4, 13);
	printf("戌式式式式式式式式式戎    戌式式式式式式式式式戎");
	Gotoxy(22, 13);
	printf("戌式式式式式式式式式戎    戌式式式式式式式式式戎");
	Gotoxy(7, 9);
	printf("%d", num[0]);
	Gotoxy(14, 9);
	printf("%d", num[1]);
}

void card2() // 摹鷗 �� 蘋萄鎰晦
{
	Gotoxy(8, 5);
	printf("忙式式式式式式式式式忖");
	Gotoxy(24, 5);
	printf("忙式式式式式式式式式忖");
	Gotoxy(8, 6);
	printf("弛         弛");
	Gotoxy(24, 6);
	printf("弛         弛");
	Gotoxy(8, 7);
	printf("弛         弛");
	Gotoxy(24, 7);
	printf("弛         弛");
	Gotoxy(8, 8);
	printf("弛         弛");
	Gotoxy(24, 8);
	printf("弛         弛");
	Gotoxy(8, 9);
	printf("弛         弛");
	Gotoxy(24, 9);
	printf("弛         弛");
	Gotoxy(8, 10);
	printf("弛         弛");
	Gotoxy(24, 10);
	printf("弛         弛");
	Gotoxy(8, 11);
	printf("弛         弛");
	Gotoxy(24, 11);
	printf("弛         弛");
	Gotoxy(8, 12);
	printf("弛         弛");
	Gotoxy(24, 12);
	printf("弛         弛");
	Gotoxy(8, 13);
	printf("戌式式式式式式式式式戎");
	Gotoxy(24, 13);
	printf("戌式式式式式式式式式戎");
}

void choice_bar()
{
	Gotoxy(10, 15); // 摹鷗雖 hit = 蘋萄 ж釭 鉻堅 蝓睡 / stand = ⑷營 薄熱煎 蝓睡
	printf("Hit");
	Gotoxy(28, 15);
	printf("Stand");
	Gotoxy(15, 17);
	printf(" -褐醞ж啪 堅腦撮蹂-");

	Gotoxy(8, 15);
	printf("Ⅰ");

	Gotoxy(26, 15);
	printf("Ⅰ");

}

void hit()
{
	clear();
	gamemap();
	card2();	
	Gotoxy(10, 16);
	printf("-蝓ぬ蒂 爾溥賊 蝶む檜蝶夥蒂 援腦撮蹂-");
}

void stand()
{
	clear();
	gamemap();
	card2();
	Gotoxy(10, 16);
	printf("-蝓ぬ蒂 爾溥賊 蝶む檜蝶夥蒂 援腦撮蹂-");
}

void score_1(int *player, int *dealer)
{

	Gotoxy(7, 3);
	printf("渡褐曖 薄熱: %d", *player);
	Gotoxy(25, 3);
	printf("裁楝曖 薄熱: %d", *dealer);

}

void score_2(int *player, int *dealer) // hit
{
	int getrand_1 = 0, getrand_2 = 0; // 1==player 2==dealer

	getrand_1 += (rand() % 11) + 1;
	getrand_2 += (rand() % 11) + 1;
	
	*player += getrand_1;
	*dealer += getrand_2;
	
	while (1)
	{
		if (*player > 16 && *dealer < 16)
		{
			*dealer += (rand() % 11) + 1;
			break;
		}
		else if (*player < 16 && *dealer > 16)
		{
			*player += (rand() % 11) + 1;
			break;
		}
		else if (*player <16 && *dealer < 16)
		{
			*dealer += (rand() % 11) + 1;
			*player += (rand() % 11) + 1;
			break;
		}
		else
		{
			break;
		}
	}

	Gotoxy(7, 3);
	printf("渡褐曖 薄熱: %d", *player);
	Gotoxy(25, 3);
	printf("裁楝曖 薄熱: %d", *dealer);
	Gotoxy(11, 9);
	printf("%d", getrand_1);
	Gotoxy(26, 9);
	printf("%3d", getrand_2);

	


	spacebar();


	if (*player > *dealer && *player < 21)
	{
		win();
		Gotoxy(17, 3);
		printf("譆謙 唸婁");
		Gotoxy(5, 5);
		printf("Ы溯檜橫 薄熱: %d", *player);
		Gotoxy(25, 5);
		printf("裁楝 薄熱 : %d", *dealer);
		Gotoxy(1, 7);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	}
	else if (*dealer > 21 && *player < 21)
	{
		win();
		Gotoxy(17, 3);
		printf("譆謙 唸婁");
		Gotoxy(5, 5);
		printf("Ы溯檜橫 薄熱: %d", *player);
		Gotoxy(25, 5);
		printf("裁楝 薄熱 : %d", *dealer);
		Gotoxy(1, 7);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	}
	else if (*player < *dealer && *dealer < 21 )
	{
		lose();
		Gotoxy(17, 3);
		printf("譆謙 唸婁");
		Gotoxy(5, 5);
		printf("Ы溯檜橫 薄熱: %d", *player);
		Gotoxy(25, 5);
		printf("裁楝 薄熱 : %d", *dealer);
		Gotoxy(1, 7);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	}
	else if (*dealer == 21)
	{
		lose();
		Gotoxy(17, 3);
		printf("譆謙 唸婁");
		Gotoxy(5, 5);
		printf("Ы溯檜橫 薄熱: %d", *player);
		Gotoxy(25, 5);
		printf("裁楝 薄熱 : %d", *dealer);
		Gotoxy(1, 7);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	}
	else if (*player >21)
	{
		lose();
		Gotoxy(17, 3);
		printf("譆謙 唸婁");
		Gotoxy(5, 5);
		printf("Ы溯檜橫 薄熱: %d", *player);
		Gotoxy(25, 5);
		printf("裁楝 薄熱 : %d", *dealer);
		Gotoxy(1, 7);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	}
	else if (*player == *dealer )
	{
		drow();
		Gotoxy(17, 3);
		printf("譆謙 唸婁");
		Gotoxy(5, 5);
		printf("Ы溯檜橫 薄熱: %d", *player);
		Gotoxy(25, 5);
		printf("裁楝 薄熱 : %d", *dealer);
		Gotoxy(1, 7);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	}
	else if (*player > 21 && *dealer > 21)
	{
		drow();
		Gotoxy(17, 3);
		printf("譆謙 唸婁");
		Gotoxy(5, 5);
		printf("Ы溯檜橫 薄熱: %d", *player);
		Gotoxy(25, 5);
		printf("裁楝 薄熱 : %d", *dealer);
		Gotoxy(1, 7);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	}
	else if (*player == 21)
	{
		blackjack();
		Gotoxy(17, 3);
		printf("譆謙 唸婁");
		Gotoxy(5, 5);
		printf("Ы溯檜橫 薄熱: %d", *player);
		Gotoxy(25, 5);
		printf("裁楝 薄熱 : %d", *dealer);
		Gotoxy(1, 7);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	}
}

void score_3(int *player, int *dealer) // stand
{
	int getrand = 0;

	getrand += (rand() % 11) + 1;
	*dealer += getrand;

	while (1)
	{
		if (*player > 16 && *dealer < 16)
		{
			*dealer += (rand() % 11) + 1;
			break;
		}
		else
		{
			break;
		}
	}

	Gotoxy(7, 3);
	printf("渡褐曖 薄熱: %d", *player);
	Gotoxy(25, 3);
	printf("裁楝曖 薄熱: %d", *dealer);
	Gotoxy(11, 9);
	printf("%d", *player);
	Gotoxy(26, 9);
	printf("%3d", getrand);

	


	spacebar();

	if (*player > *dealer && *player < 21)
	{
		win();
		Gotoxy(17, 3);
		printf("譆謙 唸婁");
		Gotoxy(5, 5);
		printf("Ы溯檜橫 薄熱: %d", *player);
		Gotoxy(25, 5);
		printf("裁楝 薄熱 : %d", *dealer);
		Gotoxy(1, 7);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	}
	else if (*dealer > 21 && *player < 21)
	{
		win();
		Gotoxy(17, 3);
		printf("譆謙 唸婁");
		Gotoxy(5, 5);
		printf("Ы溯檜橫 薄熱: %d", *player);
		Gotoxy(25, 5);
		printf("裁楝 薄熱 : %d", *dealer);
		Gotoxy(1, 7);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	}
	else if (*player < *dealer && *dealer < 21)
	{
		lose();
		Gotoxy(17, 3);
		printf("譆謙 唸婁");
		Gotoxy(5, 5);
		printf("Ы溯檜橫 薄熱: %d", *player);
		Gotoxy(25, 5);
		printf("裁楝 薄熱 : %d", *dealer);
		Gotoxy(1, 7);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	}
	else if (*dealer == 21)
	{
		lose();
		Gotoxy(17, 3);
		printf("譆謙 唸婁");
		Gotoxy(5, 5);
		printf("Ы溯檜橫 薄熱: %d", *player);
		Gotoxy(25, 5);
		printf("裁楝 薄熱 : %d", *dealer);
		Gotoxy(1, 7);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	}
	else if (*player >21)
	{
		lose();
		Gotoxy(17, 3);
		printf("譆謙 唸婁");
		Gotoxy(5, 5);
		printf("Ы溯檜橫 薄熱: %d", *player);
		Gotoxy(25, 5);
		printf("裁楝 薄熱 : %d", *dealer);
		Gotoxy(1, 7);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	}
	else if (*player == *dealer)
	{
		drow();
		Gotoxy(17, 3);
		printf("譆謙 唸婁");
		Gotoxy(5, 5);
		printf("Ы溯檜橫 薄熱: %d", *player);
		Gotoxy(25, 5);
		printf("裁楝 薄熱 : %d", *dealer);
		Gotoxy(1, 7);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	}
	else if (*player > 21 && *dealer > 21)
	{
		drow();
		Gotoxy(17, 3);
		printf("譆謙 唸婁");
		Gotoxy(5, 5);
		printf("Ы溯檜橫 薄熱: %d", *player);
		Gotoxy(25, 5);
		printf("裁楝 薄熱 : %d", *dealer);
		Gotoxy(1, 7);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	}
	else if (*player == 21)
	{
		blackjack();
		Gotoxy(17, 3);
		printf("譆謙 唸婁");
		Gotoxy(5, 5);
		printf("Ы溯檜橫 薄熱: %d", *player);
		Gotoxy(25, 5);
		printf("裁楝 薄熱 : %d", *dealer);
		Gotoxy(1, 7);
		printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	}
}

void randscore_1(int *player,int *num)
{
	int x;

	for (x = 0; x < 2; x++)
	{
		num[x] = (rand() % 11) + 1;
		*player += num[x];
	}
}

void randscore_2(int *dealer)
{
	*dealer += (rand() % 11) + 1;
}

void spacebar()
{
	char key = 0;
	int a = 0;

	while (a < 1)
	{

		if (kbhit())
		{
			key = getch();

			switch (key)
			{
			case ' ': clear(); a++;  break;
			default: continue;
			}
		}
	}

}
 

void win()
{
	less();
	gamemap();
	Gotoxy(17, 12);
	printf("◇蝓 葬◆");
}

void lose()
{
	less();
	gamemap();
	Gotoxy(17, 12);
	printf("◇ぬ 寡◆");
}

void drow()
{
	less();
	gamemap();
	Gotoxy(17, 12);
	printf("◇鼠蝓睡◆");
}

void blackjack()
{
	less();
	gamemap();
	Gotoxy(17, 12);
	printf("◇綰楷燮◆");
}
