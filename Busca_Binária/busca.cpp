#include <iostream>
using namespace std;

int busca_bin(int vetor[], int size, int begin, int find)
{
  if (size >= 1)
  {
    int meio = begin + (size - 1) / 2;

    if (vetor[meio] == find)
      return meio;
    
    if (find < vetor[meio]) 
      return busca_bin(vetor, meio - 1, begin, find); // Size passa a ser metade para baixo
    else
      return busca_bin(vetor, size - meio, meio + 1, find); // Size passa a ser metade para cima
  }

  return -1;
}


int main()
{
  int vetor[10]; // Armazena os nums
  int size, find; // Tamhno / num para encontrar
  int res; // Recebe o valor que retorna da func

  // Entrada do tamanho
  cin >> size;

  // Entrada dos nums
  for (int i = 0; i < size; i++)
    cin >> vetor[i];
  
  // Entrada do num a ser encontrado
  cin >> find;

  // Chama a func
  res = busca_bin(vetor, size, 0, find);

  // Exibe
  cout << res << endl;

  return 0;
}