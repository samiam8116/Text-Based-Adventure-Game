#pragma once
//enemy class
#include <string>

//abstract class
class Assignments
{
public:
	Assignments(std::string name, std::string message, int strength, int damage);
	void Labs(std::string name, std::string message, int strength, int damage);
	void Homework(std::string name, std::string message, int strength, int damage);
	void Projects(std::string name, std::string message, int strength, int damage);

	virtual std::string EnemyMessage();
	virtual int GiveDamage();
	virtual int ShowStrength();

	void study();
	void focus();
	void finishAssignment();
private:
	std::string name;
	int strength;
	int damage;
	std::string message;
};