#include <iostream>
#include <math.h>
using namespace std;

struct Ponto {
	int x;
	int y;	
};

double area_triangulo(
	Ponto a, 
	Ponto b, 
	Ponto c
){
	return 
		((a.x*b.y) - (a.y*b.x) + 
		(a.y*c.x) - (a.x*c.y) + 
		(b.x*c.y) - (b.y*c.x))/2.0;  
}

double distancia(Ponto p1, Ponto p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y));
}

int orientacao(Ponto a, Ponto b, Ponto c){
	double area = area_triangulo(a,b,c);
	if(area > 0){
		return 1; 
	} else if(area < 0){
		return -1; 
	} else {
		return 0; 
	}
}

float dia(Ponto c, Ponto d)
{
    return sqrt(pow(d.x - c.x, 2) + pow(d.y - c.y, 2));
}

float espe(Ponto a, Ponto b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

float alt(Ponto a, Ponto c)
{
    return sqrt(pow(c.x - a.x, 2) + pow(c.y - a.y, 2));
}

int main()
{
    Ponto a, b, c, d;
    int esp, diaa, altu;

    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> d.x >> d.y;

    altu = alt(a, c);
    diaa = dia(c, d);
    esp = espe(a, b);

    cout << esp << endl;
    cout << diaa << endl;
    cout << altu << endl;

    return 0;
}