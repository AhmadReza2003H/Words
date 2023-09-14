#ifndef WORD_MYLIST_H
#define WORD_MYLIST_H
#include <string>
#include <map>
#include "words.h"

using namespace std;
class MyList{
public:
    void addLine(const string & line);
    void addLetter(char letter);
    void show();
private:
    Words numbers;
    Words identifiers;
    map<char , int> letters;
    int numberOfLines = 0;
    void showTopFiveLetters();
};

#endif //WORD_MYLIST_H
