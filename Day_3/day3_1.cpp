#include <vector>
#include <iostream>
#include <fstream>
#include <string>

int maxVoltage(std::string line) {
    std::vector<int> suffixMax = {};

    int max = 0;
    for (int i = line.length() - 1; i >= 0; i--) {
        int n = line[i] - '0';
        max = std::max(n, max);
        suffixMax.insert(suffixMax.begin(), max);
    }

    max = 0;
    int index = 0;
    for (int i = 0; i < line.length() - 1; i++) {
        int n = line[i] - '0';
        if (n > max) {
            max = n;
            index = i;
        }
    }

    return max*10 + suffixMax[index+1];
}

int main() {
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "File can't open" << std::endl;
        return 1;
    }

    std::string line;
    int total = 0;

    while (std::getline(inputFile, line)) {
        total += maxVoltage(line);
    }
    std::cout << total << std::endl;
    inputFile.close();

    return 0;
}
