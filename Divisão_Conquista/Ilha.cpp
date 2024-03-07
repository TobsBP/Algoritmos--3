#include <iostream>
#include <string>
using namespace std;

int func(string pistas[], int begin, int size, string find)
{   
    if (size >= 1)
    {
        int meio = begin + (size - 1) / 2;    

        if (pistas[meio][0] == find[0])
            return meio;    

        if (find[0] < pistas[meio][0])
            return func(pistas, meio - 1, begin, find);
        else
            return func(pistas, size - meio, meio + 1, find);
    }

    return -1;
}

int main()
{
    string pistas[10];
    string dica;

    for (int i = 0; i < 7; i++)
    {
        getline(cin, pistas[i]);
        cin.ignore();
    }

    cin >> dica;

    int res = func(pistas, 0, 7, dica);

    cout << "Índice da pista encontrada: " << res << endl;

    return 0;
}