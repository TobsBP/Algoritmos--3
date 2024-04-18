#include <iostream>

using namespace std;

int main()
{
  int grafo[100][100];
  int n, m;

  cin >> n >> m;

  // Inicializa a matriz com zeros, obs o problema disse que começa no 1
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      grafo[i][j] = 0;
    }
  }

  int j = 0, k = 0;
  for (int i = 1; i <= m; i++) // Loop deve iterar sobre o número de arestas, não de vértices
  {
    cin >> j >> k;
    grafo[j][k] = 1; // Aresta de j para k
    grafo[k][j] = 1; // Aresta de k para j
  }

  // Imprime a matriz de adjacência
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cout << grafo[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
