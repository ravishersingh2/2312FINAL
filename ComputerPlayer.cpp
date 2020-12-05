
/*
 * Ravisher Singh
 * CSCI 2312 Final Project
 * 101844874
 *
 */


#include <iostream>
#include <vector>
using namespace std;
#include "ComputerPlayer.h"


// a random generator function to randomly generate values
int ComputerPlayer::randomGen(int lower, int upper)
{
    srand(time(0) + rand());
    int num = rand() % (upper - lower + 1) + lower;

    return num;
}


// utility function to place a given ship on the primary grid
void ComputerPlayer::util(int i_ ,  int len , char c)
{
    int x = info[i_][1][0] - 'A' + 1;
    int y = info[i_][1][1] - '1' + 1;


    if (info[i_][2] == "H")
    {

        for (int j = x ; j < x + len ; j++)
        {
            if (j < 1 || j > 10 || y < 1 || y > 10 || primaryGrid[y][j] != '.')
            {
                return;
            }
            primaryGrid[y][j] = c;
        }

    }
    else if (info[i_][2] == "V")
    {

        for (int i = y ; i < y + len ; i++)
        {
            if (x < 1 || x > 10 || i < 1 || i > 10 || primaryGrid[i][y] != '.')
            {
                return;
            }
            primaryGrid[i][y] = c;
        }
    }

    placedShipCnt++;

}

// utility function to randomly generate x ,y coordinates and orientation(H/V) of ship for computer player
void ComputerPlayer::initInfo(string s)
{
    char c = 'A' + randomGen(0 , 9);
    char d = '1' + randomGen(0, 9);
    int h_v = randomGen(1, 2);
    char e = (h_v == 1 ) ?  'H' : 'V';

    string temp1 = "";
    temp1 += c;
    temp1 += d;

    string temp2 = "";
    temp2 += e;

    info.push_back({s , temp1, temp2 });

}


// function to arrange ships (A - E) on primary grid of computer player
void ComputerPlayer::arrangeShips()
{
    initGrid(primaryGrid);
    initGrid(trackingGrid);
    for(int i =0 ; i< 15 ; i++)
    {
        for(int j =0 ; j<15 ; j++)vis[i][j] = 0;
    }
    placedShipCnt = 0;
    info.clear();


    initInfo("Carrier");
    initInfo("Battleship");
    initInfo("Cruiser");
    initInfo("Submarine");
    initInfo("Destroyer");



    for (int i = 0 ; i < info.size() ; i++)
    {
        if (info[i][0] == "Carrier")
        {
            util(i , 5 , 'A');
        }
        else if (info[i][0] == "Battleship")
        {
            util(i, 4 , 'B');
        }
        else if (info[i][0] == "Cruiser")
        {
            util(i, 3, 'C');
        }
        else if (info[i][0] == "Submarine")
        {
            util(i, 3 , 'D');
        }
        else if (info[i][0] == "Destroyer")
        {
            util(i, 2 , 'E');
        }
    }


}


// this function ensures that ships (A-E) have been successfully placed on computer player's primary grid
void ComputerPlayer::successfulPlacement()
{
    while (placedShipCnt != 5)
    {
        arrangeShips();
    }

}



// utility function to print primary grid
void ComputerPlayer::printPrimaryGrid()
{
    cout << "    ";
    for (int i = 0 ; i < 10 ; i++)
    {
        cout << char('A' + i) << " ";
    }
    cout << '\n';
    for (int i = 1; i <= 10 ; i++)
    {
        if (i < 10)
            cout << i << "   ";
        else
            cout << i << "  ";

        for (int j = 1; j <= 10 ; j++)
        {
            cout << primaryGrid[i][j] << " ";
        }
        cout << '\n';
    }
}


// utility function to print tracking grid
void ComputerPlayer::printTrackingGrid()
{
    cout << "Computer's Tracking Grid\n\n";

    cout << "    ";
    for (int i = 0 ; i < 10 ; i++)
    {
        cout << char('A' + i) << " ";
    }
    cout << '\n';
    for (int i = 1; i <= 10 ; i++)
    {
        if (i < 10)
            cout << i << "   ";
        else
            cout << i << "  ";

        for (int j = 1; j <= 10 ; j++)
        {
            cout << trackingGrid[i][j] << " ";
        }
        cout << '\n';
    }
}


//--------------------------------------------------------------------------------------------------------

// function to check if a particular ship is sunk or not
bool ComputerPlayer::checkIfShipIsSunk(char c)
{
    for (int i = 1 ; i <= 10 ; i++)
    {
        for (int j = 1 ; j <= 10 ; j++)
        {
            if (primaryGrid[i][j] == c)return false;
        }
    }

    return true;
}

// function to check if the torpedo fired by player is a hit or miss on compter player's primary grid
bool ComputerPlayer::checkPlayerGuess(pair<int , int> playerGuessCoordinates)
{
    int x = playerGuessCoordinates.first;
    int y = playerGuessCoordinates.second;

    if (primaryGrid[y][x] == '.')
    {
        cout << "Computer's Response : Oops ! That was a miss\n\n";
        return false;
    }

    cout << "Computer's Response : Whoa ! That was a hit\n\n";


    if (primaryGrid[y][x] == 'A')
    {
        cnt[1]++;
        if (cnt[1] == 5)cout << "Computer's Response : You sunk my Carrier \n\n";
    }
    else if (primaryGrid[y][x] == 'B')
    {
        cnt[2]++;
        if (cnt[2] == 4)cout << "Computer's Response : You sunk my Battleship \n\n";
    }
    else if (primaryGrid[y][x] == 'C')
    {
        cnt[3]++;
        if (cnt[3] == 3)cout << "Computer's Response : You sunk my Cruiser \n\n";
    }
    else if (primaryGrid[y][x] == 'D')
    {
        cnt[4]++;
        if (cnt[4] == 3)cout << "Computer's Response : You sunk my Submarine \n\n";
    }
    else if (primaryGrid[y][x] == 'E')
    {
        cnt[5]++;
        if (cnt[2] == 2)cout << "Computer's Response : You sunk my Destroyer \n\n";
    }




    primaryGrid[y][x] = '.';
    return true;
}

// function to update computer player's tracking grid after computer has fired a torpedo on human player's primary grid
void ComputerPlayer::updateTrackingGrid(pair<int, int> computerGuessCordinates , bool hasHitPlayerShip)
{

    int x = computerGuessCordinates.first;
    int y = computerGuessCordinates.second;

// O = Hit
// X = Miss
    if (hasHitPlayerShip) trackingGrid[y][x] = 'O';
    else trackingGrid[y][x] = 'X';

}


// function to fire a torpedo
pair<int, int> ComputerPlayer::computerGuess()
{
    int x = randomGen(1 , 10);
    int y = randomGen(1 , 10);

    if (!vis[y][x])
    {
        return {x , y};
    }
    else
    {
        return computerGuess();
    }

}

