#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int my_number;

// return true if the human guessed our numeber
bool human_guesses()
{
    cout << "Human, ask me a number: ";

    int human_number;
    cin >> human_number;

    if (human_number > my_number)
    {
        cout << "Lower!\n";
    }
    else if (human_number < my_number)
    {
        cout << "Higher!\n";
    }
    else
    {
        cout << "You got me!\n";
        return true; // guess
    }

    return false; // no guess
}

const int MAX_NUMBER = RAND_MAX;

int low_bound = 0; // lowest possible number of the human
int up_bound = MAX_NUMBER; // one above the highest possible number of the human

// return true if we guessed the number or the human is a liar
bool i_guess()
{
    int guess = low_bound + (up_bound - low_bound) / 2;

    cout << "My guess is " << guess << ".\n";

    cout << "Enter h for higher, l for lower and = if I guessed correctly: ";

    char answer;
    cin >> answer;

    if (answer == 'h')
    {
        low_bound = guess + 1;
    }
    else if (answer == 'l')
    {
        up_bound = guess;
    }
    else if (answer == '=')
    {
        cout << "YAY!!!\n";
        return true;
    }
    else
    {
        cout << "what?!\n";
    }

    if (low_bound == up_bound)
    {
        cout << "You're lying :( I won't play anymore\n";
        return true;
    }

    return false;
}

int main()
{
    cout << "Think of a number between 0 and " << (MAX_NUMBER - 1) << ". I have do so, too\n";

    srand(time(nullptr));
    my_number = rand() % MAX_NUMBER;
    cout << "Shhh, my number is: " << my_number << "\n";

    while (true)
    {
        if (human_guesses()) break;
        if (i_guess()) break;
    }

    return 0;
}
