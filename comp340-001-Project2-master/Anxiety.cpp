//enemy class
#include "Anxiety.h"

Anxiety::Anxiety(std::string name, std::string message, int strength, int damage)
{
	this->name = name;
	this->message = message;
	this->strength - strength;
	this->damage = damage;
}

void Anxiety::BeingLate(std::string name, std::string message, int strength, int damage)
{
	this->name = name;
	this->message = message;
	this->strength = strength;
	this->damage = damage;
}

void Anxiety::CodingAnxiety(std::string name, std::string message, int strength, int damage)
{
	this->name = name;
	this->message = message;
	this->strength - strength;
	this->damage = damage;
}

void Anxiety::FrontRowAnxiety(std::string name, std::string message, int strength, int damage)
{
	this->name = name;
	this->message = message;
	this->strength - strength;
	this->damage = damage;
}

int Anxiety::ShowStrength()
{
	return this->strength;
}

int Anxiety::GiveDamage()
{
	return this->damage;
}

std::string Anxiety::EnemyMessage()
{
	return this->message;
}