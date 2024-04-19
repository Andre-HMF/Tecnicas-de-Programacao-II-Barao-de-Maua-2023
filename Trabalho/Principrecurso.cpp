#include <iostream>
using namespace std;

int interativo(int n);

//Unifi
int main()
{
    int c;
    while(true)
    {
        cout<<"\nSelecione: ";
        cin>>c;
        if(c == 0)
        {
            break;
        }
        else if(c == 1)
        {
            cout << interativo(5);
        }
    }
}

int interativo(int n)
{
    if(n<=1)
    {
        return n;
    }
    else
    {
        int pnultimo,ultimo, resultado = 0;
        ultimo=1;
        pnultimo=0;
        for (int i=2;i<=n;i++)
        {
            resultado = ultimo + pnultimo;
            pnultimo = ultimo;
            ultimo = resultado;
        }
        return resultado;
    }
}