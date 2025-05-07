#ifndef MONSTER_H
#define MONSTER_H
#include <time.h>
#include <iostream>

#include "GLib.h";

// By Roberto Reynoso

class Monster
{
public:
	GLib::Sprite* pBadGuy;

	// Monster attributes
	int x = 1;
	int y = 1;
	int indexMonster = -1;
	bool activateMonster = false;
	char monsterName[5];

	// Next Monster Object
	Monster* nextMonster;

	// Constructors
	Monster();
	~Monster();

	// Functions for Monster Object
	void nameMonster();
	void monsterMovement(Monster* monster);

};







#endif // MONSTER_H
