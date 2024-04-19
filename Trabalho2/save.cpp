//Tecnicas de Programação II
//Nome: André Henrique Marchetto Filho


//ios::binary
//Padrão
#include <iostream>
//Leitura e escrita de arquivo
#include <fstream>
//
#include <sstream>
#include <iomanip>
//rand
#include <cstdlib>
//timne
#include <ctime>
#include <string>

using namespace std;


int main()
{
    string str="iris_petalas.csv";
    
    //inserção de dados
    /*
    cout << "Arquivo a ser lido: ";
    getline(cin, str);
    */

    //Definir total de grupos
    
    int k=0;
    while (k<=1)
    {
        cout << "Definir total de grupos: ";
        cin >> k;
        if (k<=1)
        {
            cout << "Numero de grupos tem que ser maiores que 1!" << endl;
        }
    }

    ifstream inpetalas("iris_petalas.csv",ios::in);
    //Largura da pétala, Altura da pétala, Espécie da flor
    float largurap[152], alturap[152];
    string especiep[152];
    char separador;
    string linhas;
    //=inpetalas >> largurap >> alturap >> especiep
    
    // int i=0;
    // while (getline(inpetalas,linhas))
    // {
    //     istringstream str(linhas);
    //     if (str >> largurap >> separador >> alturap >> separador >> especiep)
    //     {
    //         i++;
    //     }
    // }

    // for (int j = 1; j <= k; j++)
    // {
    //     cout << "Linhas: " << i << " Aleatorio: " << Aleatorio(i,j) << endl;
    // }
    int i=0;
    while (getline(inpetalas,linhas))
    {
        istringstream str(linhas);
        str >> largurap[i] >> separador >> alturap[i] >> separador >> especiep[i];
        i++;
    }

    cout << "teste fora do escopo: " << endl;
    for (size_t i = 0; i < 150; i++)
    {
        cout << std::setw(3) << std::right << largurap[i] << "  " << std::setw(3) << std::right << alturap[i] << "  " << std::setw(13) << std::right << especiep[i] << endl;
    }
    
}

// //ifstream inpetalas("iris_petalas.csv",ios::in);
// //Largura da pétala, Altura da pétala, Espécie da flor
// float largurap, alturap;
// string especiep;
// //=inpetalas >> largurap >> alturap >> especiep
// /*
// int i=0;
// while (getline(inpetalas,linhas))
// {
//     istringstream str(linhas);
//     if (str >> largurap >> separador >> alturap >> separador >> especiep)
//     {
//         i++;
//     }
// }

// for (int j = 1; j <= k; j++)
// {
//     cout << "Linhas: " << i << " Aleatorio: " << Aleatorio(i,j) << endl;
// }

// while (getline(inpetalas,linhas))
// {
//     istringstream str(linhas);
//     if (str >> largurap >> separador >> alturap >> separador >> especiep)
//     {
//         cout << std::setw(3) << std::right << largurap << "  " << std::setw(3) << std::right << alturap << "  " << std::setw(13) << std::right << especiep << endl;
//     }
// }
// */
