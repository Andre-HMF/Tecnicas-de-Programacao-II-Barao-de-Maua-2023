#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

float Randow(){
    srand(time(0));
    return (rand() % 10) + 1;
} 

int main(){
    int x, y, z;
    char continuar = 's';
    char valor;
    float numb;

    while(continuar != 'n')
    {
        cout << "Quantas Matrizes voce quer?" << endl;
        cin >> x;
        cout << "Quantas colunas voce quer?" << endl;
        cin >> y;
        cout << "Quantas linhas voce quer?" << endl;
        cin >> z;
        cout << "'a':Retorna o mesmo numero aleatorio em todas caixas por ser muito rapido (Ainda não resolvi)" << endl;
        cout << "'m':Manual - RECOMENDADO                                                                      (EXERCICIO 1 & 2)" << endl;
        cout << "'b':Binario coloca todos numeros em 0 (mais informações adiante) - RECOMENDADO                (EXERCICIO 3)" << endl;
        cout << "'s':Sequencial - RECOMENDO                                                                    (EXERCICIO 4)" << endl;
        cout << "Aleatorio? (a/m/b/s/q)" << endl;
        cin >> valor;
        float Matriz[x][y][z] = {{{1,14,15,4},{12,7,6,9},{8,11,10,5},{13,2,3,16}}};

        //CONSTRUTOR DE MATRIZ - PARTE1
        //Aleatório?
        if (valor == 'a')
        {
            for(int i=0; i<x; i++)
            {
                for(int j=0; j<y; j++)
                {
                    for(int k=0; k<z; k++)
                    {
                        Matriz[i][j][k] = Randow();
                    }
                }
            }
        }
        else if (valor == 'm')
        {

            for(int i=0; i<x; i++)
            {
                for(int j=0; j<y; j++)
                {
                    for(int k=0; k<z; k++)
                    {
                        cout << i+1 << " " << j+1 << " " << k+1 << endl;
                        cin >> Matriz[i][j][k];
                    }
                }
            }
        }
        else if (valor == 'b')
        {
            for(int i=0; i<x; i++)
            {
                for(int j=0; j<y; j++)
                {
                    for(int k=0; k<z; k++)
                    {
                        Matriz[i][j][k] = 0;
                    }
                }
            }
        }
        else if (valor == 's')
        {
            int sequencial = 0;
            for(int i=0; i<x; i++)
            {
                for(int j=0; j<y; j++)
                {
                    for(int k=0; k<z; k++)
                    {
                        Matriz[i][j][k] = sequencial;
                        sequencial++;
                    }
                }
            }
        }
        else if (valor == 's')
        {
            //Matriz[][][] = {{{1,14,15,4},{12,7,6,9},{8,11,10,5},{13,2,3,16}}};
        }

        //LOAD - PARTE2
        for(int i=0; i<x; i++)
        {
            for(int j=0; j<y; j++)
            {
                for(int k=0; k<z; k++)
                {
                    cout << Matriz[i][j][k] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        
        char fazer;
        cout << "'c': encontra o maior valor entre matrizes                                         (Exercicio 1)" << endl;
        cout << "'d': soma da diagonal principal e encontrar maior da diagonal secundaria           (Exercicio 2)" << endl;
        cout << "'b': substituir diagonal principal por 1                                           (Exercicio 3)" << endl;
        cout << "'s': soma as matrizes que voce criou [Cuidado! ele substituirá sua ultima matriz!] (Exercicio 4)" << endl;
        cout << "'m': cubo magico (Exercicio especial)" << endl;
        cout << "O que gostaria de fazer?(c/d/b/s)" << endl;
        cin >> fazer;

        //EXECUTOR DE ATIVIDADES - PARTE3
        if (fazer == 'c')
        {
            float save;
            int savej, savek;
            for(int i=0; i<x; i++)
            {
                for(int j=0; j<y; j++)
                {
                    for(int k=0; k<z; k++)
                    {
                        if ((i==0 && j==0 && k==0))
                        {
                            save = Matriz[i][j][k];
                            savej = j;
                            savek = k;
                        }
                        else if (save < Matriz[i][j][k])
                        {
                            save = Matriz[i][j][k];
                            savej = j;
                            savek = k;
                        }
                    }
                }
            }
            cout << savej+1 << " x " << savek+1 << ": " << save << endl;
        }
        else if (fazer == 'd')
        {
            float save;
            int corretorlin = z - 1;
            int corretorcol = 0;
            for(int i=0; i<x; i++)
            {
                for(int j=0; j<y; j++)
                {
                    for(int k=0; k<z; k++)
                    {
                        if ((i==0 && j==0 && k==0))
                        {
                            save = Matriz[i][j][k];
                        }
                        else if (j == k)
                        {
                            save = save + Matriz[i][j][k];
                        }
                    }
                }
            }
            cout << "Soma diagonal principal: " << save << endl;
            save = 0;
            for(int i=0; i<x; i++)
            {
                for(int j=0; j<y; j++)
                {
                    for(int k=0; k<z; k++)
                    {
                        //cout << j << " " << k << endl;
                        //cout << "Corretor: " << corretorcol << " " << corretorlin << endl;
                        if (j==0 && k==(z-1))
                        {
                            //cout << "Win)" << Matriz[i][j][k];
                            save = Matriz[i][j][k];
                        }
                        else if (j == corretorcol && k == corretorlin && save < Matriz[i][j][k])
                        {
                            //cout << "Win2)" << Matriz[i][j][k];
                            save = Matriz[i][j][k];
                        }
                    }
                    corretorlin--;
                    corretorcol++;
                }
                corretorlin = z - 1;
                corretorcol = 0;
            }
            cout << "Maior diagonal secundaria: " << save << endl;
        }
        else if (fazer == 'b')
        {
            float save;
            for(int i=0; i<x; i++)
            {
                for(int j=0; j<y; j++)
                {
                    for(int k=0; k<z; k++)
                    {
                        if ((i==0 && j==0 && k==0))
                        {
                            Matriz[i][j][k] = 1;
                        }
                        else if (j == k)
                        {
                            Matriz[i][j][k] = 1;
                        }
                    }
                }
            }

            for(int i=0; i<x; i++)
            {
                for(int j=0; j<y; j++)
                {
                    for(int k=0; k<z; k++)
                    {
                        cout << Matriz[i][j][k] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }
        else if (fazer == 's')
        {
            float save = 0;
            for(int j=0; j<y; j++)
            {
                for(int k=0; k<z; k++)
                {
                    for(int i=0; i<(x-1); i++)
                    {
                        save = save + Matriz[i][j][k];
                    }
                    Matriz[x-1][j][k] = save;
                    save = 0;
                }
            }

            for(int i=0; i<x; i++)
            {
                for(int j=0; j<y; j++)
                {
                    for(int k=0; k<z; k++)
                    {
                        cout << Matriz[i][j][k] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }
        else if (fazer == 'm')
        {
            int smatriz[y+z+2];
            int save = 0;
            int save2 = 0;
            for(int i=0; i<x; i++)
            {
                int cont = 0;
                for(int j=0; j<y; j++)
                {
                    for(int k=0; k<z; k++)
                    {
                        save = save + Matriz[i][j][k];
                        save2 = save2 + Matriz[i][k][j];
                    }
                    smatriz[cont]=save;
                    smatriz[cont+y+2]=save2;
                    save = 0;
                    cont++;
                }
            }

            for(int i=0; i<y; i++)
            {
                cout << smatriz[i] << " ";
            }
            cout << "\n";
        }
        //FIM

        cout << "Quer continuar?(s/n)" << endl;
        cin >> continuar;
    }




}