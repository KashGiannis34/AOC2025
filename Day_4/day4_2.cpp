#include <vector>
#include <iostream>
#include <fstream>
#include <string>

int paperCount(std::vector<std::vector<char>> grid) {
    int dirs[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},
    {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    int res = 0;
    int pCount;
    do {
        pCount = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '.') {
                    continue;
                }

                int count = 0;
                for (int k = 0; k < 8; k++) {
                    if (i + dirs[k][0] < 0 || i + dirs[k][0] >= grid.size()
                    || j + dirs[k][1] < 0 || j + dirs[k][1] >= grid.size()) {
                        continue;
                    }

                    if (grid[i + dirs[k][0]][j + dirs[k][1]] == '@') {
                        count++;
                    }

                    if (count == 4) {
                        break;
                    }
                }

                if (count < 4) {
                    pCount++;
                    grid[i][j] = '.';
                }
            }
        }
        res += pCount;
    } while (pCount != 0);
    return res;
}

int main() {
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "File can't open" << std::endl;
        return 1;
    }

    char c;
    std::vector<std::vector<char>> cGrid;
    std::vector<char> currLine;
    while (inputFile.get(c)) {
        if (c != '\n') {
            currLine.push_back(c);
        } else {
            cGrid.push_back(currLine);
            currLine = {};
        }
    }

    if (currLine.size() != 0) {
        cGrid.push_back(currLine);
    }

    std::cout << paperCount(cGrid) << std::endl;

    inputFile.close();

    return 0;
}
