#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

vector<string> possible_words;

string my_word;
string hint;
size_t missing_letters;

vector<char> mistakes;

const vector<string> gallows = {
    " ______\n"
    "  |   |\n"
    "      |\n"
    "      |\n"
    "      |\n"
    ,
    " ______\n"
    "  |   |\n"
    "  O   |\n"
    "      |\n"
    "      |\n"
    ,
    " ______\n"
    "  |   |\n"
    "  O   |\n"
    "  |   |\n"
    "      |\n"
    ,
    " ______\n"
    "  |   |\n"
   " \\O   |\n"
    "  |   |\n"
    "      |\n"
    ,
    " ______\n"
    "  |   |\n"
   " \\O/  |\n"
    "  |   |\n"
    "      |\n"
    ,
    " ______\n"
    "  |   |\n"
   " \\O/  |\n"
    "  |   |\n"
    " /    |\n"
    ,
    " ______\n"
    "  |   |\n"
   " \\O/  |\n"
    "  |   |\n"
    " / \\  |\n"
    ,
};

// return true if the human guessed or the human was hanged (hehe)
bool human_guesses()
{
    cout << "\n\n";
    cout << gallows[mistakes.size()] << "\n";
    for (char letter : hint)
    {
        cout << letter << " ";
    }
    cout << "\n";

    if (!mistakes.empty())
    {
        cout << "Mistakes so far: ";
        for (char letter : mistakes)
        {
            cout << letter << " ";
        }
        cout << "\n";
    }

    cout << "Human, guess a letter: ";
    char guess;
    cin >> guess;
    guess = toupper(guess);

    bool letter_guessed = false;
    for (size_t i=0; i<my_word.length(); ++i)
    {
        if(guess == my_word[i])
        {
            letter_guessed = true;
            hint[i] = guess;
            --missing_letters;
            cout << "This letter exists in my word\n";
        }
    }

    if (missing_letters == 0)
    {
        cout << "\nYou beat me! :( My word was indeed\n\n";
        for (auto letter : my_word)
        {
            cout << letter << ' ';
        }
        cout << '\n';
        return true;
    }

    if (!letter_guessed)
    {
        mistakes.push_back(guess);
        if (mistakes.size() == (gallows.size() - 1))
        {
            cout << "\nYou are hanged! I won! :)\n";
            cout << gallows.back();
            cout << "\n My word was " << my_word << "\n";
            return true;
        }
    }

    return false;
}

bool read_words()
{
    ifstream fin{"hangman-words.txt"};

    while (fin)
    {
        string word;
        fin >> word;
        if (!word.empty())
        {
            possible_words.push_back(word);
        }
    }

    if (possible_words.empty())
    {
        return false;
    }

    return true;
}

int main()
{
    if (!read_words())
    {
        cerr << "Words can't be read\n";
        return 1;
    }

    srand(time(nullptr));
    my_word = possible_words[rand() % possible_words.size()];

    for (char& letter : my_word)
    {
        letter = toupper(letter);
    }

    // cout << "Shh, my word is " << my_word << "\n";

    hint.resize(my_word.length(), '_');
    missing_letters = my_word.length();

    while(true)
    {
        if (human_guesses()) break;
    }

    return 0;
}