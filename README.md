# Overview

Write a program that enables at least three (3) players to play a game of Connect Four using a 6 rows by 7 columns game board and two configurable player tokens.   Note that your game should be trivially extendable to any number of players, based entirely on your constructor (not a requirement for the AI portion of the bonus). (This assignment offers an optional +15 point bonus for implementation of 2 enhancements)

You can practice playing the game here to get a general idea about how it works:

https://www.mathsisfun.com/games/connect4.html


- Your program should fully manage alternating player turns.
  * Allow players to specify only the column number of their choice on a single line (the game should know what token to use, depending on who's turn it is). Like this:
  *  `X's turn:` **1** (<- the player enters "1")
  * Column titles should be values 1 through 6. (you do not need to print row numbers).
  * Players take turns dropping their tokens into a column of choice that is not yet full.
  * Each dropped token falls to the lowest available location in the selected column that is currently empty.
  * A player wins when their token occupies 4 consecutive locations on  any row, column or diagonal.
  * A tie occurs when all positions on the board are filled, but no player has yet won the game.

```
1	2	3	4	5	6	7
-	-	-	-	-	-	-
-	-	-	X	-	-	-
-	-	X	O	-	-	-
-	X	O	O	-	-	-
X	O	O	X	-	-	-
X	O	X	X	-	-	-
```

# Getting Started


# Sample Output
This output shows a game "already in progress" (created by the **ConnectFour** constructor).
The game shown below is between 2 players represented by an 'X' and 'Y' tokens.
```
Let's play Connect Four!
Enter column number like "3" for column 3.
 1  2  3  4  5  6  7
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
X's turn: 1
 1  2  3  4  5  6  7
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 X  .  .  .  .  .  .
Y's turn: 2
 1  2  3  4  5  6  7
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 X  Y  .  .  .  .  .
X's turn: 2
 1  2  3  4  5  6  7
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  X  .  .  .  .  .
 X  Y  .  .  .  .  .
Y's turn: 3
 1  2  3  4  5  6  7
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  X  .  .  .  .  .
 X  Y  Y  .  .  .  .
X's turn: 3
 1  2  3  4  5  6  7
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  X  X  .  .  .  .
 X  Y  Y  .  .  .  .
Y's turn: 4
 1  2  3  4  5  6  7
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  X  X  .  .  .  .
 X  Y  Y  Y  .  .  .
X's turn: 4
 1  2  3  4  5  6  7
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  X  X  X  .  .  .
 X  Y  Y  Y  .  .  .
Y's turn: 5
 1  2  3  4  5  6  7
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  .  .  .  .  .  .
 .  X  X  X  .  .  .
 X  Y  Y  Y  Y  .  .
Player Y wins the game via row 6
Congratulation: Player Y has won the game!
Goodbye!
```

# Implentation Constraints
  * You will utilize a `ConnectFour` class that will help you manage your entire game through its `play()` method. The `play()` method has been written for you and can be found in the `ConnectFour.cpp` file.

  * You must implement your game through 3 separate  files: `main.cpp`, `ConnectFour.cpp`,  and `ConnectFour.h`.
  * `ConnectFour.h` is already provided for(you should not change it without permisson to do so)
  * `main.cpp` is already provided for you, but you may change it to help test your program by modifying the way you call the ConnectFour constructor before starting the game.
  * `ConnectFour.cpp` is provided, but is empty. You will need to implement the "out of class" (OOC) constructor and all methods in this file. Don't forget to use the name of the class and the scope resolution operator appropriately.
  * You may NOT use the "using namespace std" statement in in `ConnectFour.cpp` class.  `(-2 points if you do)`.

- Your `ConnectFour` constructor should initialize all private member variables
  * It must use a constructor initializer list for all private members except the game board `(-2 points if you fail to use a constructor initializer list)`
  * Note that the constructor will indicate how many players want to play based on the number of unique player tokens it receives as its 2nd argument.
  * Your constructor can use a for-loop to initialize the game board, by considering the 'initTokens' argument of the constructor.  The vector 'initTokens' is optionally specified to allow any game to be started from an existing board of valid player tokens (you can assume that any initTokens vector you are given is in a valid state that does not break any of the rules of the game).
  * Your constructor prototype will provide defaults for all arguments, so that you can instance your game in multiple ways (recall that the defaults live in the `ConnectFour.h` file, so you do not need to worry about the defaults for the constructor or methods.

- Your `printInstructions()` method should print out a brief description about how to play the game.

- Your `printBoard()` method should print out the current state of the game board, as shown above

- Your `nextPlayer()` method should increment the private `currentPlayerId` member of the class (from zero to `playerTokens.size()` ) , but should start over at 0, after the last player has had a turn. (connect four is usually played with 2 players, but it should support an arbitrary number of players as long as you use the size of the `playerTokens` vector to help you determine the total number of players in the game.

- Your `getCurrentPlayerToken()` method should simply return the character that represents the `currentPlayerId` from within the private `playerTokens` vector

- Your `takeTurn()` method is responsible for communicating who's turn it is, and for collecting input from the current player
  * It should prompt the current player for a column number, and then process their turn.
  * It should test to ensure that the number received is a valid column number from 1 to 7, otherwise return `false`.
  * It should test that column chosen has space for a token to be "dropped in from the top" of the column, otherwise return `false`
  * If the column has space for a token, it should place the current player's token in the column at its "lowest" empty space on the screen (like the game)
  * It should NOT advance to the next player ( the `play()` method will do that by calling `nextPlayer()` at the right time).
  * It should return `true` after placing the current player's token on the game board, (and `false` otherwise, per above).

- Your `isWin()` method will check ONLY if the CURRENT player has won the game
  * It should set the integer value for the `winningPlayerId` if the current player has won the game (otherwise it should not change the winningPlayerId)
  * It should return `true` if the current state of the board represents a win for the current player, otherwise `false`

- Your `isTie()` method should determine if the game cannot be won by either player regardless of the number of moves.  
  * If there are no moves left on the board (no empty spaces), then return `true` (a tie), else `false`  

- Your game must support 3 or more players, which should be easy to achieve if you have followed the above directions.  Test your code by simply calling your constructor from `main()` using more than 2 player tokens

- Your `getWinningPlayerId()` method must return the ID of the value of the winningPlayerId data member of the class (NOT the TOKEN of the winning player).  Recall that your winningPlayerId member must be set by the isWin() method.


# Hints
- To simplify your code, you may want to call the `getCurrentPlayerToken()` method from within your own methods, when needed, rather than using `playerToken[ currentPlayerId ]`;
- You may want to use the private data members `numRows` and `numCols` ( which have been set to initial values of 6 rows and 7 columns), throughout your code logic, any time you want to know the maximum length of a row or column on the game board.  This may be particularly useful in your `isTie()` and `isWin()` methods.
- Use the comments in the `ConnectFour.h` file to help you understand the purpose of individual private data members
- Consider that a tie occurs when the game board is full and there is no win.
- Consider also that a win can occur (and thus the game cannot be tied) any time 4 or more of the same token (or the empty space) exist consecutively on a row, column, or diagonal.  

# Scoring
- 90 Points: Automated testing will be responsible for most of your grade (see testing below)
- 10 Points:  User-Feedback clarity and "neatness" of presentation.  Simply consider whether an uninitiated student who does not know how to play the game would be able to play your game (and enjoy it).
- `Minus 2 points: if you use the "using namespace std" statement in any of your .cpp files`
- `Minus 2 points: if you fail to use a constructor initializer list in your ConnectFour.cpp file`


# Testing (optional - but highly useful)
A `testMe.cpp` file and a `testMe.h` file, along with a testMe() function have been provided.  You will also need the `testMeIn.txt` file that controls input to the game during testing.  When you are ready to assess your grade on this project, you should uncomment the `testMe()`  method in `main.cpp` and observe your preliminary score. Note that the test will create (overwrite) a verbose output file called `testMeOut.txt` if you want more detail on why a particular test may have failed.   All scores are subject to final review by the instructor. And of course you are not allow to rewrite `testMe()` to your advantage.  :) 

# Submission
- You must submit a replit link with all necessary files (including README and testMe.cpp testMe.h files).  I will rerun your test when I receive your file. Please leave testMe() uncommented at the top of men when you submit to save me some time (I will not mark off if you do not, but it could literally save me hours of time over the course of grading all submissions - thank you! )

# Bonus Points
- 5 Points  `isTie()` BONUS: If there are still empty spaces on the game board, but you can detect that the game is ultimately going to be a tie because no one can win , return true. Otherwise, if there are any moves left on the board that could produce a potential win, return false.  Points will be granted based on your ability to pass automated tests for multiple versions of these type of "is a tie" cases

- 10 Points  Implement a `takeTurnAI()` method so that the last player in the game is controlled by the computer.  Implement an ai solution through any means you like. Random choices will only receive modest point values (but you will get some credit as long as your random choices do not try to fill empty spaces).  Modify the `play()` method as necessary to incorporate your `takeTurnAI()` method when it is the last player's turn.  Note: Your AI only needs to work for the 2-player case (you do not need to make an AI that can play against more than 1 player) - assume that only 2 players exist, but use the playerTokens array to verify that fact and you may print a warning if more than 2 players are in the game (or abort)..

# Concepts Covered in this Homework

- Vectors of Vectors (of characters)
  * declaration, initialization, access
- classes
  * general design of usable classes 
  * public and private members
  * constructors
  * function (method) overloading
  * out-of-class methods
- iostream input using cin
- vector container - initialization
- loops
 
---
#### Copyright © 2022 by Jeff Yates

All rights reserved. No part of this publication may be reproduced, distributed, or transmitted in any form or by any means, including photocopying, recording, or other electronic or mechanical methods, without the prior written permission of the publisher, except in the case of brief quotations embodied in critical reviews and certain other noncommercial uses permitted by copyright law.