#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Função para ordenar a lista de números em ordem crescente
void ordenarLista(vector<int> &numeros) {
    sort(numeros.begin(), numeros.end());
}

// Função para imprimir a lista de números
void imprimirLista(const vector<int> &numeros) {
    cout << "Lista ordenada:" << endl;
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Caso de teste 1: Lista vazia
    vector<int> listaVazia;
    ordenarLista(listaVazia);
    cout << "Caso de teste 1 (Lista vazia):" << endl;
    imprimirLista(listaVazia);
    cout << endl;

    // Caso de teste 2: Lista com um único número
    vector<int> listaUmNumero = {5};
    ordenarLista(listaUmNumero);
    cout << "Caso de teste 2 (Lista com um único número):" << endl;
    imprimirLista(listaUmNumero);
    cout << endl;

    // Caso de teste 3: Lista com vários números
    vector<int> listaNumeros = {9, 2, 7, 4, 1, 6, 3, 8, 5};
    ordenarLista(listaNumeros);
    cout << "Caso de teste 3 (Lista com vários números):" << endl;
    imprimirLista(listaNumeros);
    cout << endl;

    return 0;
}