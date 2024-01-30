#include <iostream>

using namespace std;


//exercício 2 página 5) o valor de x será igual a 13.


//exércício 2, página 6
int soma(int *v, int n){
    int x=0;
    if (n == 1)
        return v[n-1];
    else
        return v[n-1] + soma(v, n-1);
}

//exercício da página 8) a função fib(8) é chamada 41 vezes

//exercício A:
int soma_inteiros(int n){
    if(n == 1){
        return n;
    }
    else{
        return n + soma_inteiros(n-1);
    }
}

//exercício B:
int aoooo_potencia(int n, int potencia){
    if(potencia == 1)
        return n;
    else
        return n * aoooo_potencia(n, potencia - 1);
}

// exercício C: função recursiva em árvore pois trata-se de mais de um componete

//exercício D: Caso o n seja menor que 10, a função irá retornar o próprio n. No caso teste2(4532) ele irá retornar 14

/*exercício E: Ele irá retornar o primeiro valor de sete, já que no momento em que ele chega ao próximo valor igual a 7,
ele verá que ele não é maior, logo ele não irá retorná-lo.*/

//4)
int mult(int m, int n){
    if (n == 0) {
        return 0;
    }
    else
        return m + mult(m, n - 1);
}

//função interativa ultimo exercicio
int iterativa(int n){
    int soma = 0;
    for (int i = 1; i <= n; i++){
        soma += i;
    }
    return soma;
}

int main(){
    int n, potencia, m;

    cin >> n;
    int v[n];
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cout << soma(v, n);

    cin >> n;
    cout << soma_inteiros(n) << endl;
    
    cin >> n >> potencia;
    cout << aoooo_potencia(n, potencia) << endl;

    cin >> m >> n;
    cout << mult(m, n) << endl;

    cin >> n;
    cout << iterativa(n) << endl;
}