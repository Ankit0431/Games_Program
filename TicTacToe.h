#ifndef TWODARRAY_H
#define TWODARRAY_H
    #include "TwoDArray.h"
#endif // TWODARRAY_H
#define COMPUTERMOVE 'X'
#define HUMANMOVE 'O'

class TicTacToe
{
protected:
    TwoDArray *board;

public:
    TicTacToe()
    {
        board = new TwoDArray(3);
    }
    void static showInstructions()
    {
        printf("\t\t\t Tic-Tac-Toe\n\n");
        printf("Choose a cell numbered from 1 to 9 as below and play\n\n");
        printf("\t\t\t 1 | 2 | 3 \n");
        printf("\t\t\t-----------\n");
        printf("\t\t\t 4 | 5 | 6 \n");
        printf("\t\t\t-----------\n");
        printf("\t\t\t 7 | 8 | 9 \n\n");
        printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
    }
    void showboard()
    {
        board->showArray();
    }
    // This functions returns true if there are still moves left to play, false otherwise
    bool isMovesLeft()
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board->arr[i][j] == ' ')
                    return true;
        return false;
    }

    // this functions returns 1 if computer has won, -1 if human has won and 0 is there is no result
    int hasAnyoneWon()
    {
        char computer = COMPUTERMOVE;
        char human = HUMANMOVE;
        for (int i = 0; i < board->n; i++)
        {
            if (board->arr[i][0] == board->arr[i][1] && board->arr[i][1] == board->arr[i][2] && board->arr[i][0] != ' ')
            {
                if (board->arr[i][0] == computer)
                    return 1;
                else
                    return -1;
            }
        }
        for (int i = 0; i < board->n; i++)
        {
            if (board->arr[0][i] == board->arr[1][i] && board->arr[1][i] == board->arr[2][i] && board->arr[0][i] != ' ')
            {
                if (board->arr[0][i] == computer)
                    return 1;
                else
                    return -1;
            }
        }
        if (board->arr[0][0] == board->arr[1][1] && board->arr[1][1] == board->arr[2][2] && board->arr[0][0] != ' ')
        {
            if (board->arr[1][1] == computer)
                return 1;
            else
                return -1;
        }

        if (board->arr[0][2] == board->arr[1][1] && board->arr[1][1] == board->arr[2][0] && board->arr[0][2] != ' ')
        {
            if (board->arr[1][1] == computer)
                return 1;
            else
                return -1;
        }
        return 0;
    }
    // This is the play function, this executes the game of tic tac toe
};
#include "SingleTTTPlayer.h"
#include "TwoTTTPlayer.h"