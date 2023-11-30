class SudokuSolver : public Sudoku
{
public:
    SudokuSolver()
    {
        // constructor
        sudoku = new TwoDArray(9);
    }
    bool solve()
    { // function to solve the sudoku
        int row, col;

        // If there is no unassigned location,
        // we are done
        if (!findEmptyCell(row, col))
            // success!
            return true;
        // Consider digits 1 to 9
        for (int num = 1; num <= 9; num++)
        {
            // Check if looks promising
            if (isSafe(row, col, char(num + '0')))
            {
                // Make tentative assignment
                sudoku->arr[row][col] = char(num + '0');
                // Return, if success
                if (solve())
                    return true;
                // Failure, unmake & try again
                sudoku->arr[row][col] = ' ';
            }
        }
        // This triggers backtracking
        return false;
    }
    bool findEmptyCell(int &r, int &c)
    {
        for (r = 0; r < sudoku->n; r++)
            for (c = 0; c < sudoku->n; c++)
                if (sudoku->arr[r][c] == ' ')
                    return true;
        return false;
    }

    void static displayInputInstructions()
    { // function to display input instructions for sudoku
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
    { // actual function to input sudoku
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