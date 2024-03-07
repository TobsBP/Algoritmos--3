#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int *vetor, cont = 0; 
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

  // Descobre o positivo e par com ponteiro
  for (int i = 0; i < tam; i++)
  {
    if (*p % 2 == 0 && *p > 0)
      cont++;
    p++;
  }

  // Exibe
  cout << cont << endl;

  return 0;
}