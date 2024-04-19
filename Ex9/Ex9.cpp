#include <iostream>
#include <string>
using namespace std;

string Subst()
{
    string str;
    //cin.ignore();
    getline(cin,str);
    str.replace(str.find("ALUNO"),5,"ESTUDANTE");
    str.replace(str.find("ESCOLA"),6,"UNIVERSIDADE");
    return str;
}

string TECLADOOUMOUSE()
{
    string str;
    //cin.ignore();
    getline(cin,str);
    str.insert(str.find("TECLADO")+7," OU MOUSE");
    return str;
}

string login()
{
    string str;
    string login = "";
    //cin.ignore();
    getline(cin,str);
    int n = 0;
    login += str[n];
    for(int i = 0; i<str.length();i++)
    {
        n++;
    }

    return str;
}

int main()
{
    //cout << Subst();
    //cout << TECLADOOUMOUSE();
    //cout << Subst();
    return 0;
}