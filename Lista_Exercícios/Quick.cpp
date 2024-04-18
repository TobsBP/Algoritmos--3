#include <iostream> 
#include <cmath>
using  namespace std; 

void quickSort(int vetor[], int esquerda, int direita)
{
    int trab,pivo; 
    
    int i = esquerda; 
    int j = direita;  
    
    pivo = vetor[(esquerda + direita) / 2]; 
    
    while (i <= j)
    {
        while(vetor[i] < pivo)
        {
            i++;
        }
        while(vetor[j] > pivo)
        {
            j--; 
        }
        
        if(i <= j)
        {
            trab = vetor[i]; 
            vetor[i] = vetor[j]; 
            vetor[j] = trab; 
        }
        if(esquerda < j)
        {
            quickSort(vetor,esquerda,j); 
        }
        if(i < direita)
        {
            quickSort(vetor,i,direita); 
        }
    }
}

int main()
{
  int i = 0; 
  int vetor[100]; 
  int vetor2; 
  int j;
  
  cin >> vetor2;  
  
  while(vetor2 != -1)
  {
      int vetor2 = vetor[i];
      cin >> vetor2;
      i++; 
  }
    
    
    
    return 0; 
}