#pragma once

#ifndef HUMAN_PLAYER
#define HUMAN_PLAYER

#include<iostream>
#include<vector>
#include "Player.h"
using namespace std;



class HumanPlayer : public Player
{
public:



    // utility function to place a given ship on the primary grid
    void util(vector<vector<string>> info , int i_ ,  int len , char c);

    // function to arrange ships (A - E) on primary grid of human player
    void arrangeShips(string csv_filename);

    // utility function to print primary grid
    void printPrimaryGrid();

    // utility function to print tracking grid
    void printTrackingGrid();

//-------------------------------------------------------------------------------------------------------
    //function to fire a torpedo
    pair<int , int>  playerGuess();

    // function to check if the torpedo fired by computer player is a hit or miss on human player's primary grid
    bool checkComputerGuess(pair<int , int> computerGuessCoordinates);

    // function to update human player's tracking grid after human player has fired a torpedo on computer player's primary grid
    void updateTrackingGrid(pair<int, int> playerGuessCordinates , bool hasHitComputerShip);


};





//..........................................




#endif