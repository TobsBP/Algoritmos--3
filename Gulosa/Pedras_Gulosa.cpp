#include <iostream>
using namespace std;

int main()
{
  int peso[5] = {263,127,254,134,111};
	int volume[5] = {455,521,857,65,12};
	int valor[5] = {500,410,320,315,280};
  int i = 0, n = 5, capp = 400, capv = 1000;
  int melhor = 0;

  while (i < n)
  {
    if(capp >= peso[i] && capv >= volume[i])
    {
      capv -= volume[i];
      capp -= peso[i];
      melhor += valor[i];    
    }
    i++;
  }
  
  cout << melhor << endl;

  return 0;
}