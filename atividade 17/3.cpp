#include <iostream>

using namespace std;

int calcularFatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * calcularFatorial(n - 1);
    }
}

int main() {
    int num;
    cout << "Digite um número inteiro positivo: ";
    cin >> num;

    int fatorial = calcularFatorial(num);
    cout << "O fatorial de " << num << " é: " << fatorial << endl;

    retun 0; // Erro léxico: "retun" em vez de "return"

}