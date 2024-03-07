#include <iostream>
using namespace std;

int main() {

    // vairavel[0++] = Quantidade (0 pois no if tem a quantidade, para contar quantas foram usadas), Altura, Largura e Comprimento;
    int caixa_a[6] = {0, 5, 2, 2, 0, 200};
    int caixa_b[6] = {0, 1, 1, 3, 0, 150};
    int caixa_c[6] = {0, 2, 2, 1, 0, 100};
    int caminhao[4] = {0, 0, 0, 0};

    // Volume das caixas
    caixa_a[4] = caixa_a[1] * caixa_a[2] *caixa_a[3];
    caixa_b[4] = caixa_b[1] * caixa_b[2] *caixa_b[3];
    caixa_c[4] = caixa_c[1] * caixa_c[2] *caixa_c[3];
    
    // Entrada das dimensões do local do caminhão
    for (int i = 0; i < 3; i++)
        cin >> caminhao[i];
    
    // Volume do caminhão
    caminhao[3] = caminhao[0] * caminhao[1] * caminhao[2];
    
    int melhor_combinacao[3] = {0, 0, 0}; // Quantidade de cada caixa que foi utilizada
    int melhor_valor = -1; // Inicializa com um valor muito pequeno

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 20; ++j) {
            for (int k = 0; k < 25; ++k) {
                // Verifica se há quantidade suficiente para cada caixa
                if (caixa_a[0] < 10 - i && caixa_b[0] < 20 - j && caixa_c[0] < 25 - k) {
                    // Calcula o valor total da combinação atual
                    int valor_combinacao = caixa_a[5] * i + caixa_b[5] * j + caixa_c[5] * k;

                    // Verifica se a combinação cabe no caminhão
                    if (caixa_a[4] * i + caixa_b[4] * j + caixa_c[4] * k <= caminhao[3]) {
                        // Verifica se é a melhor combinação até agora
                        if (valor_combinacao > melhor_valor) {
                            melhor_valor = valor_combinacao;
                            melhor_combinacao[0] = i;
                            melhor_combinacao[1] = j;
                            melhor_combinacao[2] = k;
                        }
                    }
                }
            }
        }
    }

    // Exibe a melhor combinação e seu valor
    cout << "Caixa a foi usada: " << melhor_combinacao[0] << endl;
    cout << "Caixa b foi usada: " << melhor_combinacao[1] << endl;
    cout << "Caixa c foi usada: " << melhor_combinacao[2] << endl;

    return 0;
}
