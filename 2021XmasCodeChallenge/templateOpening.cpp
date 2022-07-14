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

    if(argc != 2) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
         infile.open(argv[1]);
         while(!infile.eof()) {
            
         }
    }
}