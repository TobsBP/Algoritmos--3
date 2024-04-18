#include <iostream>
using namespace std;

#define VERTICES 10

int main()
{
  bool adj[VERTICES][VERTICES]; // Depende da aplicação pode ser int
  int nVertices, nCaminhos, x, y;

  cin >> nVertices >> nCaminhos;

  for (int i = 1; i <= nVertices; i++) // Lembre-se caso as entradas estejam començando em 1 o for é assim
  {
    for (int j = 1; j <= nCaminhos; j++)
    {
      adj[i][j] = false;
    }
  }
  

  for (int i = 1; i <= nCaminhos; i++)
  {
    cin >> x >> y;
    adj[x][y] = true;
    adj[y][x] = true; // Usa se for bidirecional
  }
  
  // Imprime a matriz de adjacência
  for (int i = 1; i <= nCaminhos; i++)
  {
    for (int j = 1; j <= nCaminhos; j++)
    {
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}