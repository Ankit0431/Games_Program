#include <iostream>
#include "Tic-Tac-Toe/TicTacToe.h"
#include "Sudoku/SudokuSolver.h"
int main()
{
    int game, mode;
    printf("\nSelect Game: \n1: Tic-Tac-Toe\n2: Sudoku\n");
    cin >> game;
    switch (game)
    {
    case 1:
        printf("\nSelect Mode: \n1: One Player \n2: Two Player \n");
        cin >> mode;
        if (mode == 1)
        {
            SinglePlayerTicTacToe t1;
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
            TwoPlayerTicTacToe t1;
            printf("\t\t\t\t\t\tFOR 2 PLAYERS\n");
            t1.play();
        }
        printf("\n\n\t\tThanks for playing!\n");
        break;
    
    case 2:
        printf("\nSelect Mode: \n1: Challenge \n2: Solution \n");
        cin >> mode;
        if (mode == 1){
            printf("\n\t\tMODE UNDER DEVELOPMENT, SORRY FOR THE INCONVIENCE\n");
        }
        else{
            SudokuSolver s1;
            //sudoku enter karne ka logic Akshata Likhegi yayy
            s1.solve(0,0);
        }
    }
        
}
