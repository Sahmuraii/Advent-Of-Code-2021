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
    std::vector<std::vector<char>> paper(15, std::vector<char>(11,'.'));

    int x; 
    int y;
    char delim;
    std::string line;

    if(argc != 3) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
        infile.open(argv[1]);
        myfile.open(argv[2]);

         while(!infile.eof()) {
            getline(infile, line);
            std::stringstream ss(line);
            ss >> x >> delim >> y;
            coordinates.push_back(x);
            coordinates.push_back(y);
        }
    }

    for(int i = 0; i < coordinates.size(); i++) {
        if(i % 2 == 0) {
            paper[coordinates[i+1]][coordinates[i]] = '#';
        }
    }


    for(int i = 0; i < paper.size(); i++) {
        for(int j = 0; j < paper[0].size(); j++) {
            myfile << paper[i][j] << ' ';
        }
        myfile << '\n';
    }
   
}