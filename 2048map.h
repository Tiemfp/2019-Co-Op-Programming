#include <iostream>
#include<conio.h>
#include<time.h>
using namespace std;

class Map_2048 {

	int  Move_Counter;
	bool CreatChack=true;
	int  Zero_Counter;
public:
	int  Map[4][4];
	char Get_key;

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
class Map_2048_2p :public Map_2048
{

public:
	void MoveNumber(const Map_2048& a)
	{
		switch (Get_key)
		{
		case '8':
			Move_UP();
			break;
		case '4':
			Move_Left();
			break;
		case '6':
			Move_Down();
			break;
		case '5':
			Move_Right();
			break;

		default:
			cout << "다시입력해주세요" << endl;
			In_key();
			MoveNumber(a);
			print_board(a);
			break;
		}
	}
	void print_board(const Map_2048& a) {
		system("cls");
		cout << "======2048======" << "		======2048======" << '\n';
		cout << "1P"<<"				2P" <<endl ;
		for (int i = 0; i < 4; i++) {
			
			for (int j = 0; j < 4; j++)
			{
				cout << a.Map[i][j] << "   ";

			}
			cout << "		";
			for (int j = 0; j < 4; j++)
			{
				cout << Map[i][j] << "   ";

			}
			cout << '\n' << '\n';
		}
		cout << "w: 위  a: 왼쪽  s: 아래  d: 오른쪽" << '\n';
		cout << "8: 위  4: 왼쪽  5: 아래  6: 오른쪽" << '\n';
		cout << '\n';
		cout << ">>";
	}
};
class GameSe 
{
	int key;
	int ui=3;
	char selui[4];
	
public:
	bool skip=true;
	int selmod = 10;
	void Arrow() 
	{
		key = getch();
		if(key=224)
		{
			key = getch();
			switch (key)
			{
			case(72):
				++ui;
				break;
			case(80):
				--ui;
				break;
			case(13):
				skip = false;
				break;
			default:	
				break;
			}
			ui4se();
		}	
	}
	void ui4se() 
	{
		if (ui >4)
			ui = 1;
		else if(ui<1)
			ui = 4;
		for (int i = 0; i < 4; i++)
		{
			selui[i] = 'O';
		}
		selui[ui-1] = '*';
	}
	void Print_Main() 
	{
		ui4se();
		selmod = ui;
		system("cls");
		cout << "	      " << "2048 게임즈"<<endl<<endl;

		cout <<"	" <<selui[3] << " 1인 플레이(노멀 모드)" << endl << endl;
		cout <<"	" <<selui[2] << " 1인 플레이(어택 모드)" << endl << endl;
		cout <<"	" <<selui[1] << " 2인 플레이(대전 모드)" << endl << endl;
		cout <<"	" <<selui[0] << " 	게임 종료" << endl << endl;
		cout <<" 원하는 모드 선택후 Enter를 두번 눌러주세요" << endl << endl;
	}

};