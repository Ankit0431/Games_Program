#include "Sudoku.h"
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
            // cout<<"Empty cell executed: "<<++iota<<endl;
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
};