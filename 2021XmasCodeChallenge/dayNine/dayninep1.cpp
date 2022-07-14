#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>


int main(int argc, const char* argv[]) {
    std::ifstream infile;
    std::vector<int> numbersListed;
    std::vector<std::vector<int>> numbers(100, std::vector<int> (100, 0));
    std::vector<int> riskLevel;
    char digit;
    int sum = 0;

    if(argc != 2) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
        infile.open(argv[1]);

        while(!infile.eof()) {
            digit = infile.get();
            if(isdigit(digit)){
                numbersListed.push_back(digit - '0');
            }
        }
    }

    // std::cout << '\n';

    // for(int i = 0; i < numbersListed.size(); i++){
    //     std::cout << numbersListed[i] << " ";
    // }
    
    int k = 0;

    for(int i = 0; i < numbers.size(); i++) {
        for(int j = 0; j < numbers[0].size(); j++) {
            numbers[i][j] = numbersListed[k];
            k++;
        }
    }

    // for(int i = 0; i < numbers.size(); i++) {
    //     for(int j = 0; j < numbers[0].size(); j++) {
    //         std::cout << numbers[i][j] << ' ';
    //     }
    //     std::cout << '\n';
    // }

    int count;

    for (int i = 0; i < numbers.size(); ++i) {
        for (int j = 0; j < numbers[0].size(); ++j) {
            count = 0;

            if (i >= 0 && j + 1 < numbers[0].size() ) {
                if(numbers[i][j + 1] > numbers[i][j]) {
                    count++;
                }
            } else {
                count++;
            }

            if (i + 1 < numbers.size() && j >= 0) {
                if(numbers[i + 1][j] > numbers[i][j]) {
                    count++;        
                }
            }  else {
                count++;
            }

            // left middle
            if (i >= 0 && j - 1 > -1) {
                if(numbers[i][j - 1] > numbers[i][j]) {
                    count++;
                }
            } else {
                count++;
            }

            // top middle
            if (i - 1 > -1 && j >= 0) {
                if(numbers[i - 1][j] > numbers[i][j]) {
                    count++;    
                }
            } else {
                count++;
            }

            if(count == 4) {
                // std::cout << "I: " << i << " J: " << j << '\n';
                // std::cout << "PUSHING: " << numbers[i][j] << '\n';
                riskLevel.push_back(numbers[i][j] + 1);
            }
        }
    }

    for(int i = 0; i < riskLevel.size(); i++){
        sum += riskLevel[i];
    }

    std::cout << sum;

    std::cout << '\n';
    infile.close();
}
    
