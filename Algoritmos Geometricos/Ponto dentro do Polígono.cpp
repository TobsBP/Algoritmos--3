#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    int x, y;
};

// Função para calcular a área do triângulo
float area_triangulo(Point a, Point b, Point c) {
    float area = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    return abs(area) / 2.0;
}

bool coordenadas_baricentricas(Point p, Point vertices[]) {
    float area1 = area_triangulo(vertices[0], vertices[1], vertices[2]);
    float area2 = area_triangulo(vertices[0], vertices[2], vertices[3]);

    // Coordenadas baricêntricas do primeiro triangulo
    float l11 = area_triangulo(p, vertices[1], vertices[2]) / area1;
    float l12 = area_triangulo(vertices[0], p, vertices[2]) / area1;
    float l13 = area_triangulo(vertices[0], vertices[1], p) / area1;

    // Coordenadas baricêntricas do segundo triangulo
    float l21 = area_triangulo(p, vertices[2], vertices[3]) / area2;
    float l22 = area_triangulo(vertices[0], p, vertices[3]) / area2;
    float l23 = area_triangulo(vertices[0], vertices[2], p) / area2;

    bool dentro_primeiro_triangulo = (l11 >= 0 && l12 >= 0 && l13 >= 0 && (l11 + l12 + l13) == 1);
    bool dentro_segundo_triangulo = (l21 >= 0 && l22 >= 0 && l23 >= 0 && (l21 + l22 + l23) == 1);

    // Ou pq se tiver dentro de um triangulo é pq esta dentro da area
    return dentro_primeiro_triangulo || dentro_segundo_triangulo;
}

int main() {
    Point vertices[4];
    int quant;
    Point p;

    cin >> quant;
    for (int i = 0; i < quant; ++i) {
        cin >> vertices[i].x >> vertices[i].y;
    }

    cin >> p.x >> p.y;

    if (coordenadas_baricentricas(p, vertices)) {
        cout << "DENTRO" << endl;
    } else {
        cout << "!(DENTRO)" << endl;
    }

    return 0;
}
