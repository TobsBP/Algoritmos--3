#include <iostream>
#include <list>

using namespace std;

struct no
{
  int origem;
  int peso;
  int destino;
};

int main()
{
  int nCidades = 100, nCaminhos, m, n;


  // Cria um array de listas para representar a lista de adjacência
  list<int> *adj = new list<int>[nCidades];
  // Lê o número de cidades e o número de estradas
  cin >> nCidades >> nCaminhos;

  // Lê cada estrada e a adiciona à lista de adjacência
  for (int i = 0; i < nCaminhos; i++)
  {
    cin >> m >> n;
    adj[n].push_back(m); // Adiciona a aresta à lista de adjacência
    adj[m].push_back(n);
  }

  // Imprime a lista de adjacência para cada cidade
  for (int i = 1; i <= nCaminhos; i++)
  {
    cout << adj[i].size(); // Imprime o número de cidades adjacentes
    list<int>::iterator p;
    adj[i].sort(); // Ordena a lista de adjacência para cada cidade
    for (p = adj[i].begin(); p != adj[i].end(); p++)
    {
      cout << " " << *p; // Imprime as cidades adjacentes
    }
    cout << endl;
  }

  delete[] adj; // Libera a memória alocada para a lista de adjacência

  return 0;
}
