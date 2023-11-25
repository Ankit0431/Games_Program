#include <iostream>
#include <string>  //for handeling strings
#include <sstream> //for treating strings as streams
#include <random>  //for random number e=generator
#include <chrono>  //random number seeder
#include <fstream> //for reading csv files
#include "OneDArray.cpp"
using namespace std;
class Hangman
{
private:
// public:
    OneDArray *word;
    int tries;
    string answer;
    string hint;

public:
    Hangman()
    {
        this->tries = 5;
    }
    bool checkLetter(char guess)
    {
        int i = 0;
        bool flag = false;
        while (answer[i] != '\0')
        {
            if (guess == answer[i])
            {
                word->insert(guess,i);
                flag = true;
            }
            i++;
        }
        return flag;
    }
    static int generateRandomNumber()
    {
        // // Providing a seed value
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 gen(seed);

        // Define the range
        int lower_bound = 1;
        int upper_bound = 110;

        // Create a distribution for the range
        uniform_int_distribution<int> distribution(lower_bound, upper_bound);

        // Generate a random number
        int random = distribution(gen);
        return random;
    }
    void readWordFromCsv(int n)
    {
        ifstream file;
        string line;
        try
        {
            file.open("Hangman_Words.csv");
            while (getline(file, line) && (n > 0))
            {
                n--;
            }
            if (n == 0)
            {
                istringstream stream(line);   // class used for treating a string as an input stream
                getline(stream, answer, ','); // first half is stored in answer(before the comma)
                getline(stream, hint, ',');   // second half is stored in hint(after the comma)
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    void play()
    {
        char guess;
        readWordFromCsv(generateRandomNumber());
        word = new OneDArray(answer.length());
        printf("Welcome to Hangman!\n Enter your guesses from your keyboard! All the best!");
        while (tries != 0)
        {
            printf("\n\t\t");
            word->display();
            cout << "\nHint: " << hint << endl;
            printf("\nTries left: %d", tries);
            printf("\nEnter your guess: ");
            fflush(stdin);
            cin >> guess;
            if (checkLetter(guess))
            {
                if (word->matchWithString(answer))
                {
                    printf("\nCongragulatiions, you have won!");
                    break;
                }
                else
                {
                    printf("\nNicely done!\n");
                }
            }
            else
            {
                printf("\nOOPS, you seems stupid, wrong choice\n");
                tries--;
            }
        }
        if (tries == 0)
        {
            printf("\nYou have no more tries, the man has hanged, you LOOSE\n");
            cout << "Answer: " << answer << endl;
        }
    }
};
int main()
{
    Hangman h;
    // cout << Hangman::generateRandomNumber() << endl;
    // h.readWordFromCsv(Hangman::generateRandomNumber());
    // h.getAnswer();
     h.play();
//     int i = 0;
//     OneDArray word(h.answer.length());
//     while (h.answer[i] != '\0')
//         {
//             if ('e' == h.answer[i])
//             {
                
//             }
//             i++;
//         }
//     word.display();
}