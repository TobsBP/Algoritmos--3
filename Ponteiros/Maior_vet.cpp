#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int *vetor, maior = -999; 
  int *p, tam; //Ponteiro / Tamanho 

  // Entrdaa do tam
  cin >> tam;

  // Aloca meomoria
  vetor = new int[tam];

  // Define o endereço da memoria para 0
  p = vetor;

  // Entrada no vetor com ponteiro
  for (int i = 0; i < tam; i++)
  {
    cin >> *p;
    p++;
  }
  
  // Define o enderoço da memoria para 0
  p = vetor;

  // Decobre o maior de todos os valores do vetor com ponteiro
  for (int i = 0; i < tam; i++)
  {
    if (*p > maior)
      maior = *p;

    p++;
  }

  // Exibe
  cout << maior << endl;

  return 0;
}