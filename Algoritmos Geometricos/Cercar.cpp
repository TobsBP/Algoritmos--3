#include <iostream>
#include <cmath>
using namespace std;
 
#define INF 10000
 
struct Point
{
    int x;
    int y;
};
 
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
 
    if (val == 0)
        return 0; // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}
 
void gift_wrapping(Point points[], int n)
{
    if (n < 3)
        return;
 
    int next[n];
    for (int i = 0; i < n; i++)
        next[i] = -1;
 
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
 
    int p = l, q;
    do
    {
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
 
        next[p] = q;
        p = q;
    }
    while (p != l);
 
    Point res[10];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (next[i] != -1)
        {
            cout << "(" << points[i].x << ", " << points[i].y << ")\n";
            res[j].x = points[i].x;
            res[j].y = points[i].y; 
            j++;
        }
    }

    // Calcula a distancia dos pontos
    float distance = 0;
    for (int i = 0; i < j; i++)
    {
        // Descobre o proximo ponto para calcular a distancia
        int proximo = (i + 1) % j;
        distance += sqrt(pow(res[proximo].x - res[i].x, 2) + pow(res[proximo].y - res[i].y, 2));
    }
    
    cout << "Perimeter: " << distance << endl;
}
 
int main()
{
    Point points[10];
    int size;

    cin >> size;

    for (int i = 0; i < size; i++)
        cin >> points[i].x >> points[i].y;
    
    gift_wrapping(points, size);
    
    return 0;
}