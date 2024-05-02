#include <iostream>
#include <list>

using namespace std;

#define VERTICES 10

// Definição de uma estrutura para representar uma aresta do grafo
struct no
{
  int v; // Destino
  int peso;
};

bool eh_conexo(bool adj[VERTICES][VERTICES], int num_vertices, int start)
{
  list<int> fila_espera; // Fila de espera aguardando ate ser visitado
  bool visitado[num_vertices];
  int atual = start;

  // Setando que ninguem foi visitado
  for (int i = 0; i < num_vertices; i++)
    visitado[i] = false;

  fila_espera.push_back(atual);

  while (!fila_espera.empty())
  {
    atual = fila_espera.front(); // -> seria a origem e assim por diante
    visitado[atual] = true;

    // Se tiver uma conexão, vai para fila
    for (int i = 0; i < VERTICES; i++)
    {
      if(adj[atual][i] == true && visitado[i] == false)
        {
          fila_espera.push_back(i); // fila -> 0,2 na fila
        } 
    }
    fila_espera.pop_front();
  }

  for (int i = 0; i < num_vertices; i++)
  {
    if (visitado[i] == false)
    {
      return false;
    }
  }

  return true;
}

int main()
{
  bool adj[VERTICES][VERTICES];
  int nVertice, start;

  cin >> nVertice >> start;
  for (int i = 0; i < nVertice; i++)
  {
    for (int j = 0; j < nVertice; j++)
    {
      adj[i][j] = false;
    } 
  }

  int x, y;
  cin >> x >> y;
  while (x != -1 && y != -1)
  {
    adj[x][y] = true;
    adj[y][x] = true;
    cin >> x >> y;
  }
  
  // Chamada da função bfs para realizar a travessia em largura no grafo
  if (eh_conexo(adj, nVertice, start))
  {
    cout << "Conexo" << endl;
  }else
  {
    cout << "Nao conexo" << endl;
  }

  return 0;
}
