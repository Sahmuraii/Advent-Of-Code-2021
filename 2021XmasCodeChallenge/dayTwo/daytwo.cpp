#include <fstream>
#include <iostream>
int main(int argc, const char* argv[]) {
    std::ifstream infile;
    std::string word;
    int number = 0;
    int hospos = 0;
    int dephpos = 0;
    int sum;
    int aim = 0;

    if(argc != 2) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
        infile.open(argv[1]);

        while(infile >> word >> number) {
            if(word == "forward") {
                hospos = hospos + number;
                dephpos = dephpos + (aim * number);
                std::cout << "dephpos: " << dephpos << '\n';
            } else if(word == "down") {
                std::cout << "dephpos: " << dephpos << '\n';
                aim = aim + number;
            } else if(word == "up"){
                std::cout << "dephpos: " << dephpos << '\n';
                aim = aim - number;
            }
        }

        infile.close();
    }

    sum = hospos * dephpos;
    std::cout << sum << '\n'; 
    return 1;
}