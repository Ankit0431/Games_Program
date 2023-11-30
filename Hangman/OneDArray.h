#include <iostream>
using namespace std;
class OneDArray
{
public:
    char *arr; // dynamic 1d array pointer
    int size;  // size of the array(total size in memory; n)
    OneDArray(int n)
    { // constructor
        this->size = n;
        this->arr = new char[n]; // declare a memory block of size n
        for (int i = 0; i < n; i++)
            this->arr[i] = '_';
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            printf("%c ", arr[i]);
        }
    }
    bool matchWithString(string match)
    { // function to match contents of array with a string
        if (match.length() != size)
            return false;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] != match[i])
                return false;
        }
        return true;
    }
    void insert(char elem, int pos)
    { // function to insert element in the array
        arr[pos] = elem;
    }
};