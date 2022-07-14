#include <fstream>
#include <iostream>
#include <string>

long long arraytoNumber(long long array[], int length);
long long binaryToDecimal(long long n);

int main(int argc, const char* argv[]) {

    const int BINLENGTH = 12;

    long long onesList[BINLENGTH] = {};
    long long zerosList[BINLENGTH] = {};

    long long gammaRate[BINLENGTH] = {}; 
    long long epsilonRate[BINLENGTH] = {};

    long long gammaNumber = 0; 
    long long epsilonNumber = 0;
    long long powerConsump = 0;

    std::ifstream infile;

    std::string number;

    if(argc != 2) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
        infile.open(argv[1]);

        while(infile >> number) {
            for(int i = 0; i < number.length(); i++) {
                    if(number[i] == '1') {
                        onesList[i] = onesList[i] + 1;
                    } else if(number[i] == '0') {
                        zerosList[i] = zerosList[i] + 1;
                    }
            }
        }

        infile.close();
    }

    for(int gammaCount = 0; gammaCount < BINLENGTH; gammaCount++) {
        if(onesList[gammaCount] > zerosList[gammaCount]) {
            gammaRate[gammaCount] = 1;
            epsilonRate[gammaCount] = 0;
        } else {
            gammaRate[gammaCount] = 0;
            epsilonRate[gammaCount] = 1;
        }
    }

    gammaNumber = arraytoNumber(gammaRate, BINLENGTH);
    epsilonNumber = arraytoNumber(epsilonRate, BINLENGTH);

    gammaNumber = binaryToDecimal(gammaNumber);
    epsilonNumber = binaryToDecimal(epsilonNumber);

    std::cout << gammaNumber << ' ' << epsilonNumber << ' ' << '\n';

    powerConsump = gammaNumber * epsilonNumber;

    std::cout << powerConsump << '\n';

    return 0;
}

long long arraytoNumber(long long array[], int length) {
    long long binaryNum = 0;
    long long multiplier = 1;
    for (long long binConvert = length - 1; binConvert >= 0; --binConvert )
    {
        binaryNum += (multiplier * array[binConvert]);
        multiplier *= 10;
    }

    return binaryNum;
}

long long binaryToDecimal(long long n) {
    long long num = n;
    long long dec_value = 0;
 
    long long base = 1;
 
    long long temp = num;
    while (temp) {
        long long last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}