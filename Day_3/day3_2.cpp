#include <vector>
#include <iostream>
#include <fstream>
#include <string>

long long maxVoltage(std::string line, int length) {
    std::string numbers = "";
    int start = 0;
    for (int i = length-1; i >= 0; i--) {
        int max = 0;
        for (int j = start; j < line.length() - i; j++) {
            int n = line[j] - '0';
            if (n > max) {
                max = n;
                start = j+1;
            }
        }
        numbers += std::to_string(max);
    }

    return std::stoll(numbers);
}

int main() {
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "File can't open" << std::endl;
        return 1;
    }

    std::string line;
    long long total = 0;

    while (std::getline(inputFile, line)) {
        total += maxVoltage(line, 12);
    }
    std::cout << total << std::endl;

    return 0;
}
