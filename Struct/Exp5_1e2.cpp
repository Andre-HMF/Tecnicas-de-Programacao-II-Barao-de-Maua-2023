#include <iostream>
using namespace std;

struct DadosAluno{
    string nome;
    float media;
    int idade;
};

void registro(DadosAluno p[],int n){
    for (int i=0;i<10;i++)
    {
        cout << "Nome do aluno: ";
        cin >> p[i].nome;
        cout << "Nome do media: ";
        cin >> p[i].media;
        cout << "Nome do idade: ";
        cin >> p[i].idade;
    }

    for (int i=0;i<10;i++)
    {
        cout << "\nNome do aluno: ";
        cout << p[i].nome;
        cout << "\nNome do media: ";
        cout << p[i].media;
        cout << "\nNome do idade: ";
        cout << p[i].idade;
    }

}

int main(){

    //Ex1
    DadosAluno Aluno1;

    cout << "Nome do aluno: ";
    cin >> Aluno1.nome;

    cout << "Nome do media: ";
    cin >> Aluno1.media;

    cout << "Nome do idade: ";
    cin >> Aluno1.idade;

    cout << "Nome do aluno: " << Aluno1.nome << '\n';
    cout << "Media do media: " << Aluno1.media << '\n';
    cout << "Idade do idade: " << Aluno1.idade << '\n';

    //Ex2
    int i = 10;
    DadosAluno Aluno2[i];

    registro(Aluno2,i);
}