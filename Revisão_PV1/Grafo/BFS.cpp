#include <iostream>
#include <list>

using namespace std;

// Definição de uma estrutura para representar uma aresta do grafo
struct no
{
  int v; // Destino
  int peso;
};

// Função para adicionar uma aresta à lista de adjacência
void make_aresta(list<no> adj[], int u, int v, int p)
{
  no aux;

  //  Cria aresta orientada
  aux.v = v;
  aux.peso = p;
  adj[u].push_back(aux);

  // Como não é orientado ela volta também
  aux.v = u;
  adj[v].push_back(aux);
}

// Função para realizar a travessia em largura (BFS) no grafo
void bfs(list<no> adj[], int nVertices, int s)
{
  char state[nVertices];
  int pai[nVertices]; // So usa se quiser saber o pai do vertice
  list<int> Q;
  int u, v;

  // Inicializa os estados dos vértices como "não descoberto" e seus pais como -1
  for (u = 0; u < nVertices; u++)
  {
    if (u != s)
    {
      state[u] = 'u'; // undiscovered​
      pai[u] = -1; // sem pais  ​
    }
  }

  // Marca o vértice inicial como "descoberto" e adiciona-o à fila
  state[s] = 'd'; // discovered​
  pai[s] = -1;
  Q.push_back(s);

  // Enquanto a fila não estiver vazia
  while(!Q.empty())
  {
    // Retira o vértice da frente da fila
    u = *Q.begin();
    Q.pop_front();
    cout << u << endl;

    // Percorre os vértices adjacentes ao vértice u
    list<no>::iterator p;
    for (p = adj[u].begin();p != adj[u].end(); p++)
    {
      v = p->v;
      cout <<  u << " " << v << endl;

      // Se o vértice v ainda não foi descoberto
      if(state[v] == 'u')
      {
        // Marca v como "descoberto", define seu pai como u e o adiciona à fila
        state[v] = 'd';
        pai[v] = u;
        Q.push_back(v);
      }
    }
  }

  // Marca u como "processado" (fora do loop while)
  state[u] = 'p'; // processed
  cout << pai[s] << endl; // Não precisa usar isso so coloquei para tirar o erro de variavel não usada
}

int main()
{
  int v, u, p;
  int nVertice;
  int start;

  // Leitura do número de vértices e do vértice inicial
  cin >> nVertice >> start;

  // Lista de adjacências para armazenar o grafo
  list<no> adj[nVertice];

  // Leitura das arestas do grafo e construção da lista de adjacências
  cin >> u >> v >> p;
  while (v != -1 && u != -1 && p != -1)
  {
    make_aresta(adj, u, v, p);
    cin >> u >> v >> p;  
  }

  // Chamada da função bfs para realizar a travessia em largura no grafo
  bfs(adj, nVertice, start);

  return 0;
}
