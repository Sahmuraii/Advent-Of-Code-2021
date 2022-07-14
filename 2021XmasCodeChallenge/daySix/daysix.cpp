#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int main(int argc, const char* argv[]) {
    std::vector<uint8_t> dayCounts;
    std::vector<uint8_t> bornFish;
    int initialDay;
    std::ifstream infile;
    //std::ofstream myfile;
    char delim;

    int count = 0;
    if(argc != 2) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
        infile.open(argv[1]);
        //myfile.open(argv[2]);

        while(!infile.eof()) {
            infile >> initialDay >> delim;
            dayCounts.push_back(initialDay);
        }
    }

    for(int j = 0; j < 80; j++) {
        std::cout << j << '\n';
        for(int i = 0; i < dayCounts.size(); i++) {
            if(dayCounts.at(i) == 0) {
                dayCounts.at(i) = 6;
                bornFish.push_back(8);
            } else {
                dayCounts.at(i) = dayCounts.at(i) - 1;
            }
        }

        if(bornFish.size() > 0) {
            dayCounts.insert(dayCounts.end(), bornFish.begin(), bornFish.end());
            bornFish.clear();
        }
    }

    // for(int i = 0; i < dayCounts.size(); i++) {
    //     std::cout << dayCounts[i] << ',';
    // }

    std::cout << dayCounts.size() << '\n';
}