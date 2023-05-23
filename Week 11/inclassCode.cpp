#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;

vector<int> primMST(const Graph& graph, int startNode) {
    int numNodes = graph.size();
    vector<int> parent(numNodes, -1);
    vector<int> key(numNodes, INT_MAX);
    vector<bool> visited(numNodes, false);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    key[startNode] = 0;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int currentNode = pq.top().second;
        int currentWeight = pq.top().first;
        pq.pop();

        visited[currentNode] = true;

        for (const auto& edge : graph[currentNode]) {
            int neighborNode = edge.first;
            int neighborWeight = edge.second;

            if (!visited[neighborNode] && neighborWeight < key[neighborNode]) {
                parent[neighborNode] = currentNode;
                key[neighborNode] = neighborWeight;
                pq.push({key[neighborNode], neighborNode});
            }
        }
    }

    return parent;
}

void printMST(const vector<int>& parent, const Graph& graph) {
    int numNodes = parent.size();
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (int i = 1; i < numNodes; ++i) {
        int u = parent[i];
        int v = i;
        int weight = 0;
        for (const auto& edge : graph[u]) {
            if (edge.first == v) {
                weight = edge.second;
                break;
            }
        }
        cout << u << " - " << v << " : " << weight << endl;
    }
}

int main() {
    int numNodes = 6;
    Graph graph(numNodes);

    graph[0].push_back({1, 3});
    graph[1].push_back({0, 3});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 2});
    graph[2].push_back({5, 5});
    graph[3].push_back({1, 1});
    graph[4].push_back({5, 4});
    graph[5].push_back({2, 5});
    graph[5].push_back({4, 4});

    int startNode = 0;

    vector<int> parent = primMST(graph, startNode);
    printMST(parent, graph);

    return 0;
}
