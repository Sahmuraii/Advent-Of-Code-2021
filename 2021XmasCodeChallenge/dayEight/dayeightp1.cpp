#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
int main(int argc, const char* argv[]) {
    std::ifstream infile;
    std::vector<std::string> initalLetters;
    std::string currentLetters;

    if(argc != 2) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
         infile.open(argv[1]);
         while(!infile.eof()) {
            infile.ignore(256, '|');
            for(int i = 0; i < 4; i ++) {
                if(!infile.eof()) {
                    infile >> currentLetters;
                    initalLetters.push_back(currentLetters);
                }
            }
         }
    }

    //NUMBER: 1, 4, 7, 8
    //ON/OFF NEEDED : 2, 4, 3, 7
    int initalCount;

    for(int i = 0; i < initalLetters.size(); i++) {
        if(initalLetters[i].std::string::size() == 2) {
            initalCount++;
        } else if(initalLetters[i].std::string::size() == 3) {
            initalCount++;
        } else if(initalLetters[i].std::string::size() == 4) {
            initalCount++;
        }else if(initalLetters[i].std::string::size() == 7) {
            initalCount++;
        }
    }

    std::cout << initalCount << '\n';
}