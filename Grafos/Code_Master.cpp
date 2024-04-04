#include <iostream>
#include <list>

using namespace std;

struct no
{
    int v; // vertice adjacente
    int peso; // peso da aresta
};

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado){
  no aux; // Struct auxiliar

  aux.v = v; // Valor de 'v' auxliar passa a ser v
  aux.peso = p;   // Valor de 'p' auxliar passa a ser p
  adj[u].push_back(aux); // Adciona a aresta lista de adjacências

  if (orientado == 0) // Se não for orientado
  {
    aux.v = u; // Define o vertice de origem da arestaa na na variavel auxliar
    adj[v].push_back(aux); // Adciona aresta na lista de adjacências não orientada
  }
}

int main()
{
  int num_caminhos, origem, destino, peso = 1, i;
  list<no>::iterator p;
  list<no> adj[100];
  int orientado = 0;  // = 0 -> não orientado / = 1 orientado
  int num_cidade;

  cin >> num_caminhos >> num_cidade;

  // Entrada das informações
  for (int i = 0; i < num_caminhos; i++)
  {
    cin >> origem >> destino;
    cria_aresta(adj, origem, destino, peso, orientado); // Cria as arestas no grafo
  }

  for (i = 0; i < num_caminhos; i++)
  {
    for (p = adj[i].begin(); p != adj[i].end(); p++)
    {
      cout << p->v << " " << i << " " << p->peso << endl;
    }
  }

  // Limpa a memoria
  i = 0;
  while (!adj[i].empty()) 
  {
    adj[i].pop_front();
    i++;
  }


  return 0;
}