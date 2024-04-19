#include <iostream>
#include <vector>
using namespace std;

float somadearray(float v[],int n);

//vector<float> inveterarray(float v[],int n,int i);

//float contador(int c,int n);

int main()
{
    //Parte 1
    int tamanhoarray = 5;
    float v[tamanhoarray] = {1.2,5.4,3,4,3.5};

    cout << somadearray(v,tamanhoarray-1);

    //Parte 2

}


float somadearray(float v[],int n)
{
    if(n==0)
    {
        return v[n];
    }
    else
    {
        return (v[n] + somadearray(v,n-1));
    }
}

/*
vector<float> inveterarray(float v[],int n,int i)
{

    i++;
    if(n==0)
    {
        return v[i] = v[n];
    }
    else
    {
        v[i] = v[n];
        v[i] = inverterarray(v,n-1);
        return v;
    }
}

float contador(int c,int n)
{
    return 0;
}
*/