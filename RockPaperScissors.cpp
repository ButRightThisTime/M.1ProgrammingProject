#include <cstdlib> 
#include <ctime> 
#include <iostream>

using namespace std;
int generateRandomNumber();
int getPlayerChoice();
string determineWinner(int hChoice, int cChoice, int &playerScore, int &computerScore);
string convertChoice(int choice);
int main()
{
	cout << "Rock, Paper, Scissors Game" << endl << "How many rounds do you want to play?" << endl;;
	int rounds = 0;
	while (rounds == 0) {
		cin >> rounds;
		cin.clear(); // clear cin error state
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin buffer}
	}
	int playerScore, computerScore; 
	playerScore = 0;
	computerScore = 0;
	while (rounds > 0)
	{
		int computerChoice = generateRandomNumber();
		int playerChoice = getPlayerChoice();
		if (playerChoice != 4) { // player chose rock paper or scissors
			string winner = determineWinner(playerChoice, computerChoice, playerScore, computerScore); // also updates scores
			cout << "Computer Chose: " << convertChoice(computerChoice) << endl;
			cout << "Winner"  << winner << endl;
			rounds -= 1;
		}
		else			
		{ // player chose quit or rounds naturally reached 0
			rounds = 0;
		}
		cout << "Player Score: " << playerScore << " Computer Score: " << computerScore << endl;

	}
	cout << " _______________Game Over_______________" << endl << "Final Score: " << "Player Score: " << playerScore << " Computer Score: " << computerScore << endl;
	return 0;
}
/// <summary>
/// generates a number between 1 and three
/// </summary>
/// <returns>an int between 1 and 3</returns>
int generateRandomNumber()
{
	srand((unsigned)time(0));
	int i;
	i = (rand() % 3) + 1;
	return i;
}
/// <summary>
/// Input validation for an int between 1 and 4
/// </summary>
/// <returns>int between 1 and 4 of user input</returns>
int getPlayerChoice()
{
	cout << "Enter 1 for Rock, 2 for Paper, 3 for Scissors, and 4 to Quit" << endl;
	int choice;
	cin >> choice;
	if (choice < 1 || choice > 4 || cin.fail())
	{
		cin.clear(); // clear cin error state
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin buffer
		cout << "Invalid choice. Please try again." << endl;
		getPlayerChoice();
	}
	return choice;
}
/// <summary>
/// converts integer choice to string
/// </summary>
/// <param name="choice">number 1-3</param>
/// <returns>"Rock", "Paper", or "Scissors"</returns>
string convertChoice(int choice) 
{
	if (choice == 1)
	{
		return "Rock";
	}
	else if (choice == 2)
	{
		return "Paper";
	}
	else if (choice == 3)
	{
		return "Scissors";
	}
}
/// <summary>
/// Determines the winner in a game of Rock, Paper, Scissors
/// </summary>
/// <param name="hChoice">human choice 1 rock 2 paper 3 scissors</param>
/// <param name="cChoice">computer choice 1 rock 2 paper 3 scissors</param>
/// <returns>TIE,PLAYER,or COMPUTER</returns>
string determineWinner(int hChoice, int cChoice, int &playerScore, int &computerScore)
{
	if (hChoice == cChoice)
	{
		return "TIE";
	}
	else if (hChoice == 1 && cChoice == 3)
	{
		playerScore += 1;
		return "PLAYER";
	}
	else if (hChoice == 2 && cChoice == 1)
	{
		playerScore += 1;
		return "PLAYER";
		
	}
	else if (hChoice == 3 && cChoice == 2)
	{
		playerScore += 1;
		return "PLAYER";
		
	}
	else
	{
		computerScore += 1;
		return "COMPUTER";
		
	}

}