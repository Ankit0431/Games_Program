
class Challenge : public Sudoku
{
public:
    char choice;

public:
    void userChoice()
    {
        printf("\n\t\tEnter any letter from A to E for a Sudoku Challenge: ");
        scanf("%d", &choice);
        if (choice == 'A' || choice == 'a')
        {
            board1();
        }
        else if (choice == 'B' || choice == 'b')
        {
            board2();
        }
        else if (choice == 'C' || choice == 'c')
        {
            board3();
        }
        else if (choice == 'D' || choice == 'd')
        {
            board4();
        }
        else
        {
            board5();
        }
        displaySudoku();
    }
    void board1()
    {
        sudoku->arr[0][0] = '5';
        sudoku->arr[0][1] = '3';
        sudoku->arr[0][4] = '7';

        sudoku->arr[1][0] = '6';
        sudoku->arr[1][3] = '1';
        sudoku->arr[1][4] = '9';
        sudoku->arr[1][5] = '5';

        sudoku->arr[2][1] = '9';
        sudoku->arr[2][2] = '8';
        sudoku->arr[2][7] = '6';

        sudoku->arr[3][0] = '8';
        sudoku->arr[3][4] = '6';
        sudoku->arr[3][8] = '3';

        sudoku->arr[4][0] = '4';
        sudoku->arr[4][3] = '8';
        sudoku->arr[4][5] = '3';
        sudoku->arr[4][8] = '1';

        sudoku->arr[5][0] = '7';
        sudoku->arr[5][4] = '2';
        sudoku->arr[5][8] = '6';

        sudoku->arr[6][1] = '6';
        sudoku->arr[6][6] = '2';
        sudoku->arr[6][7] = '8';

        sudoku->arr[7][3] = '4';
        sudoku->arr[7][4] = '1';
        sudoku->arr[7][5] = '9';
        sudoku->arr[7][8] = '5';

        sudoku->arr[8][4] = '8';
        sudoku->arr[8][7] = '7';
        sudoku->arr[8][8] = '9';
    }
    void board2()
    {
        sudoku->arr[0][0] = '3';
        sudoku->arr[0][3] = '8';
        sudoku->arr[0][5] = '1';
        sudoku->arr[0][8] = '2';

        sudoku->arr[1][0] = '2';
        sudoku->arr[1][2] = '1';
        sudoku->arr[1][4] = '3';
        sudoku->arr[1][6] = '6';
        sudoku->arr[1][8] = '4';

        sudoku->arr[2][3] = '2';
        sudoku->arr[2][5] = '4';

        sudoku->arr[3][0] = '8';
        sudoku->arr[3][2] = '9';
        sudoku->arr[3][6] = '1';
        sudoku->arr[3][8] = '6';

        sudoku->arr[4][1] = '6';
        sudoku->arr[4][7] = '5';

        sudoku->arr[5][0] = '7';
        sudoku->arr[5][2] = '2';
        sudoku->arr[5][6] = '4';
        sudoku->arr[5][8] = '9';

        sudoku->arr[6][3] = '5';
        sudoku->arr[6][5] = '9';

        sudoku->arr[7][0] = '9';
        sudoku->arr[7][2] = '4';
        sudoku->arr[7][4] = '8';
        sudoku->arr[7][6] = '7';
        sudoku->arr[7][8] = '5';

        sudoku->arr[8][0] = '6';
        sudoku->arr[8][3] = '1';
        sudoku->arr[8][5] = '7';
        sudoku->arr[8][8] = '3';
    }
    void board3()
    {
        sudoku->arr[0][0] = '7';
        sudoku->arr[0][1] = '3';
        sudoku->arr[0][4] = '8';

        sudoku->arr[1][0] = '5';
        sudoku->arr[1][3] = '4';
        sudoku->arr[1][4] = '2';
        sudoku->arr[1][5] = '7';

        sudoku->arr[2][1] = '2';
        sudoku->arr[2][2] = '9';
        sudoku->arr[2][7] = '5';

        sudoku->arr[3][0] = '9';
        sudoku->arr[3][4] = '5';
        sudoku->arr[3][8] = '3';

        sudoku->arr[4][0] = '6';
        sudoku->arr[4][3] = '9';
        sudoku->arr[4][5] = '3';
        sudoku->arr[4][8] = '4';

        sudoku->arr[5][0] = '8';
        sudoku->arr[5][4] = '1';
        sudoku->arr[5][8] = '5';

        sudoku->arr[6][1] = '5';
        sudoku->arr[6][6] = '1';
        sudoku->arr[6][7] = '9';

        sudoku->arr[7][3] = '6';
        sudoku->arr[7][4] = '4';
        sudoku->arr[7][5] = '2';
        sudoku->arr[7][8] = '7';

        sudoku->arr[8][4] = '9';
        sudoku->arr[8][7] = '8';
        sudoku->arr[8][8] = '2';
    }
    void board4()
    {
        sudoku->arr[1][5] = '3';
        sudoku->arr[1][7] = '8';
        sudoku->arr[1][8] = '5';

        sudoku->arr[2][2] = '1';
        sudoku->arr[2][4] = '2';

        sudoku->arr[3][3] = '5';
        sudoku->arr[3][5] = '7';

        sudoku->arr[4][2] = '4';
        sudoku->arr[4][6] = '1';

        sudoku->arr[5][2] = '9';

        sudoku->arr[6][0] = '5';
        sudoku->arr[6][7] = '7';
        sudoku->arr[6][8] = '3';

        sudoku->arr[7][2] = '2';
        sudoku->arr[7][4] = '1';

        sudoku->arr[8][4] = '4';
        sudoku->arr[8][8] = '9';
    }
    void board5()
    {
        sudoku->arr[0][0] = '6';
        sudoku->arr[0][3] = '3';
        sudoku->arr[0][4] = '9';
        sudoku->arr[0][6] = '4';

        sudoku->arr[1][8] = '7';

        sudoku->arr[2][8] = '5';

        sudoku->arr[3][1] = '6';
        sudoku->arr[3][5] = '9';
        sudoku->arr[3][8] = '8';

        sudoku->arr[4][1] = '5';
        sudoku->arr[4][3] = '7';
        sudoku->arr[4][5] = '2';
        sudoku->arr[4][8] = '9';

        sudoku->arr[5][1] = '4';
        sudoku->arr[5][2] = '2';
        sudoku->arr[5][3] = '5';
        sudoku->arr[5][5] = '6';

        sudoku->arr[6][0] = '5';
        sudoku->arr[6][1] = '2';
        sudoku->arr[6][5] = '7';

        sudoku->arr[7][3] = '4';
        sudoku->arr[7][8] = '2';

        sudoku->arr[8][4] = '5';
        sudoku->arr[8][6] = '9';
        sudoku->arr[8][7] = '7';
    }
};
