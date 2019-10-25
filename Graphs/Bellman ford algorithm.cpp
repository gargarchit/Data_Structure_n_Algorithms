#include <iostream>
#define inf 1e9
using namespace std;

class Edge
{
    public:
    int src, dest, weight;
};

class Graph
{
public:
    int v, e;
    Edge *edge;

    Graph(int v, int e)
    {
        this->v = v;
        this->e = e;
        edge = new Edge[e];
    }

    void addEgde(int u, int v, int w, int count)
    {
        edge[count].src = u;
        edge[count].dest = v;
        edge[count].weight = w;
    }

    void BellmanFord(int src)
    {
        int distance[v];
        for (int i = 0; i < v; i++)
        {
            if (i == src)
            {
                distance[i] = 0;
            }
            else
            {
                distance[i] = inf;
            }
        }

        for (int i = 0; i < v - 1; i++)
        {
            for (int i = 0; i < e; i++)
            {
                int src = edge[i].src;
                int dest = edge[i].dest;
                int weight = edge[i].weight;

                if (distance[src] != inf and distance[src] + weight < distance[dest])
                {
                    distance[dest] = distance[src] + weight;
                }
            }
        }

        for (int i = 0; i < e; i++)
        {
            int src = edge[i].src;
            int dest = edge[i].dest;
            int weight = edge[i].weight;

            if (distance[src] != inf and distance[src] + weight < distance[dest])
            {
                cout << "negetive edge cycle present";
                return;
            }
        }

        for (int i = 0; i < v; i++)
        {
            cout << i << " - " << distance[i] << endl;
        }
    }
};

int main()
{
    int v, e;
    cin >> v >> e;
    Graph g(v, e);
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        g.addEgde(u, v, wt, i);
    }

    g.BellmanFord(0);
}