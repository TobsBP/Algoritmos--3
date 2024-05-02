#include <iostream>
#include <string>

using namespace std;

int main()
{
  string nome[10];
  int nPessoas, i, x;
  int adj[100][100];

  cin >> nPessoas;
  
  for (i = 0; i < nPessoas; i++)
  {
    getline(cin >> ws, nome[i]);
  }
  
  for (i = 0; i < nPessoas; i++)
  {
    for (int j = 0; j < nPessoas; j++)
    {
      adj[i][j] = 0;  
    }
  }
  
  for (i = 0; i < nPessoas; i++)
  {
    cin >> x;
    while (x != -1)
    {
      adj[i][x] = 1;
      cin >> x;
    }
  }
  
  cin >> x;

  for (i = 0; i < nPessoas; i++)
  {
    if(adj[i][x] == 1)
    {
      cout << nome[i] << endl;
    }
  }

  return 0;
}