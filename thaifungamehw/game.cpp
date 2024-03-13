// A 2D video game that consist of a 2D map and a player. In order to win,
// player must complete a series of quest and defeat the demon king in order to win.
// This program takes user input in order to dictate what users want to do whether its
// moving around the map or getting their stats
// Thai Khong
// 2/27/24
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <algorithm> 
#include <cctype>
#include <string> 
using namespace std;

class Object {
private:
	string type = "Empty"; // Buildings, road, trees
	
public:
	//constructor 
	Object() {}
	Object(string type) {
		
	}
	string getType() const {
		return this->type;
	}
	void setType(string type) {
		this->type = type;
	}
};

class Gym : public Object {
	string name = "Gym";
	string questions[5] = {
		"iron compete fine educate abhorrent descriptve repeat milky tiny ludicrous diligent irritate",
		"plot arrogant pancake standing quilt sea six weigh aback unpack youthful scared",
		"cellar puffy entertaining fang play knee squalid mint glove launch coal wrong",
		"trust complete hum gruesome desert try school cake mundane savory relax attempt",
		"lavish floor blue-eyed throat luxuriant cause oceanix high upbeat private clear suggest"
	};
	
public:
	bool prompt() {
		string userInput;
		srand(time(NULL));
		int randomNumber = rand() % 5;; // Generate random number from 0-4

		// Setting up questions for users and getting users input and turning it to all uppercase
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "You have entered your gym class! Start working out!" << endl;
		cout << "In order to build strong muscle in your fingers, " << endl;
		cout << "Please type that following sentence word for word! Goodluck!" << endl;
		cout << endl;
		cout << questions[randomNumber] << endl;
		cin.ignore();
		getline(cin, userInput);

		//Checking to see if the input matches the answers and if it matches return true, false otherwise
		if (userInput == questions[randomNumber]) {
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "\nDING DING! You are correct and type flawlessly!" << endl;
			return true;
		}
		else {
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "\nSorry you typed made a mistake! Please try again!\n" << endl;
			return false;
		}
	}
	
};

class English : public Object {
	string name = "English";
	string questions[5] = {
		"Choose the word that is spelled incorrectly.",
		"Choose the sentence that is grammatical error free.",
		"What is AI short for?",
		"What is CS short for?",
		"What is missing in this sentence? Im bored."
	};
	string questionSelection[5][3] = {
		{"A)Thunder", "B)Lightning", "C)Fyre"},
		{"A)I like to eat.", "B)I to eat.", "C)I like eat"},
		{"A)Animal In-Need", "B)Alien Index", "C)Artificial Intelligence"},
		{"A)Capital S", "B)Computer Science", "C)Carpool Soon"},
		{"A)'", "B)!", "C):)"}
	};
	string answers[5][2] = {
		{"C", "C)Fyre"},
		{"A", "A)I like to eat."},
		{"C", "C)Artificial Intelligence"},
		{"B", "B)Computer Science"},
		{"A", "A)'"}
	};

public:
	bool prompt() {

		srand(time(NULL));
		int randomNumber = rand() % 5;; // Generate random number from 0-4
		string userInput;
		bool validInput = false;


		// Shortcut for the userOutput
		string listOfSelection = questionSelection[randomNumber][0] + " " + questionSelection[randomNumber][1] + " " +
			questionSelection[randomNumber][2];

		// Setting up questions for users and getting users input and turning it to all uppercase
		cout << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "You have entered your english class! Please take your exam!" << endl;
		cout << questions[randomNumber] << endl;
		cout << listOfSelection << endl;
		cout << "Please select the correct answer! (Enter A, B, or C)" << endl;
		cout << endl;
		cin >> userInput;
		transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);

		//Makes sure that the userInput is a valid input
		if (userInput == "A" || userInput == "B" || userInput == "C") {
			validInput = true;
		}

		//Checking to see if the input matches the answers and if it matches return true, false otherwise
		if (validInput == true && userInput == answers[randomNumber][0]) {
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "\nDING DING! You are correct the answer is " << answers[randomNumber][1] << endl;
			cout << endl;
			return true;
		}
		else if (validInput == true && userInput != answers[randomNumber][0])
		{
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "\nWrong! The correct answer is " << answers[randomNumber][1] << endl;
			cout << endl;
			return false;
		}

		else {
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "\nInvalid input\n" << endl;
			return false;
		}
	}
	
};

class TreasureChest : public Object {
public:
	bool prompt() {
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "\nYou found a legendary holy sword that can slay anything!\n" << endl;
		return true;
	}
};

class Boulder : public Object {
public: 
	bool prompt() {
		string userInput;
		bool validInput = false;
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "\nYou stumbled upon a boulder! Do you think you have the strength to break it?" << endl;
		cout << "Please input (Yes or No) and hit enter!\n" << endl;
		cin >> userInput;
		transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);
		if (userInput == "YES" || userInput == "NO") {
			validInput = true;
		}
		if (userInput == "YES") {
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "\nWill now attempt to break boulder!" << endl;
			return true;
		}
		else if (userInput == "NO") {
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "\nAww try to break when stronger!\n" << endl;
			return false;
		}
		else if (validInput == false) {
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "\nInvalid input! User typed" << userInput << "Please try again and enter either (Yes or No)\n" << endl;
			return false;
		}
	}
};

class ComputerScience : public Object {
	string name = "Computer Science";
	string questions[5] = {
		"What is a syntax in programming?",
		"How do you declare a class (Soda)?",
		"Select a language that is a programming language.",
		"Your keyboard is an example of?",
		"Microsoft Window is an example of?"
	};
	string questionSelection[5][3] = {
		{"A) A softdrink", "B) Fundamental language rules of a programming language", "C) A computer that is broken"},
		{"A) class Soda{}", "B) class Soda(){}", "C) Class Soda(){}"},
		{"A) Chinese", "B) English", "C) C++"},
		{"A) Software", "B) Hardware", "C) Hard Drive"},
		{"A) Software", "B) Hardware", "C) Hard Drive"}
	};
	string answers[5][2] = {
		{"B", "B) Fundamental language rules of a programming language"},
		{"A", "A) class Soda{}"},
		{"C", "C) C++"},
		{"B", "B) Hardware"},
		{"A", "A) Software"}
	};

public:
	bool prompt() {

		srand(time(NULL));
		int randomNumber = rand() % 5;; // Generate random number from 0-4
		string userInput; 
		bool validInput = false;
		
		
		// Shortcut for the userOutput
		string listOfSelection = questionSelection[randomNumber][0] + " " + questionSelection[randomNumber][1] + " " +
			questionSelection[randomNumber][2];
		
		// Setting up questions for users and getting users input and turning it to all uppercase
		cout << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "You have entered your computer science class! Please take your exam!" << endl;
		cout << questions[randomNumber] << endl;
		cout << listOfSelection << endl;
		cout << "Please select the correct answer! (Enter A, B, or C)\n" << endl;
		cin >> userInput;
		transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);

		//Makes sure that the userInput is a valid input
		if (userInput == "A"  || userInput == "B" || userInput == "C") {
			validInput = true;
		}

		//Checking to see if the input matches the answers and if it matches return true, false otherwise
		if (validInput == true && userInput == answers[randomNumber][0]) {
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "\nDING DING! You are correct the answer is " << answers[randomNumber][1] << endl;
			cout << endl;
			return true;
		}
		else if (validInput == true && userInput != answers[randomNumber][0])
		{
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "\nWrong! The correct answer is " << answers[randomNumber][1] << endl;
			cout << endl;
			return false;
		} 
			
		else {
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "\nInvalid input\n" << endl;
			return false;
		}
	}
};

class Road : public Object {
	string description;
};

class Tree : public Object {
	string description[5] = {
		"There are apples growing in that tree",
		"You spot a pair of owl eyes peering at you through the trees",
		"There is a snake hidden behind the branches ready to strike!",
		"This tree is half destroyed!",
		"This tree is spooky and gives you chills!"
	};
public:
	void prompt() {
		srand(time(NULL));
		int randomNumber = rand() % 5;; // Generate random number from 0-4
		cout << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << description[randomNumber] << endl;
		cout << endl;
	}
};

class Boss : public Object {
	string name = "Demon King";
	
public:
	bool prompt() {
		string userInput;

		cout << "Would you like to challenge the DEMON KING?" << endl;
		cout << "Enter (Yes or No): " << endl;
		cin >> userInput;
		transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);
		if (userInput == "YES") {
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Prepare for battle!" << endl;
			return true;
		}
		else if(userInput == "NO") {
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "RUN AWAY PUNY HUMAN!" << endl;
			return false;
		}
		else {
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Invalid input you entered: " << userInput << endl;
			cout << "Today is your lucky day, you escaped with your life." << endl;
			return false;
		}
	}

	bool bossFight() {
		cout << "U WINS" << endl;
		return true;
	}
};

class Math : public Object {
	string questions[5] = {
		"5 x 5 = ?",
		"What is the area of a rectangle with width of 4 inches and length of 6 inches?",
		"What is the perimeter of a square with a side of 7 inches?",
		"7 + 3 = ?",
		"5x = 10, what is x?"
	};
	string questionSelection[5][3] = {
		{"A)25", "B)75", "C)10"},
		{"A)32", "B)20", "C)24"},
		{"A)18", "B)28", "C)26"},
		{"A)9", "B)11", "C)10"},
		{"A)2", "B)4", "C)5"}
	};
	string answers[5][2] = {
		{"A", "A) 25"},
		{"C", "C) 24"},
		{"B", "B) 28"},
		{"C", "C) 10"},
		{"A", "A) 2"}
	};
public:
	bool prompt() {

		srand(time(NULL));
		int randomNumber = rand() % 5;; // Generate random number from 0-4
		string userInput;
		bool validInput = false;

		// Shortcut for the userOutput
		string listOfSelection = questionSelection[randomNumber][0] + " " + questionSelection[randomNumber][1] + " " +
			questionSelection[randomNumber][2];

		// Setting up questions for users and getting users input and turning it to all uppercase
		cout << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "You have entered your math class! Please take the following exam!" << endl;
		cout << questions[randomNumber] << endl;
		cout << listOfSelection << endl;
		cout << "Please select the correct answer! (Enter A, B, or C)" << endl;
		cout << endl;
		cin >> userInput;
		transform(userInput.begin(), userInput.end(), userInput.begin(), toupper);

		//Makes sure that the userInput is a valid input
		if (userInput == "A" || userInput == "B" || userInput == "C") {
			validInput = true;
		}

		//Checking to see if the input matches the answers and if it matches return true, false otherwise
		if (validInput == true && userInput == answers[randomNumber][0]) {
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "\nDING DING! You are correct the answer is " << answers[randomNumber][1] << endl;
			return true;
		}
		else if (validInput == true && userInput != answers[randomNumber][0])
		{
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "\nWrong! The correct answer is " << answers[randomNumber][1] << endl;
			return false;
		}

		else {
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "\nInvalid input" << endl;
			cout << endl;
			return false;
		}
	}
};

class Gratz : public Object {
	
public: 
	bool prompt() {
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "Congratz!!! YOU BEAT THE GAME AND GRADUATED!" << endl;
		return true;
	}
	
};

class Map {
public:
	int xPos, yPos;
	
	// Setting up condition to trigger events, and gain ability. Each ability is needed in order to pass certain stages in the game.
	bool passValidation = false, roadValid = false;
	string mapIndication = "[X] ", spaceOccupiedName, type;

	Gym gym;
	English english;
	Road road;
	ComputerScience computerScience;
	Tree tree;
	TreasureChest treasureChest;
	Boss boss;
	Boulder boulder;
	Math math;
	Gratz gratz;
	
	bool getPassValidation() {
		return this->passValidation;
	}
	string getSpaceOccupiedName() {
		return this->spaceOccupiedName;
	}
	// shows the x and y coordinates when player lands on each one. Also if that space is occupied then triggers event.
	void spaceInfo() {

		if (spaceOccupiedName == "Gym") {
			passValidation = gym.prompt();
		}
		else if (spaceOccupiedName == "English") {
			passValidation = english.prompt();
		}
		else if (spaceOccupiedName == "CS") {
			passValidation = computerScience.prompt();
		}
		else if (spaceOccupiedName == "Math") {
			passValidation = math.prompt();
		}
		else if (spaceOccupiedName == "TreasureChest") {
			passValidation = treasureChest.prompt();
		}
		else if (spaceOccupiedName == "Boulder") {
			passValidation = boulder.prompt();
		}
		else if (spaceOccupiedName == "Tree") {
			tree.prompt();
		}
		else if (spaceOccupiedName == "Boss") {
			passValidation = boss.prompt();
		}
		else if (spaceOccupiedName == "Graduation") {
			gratz.prompt();
		}
	}
	
	void setMap(string type) {
		spaceOccupiedName = type;
		if (type == "Gym") {
			this->mapIndication = "[G] ";
			gym.setType("Interact");
			this->type = "Interact";
		}
		else if (type == "Road") {
			this->mapIndication = "[R] ";
			roadValid = true;
			road.setType("Static");
			this->type = "Static";
		}
		else if (type == "CS") {
			this->mapIndication = "[CS] ";
			computerScience.setType("Interact");
			this->type = "Interact";
		}
		else if (type == "English") {
			this->mapIndication = "[E] ";
			english.setType("Interact");
			this->type = "Interact";
		}
		else if (type == "TreasureChest") {
			this->mapIndication = "[TC] ";
			treasureChest.setType("Interact");
			this->type = "Interact";
		}
		else if (type == "Tree") {
			this->mapIndication = "[T] ";
			tree.setType("Interact");
			this->type = "Interact";
		}
		else if (type == "Boss") {
			this->mapIndication = "[BO] ";
			boss.setType("Interact"); type = "Interact"; 
			this->type = boss.getType();
		}
		else if (type == "Graduation") {
			this->mapIndication = "[GRATZ] ";
			gratz.setType("Interact");
			this->type = "Interact";
		}
		else if (type == "Boulder")
		{
			this->mapIndication = "[B] ";
			boulder.setType("Interact");
			this->type = "Interact";
		}
		else if (type == "Math") {
			this->mapIndication = "[M] ";
			math.setType("Interact");
			this->type = "Interact";
		}
		else if (roadValid = true && type == "Player") {
			this->mapIndication = "[O] ";
		}
	}
	string getType() {
		return this->type;
	}
	
};

class Player : public Map {
	string name = "Player", questCompleteName="NA";
	int mathPass = 0, engPass = 0, csPass = 0, gymPass = 0, legendarySword = 0;
	bool questCompleted = false;
	int playerX, playerY;

public:
	Player(int playerY, int playerX) {
		this->playerX = playerX;
		this->playerY = playerY;
	}
	int getPlayerX() {
		return this->playerX;
	}
	void setPlayerX(int playerX) {
		this->playerX = playerX;
	}
	int getPlayerY() {
		return this->playerY;
	}
	void setPlayerY(int playerY) {
		this->playerY = playerY;
	}
	int getMathPass() {
		return this->mathPass;
	}
	void setMathPass(int num) {
		this->mathPass = num;
	}
	int getGymPass() {
		return this->gymPass;
	}
	void setGymPass(int num) {
		this->gymPass = num;
	}
	int getEngPass() {
		return this->engPass;
	}
	void setEngPass(int num) {
		this->engPass = num;
	}
	int getCsPass() {
		return this->csPass;
	}
	void setCsPass(int num) {
		this->csPass = num;
	}
	int getLegendarySwordPass() {
		return this->legendarySword;
	}
	void setLegendarySwordPass(int num) {
		this->legendarySword = num;
	}
	void getPlayerStats() {
		cout << endl;
		cout << "Player stats" << endl;
		cout << "Math points: " << getMathPass() << "\nEnglish points: " << getEngPass() << "\nComputer Science points: " << getCsPass() << endl;
		cout << "Strength: " << getGymPass() << "\nLengendary Sword: " << getLegendarySwordPass() << endl;
		cout << endl;
	}
	void playerUpdateStats(bool validation, string nameOfSubject) {
		const int max = 3;
		if (validation == false) {
			string message = "no issues here maybe use for debugging..";
		}
		else if (validation == true && nameOfSubject != "TreasureChest") {
			if (getGymPass() < max && nameOfSubject == "Gym") {
				setGymPass(getGymPass() + 1);
			}
			else if (getMathPass() < max && nameOfSubject == "Math") {
				setMathPass(getMathPass() + 1);
			}
			else if (getEngPass() < max && nameOfSubject == "English") {
				setEngPass(getEngPass() + 1);
			}
			else if (getCsPass() < max && nameOfSubject == "CS") {
				setCsPass(getCsPass() + 1);
			}
			else if (getMathPass() > max && nameOfSubject == "Math") {
				cout << "You have already gained maximum points for math class!\n" << endl;
			}
			else if (getEngPass() > max && nameOfSubject == "English") {
				cout << "You have already gained maximum points for english class!\n" << endl;
			}
			else if (getCsPass() > max && nameOfSubject == "CS") {
				cout << "You have already gained maximum points for computer science class!\n" << endl;
			}
			else if (getGymPass() >= max && nameOfSubject == "Boulder") {
				questCompleted = true;
				questCompleteName = "Boulder";
			}
			else if (nameOfSubject == "Boss") {
				if (getGymPass() >= max && getCsPass() >= max && getEngPass() >= max &&
					getMathPass() >= max && getLegendarySwordPass() >= 1 && nameOfSubject == "Boss") {
					questCompleted = true;
					questCompleteName = "Boulder";

					boss.bossFight();
				}
				else {
					cout << "You dont have the neccessary equipments or player stats to fight the boss! Game over... sucks to be you..." << endl;
					cout << "Here was your player stat!" << endl;
					getPlayerStats();
					setMathPass(0);
					setEngPass(0);
					setLegendarySwordPass(0);
					setCsPass(0);
					setGymPass(0);
					cout << "Here are your new player stats!" << endl;
					getPlayerStats();
				}
			}
			else {
				cout << "Error WITHIN PLAYERUPDATESTATS FUNCTION!" << endl;
			}
		}
		else if (validation == true && nameOfSubject == "TreasureChest") {
			if (getLegendarySwordPass() < 1) {
				setLegendarySwordPass(getLegendarySwordPass() + 1);
			}
			else {
				cout << "\nYou have already obtained the almightly legendary sword!\n" << endl;
			}
		}
		else {
			cout << "Error WITHIN PLAYERUPDATESTATS FUNCTION!" << endl;
		}
		
	}

	void playerMoveAroundMap(string playerMove, Map map[][5]) {
		bool canMoveAnywhere = true;
		if (getPlayerX() || getPlayerY() == 4) {
			canMoveAnywhere = false;
		}

		if (playerMove == "STAT") {
			getPlayerStats();
		}
		else if (playerMove == "MAP") {
			printMap(map);
		}
		else if (playerMove == "W" && getPlayerY() <= 4 && getPlayerY() > 0) {
			if (map[getPlayerY()-1][getPlayerX()].roadValid == true) {
				map[getPlayerY()][getPlayerX()].setMap("Road");
				setPlayerY(getPlayerY() - 1);
				map[getPlayerY()][getPlayerX()].setMap("Player");
				printMap(map);
			}
			else{
				if (map[getPlayerY() - 1][getPlayerX()].getType() == "Interact") {
					map[getPlayerY() - 1][getPlayerX()].spaceInfo();
					playerUpdateStats(map[getPlayerY() - 1][getPlayerX()].getPassValidation(), map[getPlayerY() - 1][getPlayerX()].getSpaceOccupiedName());
					if (questCompleted == true && questCompleteName != "NA") {
						cout << "BAM BAM BAM, you broke the " << questCompleteName << "!" << endl;
						map[getPlayerY()-1][getPlayerX()].setMap("Road");
						questCompleted = false;
						questCompleteName = "NA";
					}
				}
				else {
					cout << "Error has occured within player class playerMoveAroundMap function! "<< map[getPlayerY() - 1][getPlayerX()].getType() << endl;
				}
			}
		}
		else if (playerMove == "A" && getPlayerX() <= 4 && getPlayerX() > 0) {
			if (map[getPlayerY()][getPlayerX()-1].roadValid == true) {
				map[getPlayerY()][getPlayerX()].setMap("Road");
				setPlayerX(getPlayerX() - 1);
				map[getPlayerY()][getPlayerX()].setMap("Player");
				printMap(map);
			}
			else {
				if (map[getPlayerY()][getPlayerX() - 1].getType() == "Interact") {
					map[getPlayerY()][getPlayerX() - 1].spaceInfo();
					playerUpdateStats(map[getPlayerY()][getPlayerX() - 1].getPassValidation(), map[getPlayerY()][getPlayerX() - 1].getSpaceOccupiedName());
					if (questCompleted == true && questCompleteName != "NA") {
						cout << "BAM BAM BAM, you broke the " << questCompleteName << "!" << endl;
						map[getPlayerY()][getPlayerX()-1].setMap("Road");
						questCompleted = false;
						questCompleteName = "NA";
					}
				}
				else {
					cout << "Error has occured within player class playerMoveAroundMap function! " << map[getPlayerY()][getPlayerX() - 1].getType() << endl;
				}
			}
		}
		else if (playerMove == "S" && getPlayerY() < 4 && getPlayerY() >= 0) {
			if (map[getPlayerY() + 1][getPlayerX()].roadValid == true) {
				map[getPlayerY()][getPlayerX()].setMap("Road");
				setPlayerY(getPlayerY() + 1);
				map[getPlayerY()][getPlayerX()].setMap("Player");
				printMap(map);
			}
			else {
				if (map[getPlayerY() + 1][getPlayerX()].getType() == "Interact") {
					map[getPlayerY() + 1][getPlayerX()].spaceInfo();
					playerUpdateStats(map[getPlayerY() + 1][getPlayerX()].getPassValidation(), map[getPlayerY() + 1][getPlayerX()].getSpaceOccupiedName());
					if (questCompleted == true && questCompleteName != "NA") {
						cout << "BAM BAM BAM, you broke the " << questCompleteName << "!" << endl;
						map[getPlayerY() + 1][getPlayerX()].setMap("Road");
						questCompleted = false;
						questCompleteName = "NA";
					}
				}
				else {
					cout << "Error has occured within player class playerMoveAroundMap function! " << map[getPlayerY() + 1][getPlayerX()].getType() << endl;
				}
			}
		}
		else if (playerMove == "D" && getPlayerX() < 4 && getPlayerX() >= 0) {
			if (map[getPlayerY()][getPlayerX() + 1].roadValid == true) {
				map[getPlayerY()][getPlayerX()].setMap("Road");
				setPlayerX(getPlayerX() + 1);
				map[getPlayerY()][getPlayerX()].setMap("Player");
				printMap(map);
			}
			else {
				if (map[getPlayerY()][getPlayerX() + 1].getType() == "Interact") {
					map[getPlayerY()][getPlayerX() + 1].spaceInfo();
					playerUpdateStats(map[getPlayerY()][getPlayerX() + 1].getPassValidation(), map[getPlayerY()][getPlayerX() + 1].getSpaceOccupiedName());
					if (questCompleted == true && questCompleteName != "NA") {
						cout << "BAM BAM BAM, you broke the " << questCompleteName << "!" << endl;
						map[getPlayerY()][getPlayerX() + 1].setMap("Road");
						questCompleted = false;
						questCompleteName = "NA";
					}
				}
				else {
					cout << "Error has occured within player class playerMoveAroundMap function! "<< map[getPlayerY()][getPlayerX() + 1].getType() << endl;
				}
			}
		}
		else {
			cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
			cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Invalid input, you entered " << playerMove << ", which can't happen unless falling off the map is your thing... Please try again!" << endl;
			cout << "You are at x: " << getPlayerX() <<" y: " << getPlayerY();
			cout << endl;
		}
	}
	void printMap(Map arr[][5]) {
		cout << endl;
		cout << "MAP" << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {

				cout << setw(5) << arr[i][j].mapIndication;
			}
			
			cout << "\n" << endl;
		}
		cout << "------------------------------" << endl;
		cout << endl;
		cout << "[ O: Player, R: Road, T: Trees, B: Boulder, TC: Trasure Chest, BO: Boss ]" << endl;
		cout << "[ E: English, CS: Computer Science, G: Gym, M: Math, , GRAD: Graduation ]" << endl;
	};
	void printRules() {
		cout << "Rules - Pass Math, English, Computer science, and Gym with three points!" << endl;
		cout << "After that, find the legendary sword and face the boss to graduate!" << endl;
		cout << "You may only move along the road (cannot pass trees, buildings, Boulder)" << endl;
	}
};

int main() {
	
	//initializing player map
	Map map[5][5];
	Player player(4, 0);
	bool move = true;
	string playerMove;

	//setting its x,y coord
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			map[i][j].xPos = j;
			map[i][j].yPos = i;

		}
	}

	map[0][3].setMap("Boss");
	map[0][4].setMap("Graduation");
	map[3][1].setMap("Gym");
	map[0][0].setMap("Boulder");
	map[0][1].setMap("Road");
	map[0][2].setMap("Road");
	map[1][0].setMap("Road");
	map[2][0].setMap("Road");
	map[3][0].setMap("Road");
	map[4][0].setMap("Road");
	map[4][1].setMap("Road");
	map[4][2].setMap("Road");
	map[3][2].setMap("Road");
	map[3][3].setMap("Road");
	map[3][4].setMap("Road");
	map[4][3].setMap("Tree");
	map[4][4].setMap("TreasureChest");
	map[2][1].setMap("Tree");
	map[1][1].setMap("Tree");
	map[1][2].setMap("Tree");
	map[1][3].setMap("Tree");
	map[1][4].setMap("Tree");
	map[2][2].setMap("CS");
	map[2][4].setMap("Math");
	map[2][3].setMap("English");

	map[player.getPlayerY()][player.getPlayerX()].setMap("Player");

	player.printRules();
	cout << endl;
	player.printMap(map);
	
	
	while (move) {
		cout << endl;
		
		cout << "Type and enter [Map] to print the map and [Stat] for player status!" << endl;
		cout << "Enter [W] to go up, [A] to go left, [S] to go down, [D] to go right!" << endl;
		cin >> playerMove;
		transform(playerMove.begin(), playerMove.end(), playerMove.begin(), toupper);
		player.playerMoveAroundMap(playerMove, map);
		
	}
	return 0;
}
