//enemy class
#include "Assignments.h"

Assignments::Assignments(std::string name, std::string message, int strength, int damage)
{
	this->name = name;
	this->message = message;
	this->strength = strength;
	this->damage = damage;
}

void Assignments::Labs(std::string name, std::string message, int strength, int damage)
{
	this->name = name;
	this->message = message;
	this->strength = strength;
	this->damage = damage;
}

void Assignments::Homework(std::string name, std::string message, int strength, int damage)
{
	this->name = name;
	this->message = message;
	this->strength - strength;
	this->damage = damage;
}

void Assignments::Projects(std::string name, std::string message, int strength, int damage)
{
	this->name = name;
	this->message = message;
	this->strength - strength;
	this->damage = damage;
}
int Assignments::GiveDamage()
{
	return this->damage;
}
int Assignments::ShowStrength()
{
	return this->strength; 
}
std::string Assignments::EnemyMessage()
{
	return this->message;
}

void Assignments::study() {
	strength = strength - 20;
}

void Assignments::finishAssignment() {
	strength = strength - 20;
}

void Assignments::focus() {
	strength = strength - 20;
}