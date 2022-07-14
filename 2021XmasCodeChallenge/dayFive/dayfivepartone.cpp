#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int main(int argc, const char* argv[]) {

    std::vector<int> coordinates;
    std::vector<std::vector<int>> grid(1000, std::vector<int>(1000,0));

    int x1,y1,x2,y2;
    std::ifstream infile;
    std::ofstream myfile;
    std::string line;
    char delim;
    int count = 0;

     if(argc != 3) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
        infile.open(argv[1]);
        myfile.open(argv[2]);


        while(!infile.eof()) {
            getline(infile, line);
            std::stringstream ss(line);

            ss >> x1 >> delim >> y1 >> delim >> delim >> x2 >> delim >> y2;
            //std:: cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << '\n';
            if(x1 == x2) {
                if(y1 > y2) {
                    for(int i = y1; i >= y2; i--) {
                        coordinates.push_back(x1);
                        coordinates.push_back(i);
                    } 
                } else if(y1 < y2) {
                    for(int i = y1; i <= y2; i++) {
                        coordinates.push_back(x1);
                        coordinates.push_back(i);
                    }
                }
            } else if(y1 == y2) {
                if(x1 > x2) {
                    for(int i = x1; i >= x2; i--) {
                        coordinates.push_back(i);
                        coordinates.push_back(y1);
                    } 
                } else if(x1 < x2) {
                    for(int i = x1; i <= x2; i++) {
                        coordinates.push_back(i);
                        coordinates.push_back(y1);
                    }
                }
            } else if (x1 != x2 && y1 != y2) {
                if(x1 > x2 && y1 > y2) {
                    int y = y1;
                    for(int i = x1; i >= x2 && y >= y2; i--, y--) {
                        coordinates.push_back(i);
                        coordinates.push_back(y);
                    } 
                }

                if(x2 > x1 && y2 > y1) {
                    int y = y1;
                    for(int i = x1; i <= x2 && y <= y2; i++, y++) {
                        coordinates.push_back(i);
                        coordinates.push_back(y);
                    } 
                }

                if(x1 > x2 && y2 > y1) {
                    int y = y1;
                    for(int i = x1; i >= x2 && y <= y2; i--,y++) {
                        coordinates.push_back(i);
                        coordinates.push_back(y);
                    }
                }

                if(x2 > x1 && y1 > y2) {
                    int y = y1;
                    for(int i = x1; i <= x2 && y >= y2; i++,y--){
                        coordinates.push_back(i);
                        coordinates.push_back(y);
                    }
                }

            }
        }

        for(int i = 0; i < coordinates.size(); i++) {
            if(i % 2 == 0) {
                grid[coordinates[i]][coordinates[i+1]] += 1;
            }
        }

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] >= 2) {
                    count++;
                }
            }
        }

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                myfile << grid[i][j] << " ";
            }
            myfile << '\n';
        }
        myfile.close();
    }

    std::cout << "Balls Test" << '\n';
    std::cout << count << '\n';
}