#include <iostream>
using namespace std;

int poten(int a, int n)
{
  if (n == 0) // Condicao de parada
    return 1;
  else  // Chamada recursiva
    return a * poten(a, n - 1);
}

int main()
{
  int n; // Numero que vai elevar o numero a
  int a; // Numero a ser elevado  
  
  // Entrada
  cin >> a >> n;
  
  // Exibe
  cout << poten(a, n) << endl;
    
  return 0;
}