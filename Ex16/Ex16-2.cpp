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
    ifstream inAlunos("ALUNOS.DAT", ios::in);
    ofstream outAlunos("ALUNOS.DAT", ios::app);
    Alunos a1,a2;
    bool t=true;

    while (cin >> a1.numero >> a1.nome >> a1.curso >> a1.n1 >> a1.n2)
    {
        while (inAlunos >> a2.numero >> a2.nome >> a2.curso >> a2.n1 >> a2.n2)
        {
            cout << a1.numero << " " << a2.numero << endl;
            if (a1.numero == a2.numero)
            {
                t=false;
                break;
            }
        }

        if (t)
        {
            outAlunos << " " << a1.numero << " " << a1.nome << " " << a1.curso << " " << a1.n1 << " " << a1.n2 << endl;   
        }
        t = true;

        inAlunos.clear();
        inAlunos.seekg(0, ios::beg);
    }

    inAlunos.close();
    outAlunos.close();

    return 0;
}