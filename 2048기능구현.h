#include <iostream>
#include<conio.h>
#include<time.h>
using namespace std;

class Map_2048 {

	int  Map[4][4];
	
	int  Move_Counter;
	char Get_key;
	int  Randum_Counter[2];
	bool CreatChack=true;
	int  Zero_Counter;
public:
	Map_2048() {
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Map[i][j] = 2;
			}
		}
	}
	void In_key() {
		Get_key = _getch();
		system("cls");
	}
	void MoveNumber()
	{
		switch (Get_key)
		{
		case 'w':
			Move_UP();
			break;
		case 'a':
			Move_Left();
			break;
		case 's':
			Move_Down();
			break;
		case 'd':
			Move_Right();
			break;
		
		default:
			cout << "다시입력해주세요" << endl;
			In_key();
			MoveNumber();
			print_board();
			break;
		}
		
	}
	void Move_Left() 
	{
		for (int a= 0; a < 3; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (Map[i][j] == 0)
					{
						Map[i][j] = Map[i][j + 1];
						Map[i][j + 1] = 0;
					}
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				
				if (Map[i][j] == Map[i][j + 1])
				{
					Map[i][j] += Map[i][j + 1];
					Map[i][j + 1] = 0;
					j++;
				}
				
			}
		}
		for (int a = 0; a < 2; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (Map[i][j] == 0)
					{
						Map[i][j] = Map[i][j + 1];
						Map[i][j + 1] = 0;
					}
				}
			}
		}

	}
	void Move_Right()
	{
		for (int a = 0; a < 3; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 3; j >0; j--)
				{
					if (Map[i][j] == 0)
					{
						Map[i][j] = Map[i][j - 1];
						Map[i][j - 1] = 0;
					}
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 3; j > 0; j--)
			{
				if (Map[i][j] == Map[i][j - 1])
				{
					Map[i][j] += Map[i][j - 1];
					Map[i][j - 1] = 0;
				}
			}
		}
		for (int a = 0; a < 2; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 3; j > 0; j--)
				{
					if (Map[i][j] == 0)
					{
						Map[i][j] = Map[i][j - 1];
						Map[i][j - 1] = 0;
					}
				}
			}
		}
	}
	void Move_UP()
	{
		for (int a = 0; a < 3; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (Map[j][i] == 0)
					{
						Map[j][i] = Map[j + 1][i];
						Map[j + 1][i] = 0;
					}
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				if (Map[j][i] == Map[j + 1][i])
				{
					Map[j][i] += Map[j + 1][i];
					Map[j + 1][i] = 0;
					j++;
				}

			}
		}
		for (int a = 0; a < 2; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (Map[j][i] == 0)
					{
						Map[j][i] = Map[j + 1][i];
						Map[j + 1][i] = 0;
					}
				}
			}
		}

	}
	void Move_Down()
	{
		for (int a = 0; a < 3; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 3; j > 0; j--)
				{
					if (Map[j][i] == 0)
					{
						Map[j][i] = Map[j - 1][i];
						Map[j - 1][i] = 0;
					}
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 3; j > 0; j--)
			{
				if (Map[j][i] == Map[j - 1][i])
				{
					Map[j][i] += Map[j - 1][i];
					Map[j - 1][i] = 0;
				}
			}
		}
		for (int a = 0; a < 2; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 3; j > 0; j--)
				{
					if (Map[j][i] == 0)
					{
						Map[j][i] = Map[j - 1][i];
						Map[j - 1][i] = 0;
					}
				}
			}
		}
	}
	void print_board() {
		system("cls");
		cout << "======2048======" << '\n';
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) 
			{
					cout << Map[i][j]<<"   ";
				
			}
			cout << '\n' << '\n';
		}
		cout << "w: 위  a: 왼쪽  s: 아래  d: 오른쪽" << '\n';
		cout << '\n';
		cout << ">>";
	}
	void ZeroCounter() 
	{
		Zero_Counter = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
			{
				if (Map[i][j] == 1)
					++Zero_Counter;
			}
		}
	};
	int GetZeroCounter() 
	{
		return Zero_Counter;
	}
	void Creat2(int a){
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
			{
				if (Map[i][j] == 0)
					--a;
				if((a< 0 )&& (Map[i][j] ==0)&&CreatChack)
				{
					Map[i][j] = 2;
					CreatChack = false;
				}
			}
		}
		if (CreatChack==true)
		{
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++)
				{
					if (Map[i][j] == 0&& CreatChack == true)
					{
						Map[i][j] = 2;
						CreatChack = false;
					}
				}
			}
		}
		CreatChack = true;
	}
};
