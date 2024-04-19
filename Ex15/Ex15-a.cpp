#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outAlunoFile("Alunos_CC",ios::out);

    int NumM;
    char Nome[30], Email[30];

    while (cin >> NumM >> Nome >> Email)
    {
        outAlunoFile << NumM << ' ' << Nome << ' ' << Email << endl;
        cout << "? ";
    }
    return 0;
}