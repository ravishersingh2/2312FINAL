*If You reading this do not copy my work, you will get caught badly*
*******************************************************
* Name      : Ravisher Singh
* Student ID: 101844874
* Class     :  CSC 2321
* HW#       :  FINAL 2312
* Due Date  :  December 4, 2020
*******************************************************
Read Me

********************************************************

Description of the program

*******************************************************

Purpose of this assignment:
In this program, we have created a battleship game where a human player plays against
computer player. Human player and the computer both have 5 ships, each of different
length, a ship of length 5 for example will take up 5 squares in the player's grid.
Each player has a 10x10 grid hidden from their opponent where they place their ships.
Once ships are places players take turn tp fire a missle at opponents grid.If there is
a ship in that location it is counted as Hit, otherwise a Miss.Players keep taking
turns until entire fleet of other player's ships is sunk. Human player's ship placement is
read from a csv file while ships for computer player are randomly placed.The human player
has a function that reads in input from the file performs exception handling to in order
to only take valid inputs and not process bad inputs.I have tried my best for Error checking
throughout the the program to make sure that human player cannot enter negative values, attack
out of bounds, or enter garbage values. The Computer's ships are placed randomly and its attacks
are random, I placed checks for computer player so that it cannot attack on same spot on grid.

********************************************************
Class Based Program: Checked
Inheritance : Checked
Error Bound: Checked
Validation of data: Checked
Modularity: Checked
Exception Handling: Not created specific functions for it but indirectly logic was added in various functions
..............................................................

Extra Credit: First part completed working on Second
********************************************************
 Source files
*******************************************************
Name: main.cpp

This is driver program and only has function call to play game.

..................................................................



..................................................................
Name: Player.h

This is a base class for computer and human player.
Defination of player class


..................................................................

Name: HumanPlayer.h
Defination of Humanplayer class which inherits from Player class.

..................................................................

Name: HumanPlayer.cpp
Read in the ship from csv file, place the ships, making sure they dont
overlap, attacking on computer player grid with only number values 1-10
and col values A-J.Also a function to check number of hits human player
received.

..................................................................

Name: ComputerPlayer.h
Defination of ComputerPlayer class whicj inherits from Player class

........  ..........................................................

Name: ComputerPlayer.cpp
Randomly placing the ships, randomly generating shots, Also a function to
check number of hits human player received.

..................................................................

Name: Game.h
Defination for game play function.Implementation of game play function.Create
objects of human player and computer player , and game runs until one player
has score of 17.Once a player wins both the computer player and human player
fleet and grid is shown.


..................................................................






********************************************************
 Circumstances of programs
*******************************************************
The program runs successfully.The program was developed and tested on gnu g++ 4.4.2.  It was compiled, run,
and tested on gcc ouray.cudenver.edu.
********************************************************
How to build and run the program
*******************************************************
1.Uncompress the homework.  The homework file is compressed.To uncompress it use the following commands% unzip  F2312
Now you should see a directory named homework with the files:
main.cpp
Player.h
HumanPlayer.cpp
ComputerPlayer.cpp
Game.h



ReadMe.txt
2.  Build the program.
Change to the directory that contains the file by:% cd [F2312]
Compile the program by:% make
3.  Run the program by:% ./F2312
