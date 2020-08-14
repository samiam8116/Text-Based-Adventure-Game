#pragma once
//enemy class
#include <string>

//abstract class
class FinalProject
{
public:
	FinalProject(std::string name, std::string message, int strength, int damage);
	virtual std::string EnemyMessage();
	virtual int GiveDamage();
	virtual int ShowStrength();
private:
	std::string name;
	int damage;
	int strength;
	std::string message;
};