//enemy class
#include "FinalProject.h"

FinalProject::FinalProject(std::string name, std::string message, int strength, int damage)
{
	this->name = name;
	this->message = message;
	this->strength = strength;
	this->damage = damage;
}

int FinalProject::ShowStrength()
{
	return this->strength;
}
int FinalProject::GiveDamage()
{
	return this->damage;
}

std::string FinalProject::EnemyMessage()
{
	return this->message;
}