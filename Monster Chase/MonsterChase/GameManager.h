#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <iostream>
#include <time.h>
#include "Monster.h"
#include "Player.h"
#include "GLib.h"
#include "GameObject.h"

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <Windows.h>

#include <DirectXColors.h>

#if defined _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif // _DEBUG

// By Roberto Reynoso

class GameManager
{
private:
	int numMonsters;
	bool bQuit;



public:

	GameManager();
	~GameManager();

	void initialAddMonster();
	void addMonster(Monster* monster);
	void addNewMonster(Monster* monster);
	void removeMonster(int ind, Monster* monster);
	void randomAddMonster(Monster* monster, Player* player);
	void keyPressAddMonster(Monster* monster, Player* player);
	void sameLocationAddMonster(Monster* monster);
	void timerDestroyMonster(Monster* monster, Player* player);
	void sortIndexMonster(Monster* monster);
	bool validIndexMonster(int ind);

	void playerEscape(Player* player);
	void playerCaught(Monster* monster, Player* player);

	void keyPressEndGame(Player* player);
	void displayGame(Monster* monster, Player* player, GameObject& io_Object);
	void runGame(Monster *monster, Player* player, bool intialize, GameObject& io_Object);

	void shutDown(Monster* monster, Player* player);

	void createSprite(bool bSuccess);
	void renderSprite(GLib::Sprite* spr, float _x, float _y);
	void releaseSprite(GLib::Sprite* spr);


};

#endif
