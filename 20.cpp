#include"2048map.h"

int main()
{
	
	srand(time(0));
	
	GameSe a;
	while (a.skip)
	{
		a.Print_Main();
		a.Arrow();
		a.Print_Main();
		
	}
	if(a.selmod==4)
	{
		Map_2048 Map1;
		while (true)
		{
			Map1.print_board();
			Map1.In_key();
			Map1.MoveNumber();
			Map1.print_board();
			Map1.ZeroCounter();
			int b = rand() % 16;
			Map1.Creat2(b);
		}
	}
	else if (a.selmod == 2)
	{
		Map_2048 Map1;
		Map_2048_2p Map2;
		int b=0;
		while (true)
		{
			Map2.print_board(Map1);
			cout << "1P차례입니다.";
			Map1.In_key();
			Map1.MoveNumber();
			Map1.ZeroCounter();
			b = rand() % 16;
			Map1.Creat2(b);
			Map2.print_board(Map1);
			cout << "2P차례입니다.";
			Map2.In_key();
			Map2.MoveNumber(Map1);
			Map2.ZeroCounter();
			b = rand() % 16;
			Map2.Creat2(b);
		}
	}
}
