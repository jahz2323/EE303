#include <Energia.h>

// ... (other code)

void dijkstra(Queue<int, 5>& myQueue, int graph[5][5], int src, int dest) {
  int dist[5];  // Array to store the shortest distances
  bool sptSet[5];  // Array to track whether a vertex is included in the shortest path tree

  // Initialize arrays
  for (int i = 0; i < 5; i++) {
    dist[i] =  0x7FFFFFFF;
    sptSet[i] = false;
  }

  // Distance from source vertex to itself is always 0
  dist[src] = 0;

  // Find the shortest path for all vertices
  for (int count = 0; count < 5 - 1; count++) {
    // Find the minimum distance vertex from the set of vertices not yet processed
    int u = -1;
    for (int v = 0; v < 5; v++) {
      if (!sptSet[v] && (u == -1 || dist[v] < dist[u]))
        u = v;
    }

    // Mark the selected vertex as processed
    sptSet[u] = true;

    // Update the distance value of the adjacent vertices
    for (int v = 0; v < 5; v++) {
      if (!sptSet[v] && graph[u][v] && dist[u] !=  0x7FFFFFFF && dist[u] + graph[u][v] < dist[v]) {
        dist[v] = dist[u] + graph[u][v];
      }
    }
  }

  // Print the shortest distances
  Serial.println("Shortest distances from source vertex:");
  for (int i = 0; i < 5; i++) {
    Serial.print(dist[i]);
    Serial.print(" ");
  }
  Serial.println();

  // Enqueue the shortest path to the destination vertex
  int current = dest;
  myQueue.enqueue(current);
  while (current != src) {
    for (int i = 0; i < 5; i++) {
      if (graph[i][current] && dist[current] - graph[i][current] == dist[i]) {
        myQueue.enqueue(i);
        current = i;
        break;
      }
    }
  }
}

void setup() {
  // ... (previous setup code)

  // Weighted graph representation (adjust weights as needed)
  int graph[5][5] = {
    {0, 1, 4, 0, 0, 0, 0},
    {1, 0, 2, 5, 0, 0, 0},
    {4, 2, 0, 1, 3, 0, 0},
    {0, 5, 1, 0, 2, 6, 0},
    {0, 0, 3, 2, 0, 1, 4},
    {0, 0, 0, 6, 1, 0, 3},
    {0, 0, 0, 0, 4, 3, 0}
  };

  // Source and destination vertices
  int src = 0;
  int dest = 4;

  // Run Dijkstra's algorithm and enqueue the shortest path to the destination
  dijkstra(myQueue, graph, src, dest);
}
