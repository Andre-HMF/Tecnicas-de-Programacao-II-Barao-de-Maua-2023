#include <iostream>
using namespace std;
//Desvendar P.G - Quebrar PG

long double Pg(long double f1, long double r, long int x, int s);
long double rp(long double n1=0, long double n2=0, char c='0', long int m=1);

int main()
{
    int s = -1;
    while (s != 0)
    {
        long int x,d;
        long double f1, r;
        bool b=true;
        char c;
        cout << "Escolha a opcao(0=sair,1=editar,2=resultado final,3=variacao de analise): ";
        cin >> s;

        if(s==1)
        {
            cout << "Digite as informacoes da PG: " << endl << "[f1=primeiro termo][r=razao][x=termo]" << endl;
            cin >> f1 >> r >> x;
        }
        else if (s==2)
        {
            cout << "Escolha a opcao(1=pgg,2=pgs,3=pgi,4=pgp): ";
            cin >> s;
            cout << "Resultado: " << Pg(f1,r,x,s) << endl;
        }
        else if (s==3)
        {
            cout << "Digite as informacoes da PG: " << endl << "[c=operacao][d=distancia]" << endl;
            cin >> c >> d;
            cout << rp(f1,r,c,x*d) << endl;
        }
    }
    
}

long double Pg(long double f1, long double r, long int x, int s)
{
    cout << "Valores de entrada: " << f1 << " " << r << " " << x << " " << s << endl;
    if(s == 1)f1 = f1 * rp(r,x-1);
    else if(s == 2)f1 = (f1 * (rp(r,x) - 1))/(r - 1);
    else if(s == 3)f1 = f1/(1 - r);
    else if(s == 4)f1 = rp(f1,x) * rp(r,((x*(x-1))/2));
    
    return f1;
}

long double rp(long double n1, long double n2, char c, long int m)
{
    cout << "Valores de entrada: " << n1 << " " << n2 << " " << c << " " << m << endl;
    if ((n1 && n2 != 0))
    {

        if (c=='0')
        {
            m = (long int) n2;
            n2 = n1;
            c = '*';
        }

        for (long int i = 1; i < m; i++) cout << i << "|";
        cout << endl;

        for (long int i = 1; i < m; i++)
        {
            if (c=='+')
            {
                n1 = n1 + n2;
            }
            else if (c=='-')
            {
                n1 = n1 - n2;
            }
            else if (c=='*')
            {
                n1 = n1 * n2;
            }
            else if (c=='/')
            {
                n1 = n1 / n2;
            }
            else if (c=='%')
            {
                n1 = (long int) n1 % (long int) n2;
            }
            else
            {
                cout << "Aritmetica nao encontrada!" << endl;
            }
            
            cout << n1 << "|";
        }
        cout << endl;
    }
    else
    {
        cout << "Erro de aritmetico!";
    }
    cout << endl;

    return n1;
}