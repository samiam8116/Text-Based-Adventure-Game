#pragma once
//enemy class
#include <string>

//abstract class
class Stress
{
public:
	Stress(std::string name, std::string message, int strength, int damage);
	void TooManyDueDates(std::string name, std::string message, int strength, int damage);
	void LackofSleep(std::string name, std::string message, int strength, int damage);
	void PilingUp(std::string name, std::string message, int strength, int damage);
	//classwork from other classes piling up
	virtual std::string EnemyMessage();
	virtual int GiveDamage();
	virtual int ShowStrength();

	void procrastination();
	void netflixBinge();
	void ignoreAndTakeANap();
private:
	std::string name;
	int strength;
	int damage;
	std::string message;
};