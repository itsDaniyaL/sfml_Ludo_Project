#include <SFML\Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <fstream>

using namespace sf;
using namespace std;

// Window properties
const int windowWidth = 1035;
const int windowHeight = 860;

// Game properties
int totalPlayers = 2;
int playerTurn = 0;

// Textures
Texture Start;
Texture BackG;
Texture HowToPlay;

Texture Red_Turn;
Texture Yellow_Turn;

Texture Red_Win;
Texture Yellow_Win;

Texture Red_Best;
Texture Yellow_Best;
Texture Nothing_Best;

Texture Red1;
Texture Red2;
Texture Red3;
Texture Red4;

Texture Green1;
Texture Green2;
Texture Green3;
Texture Green4;

Texture Blue1;
Texture Blue2;
Texture Blue3;
Texture Blue4;

Texture Yellow1;
Texture Yellow2;
Texture Yellow3;
Texture Yellow4;

Texture Dice1;
Texture Dice2;
Texture Dice3;
Texture Dice4;
Texture Dice5;
Texture Dice6;

// Sprites
Sprite sStart;
Sprite sBackG;
Sprite sHowToPlay;

Sprite sTurn;

Sprite sRed_Win;
Sprite sYellow_Win;
Sprite sNothing_Best;

Sprite sBestScore;

Sprite sRed1;
Sprite sRed2;
Sprite sRed3;
Sprite sRed4;

Sprite sBlue1;
Sprite sBlue2;
Sprite sBlue3;
Sprite sBlue4;

Sprite sYellow1;
Sprite sYellow2;
Sprite sYellow3;
Sprite sYellow4;

Sprite sGreen1;
Sprite sGreen2;
Sprite sGreen3;
Sprite sGreen4;

Sprite dice;

// Positions
Vector2f TurnPosition = Vector2f(860, 690);

Vector2f dicePosition = Vector2f(860, 690);

Vector2f Red_Movement[58] = { Vector2f(464, 65),Vector2f(464,122),Vector2f(464,180),Vector2f(464,238),Vector2f(464,295),Vector2f(520,350),Vector2f(577,350),Vector2f(635,350),Vector2f(691,350),Vector2f(750,350),Vector2f(806,350),Vector2f(806,408),Vector2f(806,465),Vector2f(750,465),Vector2f(691,465),Vector2f(635,465),Vector2f(577,465),Vector2f(520,465),Vector2f(463,520),Vector2f(463,578),Vector2f(463,634),Vector2f(463,692),Vector2f(463,750),Vector2f(463,806),Vector2f(407,806),Vector2f(350,806),Vector2f(350,750),Vector2f(350,692),Vector2f(350,634),Vector2f(350,578),Vector2f(350,520),Vector2f(293,463),Vector2f(236,463),Vector2f(178,463),Vector2f(122,463),Vector2f(65,463),Vector2f(7,463),Vector2f(7,408),Vector2f(7,350),Vector2f(65,350),Vector2f(122,350),Vector2f(178,350),Vector2f(236,350),Vector2f(293,350),Vector2f(350,293),Vector2f(350,238),Vector2f(350,180),Vector2f(350,122),Vector2f(350,65),Vector2f(350,7),Vector2f(407,7),Vector2f(464,7),Vector2f(407,65),Vector2f(407,122),Vector2f(407,180),Vector2f(407,238),Vector2f(407,293),Vector2f(407,350) };

Vector2f Yellow_Movement[58] = { Vector2f(350,750),Vector2f(350,692),Vector2f(350,634),Vector2f(350,578),Vector2f(350,520),Vector2f(293,463),Vector2f(236,463),Vector2f(178,463),Vector2f(122,463),Vector2f(65,463),Vector2f(7,463),Vector2f(7,408),Vector2f(7,350),Vector2f(65,350),Vector2f(122,350),Vector2f(178,350),Vector2f(236,350),Vector2f(293,350),Vector2f(350,293),Vector2f(350,238),Vector2f(350,180),Vector2f(350,122),Vector2f(350,65),Vector2f(350,7),Vector2f(407,7),Vector2f(464,7),Vector2f(464, 65),Vector2f(464,122),Vector2f(464,180),Vector2f(464,238),Vector2f(464,295),Vector2f(520,350),Vector2f(577,350),Vector2f(635,350),Vector2f(691,350),Vector2f(750,350),Vector2f(806,350),Vector2f(806,408),Vector2f(806,465),Vector2f(750,465),Vector2f(691,465),Vector2f(635,465),Vector2f(577,465),Vector2f(520,465),Vector2f(463,520),Vector2f(463,578),Vector2f(463,634),Vector2f(463,692),Vector2f(463,750),Vector2f(463,806),Vector2f(407,806),Vector2f(350,806),Vector2f(407,750),Vector2f(407,692),Vector2f(407,634),Vector2f(407,578),Vector2f(407,520),Vector2f(407,470) };

Vector2f redStopPositions[4] = { Vector2f(665,95), Vector2f(605, 150), Vector2f(720, 150), Vector2f(665, 207) };
Vector2f yellowStopPositions[4] = { Vector2f(150, 610), Vector2f(95, 660), Vector2f(205, 660), Vector2f(150, 720) };

// Game positions
int redCurrentPositions[4];
int yellowCurrentPositions[4];

void print(string message) {
	cout << message << endl;
}

int rollDice() {
	srand(time(0));

	int num = (rand() % 6) + 1;
	switch (num)
	{
	case 1:
		dice.setTexture(Dice1);
		break;
	case 2:
		dice.setTexture(Dice2);
		break;
	case 3:
		dice.setTexture(Dice3);
		break;
	case 4:
		dice.setTexture(Dice4);
		break;
	case 5:
		dice.setTexture(Dice5);
		break;
	case 6:
		dice.setTexture(Dice6);
		break;
	default:
		break;
	}

	return num;
}

void initializeSprites() {
	//All The Textures Used In The Project
	Start.loadFromFile("Start_Up.jpg");
	BackG.loadFromFile("Ludo.jpg");
	HowToPlay.loadFromFile("How_To_Play_Page.jpg");
	sStart = Sprite(Start);
	sBackG = Sprite(BackG);
	sHowToPlay = Sprite(HowToPlay);

	Red_Turn.loadFromFile("Red_Turn.jpg");
	Yellow_Turn.loadFromFile("Yellow_Turn.jpg");
	sTurn = Sprite();

	Red_Win.loadFromFile("Red_Win.jpg");
	Yellow_Win.loadFromFile("Yellow_Win.jpg");
	sRed_Win = Sprite(Red_Win);
	sYellow_Win = Sprite(Yellow_Win);

	Red_Best.loadFromFile("Best_Show_Red.jpg");
	Yellow_Best.loadFromFile("Best_Show_Yellow.jpg");
	Nothing_Best.loadFromFile("Best_Show_Nothing.jpg");


	Red1.loadFromFile("Red1.jpg");
	Red2.loadFromFile("Red2.jpg");
	Red3.loadFromFile("Red3.jpg");
	Red4.loadFromFile("Red4.jpg");
	sRed1 = Sprite(Red1);
	sRed2 = Sprite(Red2);
	sRed3 = Sprite(Red3);
	sRed4 = Sprite(Red4);

	Green1.loadFromFile("Green1.jpg");
	Green2.loadFromFile("Green2.jpg");
	Green3.loadFromFile("Green3.jpg");
	Green4.loadFromFile("Green4.jpg");
	sGreen1 = Sprite(Green1);
	sGreen2 = Sprite(Green2);
	sGreen3 = Sprite(Green3);
	sGreen4 = Sprite(Green4);

	Blue1.loadFromFile("Blue1.jpg");
	Blue2.loadFromFile("Blue2.jpg");
	Blue3.loadFromFile("Blue3.jpg");
	Blue4.loadFromFile("Blue4.jpg");
	sBlue1 = Sprite(Blue1);
	sBlue2 = Sprite(Blue2);
	sBlue3 = Sprite(Blue3);
	sBlue4 = Sprite(Blue4);

	Yellow1.loadFromFile("Yellow1.jpg");
	Yellow2.loadFromFile("Yellow2.jpg");
	Yellow3.loadFromFile("Yellow3.jpg");
	Yellow4.loadFromFile("Yellow4.jpg");
	sYellow1 = Sprite(Yellow1);
	sYellow2 = Sprite(Yellow2);
	sYellow3 = Sprite(Yellow3);
	sYellow4 = Sprite(Yellow4);

	Dice1.loadFromFile("Dice1.jpg");
	Dice2.loadFromFile("Dice2.jpg");
	Dice3.loadFromFile("Dice3.jpg");
	Dice4.loadFromFile("Dice4.jpg");
	Dice5.loadFromFile("Dice5.jpg");
	Dice6.loadFromFile("Dice6.jpg");
	dice = Sprite();
	dice.setPosition(dicePosition);
}

void movePawn(int diceValue, bool& requiresPawnInput, Vector2f mousePosition) {
	bool actionTaken = false;
	static bool redKill = false;
	static bool yellowKill = false;
	static bool checkRed = true;
	static bool checkYellow = true;
	//Checking which player is currently playing
	if (playerTurn == 0) {
		//Checking whether position of mouse is on the pawn while clicking it.
		if (sRed1.getGlobalBounds().contains(mousePosition)) {
			actionTaken = true;
			if (diceValue == 6 && 
				sRed1.getPosition().x == redStopPositions[0].x && sRed1.getPosition().y == redStopPositions[0].y) {
				redCurrentPositions[0] = 0;
				sRed1.setPosition(Red_Movement[redCurrentPositions[0]]);
			}
			else if(sRed1.getPosition().x != redStopPositions[0].x && sRed1.getPosition().y != redStopPositions[0].y) {
				if (!redKill) {
					redCurrentPositions[0] = (redCurrentPositions[0] + diceValue) % 52;
				}
				if (redKill && (redCurrentPositions[0]+diceValue) <= 58) {
					redCurrentPositions[0] = (redCurrentPositions[0] + diceValue);
					if (redCurrentPositions[0] > 51 && checkRed) {
						redCurrentPositions[0] += 1;
						checkRed = false;
					}
				}
				sRed1.setPosition(Red_Movement[redCurrentPositions[0]]);
				if (Red_Movement[redCurrentPositions[0]] == Yellow_Movement[yellowCurrentPositions[0]])
				{
					sYellow1.setPosition(yellowStopPositions[0]);
					redKill = true;
				}
				if (Red_Movement[redCurrentPositions[0]] == Yellow_Movement[yellowCurrentPositions[1]])
				{
					sYellow2.setPosition(yellowStopPositions[1]);
					redKill = true;
				}
				if (Red_Movement[redCurrentPositions[0]] == Yellow_Movement[yellowCurrentPositions[2]])
				{
					sYellow3.setPosition(yellowStopPositions[2]);
					redKill = true;
				}
				if (Red_Movement[redCurrentPositions[0]] == Yellow_Movement[yellowCurrentPositions[3]])
				{
					sYellow4.setPosition(yellowStopPositions[3]);
					redKill = true;
				}

			}
		}
		if (sRed2.getGlobalBounds().contains(mousePosition)) {
			actionTaken = true;
			if (diceValue == 6 &&
				sRed2.getPosition().x == redStopPositions[1].x && sRed2.getPosition().y == redStopPositions[1].y) {
				redCurrentPositions[1] = 0;
				sRed2.setPosition(Red_Movement[redCurrentPositions[1]]);
			}
			else if (sRed2.getPosition().x != redStopPositions[1].x && sRed2.getPosition().y != redStopPositions[1].y) {
				if (!redKill) {
					redCurrentPositions[1] = (redCurrentPositions[1] + diceValue) % 52;
				}
				if (redKill && (redCurrentPositions[1]+diceValue) <= 58) {
					redCurrentPositions[1] = (redCurrentPositions[1] + diceValue);
					if (redCurrentPositions[1] > 51 && checkRed) {
						redCurrentPositions[1] += 1;
						checkRed = false;
					}
				}
				sRed2.setPosition(Red_Movement[redCurrentPositions[1]]);
				if (Red_Movement[redCurrentPositions[1]] == Yellow_Movement[yellowCurrentPositions[0]])
				{
					sYellow1.setPosition(yellowStopPositions[0]);
					redKill = true;
				}
				if (Red_Movement[redCurrentPositions[1]] == Yellow_Movement[yellowCurrentPositions[1]])
				{
					sYellow2.setPosition(yellowStopPositions[1]);
					redKill = true;
				}
				if (Red_Movement[redCurrentPositions[1]] == Yellow_Movement[yellowCurrentPositions[2]])
				{
					sYellow3.setPosition(yellowStopPositions[2]);
					redKill = true;
				}
				if (Red_Movement[redCurrentPositions[1]] == Yellow_Movement[yellowCurrentPositions[3]])
				{
					sYellow4.setPosition(yellowStopPositions[3]);
					redKill = true;
				}


			}
		}
		if (sRed3.getGlobalBounds().contains(mousePosition)) {
			actionTaken = true;
			if (diceValue == 6 &&
				sRed3.getPosition().x == redStopPositions[2].x && sRed3.getPosition().y == redStopPositions[2].y) {
				redCurrentPositions[2] = 0;
				sRed3.setPosition(Red_Movement[redCurrentPositions[2]]);
			}
			else if (sRed3.getPosition().x != redStopPositions[2].x && sRed3.getPosition().y != redStopPositions[2].y) {
				if (!redKill) {
					redCurrentPositions[2] = (redCurrentPositions[2] + diceValue) % 52;
				}
				if (redKill && (redCurrentPositions[2] + diceValue) <= 58) {
					redCurrentPositions[2] = (redCurrentPositions[2] + diceValue);
					if (redCurrentPositions[2] > 51 && checkRed) {
						redCurrentPositions[2] += 1;
						checkRed = false;
					}
				}

				sRed3.setPosition(Red_Movement[redCurrentPositions[2]]);
				if (Red_Movement[redCurrentPositions[2]] == Yellow_Movement[yellowCurrentPositions[0]])
				{
					sYellow1.setPosition(yellowStopPositions[0]);
					redKill = true;
				}
				if (Red_Movement[redCurrentPositions[2]] == Yellow_Movement[yellowCurrentPositions[1]])
				{
					sYellow2.setPosition(yellowStopPositions[1]);
					redKill = true;
				}
				if (Red_Movement[redCurrentPositions[2]] == Yellow_Movement[yellowCurrentPositions[2]])
				{
					sYellow3.setPosition(yellowStopPositions[2]);
					redKill = true;
				}
				if (Red_Movement[redCurrentPositions[2]] == Yellow_Movement[yellowCurrentPositions[3]])
				{
					sYellow4.setPosition(yellowStopPositions[3]);
					redKill = true;
				}

			}
		}
		if (sRed4.getGlobalBounds().contains(mousePosition)) {
			actionTaken = true;
			if (diceValue == 6 &&
				sRed4.getPosition().x == redStopPositions[3].x && sRed4.getPosition().y == redStopPositions[3].y) {
				redCurrentPositions[3] = 0;
				sRed4.setPosition(Red_Movement[redCurrentPositions[3]]);
			}
			else if (sRed4.getPosition().x != redStopPositions[3].x && sRed4.getPosition().y != redStopPositions[3].y) {
				if (!redKill) {
					redCurrentPositions[3] = (redCurrentPositions[3] + diceValue) % 52;
				}
				if (redKill && (redCurrentPositions[3] + diceValue) <= 58) {
					redCurrentPositions[3] = (redCurrentPositions[3] + diceValue);
					if (redCurrentPositions[3] > 51 && checkRed) {
						redCurrentPositions[3] += 1;
						checkRed = false;
					}
				}
				sRed4.setPosition(Red_Movement[redCurrentPositions[3]]);
				if (Red_Movement[redCurrentPositions[3]] == Yellow_Movement[yellowCurrentPositions[0]])
				{
					sYellow1.setPosition(yellowStopPositions[0]);
					redKill = true;
				}
				if (Red_Movement[redCurrentPositions[3]] == Yellow_Movement[yellowCurrentPositions[1]])
				{
					sYellow2.setPosition(yellowStopPositions[1]);
					redKill = true;
				}
				if (Red_Movement[redCurrentPositions[3]] == Yellow_Movement[yellowCurrentPositions[2]])
				{
					sYellow3.setPosition(yellowStopPositions[2]);
					redKill = true;
				}
				if (Red_Movement[redCurrentPositions[3]] == Yellow_Movement[yellowCurrentPositions[3]])
				{
					sYellow4.setPosition(yellowStopPositions[3]);
					redKill = true;
				}

			}
		}
	}
	else if (playerTurn == 1) {
		if (sYellow1.getGlobalBounds().contains(mousePosition)) {
			actionTaken = true;
			if (diceValue == 6 &&
				sYellow1.getPosition().x == yellowStopPositions[0].x && sYellow1.getPosition().y == yellowStopPositions[0].y) {
				yellowCurrentPositions[0] = 0;
				sYellow1.setPosition(Yellow_Movement[yellowCurrentPositions[0]]);
			}
			else if (sYellow1.getPosition().x != yellowStopPositions[0].x && sYellow1.getPosition().y != yellowStopPositions[0].y) {
				if (!yellowKill) {
					yellowCurrentPositions[0] = (yellowCurrentPositions[0] + diceValue) % 52;
				}
				if (yellowKill && (yellowCurrentPositions[0]+diceValue) <= 58) {
					yellowCurrentPositions[0] = (yellowCurrentPositions[0] + diceValue);
					if (yellowCurrentPositions[0] > 51 && checkYellow) {
						yellowCurrentPositions[0] += 1;
						checkYellow = false;
					}
				}
				sYellow1.setPosition(Yellow_Movement[yellowCurrentPositions[0]]);
				if (Yellow_Movement[yellowCurrentPositions[0]] == Red_Movement[redCurrentPositions[0]])
				{
					sRed1.setPosition(redStopPositions[0]);
					yellowKill = true;
				}
				if (Yellow_Movement[yellowCurrentPositions[0]] == Red_Movement[redCurrentPositions[1]])
				{
					sRed2.setPosition(redStopPositions[1]);
					yellowKill = true;
				}
				if (Yellow_Movement[yellowCurrentPositions[0]] == Red_Movement[redCurrentPositions[2]])
				{
					sRed3.setPosition(redStopPositions[2]);
					yellowKill = true;
				}
				if (Yellow_Movement[yellowCurrentPositions[0]] == Red_Movement[redCurrentPositions[3]])
				{
					sRed4.setPosition(redStopPositions[3]);
					yellowKill = true;
				}
			}
		}
		if (sYellow2.getGlobalBounds().contains(mousePosition)) {
			actionTaken = true;
			if (diceValue == 6 &&
				sYellow2.getPosition().x == yellowStopPositions[1].x && sYellow2.getPosition().y == yellowStopPositions[1].y) {
				yellowCurrentPositions[1] = 0;
				sYellow2.setPosition(Yellow_Movement[yellowCurrentPositions[1]]);
			}
			else if (sYellow2.getPosition().x != yellowStopPositions[1].x && sYellow2.getPosition().y != yellowStopPositions[1].y) {
				if (!yellowKill) {
					yellowCurrentPositions[1] = (yellowCurrentPositions[1] + diceValue) % 52;
				}
				if (yellowKill && (yellowCurrentPositions[1] + diceValue) <= 58) {
					yellowCurrentPositions[1] = (yellowCurrentPositions[1] + diceValue);
					if (yellowCurrentPositions[1] > 51 && checkYellow) {
						yellowCurrentPositions[1] += 1;
						checkYellow = false;
					}
				}
				sYellow2.setPosition(Yellow_Movement[yellowCurrentPositions[1]]);
				if (Yellow_Movement[yellowCurrentPositions[1]] == Red_Movement[redCurrentPositions[0]])
				{
					sRed1.setPosition(redStopPositions[0]);
					yellowKill = true;
				}
				if (Yellow_Movement[yellowCurrentPositions[1]] == Red_Movement[redCurrentPositions[1]])
				{
					sRed2.setPosition(redStopPositions[1]);
					yellowKill = true;
				}
				if (Yellow_Movement[yellowCurrentPositions[1]] == Red_Movement[redCurrentPositions[2]])
				{
					sRed3.setPosition(redStopPositions[2]);
					yellowKill = true;
				}
				if (Yellow_Movement[yellowCurrentPositions[1]] == Red_Movement[redCurrentPositions[3]])
				{
					sRed4.setPosition(redStopPositions[3]);
					yellowKill = true;
				}
			}
		}
		if (sYellow3.getGlobalBounds().contains(mousePosition)) {
			actionTaken = true;
			if (diceValue == 6 &&
				sYellow3.getPosition().x == yellowStopPositions[2].x && sYellow3.getPosition().y == yellowStopPositions[2].y) {
				yellowCurrentPositions[2] = 0;
				sYellow3.setPosition(Yellow_Movement[yellowCurrentPositions[2]]);
			}
			else if (sYellow3.getPosition().x != yellowStopPositions[2].x && sYellow3.getPosition().y != yellowStopPositions[2].y) {
				if (!yellowKill) {
					yellowCurrentPositions[2] = (yellowCurrentPositions[2] + diceValue) % 52;
				}
				if (yellowKill && (yellowCurrentPositions[2] + diceValue) <= 58) {
					yellowCurrentPositions[2] = (yellowCurrentPositions[2] + diceValue);
					if (yellowCurrentPositions[2] > 51 && checkYellow) {
						yellowCurrentPositions[2] += 1;
						checkYellow = false;
					}
				}
				sYellow3.setPosition(Yellow_Movement[yellowCurrentPositions[2]]);
				if (Yellow_Movement[yellowCurrentPositions[2]] == Red_Movement[redCurrentPositions[0]])
				{
					sRed1.setPosition(redStopPositions[0]);
					yellowKill = true;
				}
				if (Yellow_Movement[yellowCurrentPositions[2]] == Red_Movement[redCurrentPositions[1]])
				{
					sRed2.setPosition(redStopPositions[1]);
					yellowKill = true;
				}
				if (Yellow_Movement[yellowCurrentPositions[2]] == Red_Movement[redCurrentPositions[2]])
				{
					sRed3.setPosition(redStopPositions[2]);
					yellowKill = true;
				}
				if (Yellow_Movement[yellowCurrentPositions[2]] == Red_Movement[redCurrentPositions[3]])
				{
					sRed4.setPosition(redStopPositions[3]);
					yellowKill = true;
				}
			}
		}
		if (sYellow4.getGlobalBounds().contains(mousePosition)) {
			actionTaken = true;
			if (diceValue == 6 &&
				sYellow4.getPosition().x == yellowStopPositions[3].x && sYellow4.getPosition().y == yellowStopPositions[3].y) {
				yellowCurrentPositions[3] = 0;
				sYellow4.setPosition(Yellow_Movement[yellowCurrentPositions[3]]);
			}
			else if (sYellow4.getPosition().x != yellowStopPositions[3].x && sYellow4.getPosition().y != yellowStopPositions[3].y) {
				if (!yellowKill) {
					yellowCurrentPositions[3] = (yellowCurrentPositions[3] + diceValue) % 52;
				}
				if (yellowKill && (yellowCurrentPositions[3] + diceValue) <= 58) {
					yellowCurrentPositions[3] = (yellowCurrentPositions[3] + diceValue);
					if (yellowCurrentPositions[3] > 51 && checkYellow) {
						yellowCurrentPositions[3] += 1;
						checkYellow = false;
					}
				}
				sYellow4.setPosition(Yellow_Movement[yellowCurrentPositions[3]]);
				if (Yellow_Movement[yellowCurrentPositions[3]] == Red_Movement[redCurrentPositions[0]])
				{
					sRed1.setPosition(redStopPositions[0]);
					yellowKill = true;
				}
				if (Yellow_Movement[yellowCurrentPositions[3]] == Red_Movement[redCurrentPositions[1]])
				{
					sRed2.setPosition(redStopPositions[1]);
					yellowKill = true;
				}
				if (Yellow_Movement[yellowCurrentPositions[3]] == Red_Movement[redCurrentPositions[2]])
				{
					sRed3.setPosition(redStopPositions[2]);
					yellowKill = true;
				}
				if (Yellow_Movement[yellowCurrentPositions[3]] == Red_Movement[redCurrentPositions[3]])
				{
					sRed4.setPosition(redStopPositions[3]);
					yellowKill = true;
				}
			}
		}
	}

	//For debugging references
	if (actionTaken) {
		cout << "Dice value was for player" << diceValue << (playerTurn + 1)<<redKill<<"\t"<<yellowKill << endl;
		requiresPawnInput = false;
		playerTurn = (playerTurn + 1) % totalPlayers;
	}

}

int main()
{
	// Local variables
	int num;
	bool showStartScreen = true;
	int NumOfPlayer = 0;
	int diceValue;
	int KeepTrackRed[4] = { 0 };

	// Initialize the sprites
	initializeSprites();

	// Open the Window
	RenderWindow window(VideoMode(windowWidth, windowHeight), "Ludo SFML");

	sStart.setPosition(Vector2f(0, 0));
	sHowToPlay.setPosition(Vector2f(0, 0));

	sTurn.setPosition(Vector2f(860,0));

	sRed_Win.setPosition(Vector2f(860, 200));
	sYellow_Win.setPosition(Vector2f(860, 300));

	sBestScore.setPosition(Vector2f(250, 300));

	sRed1.setPosition(redStopPositions[0]);
	sRed2.setPosition(redStopPositions[1]);
	sRed3.setPosition(redStopPositions[2]);
	sRed4.setPosition(redStopPositions[3]); 

	sYellow1.setPosition(yellowStopPositions[0]);
	sYellow2.setPosition(yellowStopPositions[1]);
	sYellow3.setPosition(yellowStopPositions[2]); 
	sYellow4.setPosition(yellowStopPositions[3]);

	bool requiresRollDice = true;
	bool requiresPawnInput = false;
	Event event1;
	bool showBestScore = false;
	while (window.isOpen())
	{
		while (window.pollEvent(event1))
		{
			if (event1.type == Event::EventType::Closed)
			{
				window.close();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		window.draw(sBackG);

		window.draw(sRed1);
		window.draw(sRed2);
		window.draw(sRed3);
		window.draw(sRed4);

		window.draw(sYellow1);
		window.draw(sYellow2);
		window.draw(sYellow3);
		window.draw(sYellow4);
		if (showBestScore) {
			window.draw(sBestScore);
		}

		window.draw(dice);
		if (showStartScreen)
		{
			window.draw(sStart);
		}
		else {
			if (playerTurn == 0) {
				sTurn.setTexture(Red_Turn);
			}
			else if(playerTurn == 1) {
				sTurn.setTexture(Yellow_Turn);
			}
			window.draw(sTurn);
		}

		// Keyboard events
		// Game startup
		if (Keyboard::isKeyPressed(Keyboard::Enter)) 
		{
			showStartScreen = false;
			sStart.setPosition(-100, -100);
		}
		
		if (Keyboard::isKeyPressed(Keyboard::H))
		{
			window.draw(sHowToPlay);
		}

		if (Keyboard::isKeyPressed(Keyboard::Q))
		{
			showBestScore = false;
		}

		if (Keyboard::isKeyPressed(Keyboard::B))
		{
			ifstream fin;
			fin.open("Record.txt");
			char _getChar;
			showBestScore = true;
			fin>>_getChar;
			if (_getChar == 'R')
			{
				sBestScore.setTexture(Red_Best);
			}
			else if(_getChar == 'Y'){
				sBestScore.setTexture(Yellow_Best);
			}
			else {
				sBestScore.setTexture(Nothing_Best);
			}
		}

		// Dice roll up
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			if (requiresRollDice && !showStartScreen) {
				requiresRollDice = false;
				requiresPawnInput = true;
				diceValue = rollDice();
			}
		}

		// Handling mouse input for start up screen.
		if (Mouse::isButtonPressed(Mouse::Left)) {
			// Get position of mouse
			Vector2i mousePosition = Mouse::getPosition(window);

			if (requiresPawnInput && !showStartScreen) {
				Vector2f mousePositionf = Vector2f(mousePosition.x, mousePosition.y);
				movePawn(diceValue, requiresPawnInput, mousePositionf);
				requiresRollDice = !requiresPawnInput;
			}
		}
		if (redCurrentPositions[0] == 58 && redCurrentPositions[1] == 5 && redCurrentPositions[2] == 58 && redCurrentPositions[3] == 58)
		{
			window.draw(sRed_Win);
			ofstream fout;
			fout.open("Record.txt");
			fout<< "Red Won" << endl << "Yellow Lost" << endl;
		}

		if (yellowCurrentPositions[0] == 58 && yellowCurrentPositions[1] == 58 && yellowCurrentPositions[2] == 58 && yellowCurrentPositions[3] == 58)
		{
			window.draw(sYellow_Win);
			ofstream fout;
			fout.open("Record.txt");
			fout << "Yellow Won" << endl << "Red Lost" << endl;
		}

		if (showBestScore) {
			window.draw(sBestScore);
		}

		window.display();
	}
	std::system("pause");
}