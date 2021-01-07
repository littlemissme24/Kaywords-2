/* 01/01/2021
Brittney Tollison
Building the Code Breaker Training Simulation Program for CIA Recruits */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

// Create an int var to count the number of simulations being run starting at 1
int simulations = 1;
// Defines the playAgain variable so that the simulation can be rerun.
char anotherRound = 'y';
using namespace std;
string recruitsName;
// Maximum number of incorrect guesses that will be allowed.
const int MAX_WRONG = 15;
vector<string> spyWords;
//Tracks how many words the user got correct so that they need to complete 3 words.
int Correctwords = 0;

int main()
{
	// Display Title of program to user
	cout << "Welcome recruit to Training Sumulation Round 2 : Keywords2" << endl << endl << endl;
	// Ask the recruit to login using their name
	cout << "What is your name rookie? " << endl;
	// Hold the recruit's name 
	cin >> recruitsName;
	// Display an overview of what Keywords II is to the recruit.
// Display an directions to the recruit on how to use Keywords
	cout << "\n Hello " << recruitsName <<"." << endl;
	cout << "\n You will be guessing letters for the scrambled word. Once the word is desiphered you will need to unscramble it" << endl;
	cout << "\n You will be doing this 3 times to complete the training simulation"<< endl;
	// Create a collection of 10 words you had wrote down manually.
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
	// While loop for when user wants to play again
	while (anotherRound == 'y')
	{
		// Display the simulation # is starting to the recruit.
		cout << "Similation #" << simulations << " is starting." << endl;

		// While loop that requiries atleast 3 words to be completed
		while (Correctwords < 3)
		{
			// Seeds the random number generator and shuffles the words in the vector.
			srand(static_cast<unsigned int>(time(nullptr)));
			random_shuffle(spyWords.begin(), spyWords.end());
			// Pick new 3 random words from your collection as the secret code word the recruit has to guess.
            string wordsGrouped = spyWords[0];
			// Shuffles the letters in the word that was picked at random.
			random_shuffle(wordsGrouped.begin(), wordsGrouped.end());
			//Tracks number of incorrect guesses.
			int incorrect = 0;
			//Tracks how much of the word is guessed so far.
			string lettersGuessedCorrectly(wordsGrouped.size(), '-');
			//Tracks letters that were already guessed.
			string usedLetters = "";
			//Tracks guesses for unscrambling the word
			string scrambleWordGuess = "null";
			while ((incorrect < MAX_WRONG) && (lettersGuessedCorrectly != wordsGrouped))
			{
				// Tell recruit how many incorrect guesses he or she has left
				cout << "\nYou have " << (MAX_WRONG - incorrect);
				cout << " incorrect guesses remaining.\n";
				// Show recruit the letters he or she has guessed
				cout << "You have already used letter:\n" << usedLetters << endl;
				// Show player how much of the secret word he or she has guessed
				cout << "The word is:\n" << lettersGuessedCorrectly << endl;
				// Get recruit's next guess
				char guess;
				cout << "\n\nEnter your guess: ";
				cin >> guess;
				// Makes the guess letter uppercase
				guess = toupper(guess);
				// While recruit has entered a letter that he or she has already guessed
				while (usedLetters.find(guess) != string::npos)
				{
					// Get recruit ’s guess
					cout << "\nYou've already guessed " << guess << endl;
					cout << "Enter your guess: ";
					cin >> guess;
					// Makes the guess letter uppercase
					guess = toupper(guess);
				}
				// Add the new guess to the group of used letters
				usedLetters += guess;
				// If the guess is in the secret word
				if (wordsGrouped.find(guess) != string::npos)
				{
					cout << "That's correct rookie, " << recruitsName << ". " << guess << " is in the word.\n";
					// Update the word guessed so far with the new letter
					for (unsigned int i = 0; i < wordsGrouped.length(); ++i)
					{
						if (wordsGrouped[i] == guess)
						{
							lettersGuessedCorrectly[i] = guess;
						}
					}
				}
				else
				{
					// Tell the recruit the guess is incorrect
					cout << "Sorry, " << guess << " isn't in the word.\n";

					// Increment the number of incorrect guesses the recruit has made
					++incorrect;
				}
			}
			// If the recruit has made too many incorrect guesses
			if (incorrect == MAX_WRONG)
			{
				// Tell the recruit that he or she has failed the Keywords II course.
				cout << "\nYou have FAILED! \n";
				Correctwords = 3;
			}
			else if (Correctwords == 3)
			{
				// Congratulate the recruit on guessing all of the secret words.
				cout << "\nThat is correct. You have solved all of the words. Training successful.\n";
			}
			else
			{
				// Congratulate the recruit on guessing the secret words.
				cout << "You have no discovered all the letters in the code word.\n";
				cout << "Please solve the scrambled word " << wordsGrouped << "." << endl;

				while (scrambleWordGuess != spyWords[0])
				{
					// Asks the agent to guess what the scrambled word is.
					cout << "\nYour guess (PLEASE USE ALL CAPS): ";
					cin >> scrambleWordGuess;

					// If else statement saying whether or not they are correct or incorrect.
					if (scrambleWordGuess == spyWords[0])
					{
					cout << "Correct.\n";
					++Correctwords;
					}
					else
					{
					cout << "Sorry, that is incorrect.\n";
					cout << "Please solve the scrambled word " << wordsGrouped << "." << endl;
					}
				}

			}
		}
		// Ask the recruit if they would like to run the simulation again.
		if (Correctwords == 3)
		{
			cout << "\n\nCongratulations.You have passed this simulation. \n";
		}
		cout << "Do you want to play this simulation again? (y/n): " << endl;
		cin >> anotherRound;
		if (anotherRound == 'y')
		{
			++simulations;
		}
		else
		{

			cout << "This is the end of the simulation.";
			return 0;
		}
	}
	return 0;
}