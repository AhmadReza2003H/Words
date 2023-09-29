#include "words.h"

using namespace std;


void Words::showTopFive() {

    vector<std::pair<std::string, int>> vectorPairs(words.begin(), words.end());

    sort(vectorPairs.begin(), vectorPairs.end(), [](const auto &a, const auto &b) {
        return a.second > b.second;
    });

    int i = 0;
    while (i < min(5, static_cast<int>(vectorPairs.size()))) {
        auto word = vectorPairs.at(i);
        cout << "'" << word.first << "' number of this word : " << word.second << endl;
        i++;
    }
}

void Words::addWord(const std::string &txt) {
    auto obj = words.find(txt);
    if (obj != words.end()) {
        obj->second += 1;
    } else {
        words[txt] = 1;
    }
}

int Words::size() {
    return this->words.size();
}