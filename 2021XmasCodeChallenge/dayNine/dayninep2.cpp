#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <bits/stdc++.h>

int floodFill(std::vector<std::vector<int>> &screen, int m, int n, int x, int y, int prevC, int newC);
bool isValid(std::vector<std::vector<int>> &screen, int m, int n, int x, int y, int prevC, int newC);

int main(int argc, const char* argv[]) {
    std::ifstream infile;
    std::vector<int> numbersListed;
    std::vector<std::vector<int>> numbers(100, std::vector<int> (100, 0));
    std::vector<int> riskLocation;
    std::vector<int> baseLineSizes;
    char digit;
    int sum = 0;

    if(argc != 2) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
        infile.open(argv[1]);

        while(!infile.eof()) {
            digit = infile.get();
            if(isdigit(digit)){
                numbersListed.push_back(digit - '0');
            }
        }
    }
    
    int k = 0;

    for(int i = 0; i < numbers.size(); i++) {
        for(int j = 0; j < numbers[0].size(); j++) {
            numbers[i][j] = numbersListed[k];
            k++;
        }
    }

    int count;

    for (int i = 0; i < numbers.size(); ++i) {
        for (int j = 0; j < numbers[0].size(); ++j) {
            count = 0;

            if (i >= 0 && j + 1 < numbers[0].size() ) {
                if(numbers[i][j + 1] > numbers[i][j]) {
                    count++;
                }
            } else {
                count++;
            }

            if (i + 1 < numbers.size() && j >= 0) {
                if(numbers[i + 1][j] > numbers[i][j]) {
                    count++;        
                }
            }  else {
                count++;
            }

            // left middle
            if (i >= 0 && j - 1 > -1) {
                if(numbers[i][j - 1] > numbers[i][j]) {
                    count++;
                }
            } else {
                count++;
            }

            // top middle
            if (i - 1 > -1 && j >= 0) {
                if(numbers[i - 1][j] > numbers[i][j]) {
                    count++;    
                }
            } else {
                count++;
            }

            if(count == 4) {
                riskLocation.push_back(i);
                riskLocation.push_back(j);
            }
        }
    }

    
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = 0; j < numbers[0].size(); j++) {
            if(numbers[i][j] < 9) {
                numbers[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < numbers.size(); i++) {
        for(int j = 0; j < numbers[0].size(); j++) {
            std::cout << numbers[i][j] << " ";
        }
        std::cout << '\n';
    }

    std::cout << '\n';

    for(int i = 0; i < riskLocation.size(); i++) {
        int basinAmmount;
        if(i % 2 == 0) {
            basinAmmount = floodFill(numbers, numbers.size(), numbers[0].size(), riskLocation[i], riskLocation[i+1], 0, 1);
            baseLineSizes.push_back(basinAmmount);
        }
    }

    sort(baseLineSizes.begin(), baseLineSizes.end());
    
    for(int i = 0; i < baseLineSizes.size(); i++) {
        std::cout << baseLineSizes[i] << '\n';
    }

    std::cout << '\n';
    infile.close();
}

bool isValid(std::vector<std::vector<int>> &screen, int m, int n, int x, int y, int prevC, int newC)
{
    if(x < 0 || x >= m || y < 0 || y >= n || screen[x][y] != prevC
       || screen[x][y]== newC)
        return false;
    return true;
}
    
int floodFill(std::vector<std::vector<int>> &screen, int m, int n, int x, int y, int prevC, int newC)
{
    int timesRan = 1;
    std::vector<std::pair<int,int>> queue;
 
    // Append the position of starting
    // pixel of the component
    std::pair<int,int> p(x,y);
    queue.push_back(p);
 
    // Color the pixel with the new color
    screen[x][y] = newC;
 
    // While the queue is not empty i.e. the
    // whole component having prevC color
    // is not colored with newC color
    while(queue.size() > 0)
    {
        // Dequeue the front node
        std::pair<int,int> currPixel = queue[queue.size() - 1];
        queue.pop_back();
 
        int posX = currPixel.first;
        int posY = currPixel.second;
 
        // Check if the adjacent
        // pixels are valid
        if(isValid(screen, m, n, posX + 1, posY, prevC, newC))
        {
            // Color with newC
            // if valid and enqueue
            screen[posX + 1][posY] = newC;
            p.first = posX + 1;
            p.second = posY;
            queue.push_back(p);
            timesRan++;
        }
 
        if(isValid(screen, m, n, posX-1, posY, prevC, newC))
        {
            screen[posX-1][posY]= newC;
            p.first = posX-1;
            p.second = posY;
            queue.push_back(p);
            timesRan++;
        }
 
        if(isValid(screen, m, n, posX, posY + 1, prevC, newC))
        {
            screen[posX][posY + 1]= newC;
            p.first = posX;
            p.second = posY + 1;
            queue.push_back(p);
            timesRan++;
        }
 
        if(isValid(screen, m, n, posX, posY-1, prevC, newC))
        {
            screen[posX][posY-1]= newC;
            p.first = posX;
            p.second = posY-1;
            queue.push_back(p);
            timesRan++;
        }
    }
    return timesRan;
}
