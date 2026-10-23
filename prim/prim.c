
#include <stdio.h>

#define MAX_VERTICES 20
#define INF 999999

// Implement Prim's algorithm
void prim(int graph[MAX_VERTICES][MAX_VERTICES], int n)
{
    int TV[MAX_VERTICES] = {0};  // Set of selected vertices
    int edges = 0;               // Number of selected edges
    int u, v;

    // Start with vertex 0
    TV[0] = 1;

    // Continue until n-1 edges are selected
    while (edges < n - 1)
    {
        int min = INF;
        int from = -1, to = -1;

        // Find the least-cost eligible edge
        for (u = 0; u < n; u++)
        {
            if (TV[u])
            {
                for (v = 0; v < n; v++)
                {
                    if (!TV[v] && graph[u][v] < min)
                    {
                        min = graph[u][v];
                        from = u;
                        to = v;
                    }
                }
            }
        }

        // Stop if no eligible edge exists
        if (from == -1)
            break;

        // Add the selected edge to T
        printf("Edge: %d - %d, Cost: %d\n", from, to, min);

        // Add the new vertex to TV
        TV[to] = 1;
        edges++;
    }

    // Check whether a spanning tree was formed
    if (edges < n - 1)
        printf("Not a spanning tree\n");
}

int main(void)
{
    // Adjacency matrix; INF represents a missing edge
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {INF, 2,   INF, 6,   INF},
        {2,   INF, 3,   8,   5},
        {INF, 3,   INF, INF, 7},
        {6,   8,   INF, INF, 9},
        {INF, 5,   7,   9,   INF}
    };

    // Execute Prim's algorithm on 5 vertices
    prim(graph, 5);

    return 0;
}
