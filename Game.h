/*
 * Ravisher Singh
 * CSCI 2312 Final Project
 * 101844874
 *
 */


/*A single final report that includes (use template on Canvas):o
 * Summary of provided functions. This should be matched with the requirements. Provided in read me and in the .h and .cppp files whereever neccessary
 * Design that shows the overall program structures, and the explanation of key algorithms.
 * A description of user interface scheme is required to explain the menu items at top level and items in sub menus and how to navigate through menus. :Done
 * A detailed instruction and sample skeleton is available from the Design Document in Files on Canvas. UML Diagram in design document
 * Accurate status of the program, what's done, and what's not completely implemented. Done, extra credit part 2 did not work
 * Accurate status of testing on the csegrid. Done
 * The final report should be in MS Word, or PDF format. :Done */


#include<iostream>

#include "HumanPlayer.h"
#include "ComputerPlayer.h"

using namespace std;


void delay(clock_t a)
{
    clock_t start;
    start  = clock();
    while (clock() - start < a)
    {

    }
}


class Game
{
public:
    void simulateGame()
    {

        string battleship ="┏━━┓━━━━━━━┏┓━━┏┓━┏┓━━━━━━━━━┏┓━━━━━━━━\n┃┏┓┃━━━━━━┏┛┗┓┏┛┗┓┃┃━━━━━━━━━┃┃━━━━━━━━\n┃┗┛┗┓┏━━┓━┗┓┏┛┗┓┏┛┃┃━┏━━┓┏━━┓┃┗━┓┏┓┏━━┓\n┃┏━┓┃┗━┓┃━━┃┃━━┃┃━┃┃━┃┏┓┃┃━━┫┃┏┓┃┣┫┃┏┓┃\n┃┗━┛┃┃┗┛┗┓━┃┗┓━┃┗┓┃┗┓┃┃━┫┣━━┃┃┃┃┃┃┃┃┗┛┃\n┗━━━┛┗━━━┛━┗━┛━┗━┛┗━┛┗━━┛┗━━┛┗┛┗┛┗┛┃┏━┛\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃┃━━\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┗┛━━\n";
        cout << "\t\t\t\t" << endl;
             cout <<battleship << endl;

        cout << "Welcome to Battleship: Advanced Tactics & Logistic Events Simulator Human Interface Program\n ";
        cout << "Commander ! We have a developing situation, at 0900 our" << endl
             <<	"patrol boat detected, an enemy presence soon after our RADAR system" << endl
             << "went dark. Our communication net is also being jammed so you will" << endl
             << "only have limited orders available. The President has given us" << endl
             << "clearance for a full scale attack. The fleet at your disposal" << endl
             << "consists of:" << endl
             << "- A Aircraft Size-5 Carrier" << endl
             << "- Reagan Size-4  Battleship" << endl
             << "- Ticonderoga Size-3  Cruiser" << endl
             << "- Collins Size-3  Submarine" << endl
             << "- Abbot Size-2  Destroyer" << endl << endl;

        delay(2000);

        cout << "Enter the .csv file name for human player's ship placement \n\n" ;


        string csv_fileName ;
        cin >> csv_fileName;

        HumanPlayer p;
        p.arrangeShips(csv_fileName); // human player arranges his ships
        cout << "Player's Board : \n\n";
        p.printPrimaryGrid();

        cout << '\n';

        ComputerPlayer c;
        c.successfulPlacement(); // computer player arranges his ships
        /*
         *
         * Testing
         */
         //cout << "Computer's Board : \n\n";
         //c.printPrimaryGrid(); // uncomment this to see computer player's primary grid



        cout << "\n\n\n";


        /*
         * Playing the game continues till one of the players have lost all ships
         *
         */

        while (!p.isEmpty() && !c.isEmpty())
        {
            pair<int, int> playerGuessCordinates = p.playerGuess(); // human player fires a torpedo

            if (playerGuessCordinates.first == -1 && playerGuessCordinates.second == -1)
            {
                p.printTrackingGrid();
                cout << '\n';

                cout << "Computer Player's Primary Grid \n\n";
                c.printPrimaryGrid();
              /* only valid input */
                cout << "Enter any letter and hit Enter key to exit\n";
                char in ;
                cin >> in;
                  /*
                   * otherwise exit
                   */
                exit(0);

            }
               /*
                * Check whether player correctly fired shot at computers grid
                *
                 */
            bool hasHitComputerShip = c.checkPlayerGuess(playerGuessCordinates); // computer player checks if the torpedo fired by human player is a hit or miss
            p.updateTrackingGrid(playerGuessCordinates , hasHitComputerShip); // human player updates his tracking grid ( based on computer player's response - whether fired torpedo was a hit or miss)
            p.printTrackingGrid();

            delay(3000);

            pair<int, int> computerGuessCoordinates = c.computerGuess(); // computer player fires a torpedo
            cout << "Computer player Guessed x y coordinates :\n";
            char X = computerGuessCoordinates.first + 'A' - 1 ;
            int Y = computerGuessCoordinates.second ;
            cout << X <<  " " << Y << '\n';
            /*
             * human player checks if the torpedo fired by computer player is a hit or miss
             * */
            bool hasHitPlayerShip = p.checkComputerGuess(computerGuessCoordinates);
            /*
             * computer player updates his tracking grid ( based on human player's  response - whether fired torpedo was a hit or miss)
             * */
            c.updateTrackingGrid(computerGuessCoordinates , hasHitPlayerShip);

            c.printTrackingGrid();

        }


        // check who lost all ships and print the winner on screen
        if (p.isEmpty())
        {
            cout << "Computer has destroyed player's ships ....Computer Won ! :) \n";
        }
        else if (c.isEmpty())
        {
            cout << "Player has destroyed computer's ships .......Player Won ! :) \n";
        }



    }

};