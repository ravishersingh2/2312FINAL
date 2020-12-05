#pragma once

#include<iostream>
#include<vector>
using namespace std;


class Player
{
public:
    char primaryGrid[15][15];
    char trackingGrid[15][15];
    int vis[15][15]; // this tells if the given coordinates had already been guessed
    int cnt[6] = {0} ; // this tells how many times a particular ship had been hit


    // funtions to initilaize the grid to some value ( '.'' in our case , '.'' will denote absence of ship)
    void initGrid(char grid[15][15])
    {
        for (int i = 1 ; i <= 10 ; i++)
        {
            for (int j = 1; j <= 10 ; j++)
            {
                grid[i][j] = '.';
            }
        }
    }

    // this function checks if all ships have been destroyed
    bool isEmpty()
    {
        for (int i = 1 ; i <= 10 ; i++)
        {
            for (int j = 1 ; j <= 10 ; j++)
            {
                if (primaryGrid[i][j] != '.')return false;
            }
        }

        return true;
    }

};