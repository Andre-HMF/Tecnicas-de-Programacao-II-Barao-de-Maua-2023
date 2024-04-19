#include <iostream>
using namespace std;

struct nó
{
    int i;
    nó *ptrnó;
};

int main()
{
    nó s1, s2, s3;
    nó *x = &s1;

    s1.ptrnó = &s2;
    s2.ptrnó = &s3;
    s3.ptrnó = &s1;
    s1.i = 1;
    s2.i = 2;
    s3.i = 3;

    cout << "O valor inteiro do endereco do no de X: " << x->i << endl;
    cout << "O valor do ponteiro do endereco do no de X: " << x->ptrnó << endl;

    cout << "O valor inteiro do endereco do no de s1: " << x->ptrnó->i << endl;
    cout << "O valor do ponteiro do endereco do no de s1: " << x->ptrnó->ptrnó << endl;

    cout << "O valor inteiro do endereco do no de s2: " << x->ptrnó->ptrnó->i << endl;
    cout << "O valor do ponteiro do endereco do no de s2: " << x->ptrnó->ptrnó->ptrnó << endl;

    cout << "O valor inteiro do endereco do no de s3: " << x->ptrnó->ptrnó->ptrnó->i << endl;
    cout << "O valor do ponteiro do endereco do no de s3: " << x->ptrnó->ptrnó->ptrnó->ptrnó << endl;

    nó s4;
    s3.ptrnó = &s4;
    s4.ptrnó = &s1;
    s4.i = 4;

    cout << "O s1 foi desalocado" << endl;
    s1.ptrnó = NULL;
    cout << "O valor inteiro do endereco do no de s1: " << x->i << endl;
    cout << "O valor do ponteiro do endereco do no de s1: " << x->ptrnó << endl;

    x->ptrnó = &s2;
    s4.ptrnó = &s2;
    cout << "O valor inteiro do endereco do no de X: " << x->i << endl;
    cout << "O valor do ponteiro do endereco do no de X: " << x->ptrnó << endl;
    cout << "O valor inteiro do endereco do no de s4: " << x->ptrnó->ptrnó->ptrnó->i << endl;
    cout << "O valor do ponteiro do endereco do no de s4: " << x->ptrnó->ptrnó->ptrnó->ptrnó << endl;

}