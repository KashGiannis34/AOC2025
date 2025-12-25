#include <iostream>
#include <fstream>
#include <set>
#include <unordered_map>
#include <tuple>

long long dfs(std::set<std::tuple<int, int>> &map, std::unordered_map<std::string, long long> &counts, int x, int y, const int &yMax) {
    if (y >= yMax) {
        return 1;
    }

    std::unordered_map<std::string, long long>::iterator it = counts.find(std::to_string(x)+","+std::to_string(y));
    if (it != counts.end()) {
        std::cout << "Memo used" << std::endl;
        return it->second;
    }

    if (map.find({x,y}) != map.end()) {
        long long countLeft = dfs(map, counts, x-1, y+1, yMax);
        long long countRight = dfs(map, counts, x+1, y+1, yMax);
        counts[std::to_string(x-1)+","+std::to_string(y+1)] = countLeft;
        counts[std::to_string(x+1)+","+std::to_string(y+1)] = countRight;
        return countLeft + countRight;
    } else {
        return dfs(map, counts, x, y+1, yMax);
    }
}

int main() {
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "NOOOOOOOOOOOOOOOOOOOOOOOOOOO" << std::endl;
    }

    std::string line;
    std::getline(inputFile, line);
    int startX = line.find("S");
    std::set<std::tuple<int, int>> cMap;
    int y = 0;
    while (std::getline(inputFile, line)) {
        int x = line.find('^', 0);
        while (x != std::string::npos) {
            cMap.insert({x, y});
            x = line.find('^', x+1);
        }
        y++;
    }

    const int yMax = --y;

    std::unordered_map<std::string, long long> counts = {};
    long long splitCount = dfs(cMap, counts, startX, 0, yMax);

    std::cout << splitCount << std::endl;

    inputFile.close();
    return 0;
}