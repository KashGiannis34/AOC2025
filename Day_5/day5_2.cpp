#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main() {
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Aiaiyooooooooo" << std::endl;
    }

    long long min;
    long long max;
    std::vector<std::vector<long long>> ranges;
    char dash;
    while (inputFile >> min >> dash >> max) {
        std::vector<long long> range = {min, max};
        ranges.push_back(range);

        std::string dummy;
        std::getline(inputFile, dummy);
        if (inputFile.peek() == '\n') {
            break;
        }
    }
    inputFile.close();

    std::sort(ranges.begin(), ranges.end(), [](const std::vector<long long> &a, const std::vector<long long> &b) {
        return a[0] < b[0];
    });

    int i = 0;
    long long currMax = -1;
    long long freshCount = 0;
    while (i < ranges.size()) {
        if (currMax > ranges[i][1]) {
            i++;
            continue;
        }

        if (i >= ranges.size()) {
            break;
        }

        if (currMax < ranges[i][0]) {
            freshCount += (ranges[i][1] - ranges[i][0] + 1);
        } else {
            freshCount += (ranges[i][1] - currMax);
        }

        currMax = ranges[i][1];
        i++;
    }

    std::cout << freshCount << std::endl;

    return 0;
}