#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
char box[24], sbox[12], home[4][2];
int reached[4], total = 0, dice, p_out = 1, menu, opt, theme, mode, lang = 1;
char *player[4] = {"Red", "Blue", "Yellow", "Green"};
char pawn[4] = "RBYG";
char color[4][4] = {{'R', 'R', 'R', 'R'}, {'B', 'B', 'B', 'B'}, {'Y', 'Y', 'Y', 'Y'}, {'G', 'G', 'G', 'G'}}; ////// pawn inside home
char *num1[6] = {"One", "Two", "Three", "Four", "Five", "Six"};
char *num2[6] = {"एक", "दुई", "तीन", "चार", "पाँच", "छ"};
void newgame();
void aboutgame();
void setting();
void ludoboard();
void move_red(int n);
void move_blue(int n);
void move_yellow(int n);
void move_green(int n);
void send_home(int n);
int chk_vac(int val);
void s_s(int n, char c, int j);
void paint(int k);
void pawn_color(char a);

void main()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
			home[i][j] = ' ';
	}
	for (int spc = 0; spc < 24; spc++)
	{
		box[spc] = ' ';
		if (spc < 12)
			sbox[spc] = ' ';
	}
	printf("\t==================>LUDO<==================\n");
	if (lang == 1)
	{
		printf("\t\t\t<MAIN MENU>\n");
		printf("\t\t\t1.New Game\n");
		printf("\t\t\t2.Game settings\n");
		printf("\t\t\t3.About Game\n");
		printf("\t\t\t4.Exit Game\n");
		printf("\t\tPlease select any menu(1/2/3)\n\t\t\t");
		scanf("%d", &menu);
	}
	else
	{
		printf("\t\t\t<मुख्य मेनू>\n");
		printf("\t\t\t1.नयाँ खेल\n");
		printf("\t\t\t2.खेल सेटिङ\n");
		printf("\t\t\t3.खेलको जानकारी \n");
		printf("\t\t\t4.खेल बन्द गर्नुहोस्\n");
		printf("\t\tकृपया कुनै मेनू छान्नुहोस्:(1/2/3)\n\t\t\t");
		scanf("%d", &menu);
	}
	if (menu == 1)
	{
		newgame();
	}
	else if (menu == 2)
	{
		setting();
	}
	else if (menu == 3)
	{
		aboutgame();
	}
	else
	{
		printf("\t\t\tGame ended");
	}
}

void newgame()
{
	if (lang == 1)
	{
		printf("\t\tPlease select any theme:(1/2)\n");
		printf("\t\t\t1.Classic\n");
		printf("\t\t\t2.Colourful\n");
		scanf("%d", &theme);
		printf("\t\tPlease select mode:(2/3/4)\n");
		printf("\t\t\t2 Players mode\n");
		printf("\t\t\t3 Players mode\n");
		printf("\t\t\t4 Players mode\n");
	}
	else
	{
		printf("\t\tकृपया कुनै थिम छान्नुहोस्।:(1/2)\n");
		printf("\t\t\t1.सादा\n");
		printf("\t\t\t2.रंगीन\n");
		scanf("%d", &theme);
		printf("\t\tकृपया खिलाडी को सङ्ख्या चयण गर्नुहोस् :(2/3/4)\n");
		printf("\t\t\t2 जना\n");
		printf("\t\t\t3 जना\n");
		printf("\t\t\t4 जना\n");
	}
	scanf("%d", &mode);
	system("cls");
	if (lang == 1)
	{
		printf("\t\tPress any key to begin the game..\n");
	}
	else
	{
		printf("\t\tखेल सुरु गर्न कुनै पनि बटन थिच्नुहोस्..\n");
	}
	getch();
	int limit = 16;
	for (int k = 0; total < limit; k++)
	{
		if (mode == 2)
		{
			limit = 8;
			if (k % 4 == 2 || k % 4 == 3)
			{
				continue;
			}
		}
		if (mode == 3 && k % 4 == 3)
		{
			limit = 12;
			continue;
		}
		if (reached[k % 4] == 4)
		{
			continue;
		}
		if (theme == 2)
			printf("\e[1;36m");
		ludoboard();
		printf("\t\tNeed %d to take a pawn out\n", p_out);
		if (theme == 2)
			paint(k);
		printf("\t%s:\n", player[k % 4]);
		if (lang == 1)
		{
			printf("\tPress any key to roll the dice\n");
		}
		else
		{
			printf("\tपासा फलाउनको लागि कुनै बटन थिच्नुहोस्।\n");
		}
		getch();
		srand(time(NULL));
		dice = rand() % 6 + 1;
		if (theme == 2)
			printf("\e[1;0m");
		if (lang == 1)
		{
			printf("\tDice:==> %d(%s)\n", dice, num1[dice - 1]);
		}
		else
		{
			printf("\tपासा:==> %d(%s)\n", dice, num2[dice - 1]);
		}
		if (theme == 2)
			paint(k);
		if (lang == 1)
		{
			printf("\tPress any key to move your pawn.\n");
		}
		else
		{
			printf("\tआफ्नो मोहरा चाल्नलाई कुनै बटन थिच्नुहोस्।\n");
		}
		getch();
		if (k % 4 == 0)
		{
			move_red(dice);
			system("cls");
		}
		else if (k % 4 == 1)
		{
			move_blue(dice);
			system("cls");
		}
		else if (k % 4 == 2)
		{
			move_yellow(dice);
			system("cls");
		}
		else
		{
			move_green(dice);
			system("cls");
		}
		total = reached[0] + reached[1] + reached[2] + reached[3];
	}
	if (lang == 1)
	{
		printf("\nHope you enjoyed the game.\n");
	}
	else
	{
		printf("\nआशा छ तपाईंको खेल रमाइलो भयो।\n");
	}
}

void setting()
{
	int input, set;
	system("cls");
	printf("\t\tSETTINGS\n\n");
	printf("\t\t1.Dice configure\n");
	printf("\t\t2.Language\n\t\t\t");
	scanf("%d", &set);
	if (set == 1)
	{
		printf("\tDice value for taking a pawn out(1/6):\n\t\t\t");
		scanf("%d", &input);
		if (input == 6 || input == 1)
		{
			p_out = input;
		}
		printf("\t%d will be used to take a pawn out.\n", p_out);
	}
	else if (set == 2)
	{
		printf("\t\tChoose your language\n");
		printf("\t\t1.English\n");
		printf("\t\t2.नेपाली\n\t\t\t");
		scanf("%d", &input);
		if (input == 1 || input == 2)
		{
			lang = input;
		}
	}
	else
	{
		//
	}
	printf("\tEnter 0 to go to main menu.\n\t\t\t");
	scanf("%d", &opt);

	if (opt == 0)
	{
		system("cls");
		main();
	}
}

void aboutgame()
{
	system("cls");
	printf("Version 1.0.0\n\n");
	printf("Game instructions:\n");
	printf("1.Press any key to roll the dice.\n");
	printf("2.Once dice is rolled, press any key to move your pawn.\n");
	printf("3.Pawn can move only under satisfied condition.\n");
	printf("4.Must get a fixed value 1 or 6(default 1) on dice to take a pawn out.\n");
	printf("5.*New pawn can only be taken out after the previous pawn has reached its final destination.\n");
	printf("6.A player can roll dice only once in their turn.\n\n");
	printf("Enter 0 to go to main menu.\n");
	scanf("%d", &opt);
	if (opt == 0)
	{
		system("cls");
		main();
	}
}

void ludoboard()
{
	if (lang == 1)
	{
		printf("\t\t\tENJOY YOUR GAME\n");
	}
	else
	{
		printf("\t\t\tखेलको आनन्द लिनुहोस्।\n");
	}
	// Top border line
	printf("\t");
	for (int col = 1; col <= 45; col++)
	{
		printf(":");
	}

	// Middle lines
	// row->row col->column
	for (int row = 1; row <= 20; row++)
	{
		printf("\n\t||");
		for (int col = 1; col <= 41; col++)
		{
			if (row % 3 == 0)
			{
				if ((col <= 12 || col >= 30) && (row <= 6 || row >= 15))
				{
					printf("&");
				}
				else
				{
					if ((col >= 18 && col <= 24) || (row == 9 || row == 12))
						printf("+");
					else
						printf(" ");
				}
			}

			else
			{
				/// Array box placing
				if (col == 15 && row == 1)
				{
					pawn_color(box[10]);
				}
				else if (col == 21 && row == 1)
				{
					pawn_color(box[11]);
				}
				else if (col == 29 && row == 1)
				{
					pawn_color(box[12]);
				}

				else if (col == 15 && row == 4)
				{
					pawn_color(box[9]);
				}
				else if (col == 27 && row == 4)
				{
					pawn_color(box[13]);
				}

				else if (col == 1 && row == 7)
				{
					pawn_color(box[6]);
				}
				else if (col == 8 && row == 7)
				{
					pawn_color(box[7]);
				}
				else if (col == 15 && row == 7)
				{
					pawn_color(box[8]);
				}

				else if (col == 27 && row == 7)
				{
					pawn_color(box[14]);
				}
				else if (col == 33 && row == 7)
				{
					pawn_color(box[15]);
				}
				else if (col == 39 && row == 7)
				{
					pawn_color(box[16]);
				}

				else if (col == 3 && row == 10)
				{
					pawn_color(box[5]);
				}
				else if (col == 39 && row == 10)
				{
					pawn_color(box[17]);
				}

				else if (col == 3 && row == 13)
				{
					pawn_color(box[4]);
				}
				else if (col == 9 && row == 13)
				{
					pawn_color(box[3]);
				}
				else if (col == 15 && row == 13)
				{
					pawn_color(box[2]);
				}

				else if (col == 27 && row == 13)
				{
					pawn_color(box[20]);
				}
				else if (col == 33 && row == 13)
				{
					pawn_color(box[19]);
				}
				else if (col == 41 && row == 14)
				{
					pawn_color(box[18]);
				}

				else if (col == 15 && row == 16)
				{
					pawn_color(box[1]);
				}
				else if (col == 27 && row == 16)
				{
					pawn_color(box[21]);
				}

				else if (col == 13 && row == 20)
				{
					pawn_color(box[0]);
				}
				else if (col == 21 && row == 19)
				{
					pawn_color(box[23]);
				}
				else if (col == 27 && row == 19)
				{
					pawn_color(box[22]);
				}

				// Pawns inside home
				// Green
				else if (col == 3 && row == 2)
				{
					pawn_color(color[3][3]);
				}
				else if (col == 9 && row == 2)
				{
					pawn_color(color[3][2]);
				}
				else if (col == 3 && row == 5)
				{
					pawn_color(color[3][0]);
				}
				else if (col == 9 && row == 5)
				{
					pawn_color(color[3][1]);
				}

				// Yellow
				else if (col == 33 && row == 2)
				{
					pawn_color(color[2][0]);
				}
				else if (col == 39 && row == 2)
				{
					pawn_color(color[2][3]);
				}
				else if (col == 33 && row == 5)
				{
					pawn_color(color[2][1]);
				}
				else if (col == 39 && row == 5)
				{
					pawn_color(color[2][2]);
				}

				// Red
				else if (col == 3 && row == 17)
				{
					pawn_color(color[0][2]);
				}
				else if (col == 9 && row == 17)
				{
					pawn_color(color[0][1]);
				}
				else if (col == 3 && row == 20)
				{
					pawn_color(color[0][3]);
				}
				else if (col == 9 && row == 20)
				{
					pawn_color(color[0][0]);
				}

				// Blue
				else if (col == 33 && row == 17)
				{
					pawn_color(color[1][1]);
				}
				else if (col == 39 && row == 17)
				{
					pawn_color(color[1][0]);
				}
				else if (col == 33 && row == 20)
				{
					pawn_color(color[1][2]);
				}
				else if (col == 39 && row == 20)
				{
					pawn_color(color[1][3]);
				}

				/////////////////////Stamp symbol
				else if ((col == 3 && row == 7) || (col == 29 && row == 2) || (col == 13 && row == 19) || (col == 39 && row == 14))
				{
					printf("*");
				}

				//////////Stamp boxes
				else if (col == 15 && row == 19)
				{
					pawn_color(sbox[0]);
				}
				else if (col == 17 && row == 19)
				{
					pawn_color(sbox[1]);
				}
				else if (col == 17 && row == 20)
				{
					pawn_color(sbox[2]);
				}

				else if (col == 5 && row == 7)
				{
					pawn_color(sbox[3]);
				}
				else if (col == 3 && row == 8)
				{
					pawn_color(sbox[4]);
				}
				else if (col == 5 && row == 8)
				{
					pawn_color(sbox[5]);
				}

				else if (col == 25 && row == 1)
				{
					pawn_color(sbox[6]);
				}
				else if (col == 25 && row == 2)
				{
					pawn_color(sbox[7]);
				}
				else if (col == 27 && row == 2)
				{
					pawn_color(sbox[8]);
				}

				else if (col == 37 && row == 13)
				{
					pawn_color(sbox[9]);
				}
				else if (col == 39 && row == 13)
				{
					pawn_color(sbox[10]);
				}
				else if (col == 37 && row == 14)
				{
					pawn_color(sbox[11]);
				}

				/////Double home boxes

				else if (col == 21 && row == 16)
				{
					pawn_color(home[0][0]);
				}
				else if (col == 21 && row == 13)
				{
					pawn_color(home[0][1]);
				}

				else if (col == 33 && row == 10)
				{
					pawn_color(home[1][0]);
				}
				else if (col == 27 && row == 10)
				{
					pawn_color(home[1][1]);
				}

				else if (col == 21 && row == 4)
				{
					pawn_color(home[2][0]);
				}
				else if (col == 21 && row == 7)
				{
					pawn_color(home[2][1]);
				}

				else if (col == 9 && row == 10)
				{
					pawn_color(home[3][0]);
				}
				else if (col == 15 && row == 10)
				{
					pawn_color(home[3][1]);
				}

				// Reached pawns count
				else if (col == 19 && row == 11)
				{
					printf("%d", reached[0]);
				}
				else if (col == 20 && row == 11)
				{
					printf("R");
				}

				else if (col == 22 && row == 11)
				{
					printf("%d", reached[1]);
				}
				else if (col == 23 && row == 11)
				{
					printf("B");
				}

				else if (col == 22 && row == 10)
				{
					printf("%d", reached[2]);
				}
				else if (col == 23 && row == 10)
				{
					printf("Y");
				}

				else if (col == 19 && row == 10)
				{
					printf("%d", reached[3]);
				}
				else if (col == 20 && row == 10)
				{
					printf("G");
				}

				else if (col % 6 == 0)
				{
					if ((row <= 6 || row >= 15) && (col <= 12 || col >= 30))
					{
						printf("|");
					}
					else
					{
						printf("+");
					}
				}
				else
					printf(" ");
			}
		}
		printf("||");
	}

	// Bottom border line
	printf("\n\t");
	for (int col = 1; col <= 45; col++)
	{
		printf(":");
	}
	printf("\n\n");
}

int chk_vac(int val)
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (color[val][i] == pawn[val])
		{
			count += 1;
		}
	}
	return count;
}

void send_home(int n)
{
	for (int i = 0; i < 4; i++)
	{
		if (box[n] == pawn[i])
		{
			for (int j = 0; j < 4; j++)
			{
				if (color[i][j] == ' ')
				{
					color[i][j] = pawn[i];
					box[n] = ' ';
					break;
				}
			}
			break;
		}
	}
}

void s_s(int n, char c, int j)
{
	for (int i = 0; i < 3; i++)
	{
		if (sbox[(n / 2) + i] == ' ')
		{
			sbox[n / 2 + i] = c;
			sbox[j] = ' ';
			break;
		}
	}
}

void paint(int k)
{
	if (k % 4 == 0)
	{
		printf("\033[1;31m\n");
	}
	else if (k % 4 == 1)
	{
		printf("\033[1;35m\n");
	}
	else if (k % 4 == 2)
	{
		printf("\033[1;33m\n");
	}
	else
	{
		printf("\033[1;32m\n");
	}
}

void pawn_color(char col)
{
	if (col == 'R')
	{
		if (theme == 2)
			printf("\033[1;31m");
		printf("%c", col);
		if (theme == 2)
			printf("\033[1;36m");
	}
	else if (col == 'B')
	{
		if (theme == 2)
			printf("\033[1;35m");
		printf("%c", col);
		if (theme == 2)
			printf("\033[1;36m");
	}
	else if (col == 'Y')
	{
		if (theme == 2)
			printf("\033[1;33m");
		printf("%c", col);
		if (theme == 2)
			printf("\033[1;36m");
	}
	else if (col == 'G')
	{
		if (theme == 2)
			printf("\033[1;32m");
		printf("%c", col);
		if (theme == 2)
			printf("\033[1;36m");
	}
	else
	{
		printf("%c", col);
	}
}

void move_red(int dice)
{
	int cg = 0;
	int chk = chk_vac(0); // 4 full
	if (chk == 4)
	{
		if (dice == p_out)
		{
			box[0] = 'R';
			color[0][0] = ' ';
		}
		else
		{
			printf("\tNeed %d to take a pawn out.\n\n", p_out);
		}
		cg++;
	}
	else if ((reached[0] + chk) == 4)
	{
		if (dice == p_out)
		{
			for (int i = 0; i < 4; i++)
			{
				if (color[0][i] == 'R')
				{
					box[0] = 'R';
					color[0][i] = ' ';
					break;
				}
			}
		}
		else
		{
			printf("\tNeed %d to take a pawn out.\n", p_out);
		}
		cg++;
	}
	else
	{
		for (int i = 0; i < 24; i++)
		{
			if (box[i] == 'R')
			{
				int mv = i + dice;
				if (mv < 26)
				{
					if (mv % 6 == 0 && mv < 24) // for sbox
					{
						for (int j = 0; j < 3; j++)
						{
							if (sbox[mv / 2 + j] == ' ')
							{
								sbox[mv / 2 + j] = 'R';
								box[i] = ' ';
								break;
							}
						}
					}
					else if (mv > 23)
					{
						home[0][mv - 24] = 'R';
						box[i] = ' ';
					}
					else
					{
						if (box[mv] != ' ')
						{
							send_home(mv);
						}
						box[mv] = 'R';
						box[i] = ' ';
					}
				}
				else if (mv == 26)
				{
					reached[0] += 1;
					box[i] = ' ';

					printf("\tRed pawn reached to the destination.\n");
				}
				else
				{
					printf("\tMoves more than limit.\n\n");
				}
				cg++;
				break;
			}
		}
		if (cg == 0)
		{
			for (int i = 0; i < 12; i++)
			{
				if (sbox[i] == 'R')
				{
					if (dice < 6)
					{
						if (i <= 2)
						{
							if (box[dice + 0] != ' ')
							{
								send_home(dice + 0);
							}
							box[dice + 0] = 'R';
							sbox[i] = ' ';
						}
						else if (i > 2 && i <= 5)
						{
							if (box[dice + 6] != ' ')
							{
								send_home(dice + 6);
							}
							box[dice + 6] = 'R';
							sbox[i] = ' ';
						}
						else if (i > 5 && i <= 8)
						{
							if (box[dice + 12] != ' ')
							{
								send_home(dice + 12);
							}
							box[dice + 12] = 'R';
							sbox[i] = ' ';
						}
						else
						{
							if (box[dice + 18] != ' ')
							{
								send_home(dice + 18);
							}
							box[dice + 18] = 'R';
							sbox[i] = ' ';
						}
						cg++;
						break;
					}
					else
					{
						if (i < 3)
						{
							s_s(6, 'R', i);
						}
						else if (i < 6)
						{
							s_s(12, 'R', i);
						}
						else if (i < 9)
						{
							s_s(18, 'R', i);
						}
						else
						{
							home[0][0] = 'R';
							sbox[i] = ' ';
						}
						cg++;
						break;
					}
				}
			}
		}
		if (cg == 0)
		{
			if (dice < 3)
			{
				if (home[0][0] == 'R')
				{
					if (dice == 1)
					{
						home[0][1] = 'R';
						home[0][0] = ' ';
					}
					else
					{
						reached[0] += 1;
						home[0][0] = ' ';

						printf("\tRed pawn reached to the destination.\n");
					}
				}
				else
				{
					if (home[0][1] == 'R' && dice == 1)
					{
						reached[0] += 1;
						home[0][1] = ' ';
					}
					else
					{
						printf("\tMoves more than limit.\n");
					}
				}
			}
			else
			{
				printf("\tMoves more than limit.\n");
			}
		}
	}
}

void move_blue(int dice)
{
	int cg = 0;
	int chk = chk_vac(1); // 4 full
	if (chk == 4)
	{
		if (dice == p_out)
		{
			box[18] = 'B';
			color[1][0] = ' ';
		}
		else
		{
			printf("\tNeed %d to take a pawn out.\n\n", p_out);
		}
		cg++;
	}
	else if ((reached[1] + chk) == 4)
	{
		if (dice == p_out)
		{
			for (int i = 0; i < 4; i++)
			{
				if (color[1][i] == 'B')
				{
					box[18] = 'B';
					color[1][i] = ' ';
					break;
				}
			}
		}
		else
		{
			printf("\tNeed %d to take a pawn out.\n", p_out);
		}
		cg++;
	}
	else
	{
		for (int i = 0; i < 24; i++)
		{
			if (box[i] == 'B')
			{
				int mv = i + dice;
				if (mv > 23)
				{ // junction 23
					if (mv == 24)
					{
						for (int j = 0; j < 3; j++)
						{
							if (sbox[j] == ' ')
							{
								sbox[j] = 'B';
								box[i] = ' ';
								break;
							}
						}
					}
					else
					{
						if (box[mv - 24] != ' ')
						{
							send_home(mv - 24);
						}
						box[mv - 24] = 'B';
						box[i] = ' ';
					}
				} // junction
				else if ((i > 12 && i <= 17) && mv > 17) // junc home
				{
					if (mv < 20)
					{
						home[1][mv - 18] = 'B';
						box[i] = ' ';
					}
					else if (mv == 20)
					{
						reached[1] += 1;
						box[i] = ' ';

						printf("\tBlue pawn reached to the destination.\n");
					}
					else
					{
						printf("\tMoves more than limit.\n");
					}
				}
				else
				{
					if (mv % 6 == 0) // for sbox
					{
						for (int j = 0; j < 3; j++)
						{
							if (sbox[mv / 2 + j] == ' ')
							{
								sbox[mv / 2 + j] = 'B';
								box[i] = ' ';
								break;
							}
						}
					}
					else
					{
						if (box[mv] != ' ')
						{
							send_home(mv);
						}
						box[mv] = 'B';
						box[i] = ' ';
					}
				}
				cg++;
				break;
			}
		}
		if (cg == 0)
		{
			for (int i = 0; i < 12; i++)
			{
				if (sbox[i] == 'B')
				{
					if (dice < 6)
					{
						if (i <= 2)
						{
							if (box[dice + 0] != ' ')
							{
								send_home(dice + 0);
							}
							box[dice + 0] = 'B';
							sbox[i] = ' ';
						}
						else if (i > 2 && i <= 5)
						{
							if (box[dice + 6] != ' ')
							{
								send_home(dice + 6);
							}
							box[dice + 6] = 'B';
							sbox[i] = ' ';
						}
						else if (i > 5 && i <= 8)
						{
							if (box[dice + 12] != ' ')
							{
								send_home(dice + 12);
							}
							box[dice + 12] = 'B';
							sbox[i] = ' ';
						}
						else
						{
							if (box[dice + 18] != ' ')
							{
								send_home(dice + 18);
							}
							box[dice + 18] = 'B';
							sbox[i] = ' ';
						}
					}
					else
					{
						if (i < 3)
						{
							s_s(6, 'B', i);
						}
						else if (i < 6)
						{
							s_s(12, 'B', i);
						}
						else if (i < 9)
						{
							home[1][0] = 'B';
							sbox[i] = ' ';
						}
						else
						{
							s_s(0, 'B', i);
						}
					}
					cg++;
					break;
				}
			}
		}
		if (cg == 0)
		{
			if (dice < 3)
			{
				if (home[1][0] == 'B')
				{
					if (dice == 1)
					{
						home[1][1] = 'B';
						home[1][0] = ' ';
					}
					else
					{
						reached[1] += 1;
						home[1][0] = ' ';

						printf("\tBlue pawn reached to the destination.\n");
					}
				}
				else
				{
					if (home[1][1] == 'B' && dice == 1)
					{
						reached[1] += 1;
						home[1][1] = ' ';

						printf("\tBlue pawn reached to the destination.\n");
					}
					else
					{
						printf("\tMoves more than limit.\n");
					}
				}
			}
			else
			{
				printf("\tMoves more than limit.\n");
			}
		}
	}
}

/////////////yellow
void move_yellow(int dice)
{
	int cg = 0;
	int chk = chk_vac(2); // 4 full
	if (chk == 4)
	{
		if (dice == p_out)
		{
			box[12] = 'Y';
			color[2][0] = ' ';
		}
		else
		{
			printf("\tNeed %d to take a pawn out.\n\n", p_out);
		}
		cg++;
	}
	else if ((reached[2] + chk) == 4)
	{
		if (dice == p_out)
		{
			for (int i = 0; i < 4; i++)
			{
				if (color[2][i] == 'Y')
				{
					box[12] = 'Y';
					color[2][i] = ' ';
					break;
				}
			}
		}
		else
		{
			printf("\tNeed %d to take a pawn out.\n", p_out);
		}
		cg++;
	}
	else
	{
		for (int i = 0; i < 24; i++)
		{
			if (box[i] == 'Y')
			{
				int mv = i + dice;
				if (mv > 23)
				{ // junction 23
					if (mv == 24)
					{
						for (int j = 0; j < 3; j++)
						{
							if (sbox[j] == ' ')
							{
								sbox[j] = 'Y';
								box[i] = ' ';
								break;
							}
						}
					}
					else
					{
						if (box[mv - 24] != ' ')
						{
							send_home(mv - 24);
						}
						box[mv - 24] = 'Y';
						box[i] = ' ';
					}
				} // junction
				else if ((i > 6 && i <= 11) && mv > 11) // junc home
				{
					if (mv < 14)
					{
						home[2][mv - 12] = 'Y';
						box[i] = ' ';
					}
					else if (mv == 14)
					{
						reached[2] += 1;
						box[i] = ' ';

						printf("\tYellow pawn reached to the destination.\n");
					}
					else
					{
						printf("\tMoves more than limit.\n");
					}
				}
				else
				{
					if (mv % 6 == 0) // for sbox
					{
						for (int j = 0; j < 3; j++)
						{
							if (sbox[mv / 2 + j] == ' ')
							{
								sbox[mv / 2 + j] = 'Y';
								box[i] = ' ';
								break;
							}
						}
					}
					else
					{
						if (box[mv] != ' ')
						{
							send_home(mv);
						}
						box[mv] = 'Y';
						box[i] = ' ';
					}
				}
				cg++;
				break;
			}
		}
		if (cg == 0)
		{
			for (int i = 0; i < 12; i++)
			{
				if (sbox[i] == 'Y')
				{
					if (dice < 6)
					{
						if (i <= 2)
						{
							if (box[dice + 0] != ' ')
							{
								send_home(dice + 0);
							}
							box[dice + 0] = 'Y';
							sbox[i] = ' ';
						}
						else if (i > 2 && i <= 5)
						{
							if (box[dice + 6] != ' ')
							{
								send_home(dice + 6);
							}
							box[dice + 6] = 'Y';
							sbox[i] = ' ';
						}
						else if (i > 5 && i <= 8)
						{
							if (box[dice + 12] != ' ')
							{
								send_home(dice + 12);
							}
							box[dice + 12] = 'Y';
							sbox[i] = ' ';
						}
						else
						{
							if (box[dice + 18] != ' ')
							{
								send_home(dice + 18);
							}
							box[dice + 18] = 'Y';
							sbox[i] = ' ';
						}
					}
					else
					{
						if (i < 3)
						{
							s_s(6, 'Y', i);
						}
						else if (i < 6)
						{
							home[2][0] = 'Y';
							sbox[i] = ' ';
						}
						else if (i < 9)
						{
							s_s(18, 'Y', i);
						}
						else
						{
							s_s(0, 'Y', i);
						}
					}
					cg++;
					break;
				}
			}
		}
		if (cg == 0)
		{
			if (dice < 3)
			{
				if (home[2][0] == 'Y')
				{
					if (dice == 1)
					{
						home[2][1] = 'Y';
						home[2][0] = ' ';
					}
					else
					{
						reached[2] += 1;
						home[2][0] = ' ';

						printf("\tYellow pawn reached to the destination.\n");
					}
				}
				else
				{
					if (home[2][1] == 'Y' && dice == 1)
					{
						reached[2] += 1;
						home[2][1] = ' ';

						printf("\tYellow pawn reached to the destination.\n");
					}
					else
					{
						printf("\tMoves more than limit.\n");
					}
				}
			}
			else
			{
				printf("\tMoves more than limit.\n");
			}
		}
	}
}

////////Green
void move_green(int dice)
{
	int cg = 0;
	int chk = chk_vac(3); // 4 full
	if (chk == 4)
	{
		if (dice == p_out)
		{
			box[6] = 'G';
			color[3][0] = ' ';
		}
		else
		{
			printf("\tNeed %d to take a pawn out.\n\n", p_out);
		}
		cg++;
	}
	else if ((reached[3] + chk) == 4)
	{
		if (dice == p_out)
		{
			for (int i = 0; i < 4; i++)
			{
				if (color[3][i] == 'G')
				{
					box[6] = 'G';
					color[3][i] = ' ';
					break;
				}
			}
		}
		else
		{
			printf("\tNeed %d to take a pawn out.\n", p_out);
		}
		cg++;
	}
	else
	{
		for (int i = 0; i < 24; i++)
		{
			if (box[i] == 'G')
			{
				int mv = i + dice;
				if (mv > 23)
				{ // junction 23
					if (mv == 24)
					{
						for (int j = 0; j < 3; j++)
						{
							if (sbox[j] == ' ')
							{
								sbox[j] = 'G';
								box[i] = ' ';
								break;
							}
						}
					}
					else
					{
						if (box[mv - 24] != ' ')
						{
							send_home(mv - 24);
						}
						box[mv - 24] = 'G';
						box[i] = ' ';
					}
				} // junction
				else if ((i > 0 && i <= 5) && mv > 5) // junc home
				{
					if (mv < 8)
					{
						home[3][mv - 6] = 'G';
						box[i] = ' ';
					}
					else if (mv == 8)
					{
						reached[3] += 1;
						box[i] = ' ';

						printf("\tGreen pawn reached to the destination.\n");
					}
					else
					{
						printf("\tMoves more than limit.\n");
					}
				}
				else
				{
					if (mv % 6 == 0) // for sbox
					{
						for (int j = 0; j < 3; j++)
						{
							if (sbox[mv / 2 + j] == ' ')
							{
								sbox[mv / 2 + j] = 'G';
								box[i] = ' ';
								break;
							}
						}
					}
					else
					{
						if (box[mv] != ' ')
						{
							send_home(mv);
						}
						box[mv] = 'G';
						box[i] = ' ';
					}
				}
				cg++;
				break;
			}
		}
		if (cg == 0)
		{
			for (int i = 0; i < 12; i++)
			{
				if (sbox[i] == 'G')
				{
					if (dice < 6)
					{
						if (i <= 2)
						{
							if (box[dice + 0] != ' ')
							{
								send_home(dice + 0);
							}
							box[dice + 0] = 'G';
							sbox[i] = ' ';
						}
						else if (i > 2 && i <= 5)
						{
							if (box[dice + 6] != ' ')
							{
								send_home(dice + 6);
							}
							box[dice + 6] = 'G';
							sbox[i] = ' ';
						}
						else if (i > 5 && i <= 8)
						{
							if (box[dice + 12] != ' ')
							{
								send_home(dice + 12);
							}
							box[dice + 12] = 'G';
							sbox[i] = ' ';
						}
						else
						{
							if (box[dice + 18] != ' ')
							{
								send_home(dice + 18);
							}
							box[dice + 18] = 'G';
							sbox[i] = ' ';
						}
					}
					else
					{
						if (i < 3)
						{
							home[3][0] = 'G';
							sbox[i] = ' ';
						}
						else if (i < 6)
						{
							s_s(12, 'G', i);
						}
						else if (i < 9)
						{
							s_s(18, 'G', i);
						}
						else
						{
							s_s(0, 'G', i);
						}
					}
					cg++;
					break;
				}
			}
		}
		if (cg == 0)
		{
			if (dice < 3)
			{
				if (home[3][0] == 'G')
				{
					if (dice == 1)
					{
						home[3][1] = 'G';
						home[3][0] = ' ';
					}
					else
					{
						reached[3] += 1;
						home[3][0] = ' ';

						printf("\tGreen pawn reached to the destination.\n");
					}
				}
				else
				{
					if (home[3][1] == 'G' && dice == 1)
					{
						reached[3] += 1;
						home[3][1] = ' ';

						printf("\tGreen pawn reached to the destination.\n");
					}
					else
					{
						printf("\tMoves more than limit.\n");
					}
				}
			}
			else
			{
				printf("\tMoves more than limit.\n");
			}
		}
	}
}