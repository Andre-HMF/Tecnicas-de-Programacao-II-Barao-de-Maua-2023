#include <iostream>
#include <fstream>

using namespace std;

void FoutAluno(int i);
void FinAluno(int i);

int main()
{
    char n;
    int i=1;
    while(i != 0)
    {
        cout << "Voce quer criar um novo arquivo(s,n): ";
        cin >> n;
        cout << "Digite seu total de conteudo: ";
        cin >> i;
        if (n=='s')
        {
            FoutAluno(i);
        }
        else
        {
            FinAluno(i);
        }
    }
    return 0;
}

void FoutAluno(int i)
{
    ofstream outAlunoFile("Alunos_CC.txt",ios::out);

    int NumM;
    char Nome[30], Email[30];

    while (i==0)
    {
        cin >> NumM >> Nome >> Email;
        outAlunoFile << NumM << ' ' << Nome << ' ' << Email;
        cout << "? ";
        i--;
    }
}

void FinAluno(int i)
{
    ofstream inAlunoFile("Alunos_CC.txt",ios::app);

    int NumM;
    char Nome[30], Email[30];

    while (i==0)
    {
        inAlunoFile << NumM << ' ' << Nome << ' ' << Email;
        cout << NumM << ' ' << Nome << ' ' << Email;
        cout << "? ";
        i--;
    }
}