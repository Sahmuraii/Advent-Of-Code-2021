#include <fstream>
#include <iostream>
int main(int argc, const char* argv[]) {
    std::ifstream infile;
    std::string word;
    int number = 0;
    int hospos = 0;
    int dephpos = 0;
    int sum;

    if(argc != 2) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
        infile.open(argv[1]);

        while(infile >> word >> number) {
            if(word == "forward") {
                hospos = hospos + number;
            } else if(word == "down") {
                dephpos = dephpos + number;
            } else if(word == "up"){
                dephpos = dephpos - number;
            }
        }

        infile.close();
    }

    sum = hospos * dephpos;
    std::cout << sum << '\n'; 
    return 1;
}