#include"2048map.h"

int main()
{
	srand(time(0));
	Map_2048 Map1;
	while (true)
	{

		Map1.print_board();
		Map1.In_key();
		Map1.MoveNumber();
		Map1.print_board();
		Map1.ZeroCounter();
		int b = rand()%16;
		Map1.Creat2(b);
	}
}
