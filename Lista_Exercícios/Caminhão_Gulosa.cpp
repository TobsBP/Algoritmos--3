#include <iostream>
using namespace std;

int main()
{
  // variaavel[0++] = Altura, Largura e Comprimento;
  int caminhao[4] = {0, 0, 0, 0};
  
  // vairavel[0++] = Quantidade (0 pois no if tem a quantidade, para contar quantas foram usadas), Altura, Largura e Comprimento;
  int caixa_a[5] = {0, 5, 2, 2, 0};
  int caixa_b[5] = {0, 1, 1, 3, 0};
  int caixa_c[5] = {0, 2, 2, 1, 0};
  int i, menor_v, soma_v = 0;

  // Entrada do tamanho do caminhão
  for (i = 0; i < 3; i++)
    cin >> caminhao[i];

  // Volume do caminhão
  caminhao[3] = caminhao[0] * caminhao[1] * caminhao[2];

  // Volume das caixas
  caixa_a[4] = caixa_a[1] * caixa_a[2] *caixa_a[3];
  caixa_b[4] = caixa_b[1] * caixa_b[2] *caixa_b[3];
  caixa_c[4] = caixa_c[1] * caixa_c[2] *caixa_c[3];
  
  for (i = 0; i < 3; i++)
  {
    // Menor volume
    menor_v = min(caixa_a[4], min(caixa_b[4], caixa_c[4]));

    if (caminhao[3] >= soma_v)
    {
      if (menor_v == caixa_a[4])
      {
        while (caixa_a[0] < 10 && caminhao[3] > soma_v)
        {
          soma_v += caixa_a[4]; 
          caixa_a[0] += 1; // contar quantas foram usadas
        }
        caixa_a[4] = 999;  
      }

      if (menor_v == caixa_b[4])
      {
        while (caixa_b[0] < 20 && caminhao[3] > soma_v)
        {
          soma_v += caixa_b[4];
          caixa_b[0] += 1; // contar quantas foram usadas
        }
        caixa_b[4] = 999;
      }

      if (menor_v == caixa_c[4])
      {
        while (caixa_c[0] < 25 && caminhao[3] > soma_v)
        {
          soma_v += caixa_c[4];
          caixa_c[0] += 1;  // contar quantas foram usadas
        }
        caixa_c[4] = 999;
      }
    }
  }
  
  // Exibe
  cout << "Caixa a: " << caixa_a[0] << endl;
  cout << "Caixa b: " << caixa_b[0] << endl;
  cout << "Caixa c: " << caixa_c[0] << endl;

  return 0;
}