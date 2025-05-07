#include "GameManager.h"


// By Roberto Reynoso!

GameManager::GameManager()
{
	
}

GameManager::~GameManager()
{
	
}

void GameManager::displayGame(Monster* monster, Player* player, GameObject& io_Object)
{
	Monster* copyMonster = monster;

	do
	{
		// IMPORTANT: We need to let GLib do it's thing. 
		GLib::Service(bQuit);

		/*while (monster->activateMonster)
		{
			std::cout << "Monster Name: " << monster->monsterName << " | Monster Number: " << monster->indexMonster
				<< " | Monster Location x: " << monster->x << " y:" << monster->y << std::endl;

			renderSprite(monster->pBadGuy, monster->x, monster->y);
			monster = monster->nextMonster;
		}*/
		std::cout << std::endl;
		std::cout << "Player: " << player->playerName
			<< " | Player Location x: " << player->x << " y:" << player->y << std::endl;



		renderSprite(player->pGoodGuy, io_Object.positionX, io_Object.positionY);

		monster = copyMonster;

	} while (bQuit == false);

	monster = copyMonster;

	releaseSprite(player->pGoodGuy);

	while (monster->activateMonster)
	{
		releaseSprite(monster->pBadGuy);
		monster = monster->nextMonster;
	}

	// IMPORTANT:  Tell GLib to shutdown, releasing resources.
	GLib::Shutdown();
}

void GameManager::shutDown(Monster* monster, Player* player)
{
	while (monster->activateMonster)
	{
		releaseSprite(monster->pBadGuy);
		monster = monster->nextMonster;
	}

	releaseSprite(player->pGoodGuy);

	// IMPORTANT:  Tell GLib to shutdown, releasing resources.
	GLib::Shutdown();
}


void GameManager::runGame(Monster* monster, Player* player, bool initialize, GameObject& io_Object)
{

	if (initialize)
	{

		std::cout << "Weclome to Monster Chase!" << std::endl;

		this->createSprite(initialize);

		if (numMonsters < 1)
		{
			// player->namePlayer();
			initialAddMonster();
			addMonster(monster);
			displayGame(monster, player, io_Object);
		}

		/*while (true)
		{
			player->playerMovement(monster);
			monster->monsterMovement(monster);
			timerDestroyMonster(monster, player);
			randomAddMonster(monster, player);
			keyPressAddMonster(monster, player);
			sameLocationAddMonster(monster);
			playerCaught(monster, player);
			playerEscape(player);
			keyPressEndGame(player);
			displayGame(monster, player);
		}*/
	}
	
}

void GameManager::sortIndexMonster(Monster* monster)
{
	int placeMonster = 0;
	while (true)
	{
		if (monster->activateMonster == true)
		{
			monster->indexMonster = placeMonster;
			placeMonster++;
			monster = monster->nextMonster;
		}
		else
		{
			break;
		}
	}
}

bool GameManager::validIndexMonster(int ind)
{
	if (ind < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}


void GameManager::initialAddMonster()
{
	//std::cout << "How many Monsters would you like to start with: ";
	//std::cin >> numMonsters;

	//while (std::cin.fail())
	//{
	//	std::cin.clear();
	//	// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//	std::cout << "Must be an int" << std::endl;

	//	std::cout << "How many Monsters would you like to start with: ";
	//	std::cin >> numMonsters;
	//}

	numMonsters = 5;
}

void GameManager::addMonster(Monster* monster)
{
	int count = 0;
	Monster* copyMonster = monster;
	while (count < numMonsters)
	{
		if (monster->activateMonster == false)
		{
			monster->activateMonster = true;
			//monster->nameMonster();
			//monster->pBadGuy = CreateSprite("data\\BadGuy.dds");
			monster->x *= numMonsters;
			monster->y *= numMonsters;
			monster->nextMonster = new Monster();
			count += 1;
		}
		else
		{
			monster = monster->nextMonster;
			monster->x = count + 1;
			monster->y = count + 1;
		}
		sortIndexMonster(copyMonster);
		
	}
	
}

void GameManager::addNewMonster(Monster* monster)
{
	int count = 1;
	Monster* copyMonster = monster;
	while (true)
	{
		if (monster->activateMonster == false)
		{
			monster->activateMonster = true;
			monster->nameMonster();
			monster->x *= count * numMonsters;
			monster->y *= count * numMonsters;
			monster->nextMonster = new Monster();
			break;
		}

		monster = monster->nextMonster;
		count += 1;
	}
	sortIndexMonster(copyMonster);
	
}




void GameManager::removeMonster(int ind, Monster* monster)
{
	Monster* copyMonster = monster;
	Monster* shiftMonster = new Monster();

	while (true)
	{
		if (!validIndexMonster(ind))
		{
			break;
		}

		if (ind == 0)
		{
			monster = monster->nextMonster;
			break;
		}

		if (monster->indexMonster == ind)
		{
			shiftMonster = monster->nextMonster;
			delete monster;
			break;
		}

		monster = monster->nextMonster;
		
	}
	while (true)
	{
		if (!validIndexMonster(ind))
		{
			break;
		}

		if (ind == 0)
		{
			break;
		}

		if (copyMonster->indexMonster == (ind - 1))
		{
			copyMonster->nextMonster = shiftMonster;
			break;

		}
		copyMonster = copyMonster->nextMonster;

	
	}

	if (ind == 0)
	{
		sortIndexMonster(monster);
	}
	else
	{
		sortIndexMonster(copyMonster);
	}
}

void GameManager::timerDestroyMonster(Monster* monster, Player* player)
{
	Monster* copyMonster = monster;
	int count = -1;
	time_t t;
	srand((unsigned)time(&t));
	
	if (player->numMovements >= 5)
	{
		while (monster->activateMonster == true)
		{
			count += 1;
			monster = monster->nextMonster;
		}

		int willDelete = (rand() % count);
		std::cout << std::endl << "DESTROYED MONSTER NUMBER: " << willDelete << " AND RESET NUMBERS!"<< std::endl;
		removeMonster(willDelete, copyMonster);
		player->numMovements = 0;
	}
}


void GameManager::randomAddMonster(Monster* monster, Player* player)
{
	if (player->numMovements >= 2)
	{
		time_t t;
		srand((unsigned)time(&t));
		int willAdd = (rand() % 50) + 1;

		if (willAdd > 35)
		{
			std::cout << std::endl << "RANDOM MONSTER APPEARED!" << std::endl;
			addNewMonster(monster);
		}
	}

}

void GameManager::keyPressAddMonster(Monster* monster, Player* player)
{
	if (player->addMonsterByKey)
	{
		addNewMonster(monster);
		player->addMonsterByKey = false;
	}
}

void GameManager::sameLocationAddMonster(Monster* monster)
{
	Monster* copyMonster = monster;
	Monster *checkMonster = copyMonster;

	while (true)
	{
		while (checkMonster->activateMonster)
		{
			if (monster->x == checkMonster->x && monster->y == checkMonster->y && checkMonster->indexMonster != monster->indexMonster)
			{
				std::cout << std::endl << "SAME LOCATION MONSTER... MADE A NEW ONE APPEAR" << std::endl;
				monster->x += 5;
				monster->y += 5;
				checkMonster->x -= 3;
				checkMonster->y -= 3;
				addNewMonster(copyMonster);
			}
			checkMonster = checkMonster->nextMonster;
		}

		if(monster->nextMonster->activateMonster == false)
		{
			break;
		}

		monster = monster->nextMonster;
		checkMonster = copyMonster;
	}
	sortIndexMonster(copyMonster);
	
}

void GameManager::playerEscape(Player* player)
{
	if (player->x == 50 && player->y == 50)
	{
		std::cout << std::endl << "You win!";
		_exit(0);
	}
	
}

void GameManager::playerCaught(Monster* monster, Player* player)
{
	Monster* checkMonster = monster;

	while (true)
	{
		while (checkMonster->activateMonster)
		{
			if (player->x == checkMonster->x && player->y == checkMonster->y)
			{
				std::cout << std::endl << "Monster Caught YOU, you can keep going though... Try not to get caught again.." << std::endl;
				checkMonster->x -= 3;
				checkMonster->y -= 3;
			}
			checkMonster = checkMonster->nextMonster;
		}

		break;

	}

}

void GameManager::keyPressEndGame(Player* player)
{
	if (player->endGame)
	{
		_exit(0);
	}
}

void GameManager::createSprite(bool bSuccess)
{
	if (bSuccess)
	{
		// IMPORTANT (if we want keypress info from GLib): Set a callback for notification of key presses
		//GLib::SetKeyStateChangeCallback(TestKeyCallback);
		bQuit = false;
	}

	bQuit = true;
}

void GameManager::renderSprite(GLib::Sprite* spr, float _x, float _y)
{
	if (!bQuit)
	{
		// IMPORTANT: Tell GLib that we want to start rendering
		GLib::BeginRendering(DirectX::Colors::Blue);
		// Tell GLib that we want to render some sprites
		GLib::Sprites::BeginRendering();

		static float			moveDistX = _x;
		static float			moveDirX = moveDistX;
		static float			moveDistY = _y;
		static float			moveDirY = moveDistY;

		static GLib::Point2D	Offset = { -180.0f, -100.0f };

		if (Offset.x < -220.0f)
			moveDirX = moveDistX;
		else if (Offset.x > -140.0f)
			moveDirX = -moveDistX;

		Offset.x += moveDirX;

		if (Offset.y < -220.0f)
			moveDirY = moveDistY;
		else if (Offset.y > -140.0f)
			moveDirY = -moveDistY;

		Offset.y += moveDirY;

	// Tell GLib to render this sprite at our calculated location
	GLib::Render(*spr, Offset, 0.0f, 0.0f);
	}

	// Tell GLib we're done rendering sprites
	GLib::Sprites::EndRendering();
	// IMPORTANT: Tell GLib we're done rendering
	GLib::EndRendering();
}


void GameManager::releaseSprite(GLib::Sprite* spr)
{
	if (spr)
		GLib::Release(spr);
}





