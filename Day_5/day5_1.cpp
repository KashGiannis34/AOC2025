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

    std::sort(ranges.begin(), ranges.end(), [](const std::vector<long long> &a, const std::vector<long long> &b) {
        return a[0] < b[0];
    });

    long long id;
    std::vector<long long> ids;
    while (inputFile >> id) {
        ids.push_back(id);
    }
    std::sort(ids.begin(), ids.end());

    int i = 0;
    int freshCount = 0;
    for (long long id: ids) {
        while (i < ranges.size() && id > ranges[i][1]) {
            i++;
        }

        if (i >= ranges.size()) {
            break;
        }

        if (id >= ranges[i][0]) {
            freshCount++;
        }
    }
    std::cout << freshCount << std::endl;

    return 0;
}