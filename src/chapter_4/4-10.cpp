/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4, exercise 10
	Page 127
*/
#include "std_lib_facilities.h"

// We use Stroustrup's solution for generating the next cpu play.
// http://www.stroustrup.com/Programming/Solutions/Ch4/e4-10.cpp
/*************************************************************************************************************/
int v1 = 1;
int v2 = 2;

int fib()	// generate the next element of a (Fibbonacci) series:
			// 1 2 3 5 8 13 21 34
{
	int s = v1+v2;
	if (s<=0) s = 1;	// how could s become less than zero?
	v1 = v2;
	v2 = s;
	return s;
}

void generate(int seed)
	// use the seed to choose where in the sequence the game starts
{
		if (seed<0) seed = -seed;	// don't want a negative number
		seed %=10;					// don't want a number larger than 9
		if (seed==0) return;		// don't bother: use the default
		for (int i=0 ; i<seed; ++i) fib();	// move seed steps forward
}

int next_play()	// generate a reasonably obscure sequence of 0s, 1s, and 2s
{
	return fib()%3;	// we are only interested in a value 0, 1, or 2 (% is the modulus/remainder operation)
}
/*************************************************************************************************************/
int parse_choice(string choice)
{
	if (choice == "r" || choice == "rock") 
		return 0;
	else if (choice == "p" || choice == "paper")
		return 1;
	else if (choice == "s" || choice == "scissors")
		return 2;
	else if (choice == "q" || choice == "quit")
                return 3;	
	else
		return -1; // Choice was invalid.
}

int main()
{
	cout << "Welcome to Rock, Paper, Scissors!" << endl;
	cout << "---------------------------------" << endl << endl;
	cout << "Enter a seed to help me play: ";
	int seed;
	cin >> seed;
	generate(seed);

	// Lets keep score.
	int user_wins = 0;
	int cpu_wins  = 0;
	int draws     = 0;
	
	int continue_game = 1; // 1 = true, set to 0 for false.
	while (continue_game == 1) {
		cout << "Enter your pick ([r]ock, [p]aper, [s]cissors, or [q]uit): ";
		string choice;
		cin >> choice;	

		// Convert users choice to an integer we can easily compare to cpu choice.
		// Is set to invalid(-1) if choice is not recognized.
		int user_choice = parse_choice(choice);

		if (user_choice == -1) {
			cout << "Invalid choice." << endl;
			continue_game = 0;
		}
		else if (user_choice == 3) { // Quit game was requested.
            cout << "Goodbye!" << endl;
			continue_game = 0;
        }
		else { // Play game.
			const int rock    = 0;
			const int paper   = 1;
			const int scissor = 2;
			
			int round_winner = 0; // CPU wins by default.
			string cpu_choice;    // String representation of cpu's choice.
			int cpu_play = next_play();
			
			if (cpu_play == user_choice) round_winner = 0xD; // It's a draw.
			else { 
				switch (cpu_play) {
				case rock:
					if (user_choice == paper) round_winner = 1;
					cpu_choice = "rock";
					break;
				case paper:
					if (user_choice == scissor) round_winner = 1;
					cpu_choice = "paper";
					break;
				case scissor:
					if (user_choice == rock) round_winner = 1;
					cpu_choice = "scissors";
					break;
				}
			}

			switch (round_winner) {
			case 0:
				cout << "Winner is CPU. " << cpu_choice << " beats " << choice << "." << endl;
				++cpu_wins;
				break;
			case 1:
				cout << "You win. " << choice << " beats " << cpu_choice << "." << endl;
				++user_wins;
				break;
			case 0xD:  
				cout << "It's a draw." << endl;
				++draws;
				break;
			}
	
			cout << "Your score is:" << endl 
                 << "Wins: " << user_wins << endl 
				 << "Losses: " << cpu_wins << endl 
				 << "Draws: " << draws << endl;
		}
	}
	return 0;
}
