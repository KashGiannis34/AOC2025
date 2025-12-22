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
        int mult = (dir == "L" ? -1: 1); // -1 = left, 1 = right
        int thresh = (dir == "L" ? 0: 100); // 0 = left, 100 = right

        if (diff + currVal*mult >= thresh) {
            if (currVal != 0) {
                code++;
                diff -= (thresh - currVal*mult);
                currVal = 0;
            }

            code += (diff / 100);
            currVal = (diff*mult % 100 + 100) % 100;
        } else {
            currVal += (diff * mult);
        }
    }

    std::cout << code << std::endl;

    return 0;
}
