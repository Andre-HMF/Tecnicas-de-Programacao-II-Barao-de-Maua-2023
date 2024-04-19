#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
#define _USE_MATH_DEFINES

//|Vr - Va|
//Va/Vr

double pot(double nbase, int nloops);

double fat(int n);

double absol(double n);

double porc(double n);

double arredondamento(double x, int n);

double Verificadornan(double n, double ab);

double minimizadordeangulo(double n);

int main(){
    
    double a;
    cout << "\nDigite um valor em graus: ";
    cin >> a;
    a = minimizadordeangulo(a);
    double rad = (a*M_PI)/180;
    cout << "\nRadiano: " << rad;

    double resultcos = 0, resultsen = 0, resultcos2 = 0, resultsen2 = 0;

    cout << "\n\nParte1\n";
    //Parte1
    for(int i=0;i<3;i++)
    {
        //resultcos = resultcos + ?;
        resultcos = resultcos + (pot(-1,i)*(pot(rad,2*i)/fat(2*i)));
        cout << "\nSerie de potencia do termo " << i << " em cos: " << (pot(-1,i)*(pot(rad,2*i)/fat(2*i)));
        resultsen = resultsen + (pot(-1,i)*(pot(rad,(2*i)+1)/fat((2*i)+1)));
        cout << "\nSerie de potencia do termo " << i << " em sen: " << (pot(-1,i)*(pot(rad,(2*i)+1)/fat((2*i)+1)));
        cout << "\nSomatorio de cos: " << resultcos;
        cout << "\nSomatorio de sen: " << resultsen;
    }
    cout << "\n\nResultado de cos para 3 termos: " << resultcos;
    cout << "\nResultado de sen para 3 termos: " << resultsen;

    cout << "\n\nParte2\n";
    //Parte2
    for(int i=0;i<40;i++)
    {
        //resultcos = resultcos + ?;
        resultcos2 = resultcos2 + (pot(-1,i)*(pot(rad,2*i)/fat(2*i)));
        cout << "\nSerie de potencia do termo " << i << " em cos: " << (pot(-1,i)*(pot(rad,2*i)/fat(2*i)));
        resultsen2 = resultsen2 + (pot(-1,i)*(pot(rad,(2*i)+1)/fat((2*i)+1)));
        cout << "\nSerie de potencia do termo " << i << " em sen: " << (pot(-1,i)*(pot(rad,(2*i)+1)/fat((2*i)+1)));
        cout << "\nSomatorio de cos: " << resultcos2;
        cout << "\nSomatorio de sen: " << resultsen2;
    }
    cout << "\n\nResultado de cos para 40 termos: " << resultcos2;
    cout << "\nResultado de sen para 40 termos: " << resultsen2;

    cout << "\n\nParte3\n";
    //Parte3
    cout << "\nValor do cos(" << a << ") = " << cos(rad);
    cout << "\nValor do sen(" << a << ") = " << sin(rad);

    cout << "\n\nParte4\n";

    cout << "\nAbsoluto cos: " << absol(cos(rad)-resultcos2);
    cout << "\nAbsoluto sen: " << absol(sin(rad)-resultsen2);

    //Parte4
    double absolcos = absol(cos(rad)-resultcos);
    double absolsen = absol(sin(rad)-resultsen);
    cout << "\nErros: " << "\nParte 1 para 3: ";
    cout << "\nAbsoluto cos: " << fixed << setprecision(5) << absolcos;
    cout << "\nAbsoluto sen: " << fixed << setprecision(5) << absolsen;
    cout << "\nPorcentagem cos: " << fixed << setprecision(0) << round(porc(Verificadornan(absolcos/cos(rad),absolcos))) << "%";
    cout << "\nPorcentagem sen: " << fixed << setprecision(0) << round(porc(Verificadornan(absolsen/sin(rad),absolsen))) << "%";
    absolcos = absol(cos(rad)-resultcos2);
    absolsen = absol(sin(rad)-resultsen2);
    cout << "\nParte 2 para 3: ";
    cout << "\nAbsoluto cos: " << fixed << setprecision(5) << absolcos;
    cout << "\nAbsoluto sen: " << fixed << setprecision(5) << absolsen;
    cout << "\nPorcentagem cos: " << fixed << setprecision(0) << round(porc(Verificadornan(absolcos/cos(rad),absolcos))) << "%";
    cout << "\nPorcentagem sen: " << fixed << setprecision(0) << round(porc(Verificadornan(absolsen/sin(rad),absolsen))) << "%\n";
}

//Porcentagem
double porc(double n)
{
    n = absol(n);
    n = n * 100.0;
    n = n - 100;
    n = absol(n);
    return n;
}

//Absoluto
double absol(double n)
{
    if(n<0)
    {
        n = n * -1;
    }
    return n;
}

//Potência
double pot(double nbase, int nloops)
{
    double r = 1;
    for(int i=0;i<nloops;i++)
    {
        r = r * nbase;
    }
    return r;
}

//Fatorial interativo
double fat(int n)
{
    float r = 1;
    for(int i=1;i<=n;i++)
    {
        r = r * i;
    }
    return r;
}

//Verificador de nan
double Verificadornan(double n, double ab)
{
    if(isnan(n))
    {
        cout << "Erro NaN detectado! Valor de verificacao eh: ";
        if(ab > -0.000001 && ab < 0.000001)
        {
            n = 0;
        }
    }
    return n;
}

//Diminui a taxa de erro, diminuindo o angulo
double minimizadordeangulo(double n)
{
    double i = 1;
    bool t1 = false, t2 = false;
    cout << "\n--------Divisor de 360 e variante de angulo---------\n";
    while(n > 180 || n < -180)
    {
        cout << i << "   " << n <<"\n";
        if(n > 180)
        {
            t1 = true;
            if(t1 && t2)
            {
                if(absol(i) < 1e-12)
                {
                    t2 = false;
                }
                else
                {
                    i=i/2;
                }
            }
            else
            {
                i=i*2;
            }
            n = n - (360*i);
        }
        else if(n < -180)
        {
            t2 = true;
            if(t1 && t2)
            {
                if(absol(i) < 1e-12)
                {
                    t1 = false;
                }
                else
                {
                    i=i/2;
                }
            }
            else
            {
                i=i*2;
            }
            n = n + (360*i);
        }
    }
    cout << "\nAngulo Aproximado: " << n << "\n";
    cout << "\n----------------------------------------------------\n";
    return n;
}