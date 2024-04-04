#include <iostream>
#include <list>

#define INT_MAX 100000

using namespace std;

struct no
{
    int peso;
    int destino;
    int origem;
};

int main()
{
    int nVertices, orientado; // 0 Para não irentado
    int destino, origem, peso = 1;
    no aux;

    cin >> nVertices >> orientado;
    list<no> *adj = new list<no>[nVertices];

    cin >> origem >> destino >> peso;
    while(origem != -1 && destino != -1 && peso != -1)
    {
        aux.origem = origem;
        aux.destino = destino;
        aux.peso = peso;
        adj[origem].push_back(aux);
        if (orientado == 0)
        {
            aux.origem = destino;
            aux.destino = origem;
            adj[destino].push_back(aux);
        }
        cin >> origem >> destino >> peso;
    }

    list<no>::iterator p;
    for (int i = 0; i < nVertices; i++)
    {
        for (p = adj[i].begin(); p != adj[i].end(); p++)
        {
            cout << p->origem << " " << p->destino << " " << p->peso << endl;
        }
    }

    return 0;
}