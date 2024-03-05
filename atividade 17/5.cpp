#include <iostream>

using namespace std;

// Função para resolver o sistema de equações lineares
void resolverSistemaLinear(double a1, double b1, double c1, double a2, double b2, double c2) {
    // Calcula o determinante
    double determinante = a1 * b2 - a2 * b1;

    // Verifica se o determinante é diferente de zero
    if (determinante != 0) {
        // Calcula as incógnitas
        double x = (c1 * b2 - c2 * b1) / determinante;
        double y = (a1 * c2 - a2 * c1) / determinante;

        // Imprime as soluções
        cout << "Solução:" << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    } else {
        // Se o determinante for zero, não há solução única
        cout << "O sistema não possui solução única." << endl;
    }
}

int main() {
    // Coeficientes das equações
    double a1, b1, c1; // Equação 1: a1x + b1y = c1
    double a2, b2, c2; // Equação 2: a2x + b2y = c2

    // Solicita ao usuário para inserir os coeficientes
    cout << "Digite os coeficientes da primeira equação (a1 b1 c1): ";
    cin >> a1 >> b1 >> c1;

    cout << "Digite os coeficientes da segunda equação (a2 b2 c2): ";
    cin >> a2 >> b2 >> c2;

    // Resolve o sistema de equações lineares
    resolverSistemaLinear(a1, b1, c1, a2, b2, c2);

    return 0;
}