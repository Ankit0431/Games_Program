#include <iostream>
#include "Tic-Tac-Toe/TicTacToe.h"
#include "Sudoku/Sudoku.h"
int main()
{
    int game, mode;
    while (true)
    {
        bool playagain = true;
        printf("\nSelect Game: \n1: Tic-Tac-Toe\n2: Sudoku\n3: Hangman\n4: Exit\n");
        cin >> game;
        switch (game)
        {
        case 1:
            playagain = true;
            printf("\nSelect Mode: \n1: One Player \n2: Two Player \n");
            cin >> mode;
            if (mode == 1)
            {
                while (playagain)
                {
                    SinglePlayerTicTacToe t1;
                    bool difficulty;
                    int choice;
                wrongip:
                    printf("\nSelect Mode: \n1: Easy\n2: Hard\n");
                    scanf("%d", &choice);
                    switch (choice)
                    {
                    case 1:
                        printf("\nEASY MODE!");
                        difficulty = true;
                        break;
                    case 2:
                        printf("\nHARD MODE!");
                        difficulty = false;
                        break;
                    default:
                        printf("\nChoose right mate\n");
                        goto wrongip;
                    }
                    t1.play(difficulty);
                    printf("\nOne more?\n1: Bring it ON!\n2: Hell nah\n");
                    scanf("%d", &choice);
                    if (choice != 1)
                    {
                        printf("\nAlright then, have a good one!\n");
                        playagain = false;
                    }
                    else
                        printf("\nYeah thats what i am talking about, BRING IT ON!\n");
                }
            }
            else
            {
                int choice = 0;
                while (playagain)
                {
                    TwoPlayerTicTacToe t1;
                    printf("\t\t\t\t\t\tFOR 2 PLAYERS\n");
                    t1.play();
                    printf("\nOne more?\n1: Bring it ON!\n2: Hell nah\n");
                    scanf("%d", &choice);
                    if (choice != 1)
                    {
                        printf("\nAlright then, have a good one!\n");
                        playagain = false;
                    }
                    else
                        printf("\nYeah thats what i am talking about, BRING IT ON!\n");
                }
            }
            break;

        case 2:
            printf("\nSelect Mode: \n1: Challenge \n2: Solution \n");
            cin >> mode;
            if (mode == 1)
            {
                printf("\n\t\tMODE UNDER DEVELOPMENT, SORRY FOR THE INCONVIENCE\n");
            }
            else
            {
                // Ankit ne hi likh diya code matrix input ka
                printf("\t\t\tSolve 9x9 sudoku!\n");
                SudokuSolver s1;
                s1.inputSudoku();
                s1.solve(0, 0);
            }
        case 3: // case for hangman
        case 4:
            printf("\nThank you so much for playing! I hope you enjoyed, see you again soon! GGs only!\n");
            exit(0);
        default:
            printf("\nEnter a valid option mate\n");
        }
    }
}
