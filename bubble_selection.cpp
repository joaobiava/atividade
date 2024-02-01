#include <iostream>

using namespace std;

/* II - Caso troque o valor de n-1 por n no código, o mesmo executará da mesma forma, porém ele terá uma 
execução a mais que será inútil, pois o vetor já estará completamente organizado*/

/* III - Não corre troca entre eles, já que eles posueem o mesmo valor, ele passa para a próxima casa do vetor*/

/* IV - em v3 ocorre 0 trocas, porém em v4, irá ocorrer duas trocas, que será com os valores 1 e 4, e 2 e 3.*/

/* II - serão necessárias 10 trocas e 9 comparações até que o vetor fique organizado*/

/*Ambos os algoritmos têm complexidades de comparação e trocas quadráticas, o que faz com que sejam ineficientes para
grandes conjuntos de dados.*/

void bubbleRecursivo(int v[], int n) {
    if (n <= 1) {
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            swap(v[i], v[i + 1]);
        }
    }

    bubbleRecursivo(v, n - 1);
}

void selecaoDecrescente(int v[], int n){
    int i, j, maior;
    for (i = 0; i < n - 1; i++){
        maior = i;
        for (j = i + 1; j < n; j++){
            if (v[j] > v[maior]){
                maior = j;
            }
        }
        if (v[maior] != v[i]){
            swap(v[maior], v[i]);
        }
    }
}

int main(){
    int n;
    cin >> n;
    int v[n];
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    bubbleRecursivo(v, n);

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    selecaoDecrescente(v, n);
    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
