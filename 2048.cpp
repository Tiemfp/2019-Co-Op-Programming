#include"2048map.h"

int main()
{
	srand(time(NULL));
	Map_2048 Map1;
	while (true)
	{

		Map1.print_board();
		Map1.In_key();
		Map1.MoveNumber();
		Map1.print_board();
		Map1.ZeroCounter();
	//	Map1.Zero_Counter = rand() % Map1.Zero_Counter;
	//	Map1.Creat2();
	}
}
