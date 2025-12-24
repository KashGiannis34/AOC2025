#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "WHYYYYYYYYYYYYYYYYYYYY" << std::endl;
    }

    std::vector<std::vector<int>> numbers;
    std::vector<int> row;
    int currNum;
    while (inputFile >> currNum) {
        row.push_back(currNum);

        if (inputFile.peek() == '\n') {
            numbers.push_back(row);
            row = {};
            if (numbers.size() == 4) {
                break;
            }
        }
    }

    char c;
    size_t i = 0;
    long long sum = 0;
    while (inputFile >> c) {
        if (c == '+') {
            sum += ((long long) numbers[0][i] + numbers[1][i]
                + numbers[2][i] + numbers[3][i]);
        } else {
            sum += ((long long) numbers[0][i] * numbers[1][i]
                * numbers[2][i] * numbers[3][i]);
        }
        i++;
    }

    inputFile.close();
    std::cout << sum << std::endl;

    return 0;
}