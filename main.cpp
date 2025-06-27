#include "ConnectFour.h"
#include "testMe.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
	testMe(); 
	ConnectFour game; // default constructor
	game.play(); // play the game
}