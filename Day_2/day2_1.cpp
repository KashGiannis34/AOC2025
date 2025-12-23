#include <iostream>
#include <fstream>
#include <string>

long long sumInvalidIds(std::string range) {
    std::size_t split = range.find("-");
    std::string low = range.substr(0, split);
    std::string high = range.substr(split+1);

    long long i = low.length()/2 == 0 ? 0 : std::stoll(low.substr(0, low.length()/2));

    long long min = std::stoll(low);
    long long max = std::stoll(high);
    long long sum = 0;

    while (true) {
        long long candidate = std::stoll(std::to_string(i) + std::to_string(i));
        if (candidate < min) {
            i++;
            continue;
        } else if (candidate > max) {
            break;
        } else {
            sum += candidate;
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

    return 0;
}
