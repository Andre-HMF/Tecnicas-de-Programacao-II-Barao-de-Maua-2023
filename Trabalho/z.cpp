#include <iostream>
#include <cctype>
#include <string>
#include <ctime>

using namespace std;

struct datas
{
    short int dia,mes,ano;
};

struct infemprestimo
{
    datas dataemissaoparcela, datavalidadeparcela;
    float valordaparcela;
};

//Structs
struct Cliente
{
    string nome, endereco, cpf;
    datas datanascimento;
    int parceladoemvzs;
    float valoremprestimo;
    infemprestimo emprestimo[12];
};

//Protótipos
Cliente * cadastros(Cliente * ptr, int n);
Cliente * Verificadordeexclusao(Cliente * ptr, int n);
void InserirdadosCliente(Cliente * ptr, int i);
void InseriremprestimoCliente(Cliente * ptr, int i);
//void ModificardadosCliente(Cliente * ptr, int n);
void MostrardadosCliente(Cliente * ptr, int sel);

void ModificardadosCliente(Cliente * ptr, int i);


void editnomecliente(Cliente * ptr, int i);
void editdatadenascimentocliente(Cliente * ptr, int i);
void editcpfcliente(Cliente * ptr, int i);
void editenderecocliente(Cliente * ptr, int i);
void editvalortotalemprestimocliente(Cliente * ptr, int i);
void editparcelascliente(Cliente * ptr, int i);

float editjuros();
void calculadordeemprestimo(Cliente * ptr, float juros, int ncadastro);
void pagarparcela(Cliente * ptr, int sel);

int Selecioneousuario(Cliente * ptr, int ncadastros);


/*___________________________________________Main___________________________________________*/
int main(){
    string menu;
    int ncadastros = 0;
    int juros = 4.5;
    Cliente * ptr = new Cliente [ncadastros];
    Cliente * ptrsavedel;
    //string stt = __DATE__;
    //cout << stt;
    while(true)
    {
        cout << "\n1. Cadastrar cliente";
        cout << "\n2. Visualizar as informacoes de um cliente";
        cout << "\n3. Editar as informacoes de um cliente";
        cout << "\n4. Cadastrar parcela paga";
        cout << "\n5. Cadastrar emprestimo";
        cout << "\n6. Excluir cliente";
        cout << "\n7. Modificar juros";
        cout << "\n8. Sair";
        cout << "\nEscolha: ";
        cin >> menu;

        if(menu == "1")
        {
            //'ptrsavedel' salva e deleta o antigo new, para 'ptr' receber um novo 'new Cliente'
            ptrsavedel = ptr;
            ptr = cadastros(ptr, ncadastros);
            delete [] ptrsavedel;
            ncadastros = ncadastros + 1;
        }
        else if(menu == "2")
        {
            int sel = Selecioneousuario(ptr,ncadastros);
            MostrardadosCliente(ptr,sel);
        }
        else if(menu == "3")
        {
            int sel = Selecioneousuario(ptr,ncadastros);
            ModificardadosCliente(ptr,sel);
        }
        else if(menu == "4")
        {
            int sel = Selecioneousuario(ptr,ncadastros);
            pagarparcela(ptr,sel);
        }
        else if(menu == "5")
        {
            int sel = Selecioneousuario(ptr,ncadastros);
            InseriremprestimoCliente(ptr,sel);
        }
        else if(menu == "6")
        {
            int sel = Selecioneousuario(ptr,ncadastros);
            (ptr+sel)->nome = "";
            ptrsavedel = ptr;
            ptr = Verificadordeexclusao(ptr, ncadastros);
            delete [] ptrsavedel;
            ncadastros = ncadastros - 1;
        }
        else if(menu == "7")
        {
            juros = editjuros();
        }
        else if(menu == "8")
        {
            break;
        }
        else
        {
            cout << "\nValor invalido!";
        }
        calculadordeemprestimo(ptr,juros,ncadastros);
    }
    
    return 0;
}
/*______________________________________________________________________________________*/




//Cadastro
Cliente * cadastros(Cliente * ptr, int n)
{
    Cliente * ptrnew = new Cliente [n+1];

    //Limpar

    (ptrnew+n)->nome = "Nome";
    (ptrnew+n)->endereco = "Endereco";
    (ptrnew+n)->datanascimento.dia = 00;
    (ptrnew+n)->datanascimento.mes = 00;
    (ptrnew+n)->datanascimento.ano = 0000;
    (ptrnew+n)->cpf = "000.000.000-00";
    (ptrnew+n)->parceladoemvzs = 0;
    (ptrnew+n)->valoremprestimo = 0;

    for(int i=0;i<12;i++)
    {
        (ptrnew+n)->emprestimo[i].dataemissaoparcela.dia = 00;
        (ptrnew+n)->emprestimo[i].dataemissaoparcela.mes = 00;
        (ptrnew+n)->emprestimo[i].dataemissaoparcela.ano = 0000;
        (ptrnew+n)->emprestimo[i].datavalidadeparcela.dia = 00;
        (ptrnew+n)->emprestimo[i].datavalidadeparcela.mes = 00;
        (ptrnew+n)->emprestimo[i].datavalidadeparcela.ano = 0000;
        (ptrnew+n)->emprestimo[i].valordaparcela = 0;
    }

    if(n != 0)
    {
        for(int i=0; i<n; i++)
        {
            cout << "\nverificador: " << (ptr+i)->nome;
            (ptrnew+i)->nome = (ptr+i)->nome;
            (ptrnew+i)->endereco = (ptr+i)->endereco;
            (ptrnew+i)->datanascimento.dia = (ptr+i)->datanascimento.dia;
            (ptrnew+i)->datanascimento.mes = (ptr+i)->datanascimento.mes;
            (ptrnew+i)->datanascimento.ano = (ptr+i)->datanascimento.ano;
            (ptrnew+i)->cpf = (ptr+i)->cpf;
            (ptrnew+i)->parceladoemvzs = (ptr+i)->parceladoemvzs;
            (ptrnew+i)->valoremprestimo = (ptr+i)->valoremprestimo;
            for(int j=0;j<12;j++)
            {
                (ptrnew+i)->emprestimo[j].valordaparcela = (ptr+i)->emprestimo[j].valordaparcela;
                (ptrnew+i)->emprestimo[j].dataemissaoparcela.dia = (ptr+i)->emprestimo[j].dataemissaoparcela.dia;
                (ptrnew+i)->emprestimo[j].dataemissaoparcela.mes = (ptr+i)->emprestimo[j].dataemissaoparcela.mes;
                (ptrnew+i)->emprestimo[j].dataemissaoparcela.ano = (ptr+i)->emprestimo[j].dataemissaoparcela.ano;
                (ptrnew+i)->emprestimo[j].datavalidadeparcela.dia = (ptr+i)->emprestimo[j].datavalidadeparcela.dia;
                (ptrnew+i)->emprestimo[j].datavalidadeparcela.mes = (ptr+i)->emprestimo[j].datavalidadeparcela.mes;
                (ptrnew+i)->emprestimo[j].datavalidadeparcela.ano = (ptr+i)->emprestimo[j].datavalidadeparcela.ano;
            }
        }
    }

    InserirdadosCliente(ptrnew,n);

    cout << "\nGostaria de cadastrar seu emprestimo agora: ";
    string decisao;
    cin >> decisao;
    if (decisao == "S" || decisao == "s" || decisao == "sim" || decisao == "Sim" || decisao == "SIM")
    {
        InseriremprestimoCliente(ptrnew,n);
    }

    return ptrnew;
}

//Verificador de Exclusão
Cliente * Verificadordeexclusao(Cliente * ptr, int n)
{
    int verific = 0;

    if(n != 0)
    {
        for(int i=0;i<n;i++)
        {
            if((ptr+i)->nome == "")
            {
                verific++;
            }
        }
        cout << "\n" << verific << "\n";
    }

    Cliente * ptrnew = new Cliente [n-verific];

    if(n != 0)
    {
        int k = 0;
        for(int i=0; i<n; i++)
        {
            if((ptr+i)->nome != "")
            {
                cout << "\nverificador: " << (ptr+i)->nome;
                (ptrnew+k)->nome = (ptr+i)->nome;
                (ptrnew+k)->endereco = (ptr+i)->endereco;
                (ptrnew+k)->datanascimento.dia = (ptr+i)->datanascimento.dia;
                (ptrnew+k)->datanascimento.mes = (ptr+i)->datanascimento.mes;
                (ptrnew+k)->datanascimento.ano = (ptr+i)->datanascimento.ano;
                (ptrnew+k)->cpf = (ptr+i)->cpf;
                (ptrnew+k)->parceladoemvzs = (ptr+i)->parceladoemvzs;
                (ptrnew+k)->valoremprestimo = (ptr+i)->valoremprestimo;
                for(int j=0;j<12;j++)
                {
                    (ptrnew+k)->emprestimo[j].valordaparcela = (ptr+i)->emprestimo[j].valordaparcela;
                    (ptrnew+k)->emprestimo[j].dataemissaoparcela.dia = (ptr+i)->emprestimo[j].dataemissaoparcela.dia;
                    (ptrnew+k)->emprestimo[j].dataemissaoparcela.mes = (ptr+i)->emprestimo[j].dataemissaoparcela.mes;
                    (ptrnew+k)->emprestimo[j].dataemissaoparcela.ano = (ptr+i)->emprestimo[j].dataemissaoparcela.ano;
                    (ptrnew+k)->emprestimo[j].datavalidadeparcela.dia = (ptr+i)->emprestimo[j].datavalidadeparcela.dia;
                    (ptrnew+k)->emprestimo[j].datavalidadeparcela.mes = (ptr+i)->emprestimo[j].datavalidadeparcela.mes;
                    (ptrnew+k)->emprestimo[j].datavalidadeparcela.ano = (ptr+i)->emprestimo[j].datavalidadeparcela.ano;
                }
                k++;
            }
        }
    }

    return ptrnew;
}

//Mostrar dados
void MostrardadosCliente(Cliente * ptr, int sel)
{
    cout << "\nNome: " << (ptr+sel)->nome;
    cout << "\nData nascimento: " << (ptr+sel)->datanascimento.dia << '/' << (ptr+sel)->datanascimento.mes << '/' << (ptr+sel)->datanascimento.ano;
    cout << "\nCpf: " << (ptr+sel)->cpf;
    cout << "\nEndereco: " << (ptr+sel)->endereco;
    cout << "\nValor total do emprestimo: " << (ptr+sel)->valoremprestimo;
    cout << "\nNumero de Parcelas: " << (ptr+sel)->parceladoemvzs;
    for(int i=0;i<12;i++)
    {
        if((ptr+sel)->emprestimo[i].valordaparcela != 0)
        {
            cout << "\nValor da parcela[" << i+1 << "]: " << (ptr+sel)->emprestimo[i].valordaparcela;
            cout << "\nData de emissao do Emprestimo[" << i+1 << "]: " << (ptr+sel)->emprestimo[i].dataemissaoparcela.dia << "/" << (ptr+sel)->emprestimo[i].dataemissaoparcela.mes << "/" << (ptr+sel)->emprestimo[i].dataemissaoparcela.ano;
            cout << "\nData de validade do Emprestimo[" << i+1 << "]: " << (ptr+sel)->emprestimo[i].datavalidadeparcela.dia << "/" << (ptr+sel)->emprestimo[i].datavalidadeparcela.mes << "/" << (ptr+sel)->emprestimo[i].datavalidadeparcela.ano;
        }
    }
    cout << '\n';
}


void ModificardadosCliente(Cliente * ptr, int i)
{
    string decisao;
    cout << "Gostaria de editar tudo?";
    cin >> decisao;
    if (decisao == "S" || decisao == "s" || decisao == "sim" || decisao == "Sim" || decisao == "SIM")
    {
        editnomecliente(ptr,i);
        editdatadenascimentocliente(ptr,i);
        editcpfcliente(ptr,i);
        editenderecocliente(ptr,i);
        editvalortotalemprestimocliente(ptr,i);
        editparcelascliente(ptr,i);
    }
    else
    {
        int escolha;
        cout << "\n1. Nome";
        cout << "\n2. Data nascimento";
        cout << "\n3. Cpf";
        cout << "\n4. Endereco";
        cout << "\n5. Valor total do emprestimo.";
        cout << "\n6. Parcelado em quantas vezes";
        cout << "\nEscolha: ";
        cout << "Qual gostaria parte gostaria de editar?";
        cin >> escolha;

        if(escolha==1)
        {
            editnomecliente(ptr,i);
        }
        else if(escolha==2)
        {
            editdatadenascimentocliente(ptr,i);
        }
        else if(escolha==3)
        {
            editcpfcliente(ptr,i);
        }
        else if(escolha==4)
        {
            editenderecocliente(ptr,i);
        }
        else if(escolha==5)
        {
            editvalortotalemprestimocliente(ptr,i);
        }
        else if(escolha==6)
        {
            editparcelascliente(ptr,i);
        }
    }
}


/*____________________Resumo___________________*/
//Inserir dados principais do cliente
void InserirdadosCliente(Cliente * ptr, int i)
{
    editnomecliente(ptr,i);
    editdatadenascimentocliente(ptr,i);
    editcpfcliente(ptr,i);
    editenderecocliente(ptr,i);
}

void InseriremprestimoCliente(Cliente * ptr, int i)
{
    editvalortotalemprestimocliente(ptr,i);
    editparcelascliente(ptr,i);
}
/*_____________________________________________*/

//Envio de informação
void editnomecliente(Cliente * ptr, int i){
    cout << "\nNome("<< (ptr+i)->nome << "): ";
    cin.ignore();
    getline(cin,(ptr+i)->nome);
}
void editdatadenascimentocliente(Cliente * ptr, int i)
{
    cout << "\nData nascimento("<< (ptr+i)->datanascimento.dia << '/' << (ptr+i)->datanascimento.mes << '/' << (ptr+i)->datanascimento.ano <<"): ";
    cout << "\nEx:(00 00 00) - Coloque espaco em vez de '/', a sequencia de dia mes e ano nao e string!" << endl;
    cin >> (ptr+i)->datanascimento.dia >> (ptr+i)->datanascimento.mes >> (ptr+i)->datanascimento.ano;
    
}
void editcpfcliente(Cliente * ptr, int i)
{
    
    cout << "\nCpf("<< (ptr+i)->cpf << "): ";
    string test = " ";
    cin >> test;
    while(test.length() > 10 && test.length() < 14)
    {
        cout << "\nEntrada invalida!";
        cout << "\nCpf("<< (ptr+i)->cpf << "): ";
        cin >> test;
    }
    (ptr+i)->cpf = test;
}
void editenderecocliente(Cliente * ptr, int i)
{
    cout << "\nEndereco("<< (ptr+i)->endereco << "): ";
    cin >> (ptr+i)->endereco;
}
void editvalortotalemprestimocliente(Cliente * ptr, int i)
{
    cout << "\nValor total("<< (ptr+i)->valoremprestimo << "): ";
    cin >> (ptr+i)->valoremprestimo;
}
void editparcelascliente(Cliente * ptr, int i)
{
    cout << "\nParcelado em quantas vezes("<< (ptr+i)->parceladoemvzs << "): ";
    cin >> (ptr+i)->parceladoemvzs;
    while((ptr+i)->parceladoemvzs<1 || (ptr+i)->parceladoemvzs>12)
    {
        cout << "\nNumero invalido!";
        cout << "\nParcelado em quantas vezes("<< (ptr+i)->parceladoemvzs << "): ";
        cin >> (ptr+i)->parceladoemvzs;
    }
}

void calculadordeemprestimo(Cliente * ptr, float juros, int ncadastro)
{
    //Biblioteca <ctime>
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    for(int i=0;i<ncadastro;i++)
    {
        bool verific = true;
        for(int j=0;j<(ptr+i)->parceladoemvzs;j++)
        {
            if((ptr+i)->emprestimo[j].valordaparcela>0)
            {
                verific = false;
            }
        }

        for(int j=0;j<(ptr+i)->parceladoemvzs;j++)
        {
            if((ptr+i)->valoremprestimo != 0 && verific)
            {
                (ptr+i)->emprestimo[j].valordaparcela = ((((ptr+i)->valoremprestimo*juros)/100)+(ptr+i)->valoremprestimo)/(ptr+i)->parceladoemvzs;

                (ptr+i)->emprestimo[j].dataemissaoparcela.dia = now->tm_mday;
                (ptr+i)->emprestimo[j].dataemissaoparcela.mes = (now->tm_mon + 1);
                (ptr+i)->emprestimo[j].dataemissaoparcela.ano = (now->tm_year + 1900);

                now->tm_mon = now->tm_mon + 1;
                if(now->tm_mon == 12)
                {
                    now->tm_year = now->tm_year + 1;
                    now->tm_mon = now->tm_mon - 11;
                }

                (ptr+i)->emprestimo[j].datavalidadeparcela.dia = now->tm_mday;
                (ptr+i)->emprestimo[j].datavalidadeparcela.mes = (now->tm_mon + 1);
                (ptr+i)->emprestimo[j].datavalidadeparcela.ano = (now->tm_year + 1900);
            }
        }
    }
}

void pagarparcela(Cliente * ptr, int sel)
{
    cout << "\nQual parcela gostaria de pagar?";
    for(int i=0;i<12;i++)
    {
        if((ptr+sel)->emprestimo[i].valordaparcela != 0)
        {
            cout << "\n\nValor da parcela[" << i+1 << "]: " << (ptr+sel)->emprestimo[i].valordaparcela;
            cout << "\nData de emissao do Emprestimo[" << i+1 << "]: " << (ptr+sel)->emprestimo[i].dataemissaoparcela.dia << "/" << (ptr+sel)->emprestimo[i].dataemissaoparcela.mes << "/" << (ptr+sel)->emprestimo[i].dataemissaoparcela.ano;
            cout << "\nData de validade do Emprestimo[" << i+1 << "]: " << (ptr+sel)->emprestimo[i].datavalidadeparcela.dia << "/" << (ptr+sel)->emprestimo[i].datavalidadeparcela.mes << "/" << (ptr+sel)->emprestimo[i].datavalidadeparcela.ano;
        }
    }
    int escolha;
    cin >> escolha;
    (ptr+sel)->emprestimo[escolha-1].valordaparcela = 0;
    (ptr+sel)->emprestimo[escolha-1].dataemissaoparcela.dia = 00;
    (ptr+sel)->emprestimo[escolha-1].dataemissaoparcela.mes = 00;
    (ptr+sel)->emprestimo[escolha-1].dataemissaoparcela.ano = 0000;
    (ptr+sel)->emprestimo[escolha-1].datavalidadeparcela.dia = 00;
    (ptr+sel)->emprestimo[escolha-1].datavalidadeparcela.mes = 00;
    (ptr+sel)->emprestimo[escolha-1].datavalidadeparcela.ano = 0000;
}

float editjuros()
{
    float i;
    cout << "\nGostaria de aplicar quanto de juros? (Ex:2.0%)";
    cin >> i;
    return i;
}

int Selecioneousuario(Cliente * ptr, int ncadastros)
{
    int sel;
    for(int i=0;i<ncadastros;i++)
    {
        cout << '\n' << i+1 << (ptr+i)->nome;
    }
    cout << "\nSelecione seu usuario: ";
    cin >> sel;
    sel = sel - 1;
    return sel;
}

void Problema(string e)
{

}