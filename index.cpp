#include <iostream>
#define COMPUTERMOVE 'X';
#define HUMANMOVE 'O';
using namespace std;
class TwoDArray
{
public:
    char **arr; // dynamic 2d array pointer
    int size;   // size of the array(total size in memory; n*n)
    int n;      // dimetion of the array, only array of dimention nxn are allowed for tic-tac-toe
    TwoDArray(int n)
    { // constructor
        this->n = n;
        this->size = n * n;
        this->arr = new char *[n]; // declare a memory block of size n
        for (int i = 0; i < n; i++)
            arr[i] = new char[n]; // declare memory blocks on size n
        // initialising the array
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                arr[i][j] = ' ';
        }
    }
    void showArray()
    {
        printf(" \n \n ");
        printf(" \t \t \t % c | % c | % c \n ", arr[0][0], arr[0][1], arr[0][2]);
        printf(" \t \t \t -------------- \n ");
        printf(" \t \t \t % c | % c | % c \n ", arr[1][0], arr[1][1], arr[1][2]);
        printf(" \t \t \t -------------- \n ");
        printf(" \t \t \t % c | % c | % c \n \n ", arr[2][0], arr[2][1], arr[2][2]);
    }
    void updateArray(char elem, int m)
    {
        m -= 1;
        arr[m / this->n][m % this->n] = elem;
    }
    void updateArray(char elem, int m1, int m2)
    {
        arr[m1][m2] = elem;
    }
    char getArrayElement(int m)
    {
        m -= 1;
        return arr[m / this->n][m % this->n];
    }
};
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
//class for 2 player
class TwoPlayer: public TicTacToe
{
    public: char player1 = HUMANMOVE;
    public: char player2 = COMPUTERMOVE;
    void play(){
        int choice;
        printf("\t\t\tThe Game Begins!");
        showInstructions();
        while(true){
            mistake:
            printf("\tYour Move\n");
            printf("\tEnter Your Choice (Player 1): ");
            scanf("%d", &choice);
            if (board->getArrayElement(choice) != ' ')
            {
                printf("\nThis box has already been taken, please select a different box\n");
                goto mistake;
            }else{
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
                if(!isMovesLeft()){
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
                board->updateArray(player2,choice);
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
                if(!isMovesLeft()){
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
int main()
{
   TicTacToe t1;
    bool difficulty;
    int game;
    printf("\nSelect Game: \n1: One Player Game\n2: Two Player Game\n");
    scanf("%d",&game);
    if(game == 1){
        int choice;
        printf("\nSelect Mode: \n1: Easy\n2: Hard\n");
        scanf("%d", &choice);
        if (choice == 1){
            printf("\nEASY MODE!");
            difficulty = true;
        }
        else{
            printf("\nHARD MODE!");
            difficulty = false;
        }
    t1.play(difficulty);
    }else{
        TwoPlayer t;
        printf("\t\t\t\t\t\tFOR 2 PLAYERS\n");
        t.play(); 
    }
    printf("\n\n\t\tThanks for playing!\n");
}
