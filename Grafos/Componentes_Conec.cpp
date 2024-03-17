#include <iostream>
#include <list>
using namespace std;

struct no
{
  int origem;  // Vert
  int destino; // linha
  bool visitado = false;
};

void bfs(list<no> lista_adjacente[], int no_inicio, int n, int &vertices_visitados)
{
  list<no>::iterator p;
  list<int> lista_inicial; // lista principal para bfs
  // marcando o primeiro nó visitado e colocando-o na lista
  bool visitado[n] = {false};
  visitado[no_inicio] = true;
  lista_inicial.push_back(no_inicio);
  vertices_visitados = 1;

  // loop que percorre a lista
  while (!lista_inicial.empty())
  {
    // retira um vertice da lista e o imprime
    int no_atual = lista_inicial.front();
    lista_inicial.pop_front();

    for (int i = 0; i < n; i++)
    {
      for (p = lista_adjacente[no_atual].begin(); p != lista_adjacente[no_atual].end(); p++)
      {
      if (!visitado[p->destino])
      {
        visitado[p->destino] = true;
        vertices_visitados++; // contador para dizer se sao conexos ou nao
        lista_inicial.push_back(p->destino);
      }
      }
    }
  }
}

int main()
{
  no aux;
  list<no>::iterator p;
  list<no> adjs[100];
  int quant_vert;
  int start;
  int i = 0;

  cin >> quant_vert >> start;
  cin >> aux.origem >> aux.destino;

  while (aux.origem != -1 && aux.destino != -1)
  {
    adjs[start + i].push_back(aux);
    cin >> aux.origem >> aux.destino;
    i++;
  }

  for (i = 0; i < quant_vert; i++)
  {
    for (p = adjs[i].begin(); p != adjs[i].end(); p++)
    {
      cout << p->origem << " " << p->destino << endl;
    }
  }

  return 0;
}