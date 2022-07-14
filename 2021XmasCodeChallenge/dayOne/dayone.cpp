#include <fstream>
#include <iostream>

int main(int argc, const char* argv[]) {
    int numInc = -1;
    int curNum = 0;
    int nextNum = 0;

    std::ifstream infile;
    
    if(argc != 2) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
        infile.open(argv[1]);
        while(infile >> nextNum) {
            if(curNum < nextNum) {
                numInc++;
                //std::cout << "curNum:" << curNum << '\n';
                curNum = nextNum;
                //std::cout << "nextNum:" << nextNum << '\n';
            } else if(curNum > nextNum) {
                curNum = nextNum;
            }
        }
        infile.close();
    }

    std::cout << numInc << '\n';
    return 0;
}