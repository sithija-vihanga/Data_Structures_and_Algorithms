#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Node {
    int id;
    int distance;
};

struct CompareNodes {
    bool operator()(const Node& a, const Node& b) {
        return a.distance > b.distance;
    }
};

void dijkstra(const vector<vector<int>>& graph, int source, vector<int>& distances) {
    int n = graph.size();

    priority_queue<Node, vector<Node>, CompareNodes> pq;

    distances.assign(n, INT_MAX);
    distances[source] = 0;

    pq.push({source, 0});

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        int currId = curr.id;
        int currDist = curr.distance;

        if (currDist > distances[currId]) {
            continue;
        }

        for (int neighborId = 0; neighborId < n; neighborId++) {
            int neighborDist = graph[currId][neighborId];

            if (neighborDist == 0 || currDist == INT_MAX) {
                continue;
            }

            int newDist = currDist + neighborDist;

            if (newDist < distances[neighborId]) {
                distances[neighborId] = newDist;
                pq.push({neighborId, newDist});
            }
        }
    }
}

int main() {
    int n = 6;

    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int source = 0;

    vector<int> distances;

    dijkstra(graph, source, distances);

    cout << "Shortest distances from the node " << source << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";
        if (distances[i] == INT_MAX) {
            cout << "Not reachable\n";
        } else {
            cout << distances[i] << "\n";
        }
    }

    return 0;
}
