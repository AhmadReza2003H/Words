#include "mylist.h"

using namespace std;

void MyList::addLine(const string &line) {
    this->numberOfLines++;
    int i = 0;
    while (i < line.length()) {
        string word;
        if (isdigit(line[i])) {
            // Extract a number
            this->numbers.addWord(this->extractWord(&isdigit, i, &line));
        } else if (isalpha(line[i])) {
            // Extract an identifiers
            string identifier = this->extractWord(&isalnum , i , &line);
            if (identifier.length() > 1) {
                this->identifiers.addWord(identifier);
            }
        } else {
            // Skip non-alphanumeric characters
            i++;
        }
    }
}

string MyList::extractWord(IsVerified isVerified, int &i, const string *line) {
    string word;
    while ((*isVerified)((*line)[i]) && i < line->length()){
        word += tolower((*line)[i]);
        this->letters.addWord(string( 1, tolower((*line)[i])));
        i++;
    }
    return word;
}

void MyList::show() {
    cout << "number of lines : " << this->numberOfLines <<  endl;
    cout << "number of letters : " << this->letters.size() << endl;
    this->letters.showTopFive();
    cout << "number of numbers : " << this->numbers.size() << endl;
    this->numbers.showTopFive();
    cout << "number of identifiers : " << this->identifiers.size() << endl;
    this->identifiers.showTopFive();
}


