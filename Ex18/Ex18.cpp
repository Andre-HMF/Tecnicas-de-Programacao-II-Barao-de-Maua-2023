#include <iostream>
#include <fstream>

using namespace std;

struct Venda
{
    int cod_vendedor;
    string nome_vendedor;
    float valor_vendedor;
    int mes;
};


void Create_Venda();
void Leitura_Venda();
void Adicionar_Vendedor();


int main()
{
    int n = 1;
    while (n!=0)
    {
        cout << "Escolha(1-Criar_Venda,2-Leitura_da_venda,3-Adicionar_Venda): "<< endl;
        cin >> n;

        if (n==1)
        {
            Create_Venda();
        }
        else if (n==2)
        {
            Leitura_Venda();
        }
        else if (n==3)
        {
            Adicionar_Vendedor();
        }
        
        
    }
    
    return 0;
}


void Create_Venda()
{
    int Tamanho;
    cout << "Quantos usuarios gostaria de inserir: ";
    cin >> Tamanho;
    Venda Vendedor[Tamanho];

    for (size_t i = 0; i < Tamanho; i++)
    {
        cout << "Insira os valores: " << endl;
        Vendedor[i].cod_vendedor = i;
        cin >> Vendedor[i].nome_vendedor >> Vendedor[i].valor_vendedor >> Vendedor[i].mes;
    }

    fstream outvendas("VENDAS.DAT",ios::out | ios::binary);
    outvendas.write(reinterpret_cast<char *>(Vendedor),Tamanho*sizeof(Venda));
    outvendas.close();
}

void Leitura_Venda()
{
    int Tamanho;
    cout << "Quantos usuarios: ";
    cin >> Tamanho;
    Venda Vendedor[Tamanho];

    fstream invendas("VENDAS.DAT",ios::in | ios::binary);
    invendas.seekg(0,ios::beg);
    invendas.read(reinterpret_cast<char *>(Vendedor),Tamanho*sizeof(Venda));
    
    for (size_t i = 0; i < Tamanho; i++)
    {
        cout << "Insira os valores: " << endl;
        cout << Vendedor[i].cod_vendedor << Vendedor[i].nome_vendedor << Vendedor[i].valor_vendedor << Vendedor[i].mes<<endl;
    }

    invendas.close();
}

void Adicionar_Vendedor()
{
    int Tamanho;
    cout << "Quantos usuarios: ";
    cin >> Tamanho;
    Venda Vendedor[Tamanho+1];

    fstream fvendas("VENDAS.DAT",ios::app | ios::in | ios::binary);
    fvendas.read(reinterpret_cast<char *>(Vendedor),Tamanho-1*sizeof(Venda));
    Vendedor[Tamanho].cod_vendedor = Tamanho;
    cin >> Vendedor[Tamanho].nome_vendedor >> Vendedor[Tamanho].valor_vendedor >> Vendedor[Tamanho].mes;
    fvendas.write(reinterpret_cast<char *>(Vendedor),Tamanho*sizeof(Venda));
    fvendas.close();
}

//fstream -> Não abre se não existir o arq, a não ser que use trunc