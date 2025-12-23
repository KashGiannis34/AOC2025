#include <iostream>
#include <fstream>
#include <string>

long long sumInvalidIds(std::string range) {
    std::size_t split = range.find("-");
    std::string low = range.substr(0, split);
    std::string high = range.substr(split+1);

    long long i = std::stoll(low);
    long long max = std::stoll(high);
    long long sum = 0;

    while (i <= max) {
        std::string s;
        bool candidate = false;
        std::string iString = std::to_string(i);
        for (int j = 1; j <= iString.length()/2; j++) {
            std::size_t len = iString.length();
            if (len % j != 0) {
                continue;
            }

            s = "";
            s.reserve(iString.length());
            while (s.length() < len) {
                s += iString.substr(0, j);
            }

            if (s == iString) {
                candidate = true;
                break;
            }
        }

        if (candidate) {
            sum += i;
        }
        i++;
    }

    return sum;
}

int main() {
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "File was not opened" << std::endl;
    }

    std::string ranges;
    getline(inputFile, ranges);
    std::size_t startPos = 0;
    std::size_t endPos = ranges.length() - 1;
    std::size_t index = ranges.find(",", startPos);
    long long sum = 0;

    while (startPos <= endPos && index != std::string::npos) {
        std::string range = ranges.substr(startPos, index - startPos);
        sum += sumInvalidIds(range);
        startPos = index + 1;
        index = ranges.find(",", startPos);
    }

    sum += sumInvalidIds(ranges.substr(startPos, index - startPos));

    std::cout << sum << std::endl;
    inputFile.close();

    return 0;
}
