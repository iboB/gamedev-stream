#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const string INPUT = "hangman-words.original.txt";
const string OUTPUT = "hangman-words.txt";

bool is_shorter_than_4_characters(string s)
{
    return s.length() < 4;
}

int main()
{
    vector<string> words;
    ifstream fin{INPUT};

    while (fin)
    {
        string word;
        fin >> word;
        if (!word.empty())
        {
            words.push_back(word);
        }
    }

    if (words.empty())
    {
        cerr << "Error: cannot reads words from " << INPUT << "\n";
        return 1;
    }

    cout << "Successfully read " << words.size() << " words from " << INPUT << "\n";

    auto new_end = remove_if(words.begin(), words.end(), is_shorter_than_4_characters);
    words.erase(new_end, words.end());

    ofstream fout{OUTPUT};
    for(auto word : words)
    {
        fout << word << "\n";
    }

    cout << "Succesfully wrote " << words.size() << " words to " << OUTPUT << "\n";

    return 0;
}
