
#include "Health.h"

Health::Health(std::string item, std::string message, int health) : Item(item, message)
{
	this->health = health;
}

int Health::GetHealth()
{
	return this->health;
}