#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Ponto
{
    int x, y;
};

void multplyk(float *ptrv,int *qnt, float *ptrk);
void soma2vet(float *ptrv1,float *ptrv2,int *qnt);
void consvet(Ponto *ptrv,int *qnt);
int aleatorio();

int main()
{
    //Ex1
    int qnt = 5;
    float vet[qnt] = {10,3,7.4,8.2,5.1}, k = 3;
    multplyk(vet, &qnt, &k);

    for (int i = 0; i < qnt; i++)
    {
        cout << vet[i] << " ";
    }
    cout << endl;
    //Ex2
    float vet2[qnt] = {1,3.6,2,4.4,3.3};
    soma2vet(vet,vet2,&qnt);

    for (int i = 0; i < qnt; i++)
    {
        cout << vet[i] << " ";
    }

    //Ex3
    qnt = 10;
    Ponto vet3[qnt];
    consvet(vet3,&qnt);

    for (int i = 0; i < qnt; i++)
    {
        cout << vet3[i].x << " " << vet3[i].y << endl;
    }
}

int aleatorio(){
    srand(time(0));
    return rand() % 11;
};

void multplyk(float *ptrv,int *qnt, float *ptrk)
{
    for (int i = 0; i < *qnt; i++)
    {
        *(ptrv+i) = *(ptrv+i) * *ptrk;
    }
    
}

void soma2vet(float *ptrv1,float *ptrv2,int *qnt)
{
    for (int i = 0; i < *qnt; i++)
    {
        *(ptrv1+i) = *(ptrv1+i) + *(ptrv2+i);
    }
}

void consvet(Ponto *ptrv,int *qnt)
{
    for (int i = 0; i < *qnt; i++)
    {
        (ptrv+i)->x = aleatorio();
        (ptrv+i)->y = aleatorio();
    }
}