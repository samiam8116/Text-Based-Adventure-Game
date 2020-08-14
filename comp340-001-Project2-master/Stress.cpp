//enemy class
#include "Stress.h"

Stress::Stress(std::string name, std::string message, int strength, int damage)
{
	this->name = name;
	this->message = message;
	this->strength = strength;
	this->damage = damage;
}

int Stress::ShowStrength()
{
	return this->strength; 
}

void Stress::TooManyDueDates(std::string name, std::string message, int strength, int damage)
{
	this->name = name;
	this->message = message;
	this->strength - strength;
	this->damage = damage;
}

void Stress::LackofSleep(std::string name, std::string message, int strength, int damage)
{
	this->name = name;
	this->message = message;
	this->strength - strength;
	this->damage = damage;
}

void Stress::PilingUp(std::string name, std::string message, int strength, int damage)
{
	this->name = name;
	this->message = message;
	this->strength - strength;
	this->damage = damage;
}

int Stress::GiveDamage()
{
	return this->damage;
}

std::string Stress::EnemyMessage()
{
	return this->message;
}

void Stress::procrastination() {
	strength = strength - 10;
}

void Stress::netflixBinge() {
	strength = strength - 10;
}

void Stress::ignoreAndTakeANap() {
	strength = strength - 10;
}