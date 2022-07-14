#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int main(int argc, const char* argv[]) {
    std::vector<uint8_t> dayCounts;
    std::vector<long long> fishes = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
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

     for (int i = 0; i < dayCounts.size(); i++) {
		fishes[dayCounts[i]]++;
	}

    for(int j = 0; j < 256; j++) {
            std::rotate(&fishes[0], &fishes[0]+1, &fishes[9]); 
            fishes[6] += fishes[8];
    }

    long long total = 0;

    for(int i = 0; i < fishes.size(); i++) {
        total += fishes[i];
    }

    std::cout << total << '\n';
}