#include "mylist.h"
#include <iostream>

using namespace std;

void MyList::addLine(const string &line) {
    this->numberOfLines++;
    int i = 0;
    while (i < line.length()) {
        string word;

        if (isdigit(line[i])) {
            // Extract a number
            while (i < line.length() && isdigit(line[i])) {
                word += line[i];
                this->addLetter(line[i]);
                i++;
            }
            this->numbers.addWord(word);
        } else if (isalpha(line[i])) {
            // Extract an identifiers
            while (i < line.length() && isalnum(line[i])) {
                word += tolower(line[i]);
                this->addLetter(tolower(line[i]));
                i++;
            }
            if (word.length() > 1) {
                this->identifiers.addWord(word);
            }
        } else {
            // Skip non-alphanumeric characters
            i++;
        }
    }
}

void MyList::show() {
    printf("number of lines : %d\tnumber of letters : %zu\n\n", this->numberOfLines, this->letters.size());
    this->showTopFiveLetters();
    printf("number of numbers : %d\n", this->numbers.size());
    this->numbers.showTopFive();
    printf("number of identifiers : %d\n", this->identifiers.size());
    this->identifiers.showTopFive();
}

void MyList::addLetter(char letter) {
    if (letters.count(letter)) {
        this->letters[letter] = ++letters[letter];
    } else {
        this->letters[letter] = 1;
    }
}

void MyList::showTopFiveLetters() {
    char topFiveLetters[5] = {0, 0, 0, 0, 0};
    for(auto letter : this->letters){
        for(int i = 0 ;i < 5 ; i++){
            if(topFiveLetters[i] == 0 || letter.second > this->letters.find(topFiveLetters[i])->second || (letter.second == this->letters.find(topFiveLetters[i])->second && letter.second < this->letters.find(topFiveLetters[i])->second)){
                for (int z = 4; z > i; z--) {
                    topFiveLetters[z] = topFiveLetters[z - 1];
                }
                topFiveLetters[i] = letter.first;
                break;
            }
        }
    }
    for (char letter : topFiveLetters) {
        if (letter != 0) {
            cout << "\"" << letter  << "\" number of this letter : "
                 << this->letters.find(letter)->second << endl;
        }
    }
    cout << endl;
}
