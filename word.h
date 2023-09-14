#ifndef WORD_WORD_H
#define WORD_WORD_H

#include <string>
#include <utility>

using namespace std;
class Word{
public:
    Word(string txt) : text(std::move(txt)) , counter(1){}

    string getText() const {
        return text;
    }

    int getCounter() const {
        return counter;
    }
    void operator++(int){
        this->counter++;
    }

private:
    string text;
    int counter;
};


#endif //WORD_WORD_H
