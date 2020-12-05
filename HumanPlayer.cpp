#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
#include "HumanPlayer.h"

// utility function to place a given ship on the primary grid

void HumanPlayer::util(vector<vector<string>> info , int i_ ,  int len , char c)
{
    int x = info[i_][1][0] - 'A' + 1;
    int y = info[i_][1][1] - '1' + 1;


    if (info[i_][2] == "H")
    {

        for (int j = x ; j < x + len ; j++)
        {
            if (j < 1 || j > 10 || y < 1 || y > 10 || primaryGrid[y][j] != '.')
            {
                cout << "Bad Input File\n\n";
                cout << i_ << '\n';

                cout << "enter any letter and hit Enter key to exit\n";
                char in ;
                cin >> in;

                exit(0);

            }
            primaryGrid[y][j] = c;
        }

    }
    else if (info[i_][2] == "V")
    {

        for (int i = y ; i < y + len ; i++)
        {
            if (x < 1 || x > 10 || i < 1 || i > 10 || primaryGrid[i][x] != '.')
            {
                cout << "Bad Input File\n";
                cout << i_ << '\n';

                cout << "enter any letter and hit Enter key to exit\n";
                char in ;
                cin >> in;

                exit(0);
            }
            primaryGrid[i][x] = c;
        }
    }

}

// function to arrange ships (A - E) on primary grid of human player
void HumanPlayer::arrangeShips(string csv_filename)
{
    initGrid(primaryGrid);
    initGrid(trackingGrid);

    for(int i =0 ; i<15 ; i++)
    {
        for(int j =0 ; j<15 ; j++)vis[i][j] = 0;
    }


    fstream fin;
    fin.open(csv_filename);

    if (!fin.is_open())
    {
        cout << "Error Opening File\n\n";
        cout << "enter any letter and hit Enter key to exit\n";
        char in ;
        cin >> in;

        exit(0);
    }

    vector<vector<string>> info;



    string shipName, coordinates , orientation;
    string line;

    int cnt = 0;
    while (getline(fin , line))
    {
        stringstream ss(line);
        getline(ss , shipName , ',');
        getline(ss , coordinates , ',');
        getline(ss , orientation , '\n');

        cnt++;

        info.push_back({shipName , coordinates , orientation});

    }


    fin.close();

    // if input csv file doesn't consist of all 5 ships , exit
    if (cnt != 5)
    {
        cout << "Bad Input File \n";
        cout << "enter any letter and hit Enter key to exit\n";
        char in ;
        cin >> in;

        exit(0);

    }



    for (int i = 0 ; i < info.size() ; i++)
    {
        if (info[i][0] == "Carrier")
        {
            util(info , i , 5 , 'A');
        }
        else if (info[i][0] == "Battleship")
        {
            util(info , i, 4 , 'B');
        }
        else if (info[i][0] == "Cruiser")
        {
            util(info , i, 3, 'C');
        }
        else if (info[i][0] == "Submarine")
        {
            util(info , i, 3 , 'D');
        }
        else if (info[i][0] == "Destroyer")
        {
            util(info , i, 2 , 'E');
        }
    }


}

// utility function to print primary grid
void HumanPlayer::printPrimaryGrid()
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
void HumanPlayer::printTrackingGrid()
{
    cout << "Human Player's Tracking Grid\n\n";

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


//-------------------------------------------------------------------------------------------------------

//function to fire a torpedo
pair<int , int> HumanPlayer::playerGuess()
{
    cout << "Player , guess x y coordinates\n";
    char ch ; cin >> ch;

    if (ch == 'Q')
    {
        cout << "Human Player has quit the game\n\n";

        return { -1, -1};
    }
    int x = ch - 'A' + 1;
    int y ; cin >> y;


    // check for valid input
    if ( ch < 'A'  || ch > 'J' || y < 1 || y > 10)
    {
        cout << "Please enter a vaild input  :( \n\n";
        return playerGuess();
    }


    if (vis[y][x]) { cout << "Try again  ... you have already entered this value \n" ; return playerGuess();}

    vis[y][x] = 1;
    return {x , y};
}

// function to check if the torpedo fired by computer player is a hit or miss on human player's primary grid
bool HumanPlayer::checkComputerGuess(pair<int , int> computerGuessCoordinates)
{
    int x = computerGuessCoordinates.first;
    int y = computerGuessCoordinates.second;

    if (primaryGrid[y][x] == '.')
    {
        cout << "Player's Response : Oops ! That was a miss\n\n";
        return false;
    }

    cout << "Player's Response : Whoa ! That was a hit\n\n";


    if (primaryGrid[y][x] == 'A')
    {
        cnt[1]++;
        if (cnt[1] == 5)cout << "Player's Response : You sunk my Carrier \n\n";
    }
    else if (primaryGrid[y][x] == 'B')
    {
        cnt[2]++;
        if (cnt[2] == 4)cout << "Player's Response : You sunk my Battleship \n\n";
    }
    else if (primaryGrid[y][x] == 'C')
    {
        cnt[3]++;
        if (cnt[3] == 3)cout << "Player's Response : You sunk my Cruiser \n\n";
    }
    else if (primaryGrid[y][x] == 'D')
    {
        cnt[4]++;
        if (cnt[4] == 3)cout << "Player's Response : You sunk my Submarine \n\n";
    }
    else if (primaryGrid[y][x] == 'E')
    {
        cnt[5]++;
        if (cnt[2] == 2)cout << "Player's Response : You sunk my Destroyer \n\n";
    }


    primaryGrid[y][x] = '.';
    return true;

}

// function to update human player's tracking grid after human player has fired a torpedo on computer player's primary grid
void HumanPlayer::updateTrackingGrid(pair<int, int> playerGuessCordinates , bool hasHitComputerShip)
{
    int x = playerGuessCordinates.first;
    int y = playerGuessCordinates.second;


    // O = Hit
    // X = Miss
    if (hasHitComputerShip)trackingGrid[y][x] = 'O';
    else trackingGrid[y][x] = 'X';
}




