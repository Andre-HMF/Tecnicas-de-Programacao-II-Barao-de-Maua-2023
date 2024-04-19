#include <iostream>
#include <fstream>

using namespace std;

struct Alunos
{
    int numero;
    char nome[30], curso[30];
    float n1,n2;
};


int main()
{
    ofstream outAlunos("ALUNOS.DAT", ios::out);
    Alunos a1;

    while (cin >> a1.numero >> a1.nome >> a1.curso >> a1.n1 >> a1.n2)
    {
        outAlunos << " " << a1.numero << " " << a1.nome << " " << a1.curso << " " << a1.n1 << " " << a1.n2 << endl;
        cout << "? ";
    }

    return 0;
}