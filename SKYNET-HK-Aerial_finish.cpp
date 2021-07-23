/*
James Ford 
C++ 215
skyNet HK-Aerial
This is an 8x8 grid search program. It uses loops to locate an enemy.
*/

//necessary libraries for this assignment
#include <iostream>
#include <cstdlib>
#include <ctime>
//declare the namespace as standard
using namespace std;
//main
int main()
{
	//declare variables for different generators and algorithms in this program
	
	//establish the lowest number
	int searchGridLowNumber = 1;
	// establish the highest number
	int searchGridHighNumber = 64;
	//seeding the random number generator
	srand(static_cast<unsigned int>(time(0)));
	//set a range
	int secretNumber = rand() % 64 + 1;
	//search algorithm's possible numbers within the range
	int targetLocationPrediction =
		((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

	//set  varibles to keep track of number of guesses
	int tries = 0;
	//start the test
	cout << "The enemy gets into attack position on an 8x8 grid \n";
	cout << "The enemy has been located at" << secretNumber << ". \n";
	cout << " SKYNET HK-Aerial initalizing search program \n";

	//Do-While loop running the algorithm and game text
	do
	{
		//increment tries to get the first ping
		++tries;
		cout << ".../n";
		cout << "HK-Aerial Radar attempt #" << tries << "\n";
		//start the search algorithm for this cycle
		targetLocationPrediction =
			((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

		//start conditional to see if the ss is less or greater than the random number

		//if guess is greater the number 
		if (targetLocationPrediction > secretNumber)
		{
			cout << "The program guessed the enemy was located in sector " << targetLocationPrediction << "\n";
			cout << " Sadly, that is higher than the sector number that the enemy is currently in \n";
			cout << "The program will use this new number as the maximum because guessing anything higher would be useless \n";
			//assign this guess as the high number
			searchGridHighNumber = targetLocationPrediction;
			//tell the user
			cout << "The new maximum possible is " << searchGridHughNumber << "\n";
		}
		//If the guess is lower than the number
		else if (targetLocationPrediction < secretNumber)
		{
			cout << "The program guessed the enemy was located in sector " << targetLocationPrediction << "\n";
			cout << " Sadly, that is lower than the sector number that the enemy is currently in \n";
			cout << "The program will use this new number as the minimum because guessing anything lower would be useless \n";

			//asign this guess as the new low number
			searchGridLowNumber = targetLocationPrediction;
			//tell the user 
			cout << "The new minmum number possible is " << searchGridLowNumber << "\n";
		}
		//correct guess condition
		else (targetLocationPrediction = secretNumber)
		{
			cout << "The program has successfully found the enemies attack positions in sector " << secretNumber << "\n";
			cout << " The enemy attack postion was located in Sector " << targetLocationPrediction << "\n";
			cout << "The SKYNET HK-Aerial program took " << tries << "guesses to find the enemies attack position";
		}
	}
	//set the loop condition
	while (targetLocationPrediction != secretNumber);

	//main() return statement
	return 0;
}