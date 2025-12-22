#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "File can't open" << std::endl;
        return 1;
    }

    std::string line;
    int currVal = 50;
    int code = 0;

    while (std::getline(inputFile, line)) {
        std::string dir = line.substr(0, 1);
        int diff = std::stoi(line.substr(1));

        if (dir == "L") {
            currVal = ((currVal - diff) % 100 + 100) % 100;
        } else {
            currVal = (currVal + diff) % 100;
        }

        if (currVal == 0) {
            code++;
        }
    }

    std::cout << code << std::endl;

    return 0;
}
