#ifndef WORD_WORDS_H
#define WORD_WORDS_H

#include <vector>
#include <map>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Words{
public:
    void showTopFive();
    void addWord(const string& txt);
    int size();
private:
    map<string , int> words;
};
#endif //WORD_WORDS_H
