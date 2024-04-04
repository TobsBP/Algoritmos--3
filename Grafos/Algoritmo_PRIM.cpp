#include <iostream>
#include <list>
using namespace std;

#define INT_MAX 99999

struct no
{
    int origem;
    int destino;
    int peso;
};

void mst_prim(list<no> adj[], int nVertices, int start)
{
    bool intree[nVertices];
    int distance[nVertices];
    int parent[nVertices];

    for (int u = 0; u < nVertices; u++)
    {
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
    }

    distance[start] = 0;
    int v = start;

    while (intree[v] == false)
    {
        intree[v] = true;
        list<no>::iterator p;
        for(p = adj[v].begin(); p != adj[v].end(); ++p)
        {
            int destino = p->destino;
            int weight = p->peso;
            if(distance[destino] > weight && intree[destino] == false)
            {
                distance[destino] = weight;
                parent[destino] = v;
            }
        }
        v = 0;
        int dist = INT_MAX;
        for (int u = 0; u < nVertices; u++)
        {
            if(intree[u] == false && dist > distance[u])
            {
                dist = distance[u];
                v = u;
            }
        }
    }
}

int main()
{
    int nVertices, orientado, start;

    cin >> nVertices >> orientado >> start;

    list<no> *adj = new list<no>[nVertices];
    int origem, destino, peso;
    while(cin >> origem >> destino >> peso && origem != -1 && destino != -1 && peso != -1)
    {
        no aux;
        aux.origem = origem;
        aux.destino = destino;
        aux.peso = peso;
        adj[origem].push_back(aux);
        if(orientado == 0)
        {
            aux.origem = destino;
            aux.destino = origem;
            adj[destino].push_back(aux);
        }
    }

    mst_prim(adj, nVertices, start);

    delete [] adj; 
    return 0;
}