#include <iostream>
using namespace std;

void cercado(int cerca, int &comp_m, int &larg_m)
{
  int area_m = 0;
  comp_m = 0;
  larg_m = 0;
  int largura;

  for (largura = 1; largura < cerca; largura++) // testa as possibilidades com diferentes larguras
  {
    int comprimento = cerca - largura; 
    int area = largura * comprimento;

    if (area > area_m) // Armazena a maior area 
    {
      area_m = area;
      larg_m = largura;
    }
  }
  comp_m = (largura - larg_m) / 2; // descobre o comprimento maior
}

int main()
{
  int cerca, comp_m, larg_m; 

  cin >> cerca; // tamanho 

  cercado(cerca, comp_m, larg_m); // chama a func

  cout << comp_m << " x " << larg_m << endl; // exibe

  return 0;
}
