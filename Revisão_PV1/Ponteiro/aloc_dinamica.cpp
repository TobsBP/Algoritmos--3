#include <iostream>
using namespace std;

int main()
{
  int tam;
  int *v;
  int *p;

  cin >> tam;

  v = new int[tam];

  p = v;
  for (int i = 0; i < tam; i++)
  {
    cin >> *p;  
    p++;
  }
  
  p = v;
  for (int i = 0; i < tam; i++)
  {
    cout << *p << endl;
    p++;
  }

  return 0;
}