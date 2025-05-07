#include "Monster.h"

// By Roberto Reynoso

Monster::Monster()
{

}

Monster::~Monster()
{

}

void Monster::nameMonster()
{
	while (true)
	{
		size_t constexpr sizeMonsterArray = sizeof(monsterName);
		std::cout << "Monster Name: ";
		std::cin >> monsterName;

		if (strlen(monsterName) > sizeMonsterArray or strlen(monsterName) < 0)
		{
			std::cout << "Monster Name has to at least be 1 Character or Up to 5" << std::endl;
		}
		else
		{
			break;
		}
	}
}

void Monster::monsterMovement(Monster* monster)
{
	time_t t;
	srand((unsigned)time(&t));
	int whichDirection;

	while (monster->activateMonster)
	{
		whichDirection = rand() % 4;

		if (whichDirection == 0)
		{
			if (monster->y <= -1)
			{
				monster->y += 10;
			}
			else if (monster->y > 100)
			{
				monster->y -= 10;
			}
			else if (monster->y >= 10)
			{
				monster->y += 5;
			}
			else
			{
				monster->y += 1;
			}
		}

		if (whichDirection == 1)
		{
			if (monster->y <= -1)
			{
				monster->y += 10;
			}
			else if (monster->y > 100)
			{
				monster->y -= 10;
			}
			else if (monster->y >= 10)
			{
				monster->y -= 5;
			}
			else
			{
				monster->y -= 1;
			}
		}

		if (whichDirection == 2)
		{
			if (monster->x <= -1)
			{
				monster->x += 10;
			}
			else if (monster->x > 100)
			{
				monster->x -= 10;
			}
			else if (monster->y >= 10)
			{
				monster->x += 5;
			}
			else
			{
				monster->x += 1;
			}
		}

		if (whichDirection == 3)
		{
			if (monster->x <= -1)
			{
				monster->x += 10;
			}
			else if (monster->x > 100)
			{
				monster->x -= 10;
			}
			else if (monster->y >= 10)
			{
				monster->x -= 5;
			}
			else
			{
				monster->x -= 1;
			}
		}

		monster = monster->nextMonster;
	}
}

