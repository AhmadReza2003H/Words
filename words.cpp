#include "words.h"
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


void Words::showTopFive() {
    int topFiveIndex[5] = {-1, -1, -1, -1, -1};
    for (int i = 0; i < this->words.size(); i++) {
        for (int j = 0; j < 5; j++) {
            if (topFiveIndex[j] == -1 ||this->words.at(i).getCounter() > this->words.at(topFiveIndex[j]).getCounter()) {
                // loop to shift elements
                for (int z = 4; z > j; z--) {
                    topFiveIndex[z] = topFiveIndex[z - 1];
                }
                topFiveIndex[j] = i;
                break;
            }
        }
    }
    for (int i : topFiveIndex) {
        if (i != -1) {
            cout << "\"" << this->words.at(i).getText() << "\" number of this word : "
                 << this->words.at(i).getCounter() << endl;
        }
    }
    cout << endl;
}

void Words::addWord(const std::string &txt) {
    bool isExist = false;
    for (auto & word : this->words) {
        if (word.getText() == txt) {
            isExist = true;
            word++;
            break;
        }
    }
    if (!isExist) {
        words.push_back(txt);
    }
}

int Words::size() {
    return this->words.size();
}