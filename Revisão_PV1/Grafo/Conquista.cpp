#include <iostream>
using namespace std;

int main()
{
  int adj[100][100];
  int i, j, nCidades;
  int a, b, nCaminhos;

  cin >> nCidades >> nCaminhos;

  for (i = 1; i <= nCidades; i++)
  {
    for (j = 1; j <= nCidades; j++)
    {
      adj[i][j] = 0;
    }
  }
  
  for (i = 1; i <= nCaminhos; i++)
  {
    cin >> a >> b;
    adj[a][b] = 1;
    adj[b][a] = 1;
  }
  
  for (i = 1; i <= nCidades; i++)
  {
    for (j = 1; j <= nCidades; j++)
    {
      cout << adj[i][j] << " "; 
    }
    cout << endl;
  }
  

  return 0;
}