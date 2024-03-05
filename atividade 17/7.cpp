#include <iostream>
#include <cmath>

using namespace std;

// Estrutura para representar um ponto no plano bidimensional
struct Ponto {
    double x;
    double y;
};

// Função para calcular a distância entre dois pontos
double calcularDistancia(const Ponto& ponto1, const Ponto& ponto2) {
    double deltaX = ponto2.x - ponto1.x;
    double deltaY = ponto2.y - ponto1.y;
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

int main() {
    // Casos de teste
    Ponto ponto1 = {0, 0};
    Ponto ponto2 = {3, 4};
    Ponto ponto3 = {-2, -1};
    Ponto ponto4 = {5, -2};

    // Calcula e imprime as distâncias para os casos de teste
    cout << "Distância entre ponto1 e ponto2: " << calcularDistancia(ponto1, ponto2) << endl;
    cout << "Distância entre ponto1 e ponto3: " << calcularDistancia(ponto1, ponto3) << endl;
    cout << "Distância entre ponto2 e ponto4: " << calcularDistancia(ponto2, ponto4) << endl;

    return 0;
}