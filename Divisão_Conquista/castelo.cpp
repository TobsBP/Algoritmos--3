#include <iostream>
using namespace std;

struct dados
{
  int poder[10];
  int peso[10];
  int capac;
  int resis;
};

int func_des(dados testes[], int quant_test, int num_pro)
{
  int i, j;
  int soma_poder = 0;
  int soma_pes = 0;
  
  if (soma_pes <= testes[i].capac)
  {
    
  }

  return -1;
}

int main()
{
  dados testes[50];
  int quant_test, num_pro;
  int res[5];

  cin >> quant_test;

  for (int i = 0; i < quant_test; i++)
  {
    cin >> num_pro;
    for (int j = 0; j < num_pro; j++)
      cin >> testes[j].poder[j] >> testes[j].peso[j];

    cin >> testes[i].capac;
    cin >> testes[i].resis;
  }


  

  return 0;
}