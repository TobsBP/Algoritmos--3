#include <iostream>
#include <list>
#include <climits>

using namespace std;

struct no
{
    int peso;
    int destino;
};

void cria_aresta(list<no> adj[], int origem, int destino, int peso, int orientado)
{
    no aux;

    aux.destino = destino;
    aux.peso = peso;
    adj[origem].push_back(aux);

    if (orientado == 0)
    {
        aux.destino = origem;
        adj[destino].push_back(aux);
    }
}

void prim(list<no> adj[], int nCidades, int start, int &custo)
{
    bool intree[nCidades];
    int distance[nCidades];
    int parent[nCidades];
    int v, u, destino, weight;
    int dist;

    for (u = 0; u < nCidades; u++)
    {
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
    }

    distance[start] = 0;
    v = start;

    while (intree[v] == false)
    {
        intree[v] = true;
        list<no>::iterator p;
        for (p = adj[v].begin(); p != adj[v].end(); p++)
        {
            destino = p->destino;
            weight = p->peso;
            if (distance[destino] > weight && intree[destino] == false)
            {
                distance[destino] = weight;
                parent[destino] = v;
            }
        }
        v = 0;
        dist = INT_MAX;
        for (u = 0; u < nCidades; u++)
        {
            if (intree[u] == false && dist > distance[u])
            {
                dist = distance[u];
                v = u;
            }
        }
    }

    // Atualiza o custo com o peso da última aresta adicionada
    for (u = start; u < nCidades; u++)
    {
        if (parent[u] != -1)
        {
            custo += distance[u];
        }
    }
}

int main()
{
    int nCidades, destino, orientado = 0;
    int origem, nConex;
    int peso, custo = 0;

    cin >> nCidades >> nConex;

    list<no>adj[nCidades];

    // Entrada dos dados das arestas
    for (int i = 0; i < nConex; i++)
    {
        cin >> origem >> destino >> peso;
        origem--; // Ajuste para começar em 0
        destino--; // Ajuste para começar em 0
        cria_aresta(adj, origem, destino, peso, orientado);
    }

    // Chama a função prim apenas uma vez, começando de um vértice arbitrário
    prim(adj, nCidades, 0, custo);

    cout << custo << endl;

    return 0;
}
