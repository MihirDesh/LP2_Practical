#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minKey(int key[], bool mstSet[], int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
}

int printMST(int parent[], vector<vector<int>> &graph, int V)
{
    int totalWeight = 0;
    cout << "Edge \tWeight\n";
    for (int i = 0; i < V; i++)
    {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
        totalWeight += graph[i][parent[i]];
    }
    return totalWeight;
}

void primMST(vector<vector<int>> &graph)
{
    int key[V];
    int parent[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet, V);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    int totalWeight = printMST(parent, graph, V);
    cout << "Total Weight of MST: " << totalWeight << endl;
}

int main()
{
    int V;

    cout << "Enter number of vertices: " << endl;
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Enter the adjacency matrix for the graph (enter 0 for no edge):\n";
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            cin >> graph[i][j];
        }
    }

    // Print the MST using Prim's algorithm
    primMST(graph, V);

    return 0;
}