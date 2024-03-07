#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float raiz(float x, float x0, float e) {
    if (abs(x0 * x0 - x) <= e) // Condicao de parada
        return x0;
    else // Chamada recursiva
        return raiz(x, (x0 * x0 + x) / (2 * x0), e); 
}

int main() {
    
    float x; // número do qual se quer calcular a raiz
    float x0; // estimativa inicial para raiz
    float e; // limitante superior para o erro

    // Entrada
    cin >> x >> x0 >> e;
    
    // Exibe com 4 casas decimais
    cout << setprecision(4) << fixed;
    cout << raiz(x, x0, e) << endl;

    return 0;
}