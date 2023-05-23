#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

int findParent(std::vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = findParent(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSubsets(std::vector<Subset>& subsets, int x, int y) {
    int xroot = findParent(subsets, x);
    int yroot = findParent(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

std::vector<Edge> findMST(std::vector<std::vector<int>>& graph, int numVertices) {
    std::vector<Edge> result;

    std::vector<Edge> edges;
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            if (graph[i][j] != 0) {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }
    std::sort(edges.begin(), edges.end(), compareEdges);

    std::vector<Subset> subsets(numVertices);
    for (int i = 0; i < numVertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int edgeIndex = 0;
    int numEdges = 0;
    while (numEdges < numVertices - 1 && edgeIndex < edges.size()) {
        Edge nextEdge = edges[edgeIndex++];

        int x = findParent(subsets, nextEdge.src);
        int y = findParent(subsets, nextEdge.dest);

        if (x != y) {
            result.push_back(nextEdge);
            unionSubsets(subsets, x, y);
            numEdges++;
        }
    }

    return result;
}

void printMST(const std::vector<Edge>& mst) {
    int totalWeight = 0;

    std::cout << "Minimum Spanning Tree (MST):\n";
    for (const Edge& edge : mst) {
        std::cout << edge.src << " - " << edge.dest << " : " << edge.weight << "\n";
        totalWeight += edge.weight;
    }

    std::cout << "Total weight: " << totalWeight << "\n";
}

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    int numVertices = graph.size();

    std::vector<Edge> mst = findMST(graph, numVertices);
    printMST(mst);

    return 0;
}
