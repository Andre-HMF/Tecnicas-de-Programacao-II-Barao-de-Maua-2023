#include <iostream>

using namespace std;

int main()
{
    float vetA[5] = {10,7.5,8,9,6}, vetB[5] = {7.3,8.5,9.4,5,3}, vetC[5];
    float *ptrA = vetA, *ptrB = vetB, *ptrC = vetC;

    for (int i = 0; i < 5; i++)
    {
        *(ptrC+i) = (*(ptrA+i) + *(ptrB+i))/2;
        cout << *(ptrC+i) << " ";
    }
    

    return 0;
}