#ifndef WORD_WORDS_H
#define WORD_WORDS_H

#include <vector>
#include "word.h"

class Words{
public:
    void showTopFive();
    void addWord(const string& txt);
    int size();
private:
    vector<Word> words;
};
#endif //WORD_WORDS_H
