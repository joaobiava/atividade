#include <iostream>
#include <vector>

using namespace std;

// Função para busca binária em uma lista ordenada
int buscaBinaria(const vector<int>& lista, int chave) {
    int esquerda = 0;
    int direita = lista.size() - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        // Se a chave estiver no meio, retorna o índice
        if (lista[meio] == chave)
            return meio;
        
        // Se a chave for menor, busca na metade esquerda
        if (lista[meio] > chave)
            direita = meio - 1;
        // Se a chave for maior, busca na metade direita
        else
            esquerda = meio + 1;
    }

    // Se a chave não estiver na lista, retorna -1
    return -1;
}

int main() {
    // Lista ordenada de números
    vector<int> lista = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    
    // Chaves para buscar na lista
    int chave1 = 7;
    int chave2 = 10;

    // Realiza a busca binária e imprime o resultado
    int indice1 = buscaBinaria(lista, chave1);
    int indice2 = buscaBinaria(lista, chave2);

    cout << "O número " << chave1 << " está na posição " << indice1 << endl;
    cout << "O número " << chave2 << " está na posição " << indice2 << endl;

    return 0;
}