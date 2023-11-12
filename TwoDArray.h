#include <iostream>
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