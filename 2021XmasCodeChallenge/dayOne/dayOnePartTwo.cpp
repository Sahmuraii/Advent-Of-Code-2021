#include <fstream>
#include <iostream>

int main(int argc, const char* argv[]) {
    int numInc = 0;

    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
  

    int sum1 = 0;
    int sum2 = 0;

    std::ifstream infile;
    
    if(argc != 2) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
        infile.open(argv[1]);
        infile >> num1 >> num2 >> num3;
        sum1 = num1 + num2 + num3;
        while(infile.good()) {
            num1 = num2;
            num2 = num3;
            infile >> num3;
            sum2 = num1 + num2 + num3;
            if(sum1 == sum2) {
                sum1 = sum2;
            }else if(sum1 < sum2) {
                numInc++;
                sum1 = sum2;
            } else {
                sum1 = sum2;
            }
        }
        infile.close();
    }

    std::cout << numInc << '\n';
    return 0;
}