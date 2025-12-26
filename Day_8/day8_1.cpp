#include <iostream>
#include <fstream>
#include <functional>
#include <tuple>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>

int explore(std::unordered_map<int, std::set<int>> &cGraph, std::set<int> &visited, int node) {
    int count = 0;
    visited.insert(node);

    for (const int &adj: cGraph[node]) {
        if (visited.count(adj) > 0) {
            continue;
        }

        count += explore(cGraph, visited, adj);
    }
    return 1 + count;
}

std::priority_queue<int> componentSizes(std::unordered_map<int, std::set<int>> &cGraph) {
    std::set<int> visited;
    std::priority_queue<int> maxSizes;
    for (std::unordered_map<int, std::set<int>>::iterator it = cGraph.begin(); it != cGraph.end(); it++) {
        if (visited.count(it->first) > 0) {
            continue;
        }

        maxSizes.push(explore(cGraph, visited, it->first));
    }
    return maxSizes;
}

int main() {
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "NOOOOOOOOOOOOOOOOOOOOOOOOOOO" << std::endl;
    }

    char comma;
    int x,y,z;
    std::vector<std::tuple<int, int, int>> points;
    std::priority_queue<std::tuple<float, int, int>,
                        std::vector<std::tuple<float, int, int>>,
                        std::greater<std::tuple<float, int, int>>> minHeap;
    while (inputFile >> x >> comma >> y >> comma >> z) {
        for (int i = 0; i < points.size(); i++) {
            float dist = std::sqrtf(std::pow(std::get<0>(points[i]) - x, 2)
                        +std::pow(std::get<1>(points[i]) - y, 2)
                        +std::pow(std::get<2>(points[i]) - z, 2));
            minHeap.push(std::make_tuple(dist, i, points.size()));
        }

        points.push_back(std::make_tuple(x,y,z));
    }

    std::unordered_map<int, std::set<int>> cGraph;
    for (int i = 0; i < 1000; i++) {
        std::tuple<float, int, int> pair = minHeap.top();
        minHeap.pop();

        cGraph[std::get<1>(pair)].insert(std::get<2>(pair));
        cGraph[std::get<2>(pair)].insert(std::get<1>(pair));
    }

    std::priority_queue<int> sizes = componentSizes(cGraph);
    int res = sizes.top();
    sizes.pop();
    res *= sizes.top();
    sizes.pop();
    res *= sizes.top();

    std::cout << res << std::endl;

    inputFile.close();
    return 0;
}