#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct Graph_t {
    int V;
    bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* Graph_create(int V)
{
    Graph* g = malloc(sizeof(Graph));
    g->V = V;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = false;
        }
    }

    return g;
}

void Graph_destroy(Graph* g)
{
    free(g);
}

void Graph_addEdge(Graph* g, int v, int w)
{
    g->adj[v][w] = true;
}

void Graph_DFSUtil(Graph* g, int v, bool visited[])
{
    visited[v] = true;
    printf("%d ", v);

    for (int i = 0; i < g->V; i++) {
        if (g->adj[v][i] && !visited[i]) {
            Graph_DFSUtil(g, i, visited);
        }
    }
}

void Graph_DFS(Graph* g, int v)
{
    bool visited[MAX_VERTICES];
    for (int i = 0; i < g->V; i++) {
        visited[i] = false;
    }

    Graph_DFSUtil(g, v, visited);
}

int main()
{
    Graph* g = Graph_create(4);
    Graph_addEdge(g, 0, 1);
    Graph_addEdge(g, 0, 2);
    Graph_addEdge(g, 1, 2);
    Graph_addEdge(g, 2, 0);
    Graph_addEdge(g, 2, 3);
    Graph_addEdge(g, 3, 3);

    printf("Following is Depth First Traversal "
           "(starting from vertex 2):\n");
    Graph_DFS(g, 2);

    Graph_destroy(g);

    return 0;
}
