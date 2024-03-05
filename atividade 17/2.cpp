#include <iostream>

using namespace std;

const double PI = 3.14159;

double calcularAreaCirculo(double raio) {
    double area = PI * raio * raio;
    return area;
}

int main() {
    double raio;
    cout << "Digite o raio do círculo: ";
    cin >> raio;

    // Impressão para depuração
    cout << "Raio: " << raio << endl;

    double area = calcularAreaCirculo(raio);

    // Impressão para depuração
    cout << "Área calculada: " << area << endl;

    cout << "A área do círculo é: " << area << endl;

    return 0;
}