#include <iostream>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    bool** adjMatrix; // Adjacency matrix representation

public:
    // Constructor
    Graph(int vertices) : V(vertices) {
        // Dynamically allocate memory for the adjacency matrix
        adjMatrix = new bool*[V];
        for (int i = 0; i < V; ++i) {
            adjMatrix[i] = new bool[V];
            // Initialize all entries to false (no edges initially)
            for (int j = 0; j < V; ++j) {
                adjMatrix[i][j] = false;
            }
        }
    }

    // Method to add an edge between two vertices (undirected graph)
    void addEdge(int u, int v) {
        adjMatrix[u][v] = true; // There is an edge from u to v
        adjMatrix[v][u] = true; // Since it's an undirected graph, add the reverse edge
    }

    // Method to print the graph
    void printGraph() {
        cout << "Adjacency matrix:" << endl;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Destructor to free memory
    ~Graph() {
       // Deallocate memory for the adjacency matrix
    for (int i = 0; i < V; ++i) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    // Deallocate memory for the array of pointers
    delete[] adjMatrix;
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Print the graph
    graph.printGraph();

    return 0;
}


