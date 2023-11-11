#include <iostream>
#include "TicTacToe.h"
int main()
{
    int game;
    printf("\nSelect Game: \n1: One Player Game\n2: Two Player Game\n");
    scanf("%d", &game);
    if (game == 1)
    {
        SingleTTTPlayer t1;
        bool difficulty;
        int choice;
        printf("\nSelect Mode: \n1: Easy\n2: Hard\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("\nEASY MODE!");
            difficulty = true;
        }
        else
        {
            printf("\nHARD MODE!");
            difficulty = false;
        }
        t1.play(difficulty);
    }
    else
    {
        TwoTTTPlayer t;
        printf("\t\t\t\t\t\tFOR 2 PLAYERS\n");
        t.play();
    }
    printf("\n\n\t\tThanks for playing!\n");
}
