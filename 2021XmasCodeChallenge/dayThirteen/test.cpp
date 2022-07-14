#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
int main(int argc, const char* argv[]) {
    std::ifstream infile;
    std::ofstream myfile;
    std::vector<int> coordinates;
    std::vector<std::vector<char>> paper(1500, std::vector<char>(1500,'.'));

    int x; 
    int y;
    char delim;
    std::string line;

    if(argc != 3) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
        infile.open(argv[1]);
        myfile.open(argv[2]);

         while(getline(infile, line)) {
            std::stringstream ss(line);

            if(line.find(',') != std::npos) {
                ss >> x >> delim >> y;
                coordinates.push_back(x);
                coordinates.push_back(y);
            } else {
                std::cout << "BRUH";
            }

        }
    }

    for(int i = 0; i < coordinates.size(); i++) {
        if(i % 2 == 0) {
            paper[coordinates[i+1]][coordinates[i]] = '#';
        }
    }

    for(int i = 0; i < paper[0].size(); i++) {
        paper[i][655] = '|';
    }

    std::cout << paper[144][661] << '\n';
    // paper[144][649] = '#';

    int away;

    for(int i = 0; i < paper.size(); i++) {
        for(int j = 0; j < paper[0].size(); j++) {
            if(j > 655) {
                away = j - 2*(j-655);
                if(j - away < paper[0].size()) {
                    paper[i][j - away] = '#';
                }
                away = 0;
            }
        }
    }

    for(int i = 0; i < paper.size(); i++) {
        for(int j = 0; j < paper[0].size(); j++) {
            myfile << paper[i][j] << ' ';
        }
        myfile << '\n';
    }
   
}