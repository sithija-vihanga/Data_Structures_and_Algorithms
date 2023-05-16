#include <iostream>
#include <list>
using namespace std;

struct Node{
    // A node will have 2 entities
    // 1. An integer data type called 'label'
    // 2. An integer type list called 'neighbours'
    int label;
    list<int> neighbours;
};

struct Graph{
    // The graph will have an array of type "Node" with length specified by 'n'
    int n = 9;
    Node* nodes = new Node[n];

    void initializeNodes(){
        // Iterate through the nodes and assign labels
        for(int i=0; i<n; i++){
            nodes[i].label = i;
        }
    }

    void addEdge(int u, int v){
        // Select node 'u' and add 'v' to its neighbours
        nodes[u].neighbours.push_back(v);

        // Select node 'v' and add 'u' to its neighbours
        nodes[v].neighbours.push_back(u);
    }

    void print(){
        // Iterate through each node and print its neighbours
        for(int i=0; i<n; i++){
            cout << "Node " << nodes[i].label << " -> ";
            for(int neighbour : nodes[i].neighbours){
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph* g = new Graph;
    g->initializeNodes();

    // Add edges to the graph
   g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(1, 4);
    g->addEdge(2, 3);
    g->addEdge(2, 6);
    g->addEdge(4, 6);
    g->addEdge(4, 7);
    g->addEdge(4, 8);
    g->addEdge(5, 6);
    g->addEdge(1, 5);
    g->addEdge(5, 7);
    g->addEdge(5, 8);

    // Print the graph adjacency list
    g->print();

    delete g; // Clean up memory allocated with 'new'
    return 0;
}
