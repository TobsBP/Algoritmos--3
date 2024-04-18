#include <iostream>
#include <list>
using namespace std;

#define VERTICE 100

void dfs(int adj[VERTICE][VERTICE], bool visited[], int vertices, int curr) 
{
  visited[curr] = true;

  for (int i = 1; i <= vertices; i++)
  {
    if(adj[curr][i] != 0 && visited[i] == false) // Ou seja se existir peso existe conexão e não foi visitado
    {
      dfs(adj, visited, vertices, i);
    }
  } 
}

int main()
{
  int grafo[VERTICE][VERTICE];
  bool visited[VERTICE];
  int nCidades, nCaminhos;

  cin >> nCidades >> nCaminhos;

  for (int i = 1; i <= nCidades; i++)
  {
    visited[i] = false;
    for (int j = 1; j <= nCidades; j++)
    {
      grafo[i][j] = 0; // Inicializando com 0
    }
  }

  // Entrada das pontes bidirecionais
  int a, b;
  for (int i = 1; i <= nCaminhos; i++)
  {
    cin >> a >> b;
    grafo[a][b] = 1;
    grafo[b][a] = 1;
  }

  // ponte destruida
  int x, y;
  cin >> x >> y;
  grafo[x][y] = 0;
  grafo[y][x] = 0;

  //Descrobre todas as cidades que se tornarão inacessíveis de X
  dfs(grafo, visited, nCidades, x);
    
  for (int i = 1; i <= nCidades; i++)
  {
    if (!visited[i])
    {
      cout << i << " ";
    }
  }
  cout << endl;

  return 0;
}
