#pragma once

#ifndef COMPUTER_PLAYER
#define COMPUTER_PLAYER

#include<iostream>
#include<vector>
#include "Player.h"
using namespace std;




class ComputerPlayer : public Player
{

public:

    vector<vector<string>> info;
    int placedShipCnt;


    // a random generator function to randomly generate values
    int randomGen(int lower, int upper);

    // utility function to place a given ship on the primary grid
    void util(int i_ ,  int len , char c);

    // utility function to randomly generate x ,y coordinates and orientation(H/V) of ship for computer player
    void initInfo(string s);

    // function to arrange ships (A - E) on primary grid of computer player
    void arrangeShips();

    // this function ensures that ships (A-E) have been successfully placed on computer player's primary grid
    void successfulPlacement();

    // utility function to print primary grid
    void printPrimaryGrid();

    // utility function to print tracking grid
    void printTrackingGrid();

//--------------------------------------------------------------------------------------------------------

    // function to check if a particular ship is sunk or not
    bool checkIfShipIsSunk(char c);

    // function to check if the torpedo fired by player is a hit or miss on compter player's primary grid
    bool checkPlayerGuess(pair<int , int> playerGuessCoordinates);

    // function to update computer player's traking grid after computer has fired a torpedo on human player's primary grid
    void updateTrackingGrid(pair<int, int> computerGuessCordinates , bool hasHitPlayerShip);

    // function to fire a torpedo
    pair<int, int> computerGuess();


};

//----------------------------------


#endif