#include "Player.h"

// By Roberto Reynoso

Player::Player()
{
	
}

Player::~Player()
{
	
}

void Player::namePlayer()
{
	while (true)
	{
		size_t constexpr sizeMonsterArray = sizeof(playerName);
		std::cout << "Player Name: ";
		std::cin >> playerName;

		if (strlen(playerName) > sizeMonsterArray or strlen(playerName) < 0)
		{
			std::cout << "Player Name has to at least be 1 Character or Up to 5" << std::endl;
		}
		else
		{
			break;
		}
	}
}

void Player::playerMovement(Monster* monster)
{
	movement[0] = ' ';
	while (true)
	{
		std::cout << "TO ESCAPE YOU MUST GET TO THE LOCATION X: 50 AND Y:50!" << std::endl;
		std::cout << std::endl <<  "Move Player (w -> up, a -> left, d -> right, s -> down, m -> add monster, q -> quit): ";
		movement[0] = _getch();
		std::cout << movement[0] << std::endl;

		if (movement[0] == 'w' ||
			movement[0] == 'a' ||
			movement[0] == 's' ||
			movement[0] == 'd' ||
			movement[0] == 'm' || 
			movement[0] == 'q')
		{
			break;
		}

	}

	if (movement[0] == 'w')
	{
		y += 5;
		numMovements += 1;
	}

	if (movement[0] == 's')
	{
		y -= 5;
		numMovements += 1;
	}

	if (movement[0] == 'd')
	{
		x += 5;
		numMovements += 1;
	}

	if (movement[0] == 'a')
	{
		x -= 5;
		numMovements += 1;
	}

	if (movement[0] == 'm')
	{
		addMonsterByKey = true;
	}

	if (movement[0] == 'q')
	{
		numMovements = 0;
		endGame = true;
		std::cout << std::endl << "Thanks For Playing";
	}



	
}
