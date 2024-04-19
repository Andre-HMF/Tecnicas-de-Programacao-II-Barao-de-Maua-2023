#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int flip(){
    srand(time(0));
    return rand() % 2;
};

int main(){
    int randow,contca=0,contco=0;
    char x;
    while (true){

        randow = flip();
        cout << flip() << endl;
        if (randow == 1){
            cout<<"Cara!"<<endl;
            contca++;
        }
        else{
            cout<<"Coroa!"<<endl;
            contco++;
        };
        cout << "Gostaria de jogar novamente?";
        cin >> x;
        if (!(x=='s'||x=='S'))
        {
            break;
        };
    }

};