#include <iostream>
#include <fstream>
#include <functional>
#include <tuple>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>

void explore(std::unordered_map<int, std::set<int>> &cGraph, std::set<int> &visited, int node) {
    visited.insert(node);

    for (const int &adj: cGraph[node]) {
        if (visited.count(adj) > 0) {
            continue;
        }

        explore(cGraph, visited, adj);
    }
}

bool connected(std::unordered_map<int, std::set<int>> &cGraph) {
    std::set<int> visited;
    explore(cGraph, visited, cGraph.begin()->first);
    return visited.size() == cGraph.size();
}

int main() {
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "NOOOOOOOOOOOOOOOOOOOOOOOOOOO" << std::endl;
    }

    char comma;
    int x,y,z;
    std::vector<std::tuple<int, int, int>> points;
    std::priority_queue<std::tuple<long long, int, int>,
                        std::vector<std::tuple<long long, int, int>>,
                        std::greater<std::tuple<long long, int, int>>> minHeap;
    std::unordered_map<int, std::set<int>> cGraph;
    while (inputFile >> x >> comma >> y >> comma >> z) {
        for (int i = 0; i < points.size(); i++) {
            long long xDist = std::get<0>(points[i]) - x;
            long long yDist = std::get<1>(points[i]) - y;
            long long zDist = std::get<2>(points[i]) - z;
            long long dist = xDist * xDist + yDist * yDist + zDist * zDist;
            minHeap.push(std::make_tuple(dist, i, points.size()));
        }

        cGraph[points.size()] = {};

        points.push_back(std::make_tuple(x,y,z));
    }

    int box1, box2;
    while (!connected(cGraph)) {
        std::tuple<long long, int, int> pair = minHeap.top();
        minHeap.pop();

        box1 = std::get<1>(pair);
        box2 = std::get<2>(pair);
        cGraph[box1].insert(box2);
        cGraph[box2].insert(box1);
    }

    std::cout << std::get<0>(points[box1]) << " " << std::get<0>(points[box2]) << std::endl;
    std::cout << ((long long) std::get<0>(points[box1]) * std::get<0>(points[box2])) << std::endl;

    inputFile.close();
    return 0;
}