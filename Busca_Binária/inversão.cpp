#include <iostream>
using namespace std;

int contar(int vetor[], int size)
{
  int cont = 0;

  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (vetor[i] > vetor[j])
      {
        cont++;
      }
    }
  }

  return cont;
}

int main()
{
  int vetor[10];      
  int size;            
  int res;          
  
  cin >> size;
  
  for (int i = 0; i < size; i++)
    cin >> vetor[i];
  
  res = contar(vetor, size);

  cout << res << endl;

  return 0;
}
