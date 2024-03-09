#include <iostream>
#include <string>
using namespace std;

struct dados
{
  string fabricante;
  float psicose;
  string nome;
  int tier;
};

int main()
{
  int limite = 60;
  float total = 0;
  int cont;
  int tier;
  dados *p;
  
  cin >> cont;

  dados *v = new dados[cont];

  for (int i = 0; i < cont; i++)
  {
    getline(cin >> ws, v[i].nome);
    getline(cin >> ws, v[i].fabricante);
    cin >> tier;
    while (true)
    {
      if (tier <= 5 && tier >= 1)
      {
        break;
      }
      cin >> v[i].tier;
    }
    cin >> v[i].psicose;
    total += v[i].psicose;
  }

  delete [] v;

  if (total < limite)
    cout << "Vamos tchum! Temos uma cidade pra conquistar!" << endl;
  else
    cout << "Alerta! Uma recompensa de 50.000 edinhos foi colocada pela sua cabeça. Você se tornou um Ciberpsicopata." << endl;
  

  return 0;
}