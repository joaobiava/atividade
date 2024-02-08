#include <iostream>

using namespace std;

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
}