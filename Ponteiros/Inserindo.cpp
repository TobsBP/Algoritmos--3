#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int *v; // Vetor
  int *p; // Ponteiro
  int tam; // Tamanho do ponteiro

  // Entrda
  cin >> tam;

  // Aloca memoria
  v = new int[tam];

  // define o endereço do ponteiro
  p = v;

  // Entrada pelo ponteiro
  for (int i = 0; i < tam; i++)
  {
    cin >> *p;
    p++;
  }

  // define o endereço do ponteiro
  p = v;

  // Exibe com  um ponteiro
  for (int i = 0; i < tam; i++)
  {
    cout << *p << " ";
    p++;
  }
  cout << endl;
  
  // Libera a memoria
  delete v;

  return 0;
}