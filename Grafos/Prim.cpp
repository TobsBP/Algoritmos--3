#include <iostream>
#include <list>

using namespace std;

struct Edge {
    int destination;
    int weight;
};

const int MAX_INT = 1000000; // Um valor grande para representar infinito

void MST_PRIM(list<Edge>* G, int numVertices, int start) {
    bool* intree = new bool[numVertices];
    int* distance = new int[numVertices];
    int* parent = new int[numVertices];

    for (int u = 0; u < numVertices; ++u) {
        intree[u] = false;
        distance[u] = MAX_INT;
        parent[u] = -1;
    }

    distance[start] = 0;
    int v = start;

    while (!intree[v]) {
        intree[v] = true;

        for (const Edge& p : G[v]) {
            int destination = p.destination;
            int weight = p.weight;

            if (distance[destination] > weight && !intree[destination]) {
                distance[destination] = weight;
                parent[destination] = v;
            }
        }

        v = 0;
        int dist = MAX_INT;

        for (int u = 0; u < numVertices; ++u) {
            if (!intree[u] && dist > distance[u]) {
                dist = distance[u];
                v = u;
            }
        }
    }

    delete[] intree;
    delete[] distance;
    delete[] parent;
}

int main() {
    // Exemplo de uso
    int numVertices = 5;
    list<Edge>* graph = new list<Edge>[numVertices];

    // Adicione as arestas e pesos aqui
    graph[0].push_back({1, 2}); // Exemplo: Aresta de 0 para 1 com peso 2
    graph[1].push_back({0, 2}); // Se o grafo for não direcionado, adicione a aresta inversa
    // Adicione outras arestas e pesos conforme necessário

    int startVertex = 0;
    MST_PRIM(graph, numVertices, startVertex);

    delete[] graph;
    
    return 0;
}
