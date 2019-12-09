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
			map1.Print_Board();//16ĭ ���
			map1.In_key(); // _getch();
			map1.Move_Number();//getKey ���� ������ �°� �Լ� ȣ��
			randnum = rand() % 10;//16ĭ�� ���� ��ġ 
			map1.Creat_2(randnum);// �������� ������� 0�� ������ ������ 2���� randnum�������������� 2����
			map1.End_Chack();
			if (map1.mapSameChack == true)//ĭ�� 0�� �ƴѼ��� ä�����ְ� mapī�Ǻ� map������ �� ��ȭ���� 2����üũ�� true�϶�
			{
				cout << "2�� �������� ���ؼ� GameOver";
				break;
			}
			if (map1.chack2048 == true)
			{
				cout << "�̱�̽��ϴ�.";
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
			if (player.mapSameChack == true)//ĭ�� 0�� �ƴѼ��� ä�����ְ� mapī�Ǻ� map������ �� ��ȭ���� 2����üũ�� true�϶�
			{
				cout << "2�� �������� ���ؼ� GameOver";
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
				cout << "�̱�̽��ϴ�." << endl;
				break;
			}
			if (player.Get_Hp() < 0)
			{
				cout << "�й��ϼ̽��ϴ�." << endl;
				break;
			}
		}

	}
	else if (mainMenu.selectMode == 2)
	{
		Map_2048 map1;
		Map_2048_2p map2;
		int randnum = 0;
		while (true)//������ ���� 128 �Ѹ� �� ���� �޼��ϸ�
		{
			map2.Print_Board(map1);
			cout << "1P�����Դϴ�.";
			map1.In_key();
			map2.Map_Chack_128(map1);
			map1.Move_Number();
			randnum = rand() % 10;
			map1.Creat_2(randnum);
			map2.Print_Board(map1);
			map1.End_Chack();
			if (map1.mapSameChack == true)
			{
				cout << "2�� �������� ���ؼ� 1P GameOver";
				break;
			}
			cout << "2P�����Դϴ�.";
			map2.In_key();
			map2.Map_Chack_128(map1);
			map2.Move_Number(map1);
			randnum = rand() % 10;
			map2.Creat_2(randnum);
			map2.End_Chack();
			if (map2.mapSameChack == true)
			{
				cout << "2�� �������� ���ؼ� 1P GameOver";
				break;
			}
			if (map2.chack128_1P > 3)
			{
				map2.Print_Board(map1);
				cout << "1p�� �¸� �Ͽ����ϴ�.";
				break;
			}
			if (map2.chack128_2P > 3)
			{
				map2.Print_Board(map1);
				cout << "2p�� �¸� �Ͽ����ϴ�.";
				break;
			}
		}
	}
	else if (mainMenu.selectMode == 2)
	{

	}
}
