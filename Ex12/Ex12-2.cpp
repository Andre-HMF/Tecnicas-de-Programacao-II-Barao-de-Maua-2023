#include <iostream>
using namespace std;

struct nó
{
    int i;
    nó *ptrnó;
};

int main()
{
    int qnt = 3;
    nó s[qnt];
    nó *x = &s[0], *save;

    for (int i = 0; i < qnt; i++)
    {
        cout << i << endl;
        if(i!=(qnt-1))
        {
            s[i].ptrnó = &s[i+1];
            s[i].i = i+1;
        }
        else
        {
            s[i].ptrnó = &s[0];
            s[i].i = i+1;
        }
    }

    cout << "O valor inteiro do endereco do no de X: " << x->i << endl;
    cout << "O valor do ponteiro do endereco do no de X: " << x->ptrnó << endl;

    save = x;
    for (int i = 0; i < qnt; i++)
    {
        cout << "O valor inteiro do endereco do no de "<< i+1 <<": " << x->i << endl;
        cout << "O valor do ponteiro do endereco do no de "<< i+1 <<": " << x->ptrnó << endl;
        x = x->ptrnó;
    }
    x = save;
}