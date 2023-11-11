#define COMPUTERMOVE 'X'
#define HUMANMOVE 'O'

class SingleTTTPlayer : public TicTacToe
{
public:
    // This is the evaluation function, it evaluates each move and gives a high value(+10) if the Maximizer wins or a low value(-10) if the Minimizer wins. It gives a 0 if there is a tie
    int evaluate()
    {
        char player = COMPUTERMOVE;
        char opponent = HUMANMOVE;
        // Checking for Rows for X or O victory.
        for (int row = 0; row < 3; row++)
        {
            if (board->arr[row][0] == board->arr[row][1] &&
                board->arr[row][1] == board->arr[row][2])
            {
                if (board->arr[row][0] == player)
                    return +10;
                else if (board->arr[row][0] == opponent)
                    return -10;
            }
        }
        // Checking for Columns for X or O victory.
        for (int col = 0; col < 3; col++)
        {
            if (board->arr[0][col] == board->arr[1][col] &&
                board->arr[1][col] == board->arr[2][col])
            {
                if (board->arr[0][col] == player)
                    return +10;

                else if (board->arr[0][col] == opponent)
                    return -10;
            }
        }
        // Checking for Diagonals for X or O victory.
        if (board->arr[0][0] == board->arr[1][1] && board->arr[1][1] == board->arr[2][2])
        {
            if (board->arr[0][0] == player)
                return +10;
            else if (board->arr[0][0] == opponent)
                return -10;
        }
        if (board->arr[0][2] == board->arr[1][1] && board->arr[1][1] == board->arr[2][0])
        {
            if (board->arr[0][2] == player)
                return +10;
            else if (board->arr[0][2] == opponent)
                return -10;
        }
        // Else if none of them have won then return 0
        return 0;
    }
    // Minimax is a kind of backtracking algorithm that is used in decision making and game theory to find the optimal move for a player, assuming that your opponent also plays optimally. It is widely used in two player turn-based games such as Tic-Tac-Toe, Backgammon, Mancala, Chess, etc.
    // learn more https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-1-introduction/
    // This is the minimax function. It considers all the possible ways the game can go and returns the value of the board
    // In this function, we have considered Computer as the Maximizer and Human as the Minimizer!
    int minimax(int depth, bool isMax)
    {
        int score = evaluate();
        // If Maximizer has won the game return his/her evaluated score
        if (score == 10)
            return score;
        // If Minimizer has won the game return his/her evaluated score
        if (score == -10)
            return score;
        // If there are no more moves and no winner then it is a tie
        if (isMovesLeft() == false)
            return 0;

        // If this maximizer's move
        if (isMax)
        {
            int best = -1000;

            // Traverse all cells
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Check if cell is empty
                    if (board->arr[i][j] == ' ')
                    {
                        // Make the move
                        board->arr[i][j] = COMPUTERMOVE;
                        // Call minimax recursively and choose the maximum value
                        best = max(best, minimax(depth + 1, !isMax));
                        // Undo the move
                        board->arr[i][j] = ' ';
                    }
                }
            }
            return best;
        }

        // If this minimizer's move
        else
        {
            int best = 1000;

            // Traverse all cells
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Check if cell is empty
                    if (board->arr[i][j] == ' ')
                    {
                        // Make the move
                        board->arr[i][j] = HUMANMOVE;

                        // Call minimax recursively and choose the minimum value
                        best = min(best,
                                   minimax(depth + 1, !isMax));
                        // Undo the move
                        board->arr[i][j] = ' ';
                    }
                }
            }
            return best;
        }
    }
    // This functions preforms the best move for hard mode and worst move for east mode
    void performBestMove(bool difficulty)
    {
        int bestVal = -1000;
        int x = -1;
        int y = -1;

        // Traverse all cells, evaluate minimax function for all empty cells. And return the cell with optimal value.
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // Check if cell is empty
                if (board->arr[i][j] == ' ')
                {
                    // Make the move
                    board->arr[i][j] = COMPUTERMOVE;
                    // compute evaluation function for this move.
                    int moveVal = minimax(0, difficulty); // if difficultu = true, easy mode, else hard mode
                    // Undo the move
                    board->arr[i][j] = ' ';
                    // If the value of the current move is more than the best value, then update best
                    if (moveVal > bestVal)
                    {
                        x = i;
                        y = j;
                        bestVal = moveVal;
                    }
                }
            }
        }
        // performing the best move
        board->arr[x][y] = COMPUTERMOVE;
    }
    void play(bool difficulty)
    {
        int choice;
        char player = HUMANMOVE;
        printf("\t\t\tThe Game Begins!");
        showInstructions();
        while (true)
        {
        mistake:
            printf("\tYour Move\n");
            printf("\tEnter Your Choice: ");
            scanf("%d", &choice);
            if (board->getArrayElement(choice) != ' ')
            {
                printf("\nThis box has already been taken, please select a different box\n");
                goto mistake;
            }
            else
                board->updateArray(player, choice);
            printf("\nBoard after your move\n");
            showboard();
            if (hasAnyoneWon() != 0)
            {
                switch (hasAnyoneWon())
                {
                case 1:
                    printf("\t\t\tComputer Wins!\nBetter luck next time! GGs Only\n");
                    break;
                case -1:
                    printf("\t\t\tYou Win!!\nGood Game\n");
                    break;
                }
                break;
            }
            if (!isMovesLeft())
                break;
            printf("\nComputer's Move!");
            performBestMove(difficulty);
            printf("Board after Computer move:\n");
            showboard();
            if (hasAnyoneWon() != 0)
            {
                switch (hasAnyoneWon())
                {
                case 1:
                    printf("\t\t\tComputer Wins!\nBetter luck next time! GGs Only\n");
                    break;
                case -1:
                    printf("\t\t\tYou Win!!\nGood Game\n");
                    break;
                }
                break;
            }
            if (!isMovesLeft())
                break;
        }
        if (hasAnyoneWon() == 0)
        {
            printf("\n\t\tIts a Tie, Well played!\n");
        }
    }
};