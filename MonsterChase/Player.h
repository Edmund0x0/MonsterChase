#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Monster.h"
#include <iostream>
#include <conio.h>

#include "GLib.h"

// By Roberto Reynoso

class Player
{
public:
	GLib::Sprite* pGoodGuy;

	int x = 0;
	int y = 0;
	int numMovements = 0;
	char playerName[5];
	char movement[1];
	bool addMonsterByKey = false;
	bool endGame = false;

	Player();
	~Player();

	void namePlayer();
	void playerMovement(Monster* monster);

};

#endif 