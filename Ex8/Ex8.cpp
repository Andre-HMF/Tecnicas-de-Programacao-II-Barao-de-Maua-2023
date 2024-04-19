#include <iostream>
using namespace std;

/*
int function1(int n,int k)
{
    if (n == 0)
    {
        return 0;
    }
    if(n%10==k)
    {
        return 1 + function1(n/10,k);
    }
    else
    {
        return 0 + function1(n/10,k);
    }
}
*/

void function2(int n)
{
    if (n == 0) return;
    function2(n/2);
    cout << n%2;
}

int mdc(int x, int y)
{
    if(x==y)
    {
        return x;
    }
    if(x>y)
    {
        return mdc(x-y,y);
    }
    else
    {
        return mdc(y,x);
    }
}

/*
int mod(int x, int y)
{
    if(x==y)
    {
        return 0;
    }
    if(x>y)
    {
        return mod(x-y,y);
    }
    else if(x<y)
    {
        return x;
    }
}
*/

//Desafio


/*
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

void desafio(int vet1[],int vet2[], int vet3[])
{
    if (n1 == 0 &&)
    return;
}
*/
int main()
{
    function2(13);
    cout << "\n" << mdc(20,10);
    cout << "\n" << mdc(20,10);
    int vet1[5] = {2,4,6,8,10}, vet2[5] = {1,3,5,7,9}, vet3[10];
    desafio(vet1,vet2,vet3);

    return 0;
}