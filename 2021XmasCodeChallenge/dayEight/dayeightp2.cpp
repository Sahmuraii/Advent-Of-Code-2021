#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

struct compare {
    inline bool operator()(const std::string& first,
            const std::string& second) const
    {
        return first.size() < second.size();
    }
};

bool arePermutation(std::string str1, std::string str2);

int main(int argc, const char* argv[]) {
    compare c;
    std::ifstream infile;
    std::vector<int> sumsList;

    if(argc != 2) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
        infile.open(argv[1]);
        while(!infile.eof()) {
            int sum = 0;
            std::string zero;
            std::string one;
            std::string two;
            std::string three;
            std::string four;
            std::string five;
            std::string six;
            std::string seven;
            std::string eight;
            std::string nine;

            std::string currentLetters;
            std::string letter;

            std::vector<std::string> outputLetters;
            std::vector<std::string> initalLetters;
            for(int i = 0; i < 10; i++) {
                if(!infile.eof()) {
                    infile >> currentLetters;
                    initalLetters.push_back(currentLetters);
                }
            }

            infile.ignore(1, '|');

            for(int i = 0; i < 4; i ++) {
                if(!infile.eof()) {
                    infile >> currentLetters;
                    outputLetters.push_back(currentLetters);
                }
            }

            std::sort(initalLetters.begin(), initalLetters.end(), c);

            one = initalLetters[0];
            seven = initalLetters[1];
            four = initalLetters[2];
            eight = initalLetters[9];

            int count = 0;

            bool found = false;
            // 9.
            int nineLocal;
            for(int j = 6; j < 9 && found == false; j++) {
                for(int i = 0; i < 6 && found == false; i++) {
                    if(initalLetters[2].std::string::find(initalLetters[j].std::string::at(i)) != std::string::npos) {
                        count++;
                    } else if(initalLetters[2].std::string::find(initalLetters[j].std::string::at(i)) == std::string::npos) {}

                    if(count == 4) {
                        nineLocal = j;
                        nine = initalLetters[j];
                        found = true;
                        count = 0;
                    }
                }
                count = 0;
            }

            found = false;
            int sixLocal;

            // 6.
            for(int j = 6; j < 9 && found == false; j++) {
                if(j != nineLocal) {
                    for(int i = 0; i < 6 && found == false; i++) {
                        if(initalLetters[1].std::string::find(initalLetters[j].std::string::at(i)) != std::string::npos) {
                            count++;
                        } else if(initalLetters[1].std::string::find(initalLetters[j].std::string::at(i)) == std::string::npos) {}

                        // std::cout << "COUNT: " << count << " J: " << j << '\n';

                        if(count == 2 && i == 5) {
                            sixLocal = j;
                            six = initalLetters[j];
                            found = true;
                            count = 0;
                        }
                    }
                }
                count = 0;
            }


            found = false;

            for(int j = 6; j < 9 && found == false; j++) {
                if(j == sixLocal || j == nineLocal) {} 
                else {
                    zero = initalLetters[j];
                }
            }


            // 3. (based on 7)
            found = false;
            count = 0;
            int ThreeLocal;

            for(int j = 3; j < 6 && found == false; j++) {
                for(int i = 0; i < 5 && found == false; i++) {
                    if(initalLetters[1].std::string::find(initalLetters[j].std::string::at(i)) != std::string::npos) {
                        count++;
                    } else if(initalLetters[1].std::string::find(initalLetters[j].std::string::at(i)) == std::string::npos) {}

                    if(count == 3) {
                        ThreeLocal = j;
                        three = initalLetters[j];
                        found = true;
                        count = 0;
                    }
                }
                count = 0;
            }

            found = false;
            count = 0;
            int fiveLocal;

            //5. 
            for(int j = 3; j < 6 && found == false; j++) {
                if(j != ThreeLocal) {
                    for(int i = 0; i < 5 && found == false; i++) {
                        if(initalLetters[2].std::string::find(initalLetters[j].std::string::at(i)) != std::string::npos) {
                            count++;
                        } else if(initalLetters[2].std::string::find(initalLetters[j].std::string::at(i)) == std::string::npos) {}

                        if(count == 3) {
                            fiveLocal = j;
                            five = initalLetters[j];
                            found = true;
                            count = 0;
                        }
                    }
                }
                count = 0;
            }

            // 2
            found = false;

            for(int j = 3; j < 6 && found == false; j++) {
                if(j == fiveLocal || j == ThreeLocal) {} 
                else {
                    two = initalLetters[j];
                }
            }

            int multiplier;

            for(int i = 0; i < outputLetters.size(); i++) {
                if(i == 0) {
                    multiplier = 1000;
                } else if(i == 1) {
                    multiplier = 100;
                } else if(i == 2) {
                    multiplier = 10;
                } else if(i == 3) {
                    multiplier = 1;
                }

                if(arePermutation(outputLetters[i], one) == true) {
                    sum += 1 * multiplier;
                } else if(arePermutation(outputLetters[i], two) == true) {
                    sum += 2 * multiplier;
                } else if(arePermutation(outputLetters[i], three) == true) {
                    sum += 3 * multiplier;
                } else if(arePermutation(outputLetters[i], four) == true) {
                    sum += 4 * multiplier;
                } else if(arePermutation(outputLetters[i], five) == true) {
                    sum += 5 * multiplier;
                } else if(arePermutation(outputLetters[i], six) == true) {
                    sum += 6 * multiplier;
                }else if(arePermutation(outputLetters[i], seven) == true) {
                    sum += 7 * multiplier;
                }else if(arePermutation(outputLetters[i], eight) == true) {
                    sum += 8 * multiplier;
                }else if(arePermutation(outputLetters[i], nine) == true) {
                    sum += 9 * multiplier;
                }
            }

            sumsList.push_back(sum);
        }
    }
    std::cout << std::accumulate(sumsList.begin(), sumsList.end(), 0) << '\n';
}

bool arePermutation(std::string str1, std::string str2)
{
    // Get lengths of both strings
    int n1 = str1.length();
    int n2 = str2.length();
 
    // If length of both strings is not same,
    // then they cannot be Permutation
    if (n1 != n2)
      return false;
 
    // Sort both strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
 
    // Compare sorted strings
    for (int i = 0; i < n1;  i++)
       if (str1[i] != str2[i])
         return false;
 
    return true;
}
