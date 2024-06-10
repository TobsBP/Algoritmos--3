#include <iostream>
#include <cmath>
using namespace std;
 
#define INF 10000
 
struct Point
{
    int x;
    int y;
};
 
int main()
{
    float distance[100];
    Point points[100];
    Point find;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    
    cin >> find.x >> find.y;    

    for (int i = 0; i < n; i++)
    {
        // Descobre o proximo ponto para calcular a distancia
        distance[i] = sqrt(pow(points[i].x - find.x, 2) + pow(points[i].y - find.y, 2));
    }
    
    float menor = 99999;
    int indice;
    for (int i = 0; i < n; i++)
    {
        if (distance[i] < menor)
        {
            menor = distance[i];
            indice = i;
        }
    }

    cout << points[indice].x << " " << points[indice].y << endl;
    
    return 0;
}