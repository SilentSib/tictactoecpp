#include <iostream>
#include <limits>
#include "player.h"

using namespace std;

bool isInputValid();

main()
{
  char grid[9], example[9];
  char initValue = '1', continueGame;
  bool playerO = false, playerX = true, playerOwins, playerXwins, gameOver = false;
  int cell;
  string name;
  Player player1, player2;
  cout << "Enter your name: "; cin >> name; cout << endl;
  player1.setPlayerName(name);
  cout << "Here player 1's name: " << player1.getPlayerName() << endl;
  /*while((playerO || playerX) && gameOver == false) // As long as player0 or playerX are playing and that the variable gameOver hasn't been set to 1
  {
    playerXwins = (
    (grid[0] == 'X' && grid[1] == 'X' && grid[2] == 'X') ||
    (grid[3] == 'X' && grid[4] == 'X' && grid[5] == 'X') ||
    (grid[6] == 'X' && grid[7] == 'X' && grid[8] == 'X') ||
    (grid[0] == 'X' && grid[3] == 'X' && grid[6] == 'X') ||
    (grid[1] == 'X' && grid[4] == 'X' && grid[7] == 'X') ||
    (grid[2] == 'X' && grid[5] == 'X' && grid[8] == 'X') ||
    (grid[0] == 'X' && grid[4] == 'X' && grid[8] == 'X') ||
    (grid[2] == 'X' && grid[4] == 'X' && grid[6] == 'X')); // We declare all possible outcomes that define playerX winning

    playerOwins = (
    (grid[0] == 'O' && grid[1] == 'O' && grid[2] == 'O') ||
    (grid[3] == 'O' && grid[4] == 'O' && grid[5] == 'O') ||
    (grid[6] == 'O' && grid[7] == 'O' && grid[8] == 'O') ||
    (grid[0] == 'O' && grid[3] == 'O' && grid[6] == 'O') ||
    (grid[1] == 'O' && grid[4] == 'O' && grid[7] == 'O') ||
    (grid[2] == 'O' && grid[5] == 'O' && grid[8] == 'O') ||
    (grid[0] == 'O' && grid[4] == 'O' && grid[8] == 'O') ||
    (grid[2] == 'O' && grid[4] == 'O' && grid[6] == 'O')); // We declare all possible outcomes that define playerO winning

    cout << "Welcome to the game of Tic Tac Toe by SilentSib!" << endl << endl;
    cout << " ------------- " << endl;
    for(int i=0;i<9;i++)
    {
      cout.width(2);
      example[i] = initValue++;
      cout << " | " << example[i];
      if(i==2) cout << " |" << endl << " ------------- " << endl;
      if(i==5) cout << " |" << endl << " ------------- " << endl;
      if(i==8) cout << " |";
    }
    cout << endl << " ------------- " << endl << endl; // We show the grid with numbers from 1-9 to tell the player how to play
    initValue = '1'; // We reinitialize initValue to 1 so that at every round, the same grid is displayed
    if(playerXwins) { playerX = true; playerO = false; } // If playerX has won, we make sure that the last player displayed is playerX
    else if(playerOwins) { playerO = true; playerX = false; } // If playerO has won, we make sure that the last player displayed is playerO
    if(playerX) cout << "Player 1 (X): " << endl << endl;
    else if(playerO) cout << "Player 2 (O): " << endl << endl;
    cout << " ------------- " << endl;
    for(int i=0;i<9;i++)
    {
      cout.width(2);
      if(grid[i] != 'X' && grid[i] != 'O') cout << " | " << " ";
      else cout << " | " << grid[i];
      if(i==2) cout << " |" << endl << " ------------- " << endl;
      if(i==5) cout << " |" << endl << " ------------- " << endl;
      if(i==8) cout << " |";
    }
    cout << endl << " ------------- " << endl << endl; // The grid is refreshed at every new turn
    if(playerXwins) { cout << "Player 1 has won!" << endl << endl; gameOver = true; } // gameOver is declared upon playerX winning
    else if(playerOwins) { cout << "Player 2 has won!" << endl << endl; gameOver = true; } // gameOver is declared upon playerO winning

    for(int i=0;i<9 && (grid[i] == 'X' || grid[i] == 'O');i++)
    {
      if(i==8 && !(playerXwins || playerOwins))
      {
        gameOver = true;
        cout << "This is a draw." << endl << endl;
      }
    } // Definition of what constitutes a draw
    if(gameOver == false) // We continue the game as long as gameOver hasn't been declared
    {
      cout << "Please choose the cell value (1-9) where you want to play: ";
      do
      {
        cin >> cell;
        if(cell < 1 || cell > 9 || grid[cell-1] == 'X' || grid[cell-1] == 'O') cout << endl << "Impossible to play here. Please try again: ";
        else break;
      } while(!isInputValid() || cell < 1 || cell > 9 || grid[cell-1] == 'X' || grid[cell-1] == 'O');
      if(playerX)
      {
        grid[cell-1] = 'X';
        playerX = false;
        playerO = true;
        system("clear");
      }
      else if(playerO)
      {
        grid[cell-1] = 'O';
        playerO = false;
        playerX = true;
        system("clear");
      }
    }
    else // This code is run if gameOver is true
    {
      cout << "Do you want to play a new game? (y/n) ";
      do
      {
        cin >> continueGame;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(continueGame != 'y' && continueGame != 'Y' && continueGame != 'n' && continueGame != 'N') cout << endl << "Incorrect choice. Please try again: ";
        else break;
      } while(continueGame != 'y' && continueGame != 'Y' && continueGame != 'n' && continueGame && 'N');
      if(continueGame == 'y' || continueGame == 'Y')
      {
        gameOver=false;
        for(int i=0;i<9;i++)
        {
          grid[i] = '\0';
          playerXwins = false;
          playerOwins = false;
          playerX = true;
          playerO = false;
          system("clear");
        } // Player wants to continue playing, so we reset all values used in the game to start over
      }
      else if(continueGame == 'n' || continueGame == 'N')
      {
        cout << endl << "Thank you for playing this game!";
        return 0;
      }
    }
  }
}

bool isInputValid()
{
  if(cin.rdstate())
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
  }
  return true;*/
}
