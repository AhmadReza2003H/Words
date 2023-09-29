#include <iostream>
#include <fstream>
#include "mylist.h"

int main() {
    std::ifstream testFile("file address");
    string line;
    MyList words;
    if (!testFile.is_open()) {
        std::cerr << "Failed to open the file!" << std::endl;
        return 1;
    }
    while (getline(testFile , line)){
        words.addLine(line);
    }
    words.show();
    testFile.close();}
