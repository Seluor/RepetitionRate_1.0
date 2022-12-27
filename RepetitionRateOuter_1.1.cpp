#include <fstream>
#include <iostream>
using namespace std;

int main() {
    int frequencyOfRepetitionOfSingleLetters[128];
    fstream firstOpenFile;
    char letter;

    firstOpenFile.open("text.txt");
    if (!firstOpenFile) {
        cout << "ERROR '404'";
        return -1;
    }

    for (int iterator = 0; iterator < 128; ++iterator) {
        frequencyOfRepetitionOfSingleLetters[iterator] = 0;
    }

    letter = firstOpenFile.get();
    while (letter != EOF) {
        letter = toupper(letter);
        ++frequencyOfRepetitionOfSingleLetters[letter];
        letter = firstOpenFile.get();
    }

    cout << endl << "Single letters frequencies in this file are:" << endl;
    for (char letter = 'A'; letter <= 'Z'; ++letter) {
        if (frequencyOfRepetitionOfSingleLetters[letter]) {
            cout << letter << ": " << frequencyOfRepetitionOfSingleLetters[letter] << ";  ";
        }
    } cout << endl;

    int frequencyOfRepetitionOfDoubleLetters[128][128];
    fstream secondOpenFile;

    secondOpenFile.open("text.txt");

    for (int firstIterator = 0; firstIterator < 128; ++firstIterator) {
        for (int secondIterator = 0; secondIterator < 128; ++secondIterator) {
            frequencyOfRepetitionOfDoubleLetters[firstIterator][secondIterator] = 0;
        }
    }

    char firstLetter, secondLetter;
    firstLetter = secondOpenFile.get();
    secondLetter = secondOpenFile.get();

    while (secondLetter != EOF) {
        firstLetter = toupper(firstLetter);
        secondLetter = toupper(secondLetter);
        ++frequencyOfRepetitionOfDoubleLetters[firstLetter][secondLetter];
        firstLetter = secondLetter;
        secondLetter = secondOpenFile.get();
    }

    cout << endl << "Double letter frequencies in this file are:" << endl;
    for (char firstLetter = 'A'; firstLetter <= 'Z'; ++firstLetter) {
        for (char secondLetter = 'A'; secondLetter <= 'Z'; ++secondLetter) {

            if (frequencyOfRepetitionOfDoubleLetters[firstLetter][secondLetter]) {
                cout << firstLetter << secondLetter << ": " << frequencyOfRepetitionOfDoubleLetters[firstLetter][secondLetter] << ";  ";
            }
        }
    } cout << endl;

    return 0;
}
