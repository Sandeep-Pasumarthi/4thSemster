#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src, dest, weight;
};

class Graph
{
public:
    int V, E;
    Edge *edge;
};

class subset
{
public:
    int parent;
    int rank;
};

Graph *createGraph(int, int);
int find(subset[], int);
void Union(subset[], int, int);
int myComp(const void *, const void *);
void KruskalMST(Graph *);

int main()
{
    int v, e;

    cout << "Enter number of vertices: - ";
    cin >> v;

    cout << "Enter number of edges: - ";
    cin >> e;

    Graph *graph = createGraph(v, e);

    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cout << "Enter edge " << i + 1 << " source: - ";
        cin >> s;

        cout << "Enter edge " << i + 1 << " destination: - ";
        cin >> d;

        cout << "Enter edge " << i + 1 << " weight: - ";
        cin >> w;

        graph->edge[i].src = s;
        graph->edge[i].dest = d;
        graph->edge[i].weight = w;

        cout << '\n';
    }

    KruskalMST(graph);

    return 0;
}

Graph *createGraph(int V, int E)
{
    Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;

    graph->edge = new Edge[E];

    return graph;
}

int find(subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void *a, const void *b)
{
    Edge *a1 = (Edge *)a;
    Edge *b1 = (Edge *)b;

    return a1->weight > b1->weight;
}

void KruskalMST(Graph *graph)
{
    int V = graph->V;
    Edge result[V];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    for (int i = 0; i < graph->E; i++)
    {
        cout << graph->edge[i].weight << " ";
    }

    subset *subsets = new subset[(V * sizeof(subset))];

    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E)
    {
        Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    cout << "Following are the edges in the constructed MST" << endl;
    int minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        cout << result[i].src << " ----- " << result[i].dest << " == " << result[i].weight << endl;
        minimumCost = minimumCost + result[i].weight;
    }

    cout << "Minimum Cost Spanning Tree: " << minimumCost << endl;
}