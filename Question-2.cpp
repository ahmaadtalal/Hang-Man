#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayHangman(int wrongGuess)
{
    switch (wrongGuess)
    {
        case 0:
            cout << "   _____\n"
                    "   |   |\n"
                    "       |\n"
                    "       |\n"
                    "       |\n"
                    "       |\n"
                    "  _____|_____\n";
            break;
        case 1:
            cout << "   _____\n"
                    "   |   |\n"
                    "   O   |\n"
                    "       |\n"
                    "       |\n"
                    "       |\n"
                    "  _____|_____\n";
            break;
        case 2:
            cout << "   _____\n"
                    "   |   |\n"
                    "   O   |\n"
                    "   |   |\n"
                    "       |\n"
                    "       |\n"
                    "  _____|_____\n";
            break;
        case 3:
            cout << "   _____\n"
                    "   |   |\n"
                    "   O   |\n"
                    "  /|   |\n"
                    "       |\n"
                    "       |\n"
                    "  _____|_____\n";
            break;
        case 4:
            cout << "   _____\n"
                    "   |   |\n"
                    "   O   |\n"
                    "  /|\\  |\n"
                    "       |\n"
                    "       |\n"
                    "  _____|_____\n";
            break;
        case 5:
            cout << "   _____\n"
                    "   |   |\n"
                    "   O   |\n"
                    "  /|\\  |\n"
                    "  /    |\n"
                    "       |\n"
                    "  _____|_____\n";
            break;
        case 6:
            cout << "   _____\n"
                    "   |   |\n"
                    "   O   |\n"
                    "  /|\\  |\n"
                    "  / \\  |\n"
                    "       |\n"
                    "  _____|_____\n";
            break;
    }
}

string chosenWord()
{
    string words[] = {"mcs", "programming", "student", "are", "lazy", "hangman", "teacher", "pakistan"};
    int size = sizeof(words) / sizeof(words[0]);
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % size;
    return words[randomIndex];
}


void displayWord(const string& word, const string& guessedLetter)
{
    for (char letter : word)
    {
        if (guessedLetter.find(letter) != string::npos)
        {
            cout << letter << " ";
        } else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main()
{
    string word = chosenWord();
    string guessedLetter = "";
    int wrongGuess = 0;
    int maxwrongGuess = 6;

    cout << "Welcome to Hangman!" << endl;

    while (wrongGuess < maxwrongGuess)
    {
        displayHangman(wrongGuess);
        displayWord(word, guessedLetter);

        cout << "Guess a letter: ";
        char guess;
        cin >> guess;

        if (guessedLetter.find(guess) != string::npos)
        {
            cout << "You already guessed that letter. Try again." << endl;
            continue;
        }

        guessedLetter += guess;

        if (word.find(guess) == string::npos)
        {
            cout << "Incorrect guess. Try again." << endl;
            wrongGuess++;
        } else
        {
            cout << "Correct guess!" << endl;
        }

        bool wordGuessed = true;
        for (char letter : word)
        {
            if (guessedLetter.find(letter) == string::npos)
            {
                wordGuessed = false;
                break;
            }
        }

        if (wordGuessed)
        {
            cout << "Congratulations! You guessed the word: " << word << endl;
            break;
        }
    }

    if (wrongGuess == maxwrongGuess)
    {
        displayHangman(wrongGuess);
        cout << "Sorry, you ran out of guesses. The correct word was: " << word << endl;
    }

    return 0;
}