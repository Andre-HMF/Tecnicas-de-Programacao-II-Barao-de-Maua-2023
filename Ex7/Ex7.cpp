#include <iostream>
using namespace std;

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

void function2(int n)
{
    cout << n%2;
    if (n%2 == 0)
    {
        return;
    }
    else
    {
        function2(n/10);
    }
}

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
*/

int main()
{
    cout << function1(762021192,2) << endl;
    function2(13);
    return 0;
}