#include <iostream>
#include <vector>
#include "ConnectFour.h"


void ConnectFour::play() 
{ 
	bool isGoodMove = false;
	this->printInstructions(); // print instructions
	this->printBoard();		   // print the board
  // keep playing as long as the game is not won or tied
	while (!this->isWin() && !this->isTie()) 
  { 
		isGoodMove = this->takeTurn(); // current player takes a turn
		if (isGoodMove) 
    {
			this->printBoard(); // print the board if that was a good move
			if (this->isWin())
				break; // if that was a winning move, quit the game
			if (this->isTie())
				break;			// else if the game is tied, quit the game
			this->nextPlayer(); // else, advance to the next player in the game.
		} // else that was an illegal move
	}	// end while: game over
	if (this->getWinningPlayerId() == -1)
		std::cout << "Sorry - It looks like the game was a tie." << std::endl;
	else
		std::cout << "Congratulations: Player #" << this->getCurrentPlayerToken()
				  << " has won the game!" << std::endl;
	std::cout << "Goodbye!" << std::endl;
} // end play

/*
Constructor
Param: _emptyToken (the token used for an empty space (defaults to dash)
Param: _playerTokens (the characters that describe the players, defaults to X and O)
Param: _initTokens (the tokens that initialize the board for a game already in progress)
Param: _startingPlayerId (the id of the player that goes first to start the game)
*/
ConnectFour::ConnectFour (char _emptyToken, std::vector<char>_playerTokens, std::vector<char> _initTokens, int _startingPlayerId) : emptyToken(_emptyToken), playerTokens(_playerTokens) 
{
  currentPlayerId = _startingPlayerId;
  /*
  Counter initialized outside the loop so the board won't be filled with only the first 7 terms of _initTokens for every row
    */
  int counter = 0; 
  for (int r = 0; r < this->numRows; r++) 
    {
      this->board.push_back({}); // create empty row to fill
      for (int c = 0; c < this->numCols; c++)
        {
          /*
          _initTokens represents a game in progress, so not all the spaces will be filled by _initToken
          */
          if (counter < _initTokens.size()) s
          {
            this->board[r].push_back(_initTokens[counter]);
            counter++;
          }
          else
            this->board[r].push_back(_emptyToken);
        }  
    }
}


    void ConnectFour::printInstructions() // print instructions for the game
  {
    std::cout << "How to Play Connect Four" << std::endl << std::endl;
    std::cout << "Drop your token into a column and it will land at the bottom of the column, or on top of the stack of tokens already in that column." << std::endl << std::endl;
    std::cout << "The objective of the game is to have four tokens in a row, whether diagonally, horizontally, or vertically." << std::endl << std::endl;
    std::cout << "Good luck!" << std::endl << std::endl;
  }


  void ConnectFour::printBoard() // print the board
  {
    std::cout << "1234567" << std::endl; //column labels
    for (int r = 0; r < this->numRows; r++) 
      {
        for (auto item: this->board[r])
          std::cout << item;
        std::cout << std::endl;
      }  
    std::cout << std::endl;
  }

// return the character that represents the current player
  char ConnectFour::getCurrentPlayerToken()  
  {
    return playerTokens[currentPlayerId];
  }

  // advance to the next player in the game
  void ConnectFour::nextPlayer() 
  {
    currentPlayerId++;
    currentPlayerId %= playerTokens.size();
  }

// prompt the current human player and process their turn, returning true if it was successful
  bool ConnectFour::takeTurn()  
 {
  std::cout << playerTokens[currentPlayerId] << "\'s' turn!" << std::endl;
  int playerColumn; 
  std::cout << "Your column: ";
  std::cin >> playerColumn;
   // decrement because the player sees the columns as 1-7, but the computer indexes them as 0-6
  playerColumn--; 
  if (playerColumn < 0 || playerColumn > 6) // out of range
    return false;
   // since the token is dropped, it falls to the greatest empty row of the selected column
  for (int row = numRows - 1; row >= 0; row--) 
    {
      if (board[row][playerColumn] == emptyToken) // slot is not taken by another token
      {
        board[row][playerColumn] = getCurrentPlayerToken(); // player's token placed in slot
        std::cout << std::endl;
        return true;
      }     
    } 
  return false; // invalid move
}

/*
Determine if the CURRENT PLAYER has won the game and update winningPlayerId to the winning player's ID.
  */
bool ConnectFour::isWin() 
{
  for (int row = 0; row < 6; row++)
    {
      for (int col = 0; col < 3; col++)
        {
          if (playerTokens[currentPlayerId] == board[row][col] && playerTokens[currentPlayerId] == board[row][col + 1] && playerTokens[currentPlayerId] == board[row][col + 2] && playerTokens[currentPlayerId] == board[row][col + 3]) // horizontal win
          {
            std::cout << "Won by horizontal " << std::endl;
            winningPlayerId = currentPlayerId;
            return true;
          }
        }
      }
  for (int row = 0; row < 3; row++)
    {
      for (int col = 0; col < 7; col++)
        {
          if (playerTokens[currentPlayerId] == board[row][col] && playerTokens[currentPlayerId] == board[row + 1][col] && playerTokens[currentPlayerId] == board[row + 2][col] && playerTokens[currentPlayerId] == board[row + 3][col]) // vertical win
          {
            winningPlayerId = currentPlayerId;
            std::cout << "Won by vertical " << std::endl;
            return true;
          }
        }
      }
  for (int row = 0; row < 3; row++)
    {
      for (int col = 0; col < 4; col++)
        {          
         if (playerTokens[currentPlayerId] == board[row][col] && playerTokens[currentPlayerId] == board[row + 1][col + 1] && playerTokens[currentPlayerId] == board[row + 2][col + 2] && playerTokens[currentPlayerId] == board[row + 3][col + 3]) // diagonal win in downward direction
            {
            std::cout << "Won by diagonal " << std::endl;
              winningPlayerId = currentPlayerId;
            return true;
            }
          }
      }
  for (int row = 3; row < 6; row++)
    {
      for (int col = 0; col < 3; col++)
        {
          if (playerTokens[currentPlayerId] == board[row][col] && playerTokens[currentPlayerId] == board[row - 1][col + 1] && playerTokens[currentPlayerId] == board[row - 2][col + 2] && playerTokens[currentPlayerId] == board[row - 3][col + 3]) // diagonal win in upward direction
          {
            std::cout << "Won by diagonal " << std::endl;
              winningPlayerId = currentPlayerId;
            return true;
          }
        }
    }
  return false;
}


// return the value of the private winningPlayerId, as set by isWin()
    int ConnectFour::getWinningPlayerId() 
    {
     return winningPlayerId; 
    }

  // determine if the game cannot be won by either player regardless of the number of moves
    bool ConnectFour::isTie() 
{
  for (int i = 0; i < numCols; i++)
    {
      /*
      If there is still an empty space at the top of the board, then there is at least one move that can still be made
      */
      if (board[1][i] == emptyToken) 
        return false;
    }
  return true;
}  