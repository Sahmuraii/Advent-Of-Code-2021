#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
int main(int argc, const char* argv[]) {
    std::ifstream infile;
    std::vector<int> initalCount;
    // std::vector<int> tempCount;
    std::vector<int> sums;

    int number;
    char delim;

    if(argc != 2) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
        infile.open(argv[1]);

        while(!infile.eof()) {
            infile >> number >> delim;
            initalCount.push_back(number);
        }

        int max = *max_element(initalCount.begin(), initalCount.end());
        int sum;


    for(int j = 0; j <= max; j++) {
        for(int i = 0; i < initalCount.size(); i++) {
            if(initalCount[i] > j) {
                sum = sum + (initalCount[i] - j);
            } else if(initalCount[i] < j) {
                sum = sum + (j - initalCount[i]);
            } else if (initalCount[i] == j) {
                sum = sum;
            }
        }
        sums.push_back(sum);
        sum = 0;
    }
        int min = *min_element(sums.begin(), sums.end());
        std::cout << min << '\n';
    }

}