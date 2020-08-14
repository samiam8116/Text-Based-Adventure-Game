#include "Room.h"
#include "StoryItem.h"
#include "Health.h"
#include "Weapon.h"
#include "Assignments.h"
#include "PublicSpeaking.h"
#include "Anxiety.h"
#include "Stress.h"
#include "FinalProject.h"
#include <vector>
#include <iostream>
#include <list>
#include <string>


int main()
{
	int health = 100;
	Room *currentRoom;
	std::vector <Room*>classroom;

	std::list < std::string > inventorylist;

	//StoryItem
	StoryItem* agenda = new StoryItem("agenda", "May 14th: Final Presentation.");
	StoryItem* connect_card = new StoryItem("connect card", "This card gives you access to the classroom.");
	StoryItem* flash_drive = new StoryItem("flash drive", "You'll need this flash drive if you want to have a successful presentation.");

	//Health
	Health* coffee = new Health("coffee", "Drink the coffee for energy!", 15);
	Health* energy_drink = new Health("Five hour engery", "Drink the energy drink for some much needed energy!", 20);
	Health* snack = new Health("granola bar", "Eat the granola bar if you are low in health.", 15);
	Health* apple = new Health("rotten apple", "This apple has been in the classroom just a little too long.", 20);

	//weapons
	Weapon* pencil = new Weapon("pencil", "An ordinary #2 pencil.", 8, 10);
	Weapon* flash_cards = new Weapon("flash cards", "Just in case you need a little help with presenting.", 5, 20);
	Weapon* book = new Weapon("book", "This is an awfully heavy book... hehehe", 4, 25);

	//enemies
	Assignments* lab = new Assignments("Lab enemy", "A Lab enemy is in your path! Defeat it!", 50, 10);
	Assignments* homework = new Assignments("Homework enemy", "Oh no... a Homework Enemy is here....dun dun dun.", 50, 10);
	Assignments* project = new Assignments("Project enemy", "You are faced with a Project enemy! It's  taunting you, how rude.", 50, 10);

	PublicSpeaking* demo = new PublicSpeaking("Demo enemy", "Oh no you have ran into a Demo enemy. What will you do? You should probably bail so you don't look like a fool.", 35, 7);
	PublicSpeaking* askForHelp = new PublicSpeaking("Ask For Help enemy", "Uh oh you are faced with an Ask For Help enemy... you should probably just hide in the corner.", 35, 7);
	PublicSpeaking* groupWork = new PublicSpeaking("Group Work enemy", "A Group Work enemy has appeared!! um... what will you do to defeat it?", 35, 7);

	Anxiety* beingLate = new Anxiety("Being Late enemy", "Oh no you are faced with a Being Late enemy... RUNNnnnNNNNN!", 25, 4);
	Anxiety* codingAnxiety = new Anxiety("Coding Anxiety enemy", "A Coding Anxiety enemy has appeared! You gotta deal with this guy, but how?", 25, 4);
	Anxiety* frontRowAnxiety = new Anxiety("Fron Row Anxiety enemy", "Oh lord you are in the front row.. that can only mean one thing...a Front Row Anxiety enemy is here for you to battle!", 25, 4);

	Stress* tooManyDueDates = new Stress("Too Many Due Dates enemy", "Oh no a Too Many Due Dates enemy is SURROUNDING YOU!!!! AHHH!!!!", 25, 4);
	Stress* lackOfSleep = new Stress("Lack Of Sleep enemy", "Yawn... a Lack Of Sleep enemy is staring at you blankly.. you should probably do something about that... nap time?", 25, 4);
	Stress* pilingUp = new Stress("Work Piling Up enemy", "A Work Piling Up enemy is charging at you!! TIME TO FREAK OUT!!", 25, 4);

	FinalProject* finalProject = new FinalProject("Final Project enemy", "It's time. The Final Project boss is here.", 20, 100);

	std::string userInput;

	//bool if doors are open or not
	bool car_door = false;
	bool classroom_door = false;
	bool card_used = false;

	//bool if items are used
	bool coffee_used = false;
	bool drink_used = false;
	bool snack_used = false;
	bool apple_used = false;

	//layout of rooms
	classroom.push_back(new Room("In Vehicle", agenda));	//classroom[0]
	classroom.push_back(new Room("Parking Lot", pencil));	//classroom[1]
	classroom.push_back(new Room("Math and Science Building Lobby", coffee));	//classroom[2]
	classroom.push_back(new Room("Hallway", connect_card));	//classroom[3]
	classroom.push_back(new Room("Classroom: Back Aisle - Right", energy_drink));	//classroom[4]
	classroom.push_back(new Room("Classroom: Back Aisle - Right Center", agenda)); //classroom[5]
	classroom.push_back(new Room("Classroom: Back Aisle - Center", agenda));  //classroom[6]
	classroom.push_back(new Room("Classroom: Back Aisle - Left Center", agenda));  //classroom[7]
	classroom.push_back(new Room("Classroom: Back Aisle - Left", agenda));	//classroom[8]
	classroom.push_back(new Room("Classroom: Middle Aisle - Left", agenda));  //classroom[9]
	classroom.push_back(new Room("Classroom: Middle Aisle - Left Center", agenda));  //classroom[10]
	classroom.push_back(new Room("Classroom: Middle Aisle - Center", agenda)); //classroom[11]
	classroom.push_back(new Room("Classroom: Middle Aisle - Right Center", apple)); //classroom[12]
	classroom.push_back(new Room("Classroom: Middle Aisle - Right", snack)); //classroom[13]
	classroom.push_back(new Room("Classroom: Front Aisle - Right", flash_drive)); //classroom[14]
	classroom.push_back(new Room("Classroom: Front Aisle - Right Center", agenda)); //classroom[15]
	classroom.push_back(new Room("Classroom: Front Aisle - Center", agenda)); //classroom[16]
	classroom.push_back(new Room("Classroom: Front Aisle - Left Center", agenda)); //classroom[17]
	classroom.push_back(new Room("Classroom: Front Aisle - Left", agenda));  //classroom[18]	
	classroom.push_back(new Room("Podium", flash_cards));	//classroom[19]

  //order is N,E,S,W
	classroom[0]->connectRooms(nullptr, nullptr, nullptr, classroom[1]);
	classroom[1]->connectRooms(classroom[2], classroom[0], nullptr, nullptr);
	classroom[2]->connectRooms(classroom[3], nullptr, classroom[1], nullptr);
	classroom[3]->connectRooms(nullptr, nullptr, classroom[2], classroom[4]);
	classroom[4]->connectRooms(classroom[13], classroom[3], nullptr, classroom[5]);
	classroom[5]->connectRooms(classroom[12], classroom[4], nullptr, classroom[6]);
	classroom[6]->connectRooms(classroom[11], classroom[5], nullptr, classroom[7]);
	classroom[7]->connectRooms(classroom[10], classroom[6], nullptr, classroom[8]);
	classroom[8]->connectRooms(classroom[9], classroom[7], nullptr, nullptr);
	classroom[9]->connectRooms(classroom[18], classroom[10], classroom[8], nullptr);
	classroom[10]->connectRooms(classroom[17], classroom[11], classroom[7], classroom[9]);
	classroom[11]->connectRooms(classroom[16], classroom[12], classroom[6], classroom[10]);
	classroom[12]->connectRooms(classroom[15], classroom[13], classroom[5], classroom[11]);
	classroom[13]->connectRooms(classroom[14], nullptr, classroom[4], classroom[12]);
	classroom[14]->connectRooms(nullptr, nullptr, classroom[13], classroom[15]);
	classroom[15]->connectRooms(nullptr, classroom[14], classroom[12], classroom[16]);
	classroom[16]->connectRooms(nullptr, classroom[15], classroom[11], classroom[17]);
	classroom[17]->connectRooms(nullptr, classroom[16], classroom[10], classroom[18]);
	classroom[18]->connectRooms(classroom[19], classroom[17], classroom[9], nullptr);
	classroom[19]->connectRooms(nullptr, nullptr, classroom[18], nullptr);

	currentRoom = classroom[0];

	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - -\n";
	std::cout << "Welcome to the adventure game...\n";
	std::cout << "THE GIRLS IN THE BACK: JOURNEY TO THE FRONT\n";
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - -\n";
	std::cout << "This is an action-packed game taking you through the journey of three college students: Elder Sarah, Sam & The Other Sam\n";
	std::cout << "These students are on a journey to the front of the classroom... grounds they have never touoched before... to complete their final mission of the semester.\n";
	std::cout << "BEWARE... there are many enemies and obstacles on the way to The Front...\n";
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - -\n";
	std::cout << "Enter 'help' for commands and 'quit' to stop at anytime!\n";
	std::cout << "...Good luck!\n\n";

	std::cout << "Your current location: " << "\n";
	std::cout << currentRoom->getDescription() << std::endl;
	std::cout << currentRoom->getMessage() << std::endl;
	currentRoom->getItemMessage();

	while (userInput != "quit")
	{
		std::cout << "\t \t \t \t \t \t \t \t \t Your current health is " << health << "%" << ". \n";
		std::cout << ">";
		std::getline(std::cin, userInput);
		std::string firstWord = userInput.substr(0, userInput.find(" "));

		if (firstWord == "help")
		{
			std::cout << "Possible commands include: \n \n";
			std::cout << "go [direction] - directions include north, south, east, and west : move to another room \n";
			std::cout << "search : reprints the description of the current room \n";
			std::cout << "inventory : prints list of items that you have to use \n";
			std::cout << "take [item] : grab item from a room and store in inventory \n";
			std::cout << "look at [item] : get a description of the item from inventory \n";
			std::cout << "open door : open the door if there is a door in the room \n";
			std::cout << "quit - end the game \n";
		}
		if (firstWord == "go")
		{
			//since go and space are index as characters 0,1,2
			if (currentRoom->getRoom(userInput.substr(3))->getDescription() == "Classroom: Back Aisle - Right" && card_used == false)
			{
				std::cout << "The door seems locked by a card scanner.";
			}
			else if ((currentRoom->getRoom(userInput.substr(3))->getDescription() == "Parking Lot" && car_door == false) || (currentRoom->getRoom(userInput.substr(3))->getDescription() == "Classroom: Back Aisle - Right" && classroom_door == false))
			{
				std::cout << "You must open the door first";
			}


			// display ENEMIES in certain rooms
				// being late ENEMY
			if (currentRoom->getRoom(userInput.substr(3))->getDescription() == "Hallway")
			{
				std::cout << beingLate->EnemyMessage() << std::endl;
				std::cout << beingLate->ShowStrength() << std::endl;
			}
			//lack of sleep ENEMY 
			if (currentRoom->getRoom(userInput.substr(3))->getDescription() == "Classroom: Back Aisle - Right Center")
			{
				std::cout << lackOfSleep->EnemyMessage() << std::endl;
				std::cout << lackOfSleep->ShowStrength() << std::endl;
			}
			// demo ENEMY
			if (currentRoom->getRoom(userInput.substr(3))->getDescription() == "Classroom: Back Aisle - Left Center")
			{
				std::cout << demo->EnemyMessage() << std::endl;
				std::cout << demo->ShowStrength() << std::endl;
			}
			//homework ENEMY
			if (currentRoom->getRoom(userInput.substr(3))->getDescription() == "Classroom: Back Aisle - Left")
			{
				std::cout << homework->EnemyMessage() << std::endl;
				std::cout << homework->ShowStrength() << std::endl;
			}
			//ask for help ENEMY
			if (currentRoom->getRoom(userInput.substr(3))->getDescription() == "Classroom: Middle Aisle - Right")
			{
				std::cout << askForHelp->EnemyMessage() << std::endl;
				std::cout << askForHelp->ShowStrength() << std::endl;
			}
			//coding anxiety ENEMY
			if (currentRoom->getRoom(userInput.substr(3))->getDescription() == "Classroom: Middle Aisle - Center")
			{
				std::cout << codingAnxiety->EnemyMessage() << std::endl;
				std::cout << codingAnxiety->ShowStrength() << std::endl;
			}
			//too many due dates ENEMY
			if (currentRoom->getRoom(userInput.substr(3))->getDescription() == "Classroom: Middle Aisle - Left Center")
			{
				std::cout << tooManyDueDates->EnemyMessage() << std::endl;
				std::cout << tooManyDueDates->ShowStrength() << std::endl;
			}
			//lab	ENEMY
			if (currentRoom->getRoom(userInput.substr(3))->getDescription() == "Classroom: Middle Aisle - Left")
			{
				std::cout << lab->EnemyMessage() << std::endl;
				std::cout << lab->ShowStrength() << std::endl;
			}
			//group work ENEMY
			if (currentRoom->getRoom(userInput.substr(3))->getDescription() == "Classroom: Front Aisle - Right")
			{
				std::cout << groupWork->EnemyMessage() << std::endl;
				std::cout << groupWork->ShowStrength() << std::endl;
			}
			//front row anxiety SO REAL ENEMY
			if (currentRoom->getRoom(userInput.substr(3))->getDescription() == "Classroom: Front Aisle - Right Center")
			{
				std::cout << frontRowAnxiety->EnemyMessage() << std::endl;
				std::cout << frontRowAnxiety->ShowStrength() << std::endl;
			}
			//piling up ENEMY 
			if (currentRoom->getRoom(userInput.substr(3))->getDescription() == "Classroom: Front Aisle - Center")
			{
				std::cout << pilingUp->EnemyMessage() << std::endl;
				std::cout << pilingUp->ShowStrength() << std::endl;
			}
			//project enemy
			if (currentRoom->getRoom(userInput.substr(3))->getDescription() == "Classroom: Front Aisle - Left Center")
			{
				std::cout << project->EnemyMessage() << std::endl;
				std::cout << project->ShowStrength() << std::endl;
			}
			//final project FINAL BOSS ENEMY
			if (currentRoom->getRoom(userInput.substr(3))->getDescription() == "Podium")
			{
				std::cout << finalProject->EnemyMessage() << std::endl;
				std::cout << finalProject->ShowStrength() << std::endl;
			}
			else
			{
				currentRoom = currentRoom->getRoom(userInput.substr(3));
				std::cout << "\n Your current location: " << "\n";
				std::cout << currentRoom->getDescription() << std::endl;
				std::cout << currentRoom->getMessage() << std::endl;
				if (currentRoom->ItemTaken(inventorylist) == false)
				{
					currentRoom->getItemMessage();
				}

			}
		}
	
	if (firstWord == "search")
	{
		std::cout << "\n Your current location: " << "\n";
		std::cout << currentRoom->getDescription() << std::endl;
		std::cout << currentRoom->getMessage() << std::endl;
		if (currentRoom->ItemTaken(inventorylist) == false)
		{
			currentRoom->getItemMessage();
		}
	}
	if (firstWord == "inventory")
	{

		for (std::string stuff : inventorylist)
		{
			if (stuff == "coffee" && coffee_used == true)
			{
				stuff = "";
			}
			if (stuff == "energy drink" && drink_used == true)
			{
				stuff = "";
			}
			if (stuff == "granola bar" && snack_used == true)
			{
				stuff = "";
			}
			if (stuff == "rotten apple" && apple_used == true)
			{
				stuff = "";
			}
			if (stuff == "pencil" && pencil->GetDamage() <= 0)
			{
				stuff = "";
			}
			std::cout << stuff << "\n";
		}
	}
	if (firstWord == "take")
	{
		if (currentRoom->ItemName() == (userInput.substr(5)))
		{
			std::cout << "Taken: " << userInput.substr(5) << "\n";
			inventorylist.push_back(currentRoom->ItemName());
		}
		else
		{
			std::cout << "Can't take that!" << "\n";
		}
	}

	if (firstWord == "open")
	{
		if (currentRoom->getDescription() == "In Vehicle")
		{
			car_door = true;
			std::cout << "You've opened the door to get out of the car. \n";
		}
		if (currentRoom->getDescription() == "Hallway" && card_used == true)
		{
			classroom_door = true;
			std::cout << "You've opened the door to get into the Classroom. \n";
		}
	}

	if (firstWord == "look")  //user types in look at
	{
		for (std::string stuff : inventorylist)
		{
			if (stuff == (userInput.substr(8)))
			{
				if (stuff == "agenda")
				{
					std::cout << agenda->LookItem() << "\n";
				}
				if (stuff == "coffee")
				{
					std::cout << coffee->LookItem() << "\n";
				}
				if (stuff == "pencil")
				{
					std::cout << pencil->LookItem() << "\n";
				}
				if (stuff == "energy drink")
				{
					std::cout << energy_drink->LookItem() << "\n";
				}
				if (stuff == "granola bar")
				{
					std::cout << snack->LookItem() << "\n";
				}
				if (stuff == "connect card")
				{
					std::cout << connect_card->LookItem() << "\n";
				}
				if (stuff == "flash drive")
				{
					std::cout << flash_drive->LookItem() << "\n";
				}
				if (stuff == "flash cards")
				{
					std::cout << flash_cards->LookItem() << "\n";
				}
				if (stuff == "rotten apple")
				{
					std::cout << apple->LookItem() << "\n";
				}
			}
		}
	



		// COMBAT
		//hide - used on askForHelp enemy
		if (firstWord == "hide")
		{
			if (currentRoom->getDescription() == "Classroon Middle Aisle - Right")
			{
				askForHelp->hideInTheCorner();
				std::cout << "You hid from that Ask For Help enemy... nice one. This also resulted in losing 5" << "%" << " health. \n";
				if (askForHelp->ShowStrength() <= 0)
				{
					std::cout << "You succesfully hid from that Ask For Help enemy... totally the right move... :D" << "\n";
				}
				else
				{
					health = health - (askForHelp->GiveDamage());
					std::cout << "The Ask For Help enemy hits back. Your health is now at " << health << "%" << ". \n";
				}
			}
		}
			//skip - used on groupWork enemy
		if (firstWord == "skip")
		{
			if (currentRoom->getDescription() == "Classroon Front Aisle - Right")
			{
				groupWork->skipClass();
				std::cout << "You'll never have to deal with that Group Work enemy becuase you are skipping class! Yahoo! This also resulted in losing 5" << "%" << " health. \n";
				if (groupWork->ShowStrength() <= 0)
				{
					std::cout << "You succesfully skipped class!" << "\n";
				}
				else
				{
					health = health - (groupWork->GiveDamage());
					std::cout << "The Group Work enemy hits back. Your health is now at " << health << "%" << ". \n";
				}
			}
		}
		//bail - used on demo enemy
		if (firstWord == "bail")
		{
			if (currentRoom->getDescription() == "Classroon Back Aisle - Left Center")
			{
				demo->bailOnDemo();
				std::cout << "Great idea you bailed on the Demo enemy! This is such a good solution to you problem. This also resulted in losing 5" << "%" << " health. \n";
				if (demo->ShowStrength() <= 0)
				{
					std::cout << "You succesfully bailed on the Demo!" << "\n";
				}
				else
				{
					health = health - (demo->GiveDamage());
					std::cout << "The Demo enemy hits back. Your health is now at " << health << "%" << ". \n";
				}
			}
		}
		//procrastinate - used on pilingUp enemy
		if (firstWord == "procrastinate")
		{
			if (currentRoom->getDescription() == "Classroon Front Aisle - Center")
			{
				pilingUp->procrastinate();
				std::cout << "You used the power of procrastination to damage the Piling Up enemy! This also resulted in losing 10" << "%" << " health. \n";
				if (pilingUp->ShowStrength() <= 0)
				{
					std::cout << "You succesfully procrastinated!" << "\n";
				}
				else
				{
					health = health - (pilingUp->GiveDamage());
					std::cout << "The Piling Up enemy hits back. Your health is now at " << health << "%" << ". \n";
				}
			}
		}
		//netflix - used on tooManyDueDates enemy
		if (firstWord == "netflix")
		{
			if (currentRoom->getDescription() == "Classroon Middle Aisle - Left Center")
			{
				tooManyDueDates->netflixBinge();
				std::cout << "You used the power of binging Netflix to damage the Too Many Due Dates enemy! This also resulted in losing 10" << "%" << " health. \n";
				if (tooManyDueDates->ShowStrength() <= 0)
				{
					std::cout << "You succesfully binged Netflix!" << "\n";
				}
				else
				{
					health = health - (tooManyDueDates->GiveDamage());
					std::cout << "The Too Many Due Dates enemy hits back. Your health is now at " << health << "%" << ". \n";
				}
			}
		}
		//ignoreAndTakeANap - used on lackOfSleep enemy
		if (firstWord == "nap")
		{
			if (currentRoom->getDescription() == "Classroon Back Aisle - Right Center")
			{
				lackOfSleep->ignoreAndTakeANap();
				std::cout << "Zzzz... you take a nap to get rid of thei Lack Of Sleep enemy! This also resulted in losing 10" << "%" << " health. \n";
				if (lackOfSleep->ShowStrength() <= 0)
				{
					std::cout << "You succesfully took a nap !" << "\n";
				}
				else
				{
					health = health - (lackOfSleep->GiveDamage());
					std::cout << "The Lack Of Sleep enemy hits back. Your health is now at " << health << "%" << ". \n";
				}
			}
		}
		//study - used on homework enemy
		if (firstWord == "study")
		{
			if (currentRoom->getDescription() == "Classroon Back Aisle - Left")
			{
				homework->study();
				std::cout << "Wow you actually studied! I'm shocked and so is the Homework enemy. This also resulted in losing 20" << "%" << " health. \n";
				if (homework->ShowStrength() <= 0)
				{
					std::cout << "You succesfully studied !" << "\n";
				}
				else
				{
					health = health - (homework->GiveDamage());
					std::cout << "The Homework enemy hits back. Your health is now at " << health << "%" << ". \n";
				}
			}
		}
		//finishAssignment - used on lab enemy
		if (firstWord == "finish")
		{
			if (currentRoom->getDescription() == "Classroon Middle Aisle - Left")
			{
				lab->finishAssignment();
				std::cout << "Did you just finished the lab? Wow this never happens. The Lab enemy is stunned. This also resulted in losing 20" << "%" << " health. \n";
			}
			if (homework->ShowStrength() <= 0)
			{
			std::cout << "You succesfully finished the lab!" << "\n";
			}
			else
			{
			health = health - (lab->GiveDamage());
			std::cout << "The Lab enemy hits back. Your health is now at " << health << "%" << ". \n";
			}
		}
		//focus - used on project enemy
		if (firstWord == "focus")
		{
			if (currentRoom->getDescription() == "Classroon Front Aisle - Left Center")
			{
				project->focus();
				std::cout << "You are... focusing... watch out Project enemy... This also resulted in losing 20" << "%" << " health. \n";
				if (lab->ShowStrength() <= 0)
				{
					std::cout << "You succesfully focused!" << "\n";
				}
				else
				{
					health = health - (lab->GiveDamage());
					std::cout << "The Lab enemy hits back. Your health is now at " << health << "%" << ". \n";
				}
			}
		}
		if (firstWord == "use")
		{
			for (std::string stuff : inventorylist)
			{
				if (userInput.substr(4) == stuff)
				{
					if (stuff == "coffee" && coffee_used == false)
					{
						health = health + coffee->GetHealth();
						std::cout << "You drank a cup of coffee to give you some much needed energy.  Your current health is " << health << "%" << ". \n";
						coffee_used = true;
					}
					if (stuff == "energy drink" && drink_used == false)
					{
						health = health + energy_drink->GetHealth();
						std::cout << "You drank Five Hour Energy to give you some much needed energy.  Your current health is " << health << "%" << ". \n";
						drink_used = true;
					}
					if (stuff == "granola bar" && snack_used == false)
					{
						health = health + snack->GetHealth();
						std::cout << "You ate a granola bar.  Your current health is " << health << "%" << ". \n";
						snack_used = true;
					}
					if (stuff == "rotten apple" && snack_used == false)
					{
						health = health - apple->GetHealth();
						std::cout << "You ate a rotten apple.  Your current health is " << health << "%" << ". \n";
						apple_used = true;
					}
					if (stuff == "connect card" && currentRoom->getDescription() == "Hallway")
					{
						std::cout << "You now have access to the classroom. \n";
						card_used = true;
					}
					if (stuff == "pencil")
					{
						// butcher -> LoseLife(pin->GetStrength());
						// std::cout << "You hit the butcher. He now has " << butcher ->getLives() << "%" << " health left." << "\n";
						pencil->LoseDamage();
						if (pencil->GetDamage() <= 0)
						{
							std::cout << "You have used the pencil too many times and it snapped in half. \n";
						}
					}
					if (stuff == "flash cards")
					{
						// butcher -> LoseLife(pin->GetStrength());
						// std::cout << "You hit the butcher. He now has " << butcher ->getLives() << "%" << " health left." << "\n";
						flash_cards->LoseDamage();
						if (flash_cards->GetDamage() <= 0)
						{
							std::cout << "You have used the flash cards too many times and it tore in half. \n";
						}
					}
					if (stuff == "book")
					{
						// butcher -> LoseLife(pin->GetStrength());
						// std::cout << "You hit the butcher. He now has " << butcher ->getLives() << "%" << " health left." << "\n";
						book->LoseDamage();
						if (book->GetDamage() <= 0)
						{
							std::cout << "You have used the book too many times and all the pages fell out. \n";
						}
					}
				}
			}
		}
	}//user input while loop close
}//main close

								/*
								   //coded so sharon is the last person you face so once her lives reach 0 the game is over
								   while(userInput != "quit" && health > 0 && sharon ->getLives() >0)
								   {

								   if(firstWord == "help")
								   {

								   std::cout << "use [item] : use an item that is in your inventory \n";
								   std::cout << "punch : action to use in battle \n";

								   }
								   if(firstWord == "go")
								   {
								   //since go and space are index as characters 0,1,2
								   if((currentRoom->getRoom(userInput.substr(3)) ->getDescription() == "Manager's Office" && aisle_door == false) || (currentRoom->getRoom(userInput.substr(3)) ->getDescription() == "Supply Closet" && bakery_door ==false) || (currentRoom->getRoom(userInput.substr(3)) ->getDescription() == "Meat Freezer" && butcher_door == false))
								   {
								   std::cout << "You must open the door first. \n";
								   }
								   else
								   {
								   currentRoom = currentRoom -> getRoom(userInput.substr(3));
								   std::cout << "\n Your current location: " << "\n";
								   std::cout << currentRoom -> getDescription() << std::endl;
								   std::cout << currentRoom -> getMessage() << std::endl;
								   if(currentRoom->ItemTaken(inventorylist) == false)
								   {
								   currentRoom -> getItemMessage();
								   }
								   if(currentRoom->getDescription() == "Aisle 3" && money_aisle3 == false)
								   {
								   std::cout << kid->EnemyMessage() << std::endl;
								   health = health - (kid -> GiveDamage());
								   std::cout << baby->EnemyMessage() << std::endl;
								   health = health - (baby -> GiveDamage());
								   }
								   if(currentRoom->getDescription() == "Aisle 11" && money_aisle11 == false)
								   {
								   std::cout << teenager->EnemyMessage() << std::endl;
								   health = health - (teenager -> GiveDamage());
								   }
								   if(currentRoom->getDescription() == "Manager's Office" && steve -> getLives() > 0)
								   {
								   std::cout << steve->EnemyMessage() << std::endl;
								   }
								   if(currentRoom->getDescription() == "Meat Freezer" &&steve -> getLives() <= 0 && butcher -> getLives() > 0)
								   {
								   std::cout << butcher->EnemyMessage() << std::endl;
								   }
								   if(currentRoom->getDescription() == "Check Out Area" && steve -> getLives() <= 0 && butcher -> getLives() <= 0 && sharon -> getLives() > 0)
								   {
								   std::cout << sharon->EnemyMessage() << std::endl;
								   }
								   }
								   }
								   if(firstWord == "search")
								   {
								   std::cout << "Your current location: " << "\n";
								   std::cout << currentRoom -> getDescription() << std::endl;
								   std::cout << currentRoom -> getMessage() << std::endl;
								   if(currentRoom->ItemTaken(inventorylist) == false)
								   {
								   currentRoom -> getItemMessage();
								   }
								   if(currentRoom->getDescription() == "Manager's Office" && steve -> getLives() > 0)
								   {
								   std::cout << steve->EnemyMessage() << std::endl;
								   }
								   if(currentRoom->getDescription() == "Meat Freezer" && steve -> getLives() <= 0 && butcher -> getLives() > 0)
								   {
								   std::cout << butcher->EnemyMessage() << std::endl;
								   }
								   if(currentRoom->getDescription() == "Check Out Area" && steve -> getLives() <= 0 && butcher -> getLives() <= 0 && sharon -> getLives() > 0)
								   {
								   std::cout << sharon->EnemyMessage() << std::endl;
								   }
								   }







								   }
								   if(firstWord == "punch")
								   {
								   if(currentRoom->getDescription() == "Aisle 3" || currentRoom->getDescription() == "Aisle 11")
								   {
								   std::cout << "You can't hit children!!! \n";
								   }
								   if(currentRoom->getDescription() == "Manager's Office" && steve ->getLives() >0)
								   {
								   health = health -5;
								   steve->LoseLife(15);
								   std::cout << "You punched Steve, which also resulted in losing 5" << "%" << " health. \n";
								   if(steve -> getLives() <= 0)
								   {
								   std::cout << "Steve is no longer a threat.  Turns out he had nothing to do with the murder." << "\n";
								   }
								   else
								   {
								   health = health - (steve ->GiveDamage()) ;
								   std::cout << "Steve hits back.  Your health is now at " << health << "%" << ". \n";
								   }
								   }
								   if(currentRoom -> getDescription() == "Meat Freezer"&& steve -> getLives() <= 0 && butcher -> getLives() > 0)
								   {
								   health = health -5;
								   butcher->LoseLife(15);
								   std::cout << "You punched the butcher, which also resulted in losing 5" << "%" << " health. \n";
								   if(butcher -> getLives() <= 0)
								   {
								   std::cout << "The butcher is no longer a threat.  Turns out he had nothing to do with the murder, but he did tell you that Sharon was looking more upset than usual at the Check Out Area." << "\n";
								   }
								   else
								   {
								   health = health - (butcher ->GiveDamage()) ;
								   std::cout << "The butcher hits back.  Your health is now at " << health << "%" << ". \n";
								   }
								   }
								   if(currentRoom -> getDescription() == "Check Out Area" && steve -> getLives() <= 0 && butcher -> getLives() <= 0 && sharon -> getLives()>0)
								   {
								   health = health -5;
								   sharon->LoseLife(15);
								   std::cout << "You punched Sharon, which also resulted in losing 5" << "%" << " health. \n";
								   if(sharon -> getLives() <= 0)
								   {
								   std::cout << "Sharon is no longer a threat.  Turns out he had nothing to do with the murder." << "\n";
								   }
								   if(count == 2)
								   {
								   std::cout << "Sharon screams ''Wait, one last thing can you help me reach this thing off the top shelf?''. \n";
								   std::cout << "Do you wish to help Sharon? \n";
								   std::getline(std::cin, userInputa);
								   std::string answer = userInputa.substr(0, userInputa.find(" "));
								   if(userInputa == "yes")
								   {
								   std::cout << "You reached up and grabbed a bag of jelly beans. \n";
								   std::cout << "Do you still want to give them to Sharon? \n";
								   std::getline(std::cin, userInputb);
								   std::string answer = userInputb.substr(0, userInputb.find(" "));
								   if(userInputb == "no")
								   {
								   inventorylist.push_back("jelly beans");
								   std::cout << "You kept the jelly beans. \n";
								   }
								   else
								   {
								   std::cout << "You decide to give the jelly beans to Sharon, which she throws at you.  One hits you in the eye and impairs your vision, substantially affecting your health. \n ";
								   health = health /2;
								   }
								   }
								   else
								   {
								   std::cout << "Wow, didn't even want to help Sharon one last time.  Don't be distracted though, the battle is still on. \n";
								   }
								   }
								   if(sharon->getLives() >0)
								   {

								   health = health - (sharon ->GiveDamage()) ;
								   std::cout << "Sharon hits back.  Your health is now at " << health << "%" << ". \n";
								   }
								   count = count +1;
								   }
								   }
								   if(firstWord == "use")
								   {
								   for(std::string stuff : inventorylist)
								   {
								   if(userInput.substr(4) == stuff)
								   {


								   if((currentRoom-> getDescription() == "Aisle 3" || currentRoom->getDescription() == "Aisle 11") && (stuff == "butcher's knife" || stuff == "rolling pin" || stuff == "oven mitt"))
								   {
								   std::cout << "You can't hit children!!";
								   }
								   if(currentRoom-> getDescription() == "Aisle 3" && stuff == "money" && money_used == false)
								   {
								   money_aisle3 = true;
								   std::cout << "You bribed the children in this aisle with money.  They will no longer bother you." << "\n";
								   money_used = true;
								   }
								   if(currentRoom-> getDescription() == "Aisle 11" && stuff == "money" && money_used == false)
								   {
								   money_aisle11 = true;
								   std::cout << "You bribed the child in this aisle with money.  He will no longer bother you." << "\n";
								   money_used = true;
								   }
								   if(currentRoom -> getDescription() == "Manager's Office" && stuff == "keys" && keys_used == false)
								   {
								   std::cout << "You used the keys to open the cabinet and there is a note." << "\n";
								   keys_used = true;
								   }
								   if(currentRoom -> getDescription() == "Meat Freezer"&& steve -> getLives() <= 0 && butcher -> getLives() > 0 && ((stuff == "butcher's knife" && knife ->GetDamage() >0) || (stuff == "rolling pin" && pin ->GetDamage() >0) || (stuff == "oven mitt" && mitt ->GetDamage() >0)))
								   {
								   if(butcher->getLives() > 0)
								   {
								   if(stuff == "butcher's knife")
								   {
								   butcher ->LoseLife(knife->GetStrength());
								   std::cout << "You stabbed the butcher.  He now has " << butcher ->getLives() << "%" << " health left." << "\n";
								   knife -> LoseDamage();
								   if (knife -> GetDamage() <=0)
								   {
								   std::cout << "You have used the butcher's knife too many times and it broke. \n";
								   }
								   }
								   if(stuff == "rolling pin")
								   {
								   butcher -> LoseLife(pin->GetStrength());
								   std::cout << "You hit the butcher. He now has " << butcher ->getLives() << "%" << " health left." << "\n";
								   pin -> LoseDamage();
								   if (pin -> GetDamage() <=0)
								   {
								   std::cout << "You have used the rolling pin too many times and it snapped in half. \n";
								   }
								   }
								   if(stuff == "oven mitt")
								   {
								   butcher -> LoseLife(mitt->GetStrength());
								   std::cout << "You punched the butcher. He now has " << butcher ->getLives() << "%" << " health left." << "\n";
								   mitt -> LoseDamage();
								   if (mitt -> GetDamage() <=0)
								   {
								   std::cout << "You have used the oven mitt too many times and the seams have come apart. \n";
								   }
								   }

								   }
								   if(butcher -> getLives() <= 0)
								   {
								   std::cout << "The butcher is no longer a threat.  Turns out he had nothing to do with the murder, but he did tell you that Sharon was looking more upset than usual at the Check Out Area." << "\n";
								   }
								   else
								   {
								   health = health - (butcher ->GiveDamage()) ;
								   std::cout << "The butcher hits back.  Your health is now at " << health << "%" << ". \n";
								   }
								   }

								   if(currentRoom -> getDescription() == "Check Out Area" && steve -> getLives() <= 0 && butcher -> getLives() <= 0 && sharon -> getLives() > 0 && ((stuff == "butcher's knife" && knife ->GetDamage() >0) || (stuff == "rolling pin" && pin ->GetDamage() >0) || (stuff == "oven mitt" && mitt ->GetDamage() >0)))
								   {
								   if(sharon->getLives() > 0)
								   {
								   if(stuff == "butcher's knife")
								   {
								   sharon ->LoseLife(knife->GetStrength());
								   std::cout << "You stabbed Sharon. She now has " << sharon ->getLives() << "%" << " health left." << "\n";
								   knife ->LoseDamage();
								   if (knife -> GetDamage() <=0)
								   {
								   std::cout << "You have used the butcher's knife too many times and it broke. \n";
								   }
								   }
								   if(stuff == "rolling pin")
								   {
								   sharon -> LoseLife(pin->GetStrength());
								   std::cout << "You hit Sharon. She now has " << sharon ->getLives() << "%" << " health left." << "\n";
								   pin ->LoseDamage();
								   if (pin -> GetDamage() <=0)
								   {
								   std::cout << "You have used the rolling pin too many times and it snapped in half. \n";
								   }
								   }
								   if(stuff == "oven mitt")
								   {
								   sharon -> LoseLife(mitt->GetStrength());
								   std::cout << "You punched Sharon. She now has " << sharon ->getLives() << "%" << " health left." << "\n";
								   mitt -> LoseDamage();
								   if (mitt -> GetDamage() <=0)
								   {
								   std::cout << "You have used the oven mitt too many times and the seams have come apart. \n";
								   }
								   }

								   }
								   if(sharon ->getLives() <= 0)
								   {
								   std::cout << "Sharon is no longer a threat.  Turns out she had nothing to do with the murder.  " << "\n";
								   }
								   if(count == 2)
								   {
								   std::cout << "Sharon screams ''Wait, one last thing can you help me reach this thing off the top shelf?''. \n";
								   std::cout << "Do you wish to help Sharon? \n";
								   std::getline(std::cin, userInputa);
								   std::string answer = userInputa.substr(0, userInputa.find(" "));
								   if(userInputa == "yes")
								   {
								   std::cout << "You reached up and grabbed a bag of jelly beans. \n";
								   std::cout << "Do you still want to give them to Sharon? \n";
								   std::getline(std::cin, userInputb);
								   std::string answer = userInputb.substr(0, userInputb.find(" "));
								   if(userInputb == "no")
								   {
								   inventorylist.push_back("jelly beans");
								   std::cout << "You kept the jelly beans. \n";
								   }
								   else
								   {
								   std::cout << "You decide to give the jelly beans to Sharon, which she throws at you.  One hits you in the eye and impairs your vision, substantially affecting your health. \n ";
								   health = health /2;
								   }
								   }
								   else
								   {
								   std::cout << "Wow, didn't even want to help Sharon one last time.  Don't be distracted though, the battle is still on.  \n";
								   }
								   }
								   if(sharon->getLives() >0)
								   {

								   health = health - (sharon ->GiveDamage()) ;
								   std::cout << "Sharon hits back with her purse.  Your health is now at " << health << "%" << ". \n";
								   }
								   count = count +1;
								   }
								   if(currentRoom -> getDescription() == "Manager's Office" && steve->getLives() >0 && ((stuff == "butcher's knife" && knife ->GetDamage() >0) || (stuff == "rolling pin" && pin ->GetDamage() >0) || (stuff == "oven mitt" && mitt ->GetDamage() >0)))
								   {
								   if(steve->getLives() > 0)
								   {
								   if(stuff == "butcher's knife")
								   {
								   steve ->LoseLife(knife->GetStrength());
								   std::cout << "You stabbed Steve. He now has " << steve ->getLives() << "%" << " health left." << "\n";
								   knife ->LoseDamage();
								   if (knife -> GetDamage() <=0)
								   {
								   std::cout << "You have used the butcher's knife too many times and it broke. \n";
								   }
								   }
								   if(stuff == "rolling pin")
								   {
								   steve -> LoseLife(pin->GetStrength());
								   std::cout << "You hit Steve. He now has " << steve ->getLives() << "%" << " health left." << "\n";
								   pin -> LoseDamage();
								   if (pin -> GetDamage() <=0)
								   {
								   std::cout << "You have used the rolling pin too many times and it snapped in half. \n";
								   }
								   }
								   if(stuff == "oven mitt")
								   {
								   steve -> LoseLife(mitt->GetStrength());
								   std::cout << "You punched Steve. He now has " << steve ->getLives() << "%" << " health left." << "\n";
								   mitt ->LoseDamage();
								   if (mitt -> GetDamage() <=0)
								   {
								   std::cout << "You have used the oven mitt too many times and the seams have come apart. \n";
								   }
								   }

								   }
								   if(steve ->getLives() <= 0)
								   {
								   std::cout << "Steve is no longer a threat.  Turns out he had nothing to do with the murder.  " << "\n";
								   }
								   else
								   {
								   health = health - (steve ->GiveDamage()) ;
								   std::cout << "Steve hits back.  Your health is now at " << health << "%" << ". \n";
								   }
								   }

								   }
								   }
								   }

								   }

								   if(health <=0)
								   {
								   std::cout << "You lost. You have reached 0" << "%" << " health.";
								   }
								   else if(steve -> getLives() <=0 && butcher ->getLives() <=0 && sharon ->getLives() <=0)
								   {
								   std::cout << "You have murdered all the potential murderers.  Unfortunately you have murdered three innocent people at a grocery store and thus you are going to jail. ";
								   std::cout << "While in jail, they do an autopsy on the manager and turns out he died due to the same three murder weapons you used the butcher's knife, rolling pin, and oven mitt. ";
								   std::cout << "It was you all along.";
								   }
								   else
								   {
								   std::cout << "You have quit the game.  Better luck next time!";
								   }


								   return 0;
								   }
								 */
