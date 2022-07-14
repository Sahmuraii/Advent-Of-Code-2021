#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int main(int argc, const char* argv[]) {

    std::vector<int> numBalls;
    int counter = 0;

    std::vector<std::vector<std::vector<int>>> boards(100);
    std::vector<std::vector<int>> boardCount(5);
    std::vector<int> linesCount(5);
    

    std::ifstream infile;
    std::string line;
    int currentNum;

    bool flag = true;

    if(argc != 2) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
        infile.open(argv[1]);

        getline(infile,line);
        std::stringstream ss(line);

        while(ss >> currentNum && ss.peek() != '\n') {
            numBalls.push_back(currentNum);
            if(ss.peek() == ',') {
                ss.ignore(1,',');
            }
        }

        while(!infile.eof()) {
            for(int bCount = 0; bCount < 100; bCount++) {
                if(infile.good()) {
                    boards.push_back(std::vector<std::vector<int>>());
                }
                for(int lines = 0; lines < 5; lines++) {
                    if(infile.good()) {
                            boards[bCount].push_back(std::vector<int>());
                        }
                    for(int numbers = 0; numbers < 5; numbers++) {
                        infile >> currentNum;
                        if(infile.good()) {
                            boards[bCount][lines].push_back(currentNum);
                        }
                    }
                }
            }
        }
    }

    //  for(int bCount = 0; bCount < 100; bCount++) {
    //     std::cout << "BOARD: " << bCount << " --------------" << '\n';
    //     for(int lines = 0; lines < 5; lines++) {
    //          for(int numbers = 0; numbers < 5; numbers++) {
    //             std::cout << boards[bCount][lines][numbers] <<" ";
    //         }
    //         std::cout << std::endl;
    //     }
    //         std::cout << std::endl;
    // }


    for(int i = 0; i < numBalls.size(); i++) {
        for(int l = 0; l < 100  && counter != 5; l++) {
            for(int j = 0; j < 5; j++) {
                for(int k = 0; k < 5; k++){
                    if(numBalls[i] == boards[l][j][k]) {
                        boards[l][j][k] = -1;
                    } 

                    if(boards[l][j][k] == -1 && i > 4) {
                        for(int row = 0; row < 5; row++){
                            if(boards[l][j][row] == -1) {
                                counter++;
                            } else {
                                counter = 0;
                                row = 6;
                            }
                        }

                        if(counter == 5) {
                            std::cout << "WINNER: BOARD " << l  << " LAST NUMBER: " << numBalls[i] << '\n';
                        } else {
                            for(int column = 0; column < 5; column++) {
                                if(boards[l][column][k] == -1) {
                                    counter++;
                                } else {
                                    counter = 0;
                                    column = 6;
                                }
                            }

                            if(counter == 5) {
                            std::cout << "WINNER: BOARD " << l  << " LAST NUMBER: " << numBalls[i] << '\n';
                            }
                        }

                    }
                }
            }
        }
    }
    
    for(int bCount = 0; bCount < 100; bCount++) {
        std::cout << "BOARD: " << bCount << " --------------" << '\n';
        for(int lines = 0; lines < 5; lines++) {
             for(int numbers = 0; numbers < 5; numbers++) {
                std::cout << boards[bCount][lines][numbers] <<" ";
            }
            std::cout << std::endl;
        }
            std::cout << std::endl;
    }

    return 0;
}