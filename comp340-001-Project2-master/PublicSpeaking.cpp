//enemy class
#include "PublicSpeaking.h"

PublicSpeaking::PublicSpeaking(std::string name, std::string message, int damage)
{
	this->name = name;
	this->message = message;
	this->damage = damage;
}

void PublicSpeaking::Demos(std::string name, std::string message, int damage)
{
	this->name = name;
	this->message = message;
	this->damage = damage;
}

void PublicSpeaking::Asking4Help(std::string name, std::string message, int damage)
{
	this->name = name;
	this->message = message;
	this->damage = damage;
}

void PublicSpeaking::GroupWork(std::string name, std::string message, int damage)
{
	this->name = name;
	this->message = message;
	this->damage = damage;
}
int PublicSpeaking::GiveDamage()
{
	return this->damage;
}

std::string PublicSpeaking::EnemyMessage()
{
	return this->message;
}


