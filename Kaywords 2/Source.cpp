/* Brittney Tollison
01/01/2021
Code Breaker Training Simulation Program named Keywords Round 2
*/
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;
vector<string> spyWords;
string recruitsName;
// Create an int var to count the number of simulations being run starting at 1
	int simulations = 1;
	// Defines the playAgain variable so that the simulation can be rerun.
	char playAgain = 'y';

	int main()
	{
		// Display Title of the program to the user
		cout << "Code Breaker Training Simulation Program named Keywords Round 2!" << endl << endl << endl;
		// Ask the recruit to log in using their name0
		cout << "Recruits are required to log in using your name!" << endl;
		// Hold the recruit's name in a var, and address them by it throughout the simulation.
		cin >> recruitsName;
		// Display an overview of what Keywords II is to the recruit 
		cout << "Dear " << recruitsName << " you have made it past the first round of training. Welcome to round 2" << endl;
		// Display directions to the recruit on how to use Keywords
		cout << "Codebreaker Training simulation Keywords 2 need you to guess key words without getting to many incorrect" << endl;
		cout << "You will be asked to input your guess, all you have to do is type in a letter and hit the enter key." << endl;

		// Create a collection of 10 words you had written down manually
		spyWords.push_back("SECRET");
		spyWords.push_back("AGENT");
		spyWords.push_back("MISSION");
		spyWords.push_back("OPERATIVE");
		spyWords.push_back("DETECTIVE");
		spyWords.push_back("CLASSIFIED");
		spyWords.push_back("INVESTIGATOR");
		spyWords.push_back("INTEL");
		spyWords.push_back("SPY");
		spyWords.push_back("UNDERCOVER");

		// While loop so the simulation can be rerun
		while (playAgain == 'y')
		{

		// Display the simulation # is starting to the recruit. 
			cout <<"Simulation has been ran " 		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
			srand(static_cast<unsigned int>(time(0)));
			random_shuffle(spyWords.begin(), spyWords.end());

		// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word

		//     Tell recruit how many incorrect guesses he or she has left

		//     Show recruit the letters he or she has guessed

		//     Show player how much of the secret word he or she has guessed

		//     Get recruit's next guess

		//     While recruit has entered a letter that he or she has already guessed

		//          Get recruit ’s guess

		//     Add the new guess to the group of used letters

		//     If the guess is in the secret word

		//          Tell the recruit the guess is correct

		//          Update the word guessed so far with the new letter

		//     Otherwise

		//          Tell the recruit the guess is incorrect

		//          Increment the number of incorrect guesses the recruit has made

		// If the recruit has made too many incorrect guesses

		//     Tell the recruit that he or she has failed the Keywords II course.

		// Otherwise

		//     Congratulate the recruit on guessing the secret words

		// Ask the recruit if they would like to run the simulation again

		// If the recruit wants to run the simulation again

		//     Increment the number of simulations ran counter

		//     Move program execution back up to // Display the simulation # is starting to the recruit. 

		// Otherwise 
	
 }
 //     Display End of Simulations to the recruit
 cout << "This is the end of the similuation!" << endl;
 //     Pause the Simulation with press any key to continue
 

