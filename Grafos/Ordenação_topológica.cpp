#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

// Estrutura para representar uma aresta do grafo
struct no {
    int destino;
    int peso = 1;
};

// Função para realizar a busca em profundidade (DFS)
void DFS_VISIT(list<no> adj[], int u, int color[], int &time, int f[]) {
    time += 1;
    color[u] = 1; // Marca u como visitado (cinza)

    list<no>::iterator it;
    for (it = adj[u].begin(); it != adj[u].end(); it++) {
        int v = it->destino;
        if (color[v] == 0) { // Se o vértice v ainda não foi visitado
            DFS_VISIT(adj, v, color, time, f); // Chama recursivamente DFS_VISIT para v
        }
    }

    color[u] = 2; // Marca u como finalizado (preto)
    time += 1;
    f[u] = time;
}

// Função para realizar a busca em profundidade (DFS) em todos os vértices
void dfs(list<no> adj[], int nVertices, int color[], int f[]) {
    int time = 0;

    // Inicializa os arrays color e f
    for (int u = 0; u < nVertices; u++) {
        color[u] = 0; // Branco (não visitado)
    }

    // Chama DFS_VISIT para cada vértice não visitado
    for (int u = 0; u < nVertices; u++) {
        if (color[u] == 0) {
            DFS_VISIT(adj, u, color, time, f);
        }
    }
}

// Função para mostrar a ordenação topológica do grafo
void ordenacao_topologica(int f[], int nVertices) {
    // Cria um array para armazenar a ordem correta dos vértices
    int ordem[nVertices];

    // Preenche a lista com os vértices em ordem decrescente de tempo de finalização
    for (int i = 0; i < nVertices; ++i) {
        ordem[i] = i; // Inicializa com os índices dos vértices
    }

    // Ordena os vértices com base no tempo de finalização (ordem decrescente)
    sort(ordem, ordem + nVertices, [&](int a, int b) {
        return f[a] > f[b];
    });

    // Mostra a ordenação topológica
    for (int i = 0; i < nVertices; i++) {
        cout << ordem[i] << " "; // Mostra o vértice
    }
    cout << endl;
}

int main() {
    int nVertices, orientado;
    int u, v;
    cin >> nVertices >> orientado;

    // Lista de adjacências para armazenar o grafo
    list<no> adj[nVertices];

    // Leitura das arestas e construção da lista de adjacências
    cin >> u >> v;
    while (u != -1 && v != -1)
    {
        no aux;
        aux.destino = v;
        adj[u].push_back(aux);
        if (orientado == 0)
        {
            aux.destino = u;
            adj[v].push_back(aux);
        }
        cin >> u >> v;
    }
    
    // Arrays para armazenar informações sobre o grafo
    int color[nVertices]; // Cor de cada vértice no DFS (0 - branco, 1 - cinza, 2 - preto)
    int f[nVertices];     // Tempo de finalização de cada vértice

    // Realiza a busca em profundidade (DFS) no grafo
    dfs(adj, nVertices, color, f);

    // Mostra a ordenação topológica do grafo
    ordenacao_topologica(f, nVertices);

    return 0;
}
