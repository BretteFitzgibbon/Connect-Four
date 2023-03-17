#include "ConnectFour.h"
#include "testMe.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
	testMe(); // uncomment when you are ready to test the class by
	// redirecting standard input and output

	// now do interactive testing

	ConnectFour game; // default constructor

	// OR

	//ConnectFour game('.', {'X', 'Y', 'Z'}); // specify empty token and the three player tokens  X, Y, and Z

	// OR

	// vector<char> playerTokens = {'P', 'Q', 'W', 'X'}; 
 //  ConnectFour game('-', playerTokens); // create an instance of the game using playerTokens.

	game.play(); // play the game
}