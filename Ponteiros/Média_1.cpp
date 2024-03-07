#include <iostream>
#include <iomanip> 
using namespace std;

struct Notas {
    int nota[4];
    float media;
};

int main() {
    Notas* aluno = new Notas;
    int soma = 0;

    for (int i = 0; i < 4; i++)
    {
      cin >> aluno->nota[i];
      soma += aluno->nota[i];
    }

    aluno->media = float(soma) / 4;

    cout << aluno->media << endl;

    delete aluno;

    return 0;
}
