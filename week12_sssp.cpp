#include <iostream>
#include <climits>

constexpr int V = 6; // Number of vertices

int minDistance(const int distances[], const bool visited[]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && distances[v] <= min) {
            min = distances[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(const int graph[V][V], int source) {
    int distances[V]; // Store the shortest distance from source to each city
    bool visited[V] = {false}; 

    for (int i = 0; i < V; i++) {
        distances[i] = INT_MAX;
    }
    distances[source] = 0;

    // Find the shortest path for all cities
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(distances, visited);

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && distances[u] != INT_MAX &&
                distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distances
    std::cout << "Shortest distances from source city " << source << "\n";
    for (int i = 0; i < V; i++) {
        std::cout << "City " << source <<" --> " << i << ": " << distances[i] << "\n";
    }
}

int main() {
    const int graph[V][V] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    const int source = 0; // Choose the source city

    dijkstra(graph, source);

    return 0;
}
