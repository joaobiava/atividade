#include <iostream>

using namespace std;

// Exercício 1: Busca Sequencial
int busca_sequencial(int v[], int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (v[i] >= x) {
            return i;
        }
    }
    return -1;
}

// Exercício 2: Busca Binária
int busca_binaria(int v[], int n, int x) {
    int inicio = 0;
    int fim = n - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (v[meio] == x) {
            return meio;
        } else if (v[meio] < x) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

// Exercício 3: Busca Sequencial Recursiva
int busca_sequencial_recursiva(int v[], int x, int index, int n) {
    if (index == n || v[index] >= x) {
        return index;
    }
    return busca_sequencial_recursiva(v, x, index + 1, n);
}

// Exercício 4: Modificação da Busca Binária
int busca_binaria_modificada(int v[], int n, int x) {
    int inicio = 0;
    int fim = n - 1;
    int result = -1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (v[meio] >= x) {
            result = meio;
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return result;
}

// Exercício 5: Problema das Duas Soma
void duas_somas(int v[], int n, int t, int& i, int& j) {
    int esq = 0;
    int dir = n - 1;
    while (esq < dir) {
        int soma = v[esq] + v[dir];
        if (soma == t) {
            i = esq;
            j = dir;
            return;
        } else if (soma < t) {
            esq++;
        } else {
            dir--;
        }
    }
    i = -1;
    j = -1;
}

int main() {
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanho = sizeof(v) / sizeof(v[0]);
    int x;
    cin >> x;
    int i, j;

    cout << "Busca Sequencial: " << busca_sequencial(v, tamanho, x) << endl;

    cout << "Busca Binaria: " << busca_binaria(v, tamanho, x) << endl;

    cout << "Busca Sequencial Recursiva: " << busca_sequencial_recursiva(v, x, 0, tamanho) << endl;

    cout << "Busca Binaria Modificada: " << busca_binaria_modificada(v, tamanho, x) << endl;

    duas_somas(v, tamanho, 10, i, j);
    cout << "Indices para Duas Soma: " << i << ", " << j << endl;

    return 0;
}
