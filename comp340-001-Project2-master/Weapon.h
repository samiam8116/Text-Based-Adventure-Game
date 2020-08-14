#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(std::string item, std::string message, int strength, int damage);
	int GetStrength();
	int GetDamage();
	void LoseDamage();
private:
	int strength;
	int damage;
};