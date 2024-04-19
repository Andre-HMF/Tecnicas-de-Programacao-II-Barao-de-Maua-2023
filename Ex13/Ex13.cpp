#include <iostream>
using namespace std;

struct nó
{
    int i;
    nó *ptrnó;
};

int main()
{
    //a-b
    nó *x = new nó, *save;

    x->ptrnó = new nó;
    x->ptrnó->ptrnó = new nó;
    x->ptrnó->ptrnó->ptrnó = x;
    
    x->i = 1;
    x->ptrnó->i = 2;
    x->ptrnó->ptrnó->i = 3;

    //s1
    cout << "O valor inteiro do endereco do no de X: " << x->i << endl;
    cout << "O valor do ponteiro do endereco do no de X: " << x->ptrnó << endl;

    //s2
    cout << "O valor inteiro do endereco do endereco do no de X: " << x->ptrnó->i << endl;
    cout << "O valor do ponteiro do endereco do endereco do no de X: " << x->ptrnó->ptrnó << endl;

    //s3
    cout << "O valor inteiro do endereco do endereco do endereco do no de X: " << x->ptrnó->ptrnó->i << endl;
    cout << "O valor do ponteiro do endereco do endereco do endereco do no de X: " << x->ptrnó->ptrnó->ptrnó << endl;

    //c
    x->ptrnó->ptrnó->ptrnó = new nó;
    x->ptrnó->ptrnó->ptrnó->i = 4;
    x->ptrnó->ptrnó->ptrnó->ptrnó = x;

    cout << "O valor inteiro do endereco do endereco do endereco do endereco do no de X: " << x->ptrnó->ptrnó->ptrnó->i << endl;
    cout << "O valor do ponteiro do endereco do endereco do endereco do endereco do no de X: " << x->ptrnó->ptrnó->ptrnó->ptrnó << endl;

    //d
    save = x;
    x = x->ptrnó;
    delete save;
    x->ptrnó->ptrnó->ptrnó = x;

    cout << "O valor inteiro do endereco do endereco do endereco do endereco do no de X: " << x->ptrnó->ptrnó->ptrnó->i << endl;
    cout << "O valor do ponteiro do endereco do endereco do endereco do endereco do no de X: " << x->ptrnó->ptrnó->ptrnó->ptrnó << endl;

    delete x->ptrnó->ptrnó;
    delete x->ptrnó;
    delete x;
}