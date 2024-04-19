#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inAlunoFile("Alunos_CC.txt",ios::in);

    int NumM;
    char Nome[30], Email[30];

    while (inAlunoFile >> NumM >> Nome >> Email)
    {
        cout << NumM << ' ' << Nome << ' ' << Email << endl;
    }
    return 0;
}
//seek put and seek get
//seekg and seekp
//ios::beg
//ios::cur
//ios::end
//log - 