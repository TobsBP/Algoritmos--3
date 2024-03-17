#include <iostream>
using namespace std;

struct dado
{
  // Info dos castelos 
  int carga[50], resistencia[50];
  int poder[50], peso[50];
};

void teste_dano(dado testes[], int num_projeteis, int num_testes, bool res[])
{
  int carga_total[10] = {0};
  int dano_total[10] = {0};

  for (int i = 0; i < num_testes; i++)
  {
    for (int j = 0; j < num_projeteis; j++)
    {
      if (carga_total[i] <= testes[i].carga[i])
      {
        carga_total[i] +=  testes[i].peso[j];
        dano_total[i] += testes[i].poder[j];
      }
    }
  }

  for (int i = 0; i < num_testes; i++)
    if (dano_total[i] >= testes[i].resistencia[i])
      res[i] = true;
  
}

int main()
{
  bool res[50] = {false};
  int num_projeteis;
  int num_testes;
  dado testes[50];
  
  cin >> num_testes >> num_projeteis;

  for (int i = 0; i < num_testes; i++)
  {
    for (int j = 0; j < num_projeteis; j++)
    {
     cin >> testes[i].poder[j] >> testes[i].peso[j];
    }
    cin >> testes[i].carga[i] >> testes[i].resistencia[i];
  }
  
  teste_dano(testes, num_projeteis, num_testes, res);

  cout << endl;

  for (int i = 0; i < num_testes; i++)
  {
    if (res[i] == true)
      cout << "Missao completada com sucesso" << endl;
    else
      cout << "Falha na missao" << endl;
  }

  return 0;
}