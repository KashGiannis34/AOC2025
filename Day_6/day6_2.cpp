#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "WHYYYYYYYYYYYYYYYYYYYY" << std::endl;
    }

    std::vector<std::string> lines;
    for (int i = 0; i < 5; i++) {
        std::string line;
        std::getline(inputFile, line);
        lines.push_back(line);
    }

    std::vector<int> nums;
    char sign = ' ';
    long long sum = 0;
    for (size_t i = 0; i <= lines[0].length(); i++) {
        if (i == lines[0].length() ||
            (lines[0][i] == ' ' && lines[1][i] == ' '
            && lines[2][i] == ' ' && lines[3][i] == ' ')) {

            long long val = nums[0];
            for (int j = 1; j < nums.size(); j++) {
                if (sign == '+') {
                    val += nums[j];
                } else {
                    val *= nums[j];
                }
            }
            nums = {};
            sum += val;
            continue;
        }

        if (i < lines[4].length() && lines[4][i] != ' ') {
            sign = lines[4][i];
        }

        std::string str = {lines[0][i], lines[1][i], lines[2][i], lines[3][i]};
        nums.push_back(std::stoi(str));
    }

    inputFile.close();
    std::cout << sum << std::endl;

    return 0;
}