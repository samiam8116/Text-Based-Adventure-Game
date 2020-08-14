#pragma once
//enemy class
#include <string>

//abstract class
class Anxiety
{
public:
	Anxiety(std::string name, std::string message, int strength, int damage);
	void BeingLate(std::string name, std::string message, int strength, int damage);
	void CodingAnxiety(std::string name, std::string message, int strength, int damage);
	void FrontRowAnxiety(std::string name, std::string message, int strength, int damage);
	virtual std::string EnemyMessage();
	virtual int GiveDamage();
	virtual int ShowStrength();
private:
	std::string name;
	int strength;
	int damage;
	std::string message;
};