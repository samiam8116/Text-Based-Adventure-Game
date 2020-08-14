#pragma once
#include "Item.h"
#include <string>

class Health : public Item
{
public:
	Health(std::string item, std::string message, int health);
	int GetHealth();
private:
	int health;
};