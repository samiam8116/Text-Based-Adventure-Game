#pragma once
//enemy class
#include <string>

//abstract class
class PublicSpeaking
{
public:
	PublicSpeaking(std::string name, std::string message, int strength, int damage);
	void Demos(std::string name, std::string message, int strength, int damage);
	void Asking4Help(std::string name, std::string message, int strength, int damage);
	void GroupWork(std::string name, std::string message, int strength, int damage);

	virtual std::string EnemyMessage();
	virtual int GiveDamage();
	virtual int ShowStrength();

	void hideInTheCorner();
	void skipClass();
	void bailOnDemo();
private:
	std::string name;
	int damage;
	int strength;
	std::string message;
};