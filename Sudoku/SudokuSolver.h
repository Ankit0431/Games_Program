class SudokuSolver : public Sudoku
{
public:
    void solve(int r, int c)
    {
        if (r > 8)
        {
            printf("\n\n<<<<<<<<<<<<< THE SOLVED SUDOKU >>>>>>>>>>>>>>>>>>>\n\n");
            displaySudoku();
            exit(0);
        }
        if (sudoku->arr[r][c] != ' ')
        { // looks for empty cells i.e. cells with zero
            findEmptyCell(r, c);
        }
        else
        {
            for (int i = 1; i <= 9; i++)
            {
                if (!checkRow(r, char(i + '0')) && !checkColumn(c, char(i + '0')) && !checkBox(r, c, char(i + '0')))
                {
                    sudoku->arr[r][c] = char(i + '0');
                    findEmptyCell(r, c);
                }
            }
            sudoku->arr[r][c] = ' ';
        }
    }
    void findEmptyCell(int r, int c)
    {
        if (c < 8)
        { // checks each column of a row for empty cell
            solve(r, c + 1);
        }
        else
        { // moves to the next row to check for new empty cells
            solve(r + 1, 0);
        }
    }
    void static displayInputInstructions()
    {
        printf("Choose a cell numbered from 1 to 9 as below\n\n");
        printf("\t\t\t 1 | 2 | 3 \n");
        printf("\t\t\t-----------\n");
        printf("\t\t\t 4 | 5 | 6 \n");
        printf("\t\t\t-----------\n");
        printf("\t\t\t 7 | 8 | 9 \n\n");
        printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
        printf("Enter the cell number along with the value for that cell like (Location,Value)\n");
        printf("To move to next internal matrix, enter -1,-1\n");
    }
    void inputSudoku()
    {
        int m;
        char elem;
        for (int i = 0; i < 9; i++)
        {
            SudokuSolver::displayInputInstructions();
            while (true)
            {
                printf("Enter the sudoku to solve in the following manner\n");
            mistake:

                printf("Entering for %d internal matrix: ", i + 1);
                scanf("%d,%c", &m, &elem);
                fflush(stdin);
                if (m < 0)
                    break;
                if (m > 9)
                {
                    printf("Wrong input, please try again!\n");
                    goto mistake;
                }
                else if (elem < '1' || elem > '9')
                {
                    printf("Numbers in sudoku can only be between 1 and 9, please try again!\n");
                    goto mistake;
                }
                m = m + (i % 3) * 3 + ((m - 1) / 3 + (i / 3) * 3) * 6 + (i / 3) * 9; // logic to convert m to suitable input for 9x9 2d array
                sudoku->updateArray(elem, m);
            }
        }
    }
};