#include <iostream>
#include <list>

using namespace std;

#define VERTICES 10

bool bfs(bool adj[VERTICES][VERTICES], int num_vert ,int origem)
{
  list<int> fila_espera;
  bool visitado[num_vert];
  int atual;

  for (int i = 0; i < num_vert; i++)
    visitado[i] = false;
  
  fila_espera.push_back(origem);

  while (!fila_espera.empty())
  {
    atual = fila_espera.front();
    visitado[atual] = true;

    for (int i = 0; i < num_vert; i++)
    {
      if (adj[atual][i] == true && visitado[i] == false)
      {
        fila_espera.push_back(i);
      }
    }
    fila_espera.pop_front();
  }

  for (int i = 0; i < num_vert; i++)
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
  bool matriz_adj[VERTICES][VERTICES];
  int num_vert, origem;

  for (int i = 0; i < VERTICES; i++)
  {
    for (int j = 0; j < VERTICES; j++)
    {
      matriz_adj[i][j] = false;
    }
  }

  cin >> num_vert >> origem;

  int i = 0, j = 0;
  while (i != -1 && j != -1)
  {
    cin >> i >> j;
    matriz_adj[i][j] = true;
    matriz_adj[j][i] = true;
  }
  
  if (bfs(matriz_adj, num_vert, origem))
  {
    cout << "Conexo" << endl;
  }else
    cout << "Nao conexo" << endl;

  return 0;
}