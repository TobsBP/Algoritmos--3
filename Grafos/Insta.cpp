#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
  bool grafo[100][100];
  string nome[10];
  int n;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      grafo[i][j] = false;
    }
  }

  for (int i = 0; i < n; i++)
  {
    getline(cin >> ws, nome[i]);
  }

  int j = 0;
  for (int i = 0; i < n; i++)
  {
    while (j != -1)
    {
      cin >> j;
      grafo[i][j] = true;
    }
  }

  int find;
  
  cin >> find;

  for (int i = 0; i < n; i++)
  {
    if (grafo[i][find])
    {
      cout << nome[i] << endl;
    }
  }
  

  return 0;
}