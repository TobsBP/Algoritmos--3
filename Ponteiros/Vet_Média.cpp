#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int *vetor, soma = 0; 
  int *p, tam; //Ponteiro / Tamanho
  float media; 

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

  // Soma todos os valores do vetor com ponteiro
  for (int i = 0; i < tam; i++)
  {
    soma += *p;
    p++;
  }

  // Calcula a meida
  media = float(soma) / tam;

  // Exibe
  cout << setprecision(2) << fixed;
  cout << media << endl;

  return 0;
}