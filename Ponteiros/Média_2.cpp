#include <iostream>
#include <iomanip>
using namespace std;

struct dado
{
  int notas[4];
  float media;
};

int main()
{
  int tam;
  float media_g;

  cin >> tam;

  dado *p = new dado[tam];

  for (int i = 0; i < tam; i++)
  {
    p[i].media = 0.0;

    for (int j = 0; j < 4; j++)
    {
      cin >> p[i].notas[j];
      p[i].media += p[i].notas[j];
    }

    p[i].media /= 4.0;
  }

  media_g = (p[0].media + p[1].media) / 2;

  cout << setprecision(2) << fixed;
  cout << media_g << endl;

  delete p;

  return 0;
}