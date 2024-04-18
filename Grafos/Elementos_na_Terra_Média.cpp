#include <iostream>

using namespace std;

int main()
{
    int *v; // Vetor de inteiros
    int *p;
    int sum = 0;
    
    v = new int[5];
    
    p = v;
    
    for(int i = 0; i < 5; i++)
    {
        cin >> *p;
        p++;
    }
    
    p = v;
    for(int i = 0; i < 5; i++)
    {
        cout << "Artefato coletado na terra " << i << ": " << *p << endl;
        sum += *p;
        p++;
    }
    
    cout << "Fim da jornada! Soma total dos artefatos: " << sum;
    
    delete[] v;
    
    return 0;
}