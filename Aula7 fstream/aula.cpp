#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //Escrita
    ofstream outClientFile("clients.dat", ios::out);
    //ios::out = gerar uma saída de dados em um arquivo
    //ios::app = acrescentar dados ao fim de um arquivo
    //ate - in - trunc - binary

    cout << "Enter the account, name, and balance." << endl << "Enter end-of-file to end input.\n?";

    int account;
    char name[30];
    double balance;

    while (cin >> account >> name >> balance)
    {
        outClientFile << account << ' ' << name << ' ' << balance << endl;
        cout << "? ";
    }//Fim do while
    //Ctrl + c or Ctrl + z

    /*setw - setprecision - right - left - fixed - showpoint <iomanip>*/
    // while(inClientFile)

    return 0;// destrutor ofstream fecha o arquivo
}// fim main