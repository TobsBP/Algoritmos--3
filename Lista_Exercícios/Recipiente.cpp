#include <iostream>
using namespace std;

int maxx(int altura[], int tam)
{
  int x, y;
  int esq, dir;
  int area;

  dir = tam - 1;
  esq = 0;

  while (esq < dir)
  {
    y = min(altura[esq], altura[dir]); // Menor altura de y
    x = dir - esq; // tamanho de x

    area = max(area, y * x); // Pega o maior elemento

    if (altura[esq] < altura[dir]) // Para a direita n ficar na esq e vice e versa
      esq++;
    else
      dir--;
  }

  return area; // retorna a area
}

int main()
{
  int altura[9]; // tamanho do vetor
  int i, cont; // contadores
  int res; // recebe a resposta

  cin >> cont; // tamanho

  for (i = 0; i < cont; i++) // entrada
  {
    cin >> altura[i];
  }

  res = maxx(altura, cont); // cahama a func

  cout << res << endl; // exibe

  return 0;
}
