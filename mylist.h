#ifndef WORD_MYLIST_H
#define WORD_MYLIST_H

#include <string>
#include <map>
#include "words.h"

using namespace std;

typedef int(*IsVerified)(int);

class MyList{
public:
    void addLine(const string &);
    void show();
private:
    Words numbers;
    Words identifiers;
    Words letters;
    int numberOfLines = 0;
    string extractWord(IsVerified , int & , const string *);
};

#endif //WORD_MYLIST_H
