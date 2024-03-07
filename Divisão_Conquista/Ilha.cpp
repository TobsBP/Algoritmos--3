#include <iostream>
using namespace std;

int buscaBinaria(string arr[], int inicio, int fim, string pista) {
    if (fim >= inicio) {
        int meio = inicio + (fim - inicio) / 2;

        if (arr[meio] == pista)
            return meio;

        if (arr[meio] > pista)
            return buscaBinaria(arr, inicio, meio - 1, pista);

        return buscaBinaria(arr, meio + 1, fim, pista);
    }
    return -1;
}

int main()
{

  return 0;
}