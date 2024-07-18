#include <iostream>
#include <math.h>
using namespace std;

struct Ponto{
	int x;
	int y;	
};

double distancia(Ponto p1, Ponto p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y));
}

int main()
{
    Ponto A, B, C, D;
    int EM, DIA, ALT;

    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;

    ALT = distancia(A, C);
    DIA = distancia(C, D);
    EM = distancia(A, B);

    cout << EM << endl;
    cout << DIA << endl;
    cout << ALT << endl;

    return 0;
}