#include <iostream>
using namespace std;

int main() {
    int cidades[8];
    int cont, i;
    int custo = 0;

    cin >> cont;
    for (i = 1; i <= cont + 1; i++)
        cin >> cidades[i];

    cidades[cont + 1] = cidades[1];

    for (i = 1; i <= cont; i++) {
        custo += min(cidades[i], min(cidades[i + 1], cidades[i + 2]));
    }
    
    cout << "Menor custo: " << custo << endl;

    return 0;
}
