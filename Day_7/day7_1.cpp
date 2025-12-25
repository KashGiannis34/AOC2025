#include <iostream>
#include <fstream>
#include <set>

int main() {
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "NOOOOOOOOOOOOOOOOOOOOOOOOOOO" << std::endl;
    }

    std::string line;
    std::set<int> sources;
    int splitCount = 0;

    std::getline(inputFile, line);
    sources.insert(line.find('S'));

    while (std::getline(inputFile, line)) {
        std::set<int> temp = {};
        for (int source: sources) {
            if (line[source] == '^') {
                temp.insert(source+1);
                temp.insert(source-1);
                splitCount++;
            } else {
                temp.insert(source);
            }
        }
        sources = temp;
    }

    std::cout << splitCount << std::endl;

    inputFile.close();
    return 0;
}