#include <iostream>
using namespace std;

void fsoma(int **p,int linhas, int colunas);
int randow();

int main()
{
    int colunas, linhas, **p;
    cin >> colunas >> linhas;
    p = (int**) malloc(sizeof(int*)*linhas);

    for (int i = 0; i < linhas; i++)
    {
        p[i] = (int*) malloc(sizeof(int)*colunas);
    }

    cout << "Vetor:" << endl;

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            p[i][j] =  randow();
            cout << *(*(p+i)+j) << "  ";
        }
        cout << endl;
    }

    fsoma(p,linhas,colunas);

    for (int i = 0; i < linhas; i++)
    {
        free(p[i]);//delete[] matriz[i];
    }
    free(p);//delete[] matriz;
}

void fsoma(int **p,int linhas, int colunas)
{
    cout << "Soma: " << endl;
    for (int i = 0; i < colunas; i++)
    {
        cout << "Coluna ["<<i+1<<"]: ";
        for (int j = 0; j < linhas; j++)
        {
            if(j != linhas-1)
            {
                *(*(p+j+1)+i) = *(*(p+j)+i) + *(*(p+j+1)+i);
                cout << *(*(p+j)+i) << "  ";
            }
            else
            {
                cout << "R:" << *(*(p+j)+i) << "  ";
            }
        }
        cout << endl;
    }   
}

int randow(){
    srand(time(0));
    return rand() % 100;
};