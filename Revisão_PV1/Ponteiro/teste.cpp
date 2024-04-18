#include <iostream>
#include <string>
using namespace std;

struct dados
{
  string nome;
  int notas[2];
};

int main()
{
  dados *aluno;
  int nAlunos;
  int sum = 0;
  int i, alun, maior = 0;
  
  cin >> nAlunos;

  aluno = new dados[nAlunos];

  for (i = 0; i < nAlunos; i++)
  {
    getline(cin >> ws, aluno[i].nome);
    cin >> aluno[i].notas[0];
    cin >> aluno[i].notas[1];
  }
  
  for (i = 0; i < nAlunos; i++)
  {
    sum += aluno[i].notas[0] + aluno[i].notas[1];
    if (sum > maior)
    {
      maior = sum;
      alun = i;
    }
    sum = 0;
  }

  for (i = 0; i < nAlunos; i++)
  {
    sum += aluno[i].notas[0] + aluno[i].notas[1];
  }

  sum = sum / i;
  if (sum >= 60)
  {
    cout << "Sala aprovada" << endl;
  }else{
    cout << "Sala reprovada" << endl;
  }

  cout << sum << endl;
  cout << "Melhor aluno: " << aluno[alun].nome << endl;

  return 0;
}