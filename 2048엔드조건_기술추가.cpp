#include"2048map.h"

int main()
{

	srand((unsigned)time(NULL));

	GameSe mainMenu;
	while (mainMenu.skip)
	{
		mainMenu.Print_Main();
		mainMenu.Arrow_Control();
		mainMenu.Print_Main();
	}
	if (mainMenu.selectMode == 4)
	{
		Map_2048 map1;
		int randnum = rand() % 16;
		while (true)
		{
			map1.Print_Board();//16칸 출력
			map1.In_key(); // _getch();
			map1.Move_Number();//getKey 문자 변수에 맞게 함수 호출
			randnum = rand() % 10;//16칸중 랜덤 위치 
			map1.Creat_2(randnum);// 랜덤숫자 기반으로 0의 갯수가 맞으면 2생성 randnum값에맞지않으면 2삽입
			map1.End_Chack();
			if (map1.mapSameChack == true)//칸이 0이 아닌수로 채워져있고 map카피본 map값복사 값 변화없고 2생성체크가 true일때
			{
				cout << "2를 생성하지 못해서 GameOver";
				break;
			}
			if (map1.chack2048 == true)
			{
				cout << "이기셨습니다.";
				break;
			}
		}
	}
	else if (mainMenu.selectMode == 3)
	{
		RPGPlayer player;
		RPGEnemy moster;
		int randnum = rand() % 16;
		bool chack = false;
		player.Print_Board();
		clock_t startTime = clock();
		clock_t endTime = clock();

		while (true)
		{

			player.Print_Board();
			moster.Print_Monster();
			player.In_key();
			player.Move_Number();
			moster.Set_Hp(player.ReturnDamage());
			player.Print_Board();
			moster.Print_Monster();
			randnum = rand() % 16;
			player.Creat_2(randnum);
			player.End_Chack();
			if (player.mapSameChack == true)//칸이 0이 아닌수로 채워져있고 map카피본 map값복사 값 변화없고 2생성체크가 true일때
			{
				cout << "2를 생성하지 못해서 GameOver";
				break;
			}
			if (chack == false)
			{
				player.Hp_less((moster.Get_Damage() * 3));
				player.Print_Board();
				moster.Print_Monster();
				chack = true;
				startTime = clock();
			}
			endTime = clock();
			if ((endTime - startTime) > 3000)
			{
				chack = false;

			}
			if (moster.Get_Hp() < 0)
			{
				cout << "이기셨습니다." << endl;
				break;
			}
			if (player.Get_Hp() < 0)
			{
				cout << "패배하셨습니다." << endl;
				break;
			}
		}

	}
	else if (mainMenu.selectMode == 2)
	{
		Map_2048 map1;
		Map_2048_2p map2;
		int randnum = 0;
		while (true)//끝나는 조건 128 한명 이 세번 달성하면
		{
			map2.Print_Board(map1);
			cout << "1P차례입니다.";
			map1.In_key();
			map2.Map_Chack_128(map1);
			map1.Move_Number();
			randnum = rand() % 10;
			map1.Creat_2(randnum);
			map2.Print_Board(map1);
			map1.End_Chack();
			if (map1.mapSameChack == true)
			{
				cout << "2를 생성하지 못해서 1P GameOver";
				break;
			}
			cout << "2P차례입니다.";
			map2.In_key();
			map2.Map_Chack_128(map1);
			map2.Move_Number(map1);
			randnum = rand() % 10;
			map2.Creat_2(randnum);
			map2.End_Chack();
			if (map2.mapSameChack == true)
			{
				cout << "2를 생성하지 못해서 1P GameOver";
				break;
			}
			if (map2.chack128_1P > 3)
			{
				map2.Print_Board(map1);
				cout << "1p가 승리 하였습니다.";
				break;
			}
			if (map2.chack128_2P > 3)
			{
				map2.Print_Board(map1);
				cout << "2p가 승리 하였습니다.";
				break;
			}
		}
	}
	else if (mainMenu.selectMode == 2)
	{

	}
}
