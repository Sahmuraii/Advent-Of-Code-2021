#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using Cave = std::unordered_map<std::string, std::vector<std::string>>;
using CaveMemory = std::unordered_set<std::string>;

int count_paths(const Cave &system, std::string start, CaveMemory &smalls);

int main(int argc, const char* argv[]) {
    std::ifstream infile;
	Cave caves;
	CaveMemory smalls;

	std::string currLine;
	std::string currentCave = "start";

    if(argc != 2) {
        std::cout << "Error: Too many arguments" << '\n';
    } else {
        infile.open(argv[1]);
        while(infile >> currLine) {
            std::size_t linePos = currLine.find('-');
			std::string caveOne = currLine.substr(0, linePos);
			std::string caveTwo = currLine.substr(linePos + 1);
			caves.insert({caveOne, {}});

			if(caveOne != "end" && caveTwo != "start") {
				caves[caveOne].push_back(caveTwo);
			}

			caves.insert({caveTwo, {}});

			if(caveTwo != "end" && caveOne != "start") {
				caves[caveTwo].push_back(caveOne);
			}
        }
    }

	std::cout << "BALLS TEST" << '\n';

	std::cout << count_paths(caves, currentCave, smalls);
}

int count_paths(const Cave &system, std::string start, CaveMemory &smalls) {
	std::cout << "BALLS TEST" << '\n';
	int pathsCount = 0;
	for(auto &next : system.at(start)) {
		if(smalls.contains(next)) {
			continue;
		}

		if(next == "end") {
			pathsCount++;
			continue;
		}
		if(std::islower(next[0])) {
			smalls.insert(next);
		}

		pathsCount += count_paths(system, next, smalls);
		
		if(std::islower(next[0])) {
			smalls.erase(next);
		}
	}
	return pathsCount;
}