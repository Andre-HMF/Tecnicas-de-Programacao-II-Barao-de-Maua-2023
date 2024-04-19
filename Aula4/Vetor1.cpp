#include <iostream>
using namespace std;

int main(){
    float notaJuiz[5];

    for(int i=0;i<5;i++){
        cout << "Digite o valor da nota do juiz" << i + 1 << ": " << endl;
        cin >> notaJuiz[i]; 
    };
    cout << notaJuiz;
}