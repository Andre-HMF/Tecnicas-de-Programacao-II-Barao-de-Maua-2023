#include <iostream>
#include <fstream>

using namespace std;

struct Alunos
{
    int numero;
    char nome[30], curso[30];
    float n1,n2;
};

void Reditar_ou_Escrever_Arquivo(Alunos &a2);
void Ler_Arquivo(float v1,float v2);

int main()
{
    Alunos a1;
    int sel=1;
    while (sel!=0)
    {
        cout << "0-Sair 1-Reeditar arquivo 2-Exibir conteudo e analizar"<<endl;
        cout << "Escolha: ";
        cin >> sel;

        if (sel==1)
        {
            Reditar_ou_Escrever_Arquivo(a1);
        }
        else if (sel==2)
        {
            cout << "Coloque parametro de 0-10" <<endl;
            int x,y;
            cin >> x >> y;
            Ler_Arquivo(x,y);
        }
        
        
    }

    return 0;
}

void Reditar_ou_Escrever_Arquivo(Alunos &a2)
{
    ifstream inAlunos("ALUNOS.DAT", ios::in);
    ofstream outAlunos("ALUNOS.DAT", ios::app);
    Alunos a1;
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
}

void Ler_Arquivo(float v1,float v2)
{
    ifstream inAlunos("ALUNOS.DAT", ios::in);
    Alunos a2;
    float m;
    while (inAlunos >> a2.numero >> a2.nome >> a2.curso >> a2.n1 >> a2.n2)
    {
        m = (a2.n1+a2.n2)/2;
        if (v1<=m && m<=v2)
        {
            cout << a2.numero << " " << a2.nome<< " "  << a2.curso<< " "  << a2.n1<< " "  << a2.n2 << endl;
        }
    }
    inAlunos.close();
}