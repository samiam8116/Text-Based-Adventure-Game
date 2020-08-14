#include "Weapon.h"

Weapon::Weapon(std::string item, std::string message, int strength, int damage) : Item(item, message)
{
	this->strength = strength;
	this->damage = damage;
}

int Weapon::GetStrength()
{
	return this->strength;
}

int Weapon::GetDamage()
{
	return this->damage;
}

void Weapon::LoseDamage()
{
	this->damage = this->damage - 1;
}