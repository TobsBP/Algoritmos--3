#include <iostream>
using namespace std;

struct dado
{
    int k; // chave
    int status; // 0: vazio   1: ocupado
};

int hash_aux(int k, int m)
{
    int h = k % m;

    // Caso de num negativo soma m
    if (h < 0)
        h += m;
    return h;
};

int hash_1(int k, int i, int m)
{
    return (hash_aux(k,m) + i) % m;
};

int hash_insert(dado t[], int m, int k)
{
    int j;
    int i = 0;

    do
    {
        j = hash_1(k,i,m);
        if (t[j].status != 1)
        {
            t[j].k = k;
            t[j].status = 1;

            return j;
        } else 
            i = i + 1;
        
    } while (i != m);

    return -1;    
};

int main()
{
    int k; // Chave 
    int m; // Tamanho da tabela hash
    int i = 0; // Contador
    dado t[20]; // Tabela hash

    cin >>  m >> k;

    // Defini os vetores vazios e ocupados
    for (i = 0; i < m; i++)
    {
        t[i].status = 0;
        t[i].k = -1;
    }
    
    // Entrada da chave na funcao
    while (k != 0)
    {
        hash_insert(t, m, k);
        cin >> k;
    }

    // Exibe
    for (i = 0; i < m; i++)
    {
        cout << t[i].k << " ";
    }

    return 0;
}