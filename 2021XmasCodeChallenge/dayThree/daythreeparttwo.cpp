#include <fstream>
#include <iostream>
#include <string>
#include <vector>


int main(int argc, const char* argv[]) {

    const int BINLENGTH = 12;
    const int NUMBCOUNT = 1000;

    int oneCount;
    int zeroCount;

    std::vector<std::vector<int>> numbers(NUMBCOUNT);

    std::ifstream infile;

    if(argc != 2) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
        infile.open(argv[1]);

        while(infile.good()) {
            for(int i = 0; i < NUMBCOUNT; i++) {
                for(int j = 0; j < BINLENGTH; j++) {
                        numbers[i].push_back(infile.get() - '0'); 
                        //std::cout << numbers[i][j] << ' ';
                    }
                    infile.ignore(2, 13);
                    infile.ignore(2, 10);
                    //std::cout << '\n';
                }
            }

        infile.close();

        std::cout << "------------------" << '\n';

        std::vector<std::vector<int>> CO(numbers);

        for(int colm = 0; colm < BINLENGTH && CO.size() > 1; colm++) {
            zeroCount = 0;
            oneCount = 0;
            for(int row = 0; row < CO.size(); row++){
                if(CO[row][colm] == 1) {
                    oneCount++;
                } else if(CO[row][colm] == 0) {
                    zeroCount++;
                }  
            }

            if(zeroCount <= oneCount && zeroCount > 0) {
               for(int i = CO.size()-1; i >= 0; i--) {
                   if(CO[i][colm] == 1) {
                       std::cout << "balls" << '\n';
                       CO.erase(CO.begin()+i);
                   }
               }
            } else if(oneCount < zeroCount && oneCount > 0) {
                for(int i = CO.size()-1; i >= 0; i--) {
                    if(CO[i][colm] == 0) {
                        std::cout << "cock" << '\n';
                        CO.erase(CO.begin()+i);
                    }
                }
            }    
        }

        std::cout << "CO2 RATING: " << '\n';

        for(int i = 0; i < BINLENGTH; i++) {
            std::cout << CO[0][i] << ' ';
        }

        std::cout << '\n';

        for(int colm = 0; colm < BINLENGTH && numbers.size() > 1; colm++) {
            zeroCount = 0;
            oneCount = 0;
            for(int row = 0; row < numbers.size(); row++){
                if(numbers[row][colm] == 1) {
                    oneCount++;
                } else if(numbers[row][colm] == 0) {
                    zeroCount++;
                }  
            }

            if(oneCount >= zeroCount) {
                for(int i = numbers.size()-1; i >= 0; i--) {
                    if(numbers[i][colm] == 0) {
                        numbers.erase(numbers.begin()+i);
                    }
                }
            } else if (zeroCount > oneCount) {
               for(int i = numbers.size()-1; i >= 0; i--) {
                   if(numbers[i][colm] == 1) {
                       numbers.erase(numbers.begin()+i);
                   }
               }
            }   
        }

        std::cout << "OXYGEN RATING: " << '\n';

        for(int i = 0; i < BINLENGTH; i++) {
            std::cout << numbers[0][i] << ' ';
        }

        std::cout << '\n';
    }

    return 0;
}
