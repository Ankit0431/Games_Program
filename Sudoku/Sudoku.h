#include <iostream>
#ifndef TWODARRAY_H
#define TWODARRAY_H
#include "../TwoDArray.h"
#endif // TWODARRAY_H
using namespace std;
class Sudoku
{
public:
    TwoDArray *sudoku;

public:
    Sudoku(int n)
    {
        // constructor
        sudoku = new TwoDArray(n);
    }
    Sudoku()
    {
        // constructor
        sudoku = new TwoDArray(9);
    }
    void displaySudoku()
    {
        for (int i = 0; i < sudoku->n; i++)
        {
            for (int j = 0; j < sudoku->n; j++)
            {
                if (j % 3 == 0)
                {
                    printf("|  ");
                }
                printf("%c\t", sudoku->arr[i][j]);
                if (j == 8)
                {
                    printf("|  ");
                }
            }
            printf("\n");
            if (i % 3 == 2)
            {
                printf("_________________________________________________________________________________________________");
            }
            printf("\n");
        }
    }
    bool checkRow(int r, char num)
    { // checks if that number is present in any column of that whole row
        for (int c = 0; c < sudoku->n; c++)
        {
            if (sudoku->arr[r][c] == num)
                return true;
        }
        return false;
    }
    int checkColumn(int c, char num)
    { // checks if that number is present in any row of that whole column
        for (int r = 0; r < sudoku->n; r++)
        {
            if (sudoku->arr[r][c] == num)
                return true;
        }
        return false;
    }
    int checkBox(int row, int col, char num)
    { // checks if that number is already present in that grid or box ( 3x3 box )
        int r, c;
        r = row;
        c = col;
        if (row != 0 && row != 3 && row != 6)
        {
            if (row == 1 || row == 2)
                r = 0;
            else if (row == 4 || row == 5)
                r = 3;
            else
                r = 6;
        }
        if (col != 0 && col != 3 && col != 6)
        {
            if (col == 1 || col == 2)
                c = 0;
            else if (col == 4 || col == 5)
                c = 3;
            else
                c = 6;
        }
        for (int i = r; i < (r + 3); i++)
        {
            for (int j = c; j < (c + 3); j++)
            {
                if (sudoku->arr[i][j] == num)
                    return true;
            }
        }
        return false;
    }
    bool isSafe(int row, int col, char num)
    {
        /* Check if 'num' is not already placed in current row, current column and current 3x3 box */
        return !checkRow(row, num) && !checkColumn(col, num) && !checkBox(row - row % 3, col - col % 3, num) && sudoku->arr[row][col] == ' ';
    }
};
#include "Challenge.h"
#ifndef SOLVER_H
#define SOLVER_H
#include "SudokuSolver.h"
#endif // TWODARRAY_H