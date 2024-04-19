#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//"Adivinhe um número"
// 1 a 1000

int Aleatorio(){
    srand(time(0));
    return (rand() % 999) + 1; 
};

int main(){
    char x = 's';
    cout << "Vamos jogar!" << endl;
    while(!(x=='n'||x=='N')){
        int Randow = Aleatorio();
        int Selecionado = -1;

        while(Randow != Selecionado){
            
            cout << "Escolha um numero!" << endl;
            cin >> Selecionado;

            if (Selecionado == Randow)
            {
                cout << "Parabens voce adivinho o numero!" << endl;
            }
            else if (Selecionado < Randow)
            {
                cout << "Muito baixo.Tente novamente!" << endl;
            }
            else if (Selecionado > Randow)
            {
                cout << "Muito Alto.Tente novamente!" << endl;
            }
        }
        cout << "Gostaria de jogar novamente?" << endl;
        cin >> x;
    }
}