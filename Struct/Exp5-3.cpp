#include <iostream>
using namespace std;

struct Biblioteca{
    string titulo;
    int paginas;
    int ano;
    float preco;
};

void registro(Biblioteca p[],int n){

    for (int i=0;i<n;i++)
    {
        cout << "\nNome do Titulo: ";
        cin >> p[i].titulo;
        cout << "\nNome do paginas: ";
        cin >> p[i].paginas;
        cout << "\nNome do preco: ";
        cin >> p[i].preco;
        cout << "\nNome do ano: ";
        cin >> p[i].ano;
    }

    for (int i=0;i<n;i++)
    {
        cout << "\nNome do Titulo: ";
        cout << p[i].titulo;
        cout << "\nNome do paginas: ";
        cout << p[i].paginas;
        cout << "\nNome do preco: ";
        cout << p[i].preco;
        cout << "\nNome do ano: ";
        cout << p[i].ano;
    }
    
    float result;
    for (int i=0;i<n;i++)
    {
        result = result + p[i].paginas;
    }
    cout << result/n;
}

int main(){
    //Ex3
    int i = 5;
    Biblioteca Livros[i];

    registro(Livros,i);
}