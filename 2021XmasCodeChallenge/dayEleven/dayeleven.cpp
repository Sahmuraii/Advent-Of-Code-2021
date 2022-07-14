#include <fstream>
#include <iostream>
#include <string>
#include <vector>


int main(int argc, const char* argv[]) {
    std::ifstream infile;

    std::vector<std::vector<int>> numbers(10);
    std::vector<std::vector<int>> numbersTruthValues(10, std::vector<int>(10,0));

    // for(int i = 0; i < numbersTruthValues.size(); i++){
    //     for(int j = 0; j < numbersTruthValues[0].size(); j++){
    //         std::cout << numbersTruthValues[i][j] << " ";
    //     }
    //     std::cout << '\n';
    // } 

    // std::cout << '\n';

    int flashes;

    if(argc != 2) {
        std::cout << "Too many Arguments" << '\n';
    } else { 
        infile.open(argv[1]);
         while(infile.good()) {
            for(int i = 0; i < 10; i++) {
                for(int j = 0; j < 10; j++) {
                        numbers[i].push_back(infile.get() - '0'); 
                        std::cout << numbers[i][j] << " ";
                    }
                    infile.ignore(2, 13);
                    infile.ignore(2, 10);
                    std::cout << '\n';
                }
            }

        for(int i = 0; i < SIZE_MAX; i++) 
        {
            for(int j = 0; j < 10; j++) 
            {
                for(int k = 0; k < 10; k++) 
                {
                    numbers[j][k] = numbers[j][k] + 1;
                }
            }

            bool flashed = true;
            while(flashed) 
            {
                flashed = false;

                for(int x = 0; x < 10; x++) 
                {
                    for(int y = 0; y < 10; y++)
                    {
                        if(numbers[x][y] > 9 && numbersTruthValues[x][y] == 0) 
                        {
                            numbersTruthValues[x][y] = 1;
                            flashed = true;
                            flashes++;

                            if(x != 9)
                                numbers[x+1][y] = numbers[x+1][y] + 1;
                            if(x != 9 && y != 9)
                                numbers[x+1][y+1] = numbers[x+1][y+1] + 1;
                            if(x != 9 && y != 0)
                                numbers[x+1][y-1] = numbers[x+1][y-1] + 1;
                            if(y != 9)
                                numbers[x][y+1] = numbers[x][y+1] + 1;
                            if(y != 0)
                                numbers[x][y-1] = numbers[x][y-1] +1;
                            if(x != 0 && y !=9)
                                numbers[x-1][y+1] = numbers[x-1][y+1] + 1;
                            if(x != 0 && y != 0)
                                numbers[x-1][y-1] = numbers[x-1][y-1] + 1;
                            if(x != 0)
                                numbers[x-1][y] = numbers[x-1][y] + 1;
                        }
                    }
                }
            }

            bool BRIGHT = true; 

            for(int x = 0; x < 10; x++) {
                for(int y = 0; y < 10; y++) {
                    if(numbersTruthValues[x][y] == 1) {
                        numbersTruthValues[x][y] = 0;
                        numbers[x][y] = 0;
                    } else {
                        BRIGHT = false;
                    }
                }
            }

            if(BRIGHT) {
                std::cout << i << '\n';
                break;
            }
        }

        std::cout << flashes << '\n';

        infile.close();
    }
}