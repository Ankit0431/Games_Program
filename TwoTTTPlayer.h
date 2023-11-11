#define PLAYER1 'X'
#define PLAYER2 'O'
class TwoTTTPlayer : public TicTacToe
{
    // player1: 'X' player2: 'O'
public:
    char player1 = PLAYER1;
    char player2 = PLAYER2;
    // play function for 2 player game
    void play()
    {
        int choice;
        printf("\t\t\tThe Game Begins!");
        showInstructions();
        while (true)
        {
        mistake:
            printf("\tYour Move\n");
            printf("\tEnter Your Choice (Player 1): ");
            scanf("%d", &choice);
            if (board->getArrayElement(choice) != ' ')
            {
                printf("\nThis box has already been taken, please select a different box\n");
                goto mistake;
            }
            else
            {
                board->updateArray(player1, choice);
                printf("\nBoard after move\n");
                showboard();
                if (hasAnyoneWon() != 0)
                {
                    switch (hasAnyoneWon())
                    {
                    case 1:
                        printf("\t\t\tPlayer 2 Wins!\n");
                        break;
                    case -1:
                        printf("\t\t\tPlayer 1 Wins!\n");
                        break;
                    }
                    break;
                }
                if (!isMovesLeft())
                {
                    break;
                }
            mistake2:
                printf("\tEnter Your choice (Player 2): ");
                scanf("%d", &choice);
                if (board->getArrayElement(choice) != ' ')
                {
                    printf("\nThis box has already been taken, please select a different box\n");
                    goto mistake2;
                }
                board->updateArray(player2, choice);
                printf("\nBoard after move\n");
                showboard();
                if (hasAnyoneWon() != 0)
                {
                    switch (hasAnyoneWon())
                    {
                    case 1:
                        printf("\t\t\tPlayer 2 Wins!\n");
                        break;
                    case -1:
                        printf("\t\t\tPlayer 1 Wins!\n");
                        break;
                    }
                    break;
                }
                if (!isMovesLeft())
                {
                    break;
                }
            }
        }
        if (hasAnyoneWon() == 0)
        {
            printf("\n\t\tIts a Tie!\n");
        }
    }
};