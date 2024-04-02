#include <iostream>
#include <list>

using namespace std;

#define VERTICES 4 // Quantidade de Vertices

bool eh_conexo(bool adj[VERTICES][VERTICES], int num_vertices)
{
  list<int> fila_espera; // Fila de espera aguardando ate ser visitado
  bool visitado[num_vertices];
  int atual;

  // Setando que ninguem foi visitado
  for (int i = 0; i < num_vertices; i++)
    visitado[i] = false;

  fila_espera.push_back(0);

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

void bfs(bool adj[VERTICES][VERTICES], int num_vertices, int origem)
{
  list<int> fila_espera; // Fila de espera aguardando ate ser visitado
  bool visitado[num_vertices];
  int atual;

  // Setando que ninguem foi visitado
  for (int i = 0; i < num_vertices; i++)
    visitado[i] = false;

  fila_espera.push_back(origem);

  while (!fila_espera.empty())
  {
    atual = fila_espera.front(); // -> seria a origem e assim por diante
    visitado[atual] = true;

    // Se tiver uma conexão, vai para fila
    for (int i = 0; i < num_vertices; i++)
    {
      if(adj[atual][i] == true && visitado[i] == false)
        {
          fila_espera.push_back(i); // fila -> 0,2 na fila
        } 
    }
    fila_espera.pop_front();
    cout << atual << endl;
  }
  
}

int main()
{
  bool matriz_adj[VERTICES][VERTICES]; // Booleano pois não é direcionado e o peso é fixo
  
  // Definindo falso para os vertices, ou seja eles não tem conexões
  for (int i = 0; i < VERTICES; i++)
  {
    for (int j = 0; j < VERTICES; j++)
    {
      matriz_adj[i][j] = false;
    }
  }

  // int i = 0, j = 0;

  // while (i != -1 && j != -1)
  // {
  //   cin >> i >> j;
  //   matriz_adj[i][j] = true; // Como não é direcionada, ela é espelhada
  //   matriz_adj[j][i] = true; // Como não é direcionada, ela é espelhada
  // }
  
  // Um grafo definido, sendo 0 -> 1 -> 2 -> 3 
  matriz_adj[0][1] = true;
  matriz_adj[1][0] = true;
  matriz_adj[2][3] = true;
  matriz_adj[3][2] = true;
  matriz_adj[1][2] = true;
  matriz_adj[2][1] = true;

  bfs(matriz_adj, 4, 3);

  if (eh_conexo(matriz_adj, 4))
  {
    cout << "Conexo" << endl;
  }else
    cout << "Nao conexo" << endl;

  return 0;
}