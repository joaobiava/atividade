#include <iostream>

using namespace std;

int somar(int a, int b) {
    return a + b;
}

void realizarOperacoes() {
    int a = 10;
    int b = 5;
    int resultado1 = somar(a, b);
    int resultado2 = a - b;
    int resultado3 = a * b;
    cout << "Resultado da soma: " << resultado1 << endl;
    cout << "Resultado da subtracao: " << resultado2 << endl;
    cout << "Resultado da multiplicacao: " << resultado3 << endl;
}

int main() {
    realizarOperacoes();
    return 0;
}