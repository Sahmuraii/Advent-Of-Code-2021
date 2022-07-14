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
    // std::vector<std::string> initalLetters;
    // std::vector<std::string> outputLetters;
    std::vector<int> sumsList;
    // std::vector<std::vector<char>> digitConfig {
    // //    0   1   2   3   4   5
    //     {'*','*','*','*','*','*'},
    //     {'*','*','*','*','*','*'},
    //     {'*','*','*','*','*','*'},
    //     {'*','*','*','*','*','*'},
    //     {'*','*','*','*','*','*'},
    //     {'*','*','*','*','*','*'},
    //     {'*','*','*','*','*','*'},
    // };
    std::string currentLetters;
    std::string letter;
    int test = 0;
    int sum = 0;

    if(argc != 2) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
         infile.open(argv[1]);
         while(!infile.eof()) {
            std::vector<std::string> initalLetters;
            std::vector<std::string> outputLetters;

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

            for(int i = 0; i < 4; i++) {
                std::cout << test << '\n';
                std::cout << outputLetters[i] << " " << '\n';
            }

            test++;

            std::sort(initalLetters.begin(), initalLetters.end(), c);
            std::sort(outputLetters.begin(), outputLetters.end(), c);

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

            for(int i = 0; i <= initalLetters.size(); i++) {
                if (i == 0){
                    // adding sides from number 1

                    // top right side
                    // digitConfig[1][5] = initalLetters[i].at(0);
                    // digitConfig[2][5] = initalLetters[i].at(0);

                    // //bottom right side
                    // digitConfig[4][5] = initalLetters[i].at(1);
                    // digitConfig[5][5] = initalLetters[i].at(1);

                    zero.push_back(initalLetters[i].at(0));
                    zero.push_back(initalLetters[i].at(1));

                    one.push_back(initalLetters[i].at(0));
                    one.push_back(initalLetters[i].at(1));

                    two.push_back(initalLetters[i].at(0));

                    three.push_back(initalLetters[i].at(0));
                    three.push_back(initalLetters[i].at(1));

                    four.push_back(initalLetters[i].at(0));
                    four.push_back(initalLetters[i].at(1));

                    five.push_back(initalLetters[i].at(1));

                    six.push_back(initalLetters[i].at(1));

                    seven.push_back(initalLetters[i].at(0));
                    seven.push_back(initalLetters[i].at(1));

                    eight.push_back(initalLetters[i].at(0));
                    eight.push_back(initalLetters[i].at(1));

                    nine.push_back(initalLetters[i].at(0));
                    nine.push_back(initalLetters[i].at(1));
                } else if(i == 1) {
                    // adding top from 7
                    // digitConfig[0][1] = initalLetters[i].at(0);
                    // digitConfig[0][2] = initalLetters[i].at(0);
                    // digitConfig[0][3] = initalLetters[i].at(0);
                    // digitConfig[0][4] = initalLetters[i].at(0);

                    zero.push_back(initalLetters[i].at(0));

                    two.push_back(initalLetters[i].at(0));

                    three.push_back(initalLetters[i].at(0));

                    five.push_back(initalLetters[i].at(0));

                    six.push_back(initalLetters[i].at(0));

                    seven.push_back(initalLetters[i].at(0));

                    eight.push_back(initalLetters[i].at(0));

                    nine.push_back(initalLetters[i].at(0));
                } else if(i == 2) {
                    //adding left top side and middle from 4

                    // //top left side
                    // digitConfig[1][0] = initalLetters[i].at(0);
                    // digitConfig[2][0] = initalLetters[i].at(0);

                    // //middle 
                    // digitConfig[3][1] = initalLetters[i].at(2);
                    // digitConfig[3][2] = initalLetters[i].at(2);
                    // digitConfig[3][3] = initalLetters[i].at(2);
                    // digitConfig[3][4] = initalLetters[i].at(2);

                    zero.push_back(initalLetters[i].at(0));

                    two.push_back(initalLetters[i].at(2));

                    three.push_back(initalLetters[i].at(2));

                    four.push_back(initalLetters[i].at(0));
                    four.push_back(initalLetters[i].at(2));

                    five.push_back(initalLetters[i].at(0));
                    five.push_back(initalLetters[i].at(2));

                    six.push_back(initalLetters[i].at(0));
                    six.push_back(initalLetters[i].at(2));

                    eight.push_back(initalLetters[i].at(0));
                    eight.push_back(initalLetters[i].at(2));

                    nine.push_back(initalLetters[i].at(0));
                    nine.push_back(initalLetters[i].at(2));
                } else if (i == 9) {
                    //adding bottom left corner from 8

                    // //bottom row
                    // digitConfig[6][1] = initalLetters[i].at(1);
                    // digitConfig[6][2] = initalLetters[i].at(1);
                    // digitConfig[6][3] = initalLetters[i].at(1);
                    // digitConfig[6][4] = initalLetters[i].at(1);

                    // //bottom left side
                    // digitConfig[4][0] = initalLetters[i].at(4);
                    // digitConfig[5][0] = initalLetters[i].at(4);

                    zero.push_back(initalLetters[i].at(1));
                    zero.push_back(initalLetters[i].at(4));

                    two.push_back(initalLetters[i].at(1));
                    two.push_back(initalLetters[i].at(4));

                    three.push_back(initalLetters[i].at(1));

                    five.push_back(initalLetters[i].at(1));

                    six.push_back(initalLetters[i].at(1));
                    six.push_back(initalLetters[i].at(4));

                    eight.push_back(initalLetters[i].at(1));
                    eight.push_back(initalLetters[i].at(4));

                    nine.push_back(initalLetters[i].at(1));
                }
            }

            int multiplier;
            sum = 0;

            std::cout << "OUTPUT SIZE: " << outputLetters.size() << '\n';

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

                std::cout << eight;
                std::cout << "8 TEST: " << arePermutation(outputLetters[i], eight) << '\n';

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

                std::cout << "SUM: " << sum << '\n';
            }
            // std::cout << "SUM: " << sum << '\n';
            sumsList.push_back(sum);
         }
    }

    std::cout << std::accumulate(sumsList.begin(), sumsList.end(), 0);

    // std::sort(initalLetters.begin(), initalLetters.end(), c);
    // std::sort(outputLetters.begin(), outputLetters.end(), c);

    // for(int i = 0; i < initalLetters.size(); i++) {
    //     std::cout << initalLetters[i] << " "; 
    // }
    
    // std::cout << '\n';

    // std::string zero;
    // std::string one;
    // std::string two;
    // std::string three;
    // std::string four;
    // std::string five;
    // std::string six;
    // std::string seven;
    // std::string eight;
    // std::string nine;

    // for(int i = 0; i <= initalLetters.size(); i++) {
    //     if (i == 0){
    //         // adding sides from number 1

    //         // top right side
    //         digitConfig[1][5] = initalLetters[i].at(0);
    //         digitConfig[2][5] = initalLetters[i].at(0);

    //         //bottom right side
    //         digitConfig[4][5] = initalLetters[i].at(1);
    //         digitConfig[5][5] = initalLetters[i].at(1);

    //         zero.push_back(initalLetters[i].at(0));
    //         zero.push_back(initalLetters[i].at(1));

    //         one.push_back(initalLetters[i].at(0));
    //         one.push_back(initalLetters[i].at(1));

    //         two.push_back(initalLetters[i].at(0));

    //         three.push_back(initalLetters[i].at(0));
    //         three.push_back(initalLetters[i].at(1));

    //         four.push_back(initalLetters[i].at(0));
    //         four.push_back(initalLetters[i].at(1));

    //         five.push_back(initalLetters[i].at(1));

    //         six.push_back(initalLetters[i].at(1));

    //         seven.push_back(initalLetters[i].at(0));
    //         seven.push_back(initalLetters[i].at(1));

    //         eight.push_back(initalLetters[i].at(0));
    //         eight.push_back(initalLetters[i].at(1));

    //         nine.push_back(initalLetters[i].at(0));
    //         nine.push_back(initalLetters[i].at(1));
    //     } else if(i == 1) {
    //         // adding top from 7
    //         digitConfig[0][1] = initalLetters[i].at(0);
    //         digitConfig[0][2] = initalLetters[i].at(0);
    //         digitConfig[0][3] = initalLetters[i].at(0);
    //         digitConfig[0][4] = initalLetters[i].at(0);

    //         zero.push_back(initalLetters[i].at(0));

    //         two.push_back(initalLetters[i].at(0));

    //         three.push_back(initalLetters[i].at(0));

    //         five.push_back(initalLetters[i].at(0));

    //         six.push_back(initalLetters[i].at(0));

    //         seven.push_back(initalLetters[i].at(0));

    //         eight.push_back(initalLetters[i].at(0));

    //         nine.push_back(initalLetters[i].at(0));
    //     } else if(i == 2) {
    //         //adding left top side and middle from 4

    //         //top left side
    //         digitConfig[1][0] = initalLetters[i].at(0);
    //         digitConfig[2][0] = initalLetters[i].at(0);

    //         //middle 
    //         digitConfig[3][1] = initalLetters[i].at(2);
    //         digitConfig[3][2] = initalLetters[i].at(2);
    //         digitConfig[3][3] = initalLetters[i].at(2);
    //         digitConfig[3][4] = initalLetters[i].at(2);

    //         zero.push_back(initalLetters[i].at(0));

    //         two.push_back(initalLetters[i].at(2));

    //         three.push_back(initalLetters[i].at(2));

    //         four.push_back(initalLetters[i].at(0));
    //         four.push_back(initalLetters[i].at(2));

    //         five.push_back(initalLetters[i].at(0));
    //         five.push_back(initalLetters[i].at(2));

    //         six.push_back(initalLetters[i].at(0));
    //         six.push_back(initalLetters[i].at(2));

    //         eight.push_back(initalLetters[i].at(0));
    //         eight.push_back(initalLetters[i].at(2));

    //         nine.push_back(initalLetters[i].at(0));
    //         nine.push_back(initalLetters[i].at(2));
    //     } else if (i == 9) {
    //         //adding bottom left corner from 8

    //         //bottom row
    //         digitConfig[6][1] = initalLetters[i].at(1);
    //         digitConfig[6][2] = initalLetters[i].at(1);
    //         digitConfig[6][3] = initalLetters[i].at(1);
    //         digitConfig[6][4] = initalLetters[i].at(1);

    //         //bottom left side
    //         digitConfig[4][0] = initalLetters[i].at(4);
    //         digitConfig[5][0] = initalLetters[i].at(4);

    //         zero.push_back(initalLetters[i].at(1));
    //         zero.push_back(initalLetters[i].at(4));

    //         two.push_back(initalLetters[i].at(1));
    //         two.push_back(initalLetters[i].at(4));

    //         three.push_back(initalLetters[i].at(1));

    //         five.push_back(initalLetters[i].at(1));

    //         six.push_back(initalLetters[i].at(1));
    //         six.push_back(initalLetters[i].at(4));

    //         eight.push_back(initalLetters[i].at(1));
    //         eight.push_back(initalLetters[i].at(4));

    //         nine.push_back(initalLetters[i].at(1));
    //     }
    // }

    // for (int i = 0; i < digitConfig.size(); i++) {
    //     for (int j = 0; j < digitConfig[i].size(); j++) {
    //         std::cout << digitConfig[i][j];
    //     }
    //     std::cout << '\n';
    // }

    // std::cout << zero << '\n';
    // std::cout << one << '\n';
    // std::cout << two << '\n';
    // std::cout << three << '\n';
    // std::cout << four << '\n';
    // std::cout << five << '\n';
    // std::cout << six << '\n';
    // std::cout << seven << '\n';
    // std::cout << eight << '\n';
    // std::cout << nine << '\n';

    // for(int i = 0; i < outputLetters.size(); i++) {
    //     if(i == 0 || i == 2) {
    //         std::cout << arePermutation(outputLetters[i], five);
    //     } else {
    //         std::cout << arePermutation(outputLetters[i], three);
    //     }
    // }

    // std::cout << '\n';
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
